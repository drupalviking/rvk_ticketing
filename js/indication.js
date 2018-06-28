(function ($) {
  
  Drupal.behaviors.editIndicationForm = {
    attach: function (context, settings) {
      $( '.revision-title' ).unbind('click').bind('click', function() {
        $( '.revision-table' ).toggleClass( 'show-table' );
        $( this ).toggleClass( 'flip-icon' );
      });
    }
  };

  Drupal.behaviors.accordion = {
    attach: function (context, settings) {

      $( '#edit-indication-fieldset-map-fieldset .media-info-btn-wrapper-small .btn' ).unbind('click').bind('click', function() {
        $( '#rvk-ticketing-create-ticket-form' ).toggleClass( 'show-map-wrapper' );
      });

      $( '.media-info-btn-wrapper .btn:nth-child(1)' ).unbind('click').bind('click', function() {
        if ($('.show-image-wrapper').length > 0) {
          $( '#rvk-ticketing-create-ticket-form' ).removeClass( 'show-image-wrapper' );
          setTimeout(
            function() 
            {
              $( '#rvk-ticketing-create-ticket-form' ).toggleClass( 'show-map-wrapper' );
            }, 900);
        } else {
          $( '#rvk-ticketing-create-ticket-form' ).toggleClass( 'show-map-wrapper' );
        }
      }); 

      
      $( '#images-fieldset-wrapper .media-info-btn-wrapper-small .btn' ).unbind('click').bind('click', function() {
        $( '#rvk-ticketing-create-ticket-form' ).toggleClass( 'show-image-wrapper' );
      }); 

      $( '.media-info-btn-wrapper .btn:nth-child(2)' ).unbind('click').bind('click', function() {
        if ($('.show-map-wrapper').length > 0) {
          $( '#rvk-ticketing-create-ticket-form' ).removeClass( 'show-map-wrapper' );
          setTimeout(
            function() 
            {
              $( '#rvk-ticketing-create-ticket-form' ).toggleClass( 'show-image-wrapper' );
            }, 900);
        } else {
          $( '#rvk-ticketing-create-ticket-form' ).toggleClass( 'show-image-wrapper' );
        }
      });

    }
  };

  Drupal.behaviors.checkboxClick = {
    attach: function (context, settings) {
      $( '#edit-indication-fieldset-map-fieldset-dont-use-map' ).unbind('click').bind('click', function() {
        $( '#rvk-ticketing-create-ticket-form' ).toggleClass( 'hide-map' );
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
  

       


