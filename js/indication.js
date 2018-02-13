(function ($) {
  

  Drupal.behaviors.accordion = {
    attach: function (context, settings) {
     
      $( '.toggle-icon' ).click(function() {
        $(this).parent().next('.collapse').toggleClass('show');
      });

    }
  };


}(jQuery));
  

       


