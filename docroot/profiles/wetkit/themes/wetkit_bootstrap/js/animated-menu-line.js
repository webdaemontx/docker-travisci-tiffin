// Run an animated line underneath your menu
// Updated: Changed line to box and with background/foreground color change

/*
(function($) {
  $.fn.magicMenu = function() {

    var $el, leftPos, newWidth;

    this.append("<li id='magic-line'></li>");

    var $magicLine = $("#magic-line");

    $magicLine


      alert($magicLine.toSource());

    this.find(".menu li a").hover(function() {
      $el = $(this);

      alert(this.toSource());


      leftPos = $el.position().left;
      newWidth = $el.parent().width();

      alert($magicLine.toSource());


      $magicLine.stop().animate({
        left: leftPos,
        width: newWidth

      });
    }, function() {
      $(this).css("color", "black");
      $magicLine.css("background-color", "#ffffff");
      alert('i');
      $magicLine.stop().animate({
        left: $magicLine.data("origLeft"),
        width: $magicLine.data("origWidth")
      });
    });
  };
})(jQuery);

(function($) {
    $(document).ready(function() {
      $(".menu").magicMenu();
      $("li a").click(function(e) {
        e.preventDefault();
      });
    });
})(jQuery);
    */