(function ($) {
  

  Drupal.behaviors.accordion = {
    attach: function (context, settings) {
     
      $( '#edit-map-fieldset-body .toggle-icon' ).click(function() {
        $(this).parent().next('.collapse').toggleClass('show');
        $(this).toggleClass('flip');
        $(this).parent().parent().parent().parent().parent().parent().toggleClass('move');
      });

      $( '#edit-image-fieldset-body .toggle-icon' ).click(function() {
        $(this).parent().next('.collapse').toggleClass('show');
        $(this).toggleClass('flip');
      });

    }
  };


}(jQuery));
  

       


