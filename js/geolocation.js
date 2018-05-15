var map, baseLayer, graphicLayer;

require(["esri/map", "esri/dijit/LocateButton", "dojo/domReady!"], function (Map, LocateButton) {
  esriConfig.defaults.geometryService = new esri.tasks.GeometryService("https://borgarvefsja.reykjavik.is/arcgis/rest/services/Utilities/Geometry/GeometryServer");

    var initialExtent = new esri.geometry.Extent({ "xmin": 352100, "ymin": 401000, "xmax": 367700, "ymax": 412000, "spatialReference": { "wkid": 3057 } });
    map = new Map("mapDiv", {
        extent: initialExtent,
        logo: false,
        zoom: 3,
    });

    geoLocatebutton = new LocateButton({
        map: map,
        highlightLocation: true,
        useTracking: true,
        enableHighAccuracy: true,
        scale: 1000,
    }, "LocateButton");
    geoLocatebutton.startup();
    //þegar kortið er tilbúið er punkti bætt á kortið
    map.on("load", function () {
        var ISN93coords = getLambert(64.132953, -21.898063);
        addPointToMap(ISN93coords[0], ISN93coords[1]);
    });
    //smellt á kortið til að bæta við punkti
    map.on("click", function(evt) {
        addPointToMap(evt.mapPoint.x, evt.mapPoint.y);
        getHverfi(evt.mapPoint.x, evt.mapPoint.y);
        document.getElementById("xcoords").value = evt.mapPoint.x;
        document.getElementById("ycoords").value = evt.mapPoint.y;
    });

    baseLayer = new esri.layers.ArcGISTiledMapServiceLayer("https://borgarvefsja.reykjavik.is/arcgis/rest/services/Borgarvefsja/Borgarvefsja/MapServer");
    graphicLayer = new esri.layers.GraphicsLayer();
    graphicLayer.on("click", function (evt) {
        alert("Xhnit:" + evt.graphic.attributes.pX + "\nYhnit:" + evt.graphic.attributes.pY);
    });
    map.addLayers([baseLayer, graphicLayer]);
});


function addPointToMap(pointX, PointY) {
    require([
        "esri/symbols/SimpleMarkerSymbol",
        "esri/symbols/SimpleLineSymbol",
        "esri/graphic",
        "esri/Color",
        "dojo/domReady!"
    ], function (SimpleMarkerSymbol, SimpleLineSymbol, Graphic, Color) {
        graphicLayer.clear();

        var qPoint = new esri.geometry.Point(pointX, PointY, new esri.SpatialReference({ wkid: 3057 }));

        var attributes = {
            Name: 'Einhver staður',
            pX: pointX,
            pY: PointY
        };
        var graphic = new Graphic(qPoint);
        var sym = new SimpleMarkerSymbol(SimpleMarkerSymbol.STYLE_CIRCLE, 10, new SimpleLineSymbol(SimpleLineSymbol.STYLE_SOLID, new Color([255, 0, 0]), 1), new Color([255, 0, 0, 0.5]));
        graphic.symbol = sym;
        graphic.attributes = attributes;
        graphicLayer.add(graphic);
    });
}

//fall sem sér um að varpa GPS hnitum í ISN93 hnit
function getLambert(phi, lambda) {
    // Parameters depend on projected coordinate system in question
    // Projected coordinate system ISN93 Iceland, Ellipsoid: GRS-80
    // Semimajor axis
    var a = 6378137.0;
    // Inverse flattening (1/f)
    //var If = 298.257222101;
    // Eccentricity
    var e = 0.0818191913305;
    // First Standard Parallel
    var phi1 = 64.250000;
    // Second Standard Parallel
    var phi2 = 65.750000;
    // Latitude False Origin
    var phiF = 65.000000;
    // Longitude False Origin
    //var lambdaF = -19.000000;
    // Longitude Natural Origin
    var lambda0 = -19.0;
    // False Easting
    var EF = 500000.0;
    // False Northing
    var NF = 500000.0;
    // Calculations
    var m1 = Math.cos(deg2rad(phi1)) / Math.sqrt(1 - (Math.pow(e, 2) * Math.pow(Math.sin(deg2rad(phi1)), 2)));
    var m2 = Math.cos(deg2rad(phi2)) / Math.sqrt(1 - (Math.pow(e, 2) * Math.pow(Math.sin(deg2rad(phi2)), 2)));
    var t = Math.tan((Math.PI / 4) - (deg2rad(phi) / 2)) / Math.pow(((1 - e * Math.sin(deg2rad(phi))) / (1 + e * Math.sin(deg2rad(phi)))), 0.5 * e);
    var t1 = Math.tan((Math.PI / 4) - (deg2rad(phi1) / 2)) / Math.pow(((1 - e * Math.sin(deg2rad(phi1))) / (1 + e * Math.sin(deg2rad(phi1)))), 0.5 * e);
    var t2 = Math.tan((Math.PI / 4) - (deg2rad(phi2) / 2)) / Math.pow(((1 - e * Math.sin(deg2rad(phi2))) / (1 + e * Math.sin(deg2rad(phi2)))), 0.5 * e);
    var tF = Math.tan((Math.PI / 4) - (deg2rad(phiF) / 2)) / Math.pow(((1 - e * Math.sin(deg2rad(phiF))) / (1 + e * Math.sin(deg2rad(phiF)))), 0.5 * e);
    var n = (Math.log(m1) - Math.log(m2)) / (Math.log(t1) - Math.log(t2));
    var F = m1 / (n * Math.pow(t1, n));
    var r = a * F * Math.pow(t, n);
    var rF = a * F * Math.pow(tF, n);
    var theta = n * (lambda - lambda0);
    // Easting
    var East = EF + r * Math.sin(deg2rad(theta));
    East = Math.round(East * 1000) / 1000;
    // Northing
    var North = NF + rF - r * Math.cos(deg2rad(theta));
    North = Math.round(North * 1000) / 1000;
    //Height, --ekki með--
    //H = 0;
    // Build an array to return
    var xyz = new Array(East, North);
    return xyz;
}
//fall sem getLambert() notar
function deg2rad(deg) {
    var rad = deg * 2 * Math.PI / 360;
    return rad;
};

function getHverfi(xCoord,yCoord){
  require([
    "esri/tasks/IdentifyTask",
    "esri/tasks/IdentifyParameters",
    "esri/geometry/Point"
  ], function (
    IdentifyTask, IdentifyParameters, Point
  ) {
      var identifyTask, identifyParams, result;

      identifyTask = new IdentifyTask("http://borgarvefsja.reykjavik.is/arcgis/rest/services/Borgarvefsja/Borgarvefsja_over/MapServer");
      identifyParams = new IdentifyParameters();
      identifyParams.tolerance = 3;
      identifyParams.returnGeometry = false;
      identifyParams.layerIds = [95];
      identifyParams.layerOption = IdentifyParameters.LAYER_OPTION_ALL;
      identifyParams.mapExtent = map.extent;

      identifyParams.geometry = new Point(xCoord, yCoord, map.spatialReference);

      identifyTask.execute(identifyParams, function (idResults) {
        if(idResults.indexOf(0)) {
          document.getElementById("neighborhood").value = idResults[0].feature.attributes.Borgarhluti;
        }
      })
  })
}