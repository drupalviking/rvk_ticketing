(function ($) {
  

  Drupal.behaviors.accordion = {
    attach: function (context, settings) {
      $( '#edit-indication-fieldset-map-fieldset .toggle-icon' ).click(function() {
        $(this).parent().next('.collapse').toggleClass('show-map');
        $(this).toggleClass('flip');
        $(this).parent().parent().parent().parent().parent().parent().toggleClass('move');
      });

     
      $( '#images-fieldset-wrapper .toggle-icon' ).click(function() {
        $(this).parent().parent().parent().parent().parent().parent().parent().parent().toggleClass('show-image');
        $(this).toggleClass('flip');
      });

    }
  };

    Drupal.behaviors.streetNameSearch = {
      attach: function (context) {

        $('#edit-autocomplete-field').focus(
            function(){
                $(this).val('');
            });

        $("#edit-indication-fieldset-map-fieldset-address-address", context).bind('autocompleteSelect', function(event, node) {
          var key = $(node).data('autocompleteValue');
          // If matches found...
          if (key != '0') {
            console.log(key);
            $.get('/index.php?q=gata/fa_x_y_hnit_gotu_callback/' + key, function(data){
              var xcoord = data[0].x;
              var ycoord = data[0].y;
              addPointToMap(xcoord, ycoord);
              var zoomPoint = new esri.geometry.Point(xcoord,ycoord, new esri.SpatialReference({ wkid: 3057 }));
              map.centerAt(zoomPoint);
            });
          }
        });
      }
    };

}(jQuery));
  

       


