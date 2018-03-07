(function ($) {
  

  Drupal.behaviors.accordion = {
    attach: function (context, settings) {
      $( '#edit-map-fieldset .toggle-icon' ).click(function() {
        $(this).parent().next('.collapse').toggleClass('show');
        $(this).toggleClass('flip');
        $(this).parent().parent().parent().parent().parent().parent().toggleClass('move');
      });

      $( '#edit-image-fieldset .toggle-icon' ).click(function() {
        $(this).parent().next('.collapse').toggleClass('show');
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

        $("#edit-address--2", context).bind('autocompleteSelect', function(event, node) {
          var key = $(node).data('autocompleteValue');
          // If matches found...
          if (key != '0') {

          }
        });
      }
    };

}(jQuery));
  

       


