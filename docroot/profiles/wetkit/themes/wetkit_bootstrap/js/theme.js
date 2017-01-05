jQuery( '#mini-panel-homepage_submenu' ).addClass( 'sticky-bottom' );

jQuery( '<div id="tiffin_logo"><a href="/" tabindex="-1"><img alt="Tiffin University" src="http://tiffin.prod.acquia-sites.com/sites/default/files/tiffin-logo_0.png"></a></div>' ).prependTo( "body.page-search #navbar .wb-menu div.row" );
jQuery( '<div id="tiffin_logo"><a href="/" tabindex="-1"><img alt="Tiffin University" src="http://tiffin.prod.acquia-sites.com/sites/default/files/tiffin-logo_0.png"></a></div>' ).prependTo( "body.page-news #navbar .wb-menu div.row" );

jQuery( 'ul[role= "menubar"] li.dropdown a' ).css( 'cursor', 'pointer' );
jQuery( 'ul[role= "menubar"] li.dropdown a' ).removeClass( 'item' );

jQuery( '<li><div id="tiffin_logo" class="logoMobile"><a href="/" tabindex="-1"><img alt="Tiffin University" src="http://tiffin.prod.acquia-sites.com/sites/default/files/tiffin-logo_0.png"></a></div></li>' ).prependTo( "#wb-glb-mn ul.pnl-btn" );

jQuery( '#mini-panel-homepage_submenu' ).addClass( 'sticky-bottom' );
jQuery( '#mini-panel-floating_all_submenu' ).addClass( 'sticky-bottom' );

function cleanMenu () {

  jQuery( 'ul[role= "menu"] li:nth-of-type(2)' ).addClass( 'no-sect' );
  jQuery( 'ul[role= "menu"] li:nth-of-type(2)' ).html( '<a class="mb-item" role="menuitem" aria-setsize="6" aria-posinset="3" tabindex="-1" href="/admissions">Admissions</a>' );

  jQuery( 'ul[role= "menu"] li:nth-of-type(4)' ).addClass( 'no-sect' );
  jQuery( 'ul[role= "menu"] li:nth-of-type(4)' ).html( '<a class="mb-item" role="menuitem" aria-setsize="6" aria-posinset="3" tabindex="-1" href="/about">About TU</a>' );

  jQuery( 'ul[role= "menu"] li:nth-of-type(5)' ).addClass( 'no-sect' );
  jQuery( 'ul[role= "menu"] li:nth-of-type(5)' ).html( '<a class="mb-item" role="menuitem" aria-setsize="6" aria-posinset="3" tabindex="-1" href="/campuslife">Life At TU</a>' );
}

jQuery( document ).ready( function () {
  jQuery( "#info-pnl" ).append( "<a href='' id='cleanthemenu' onclick='cleanMenu(); return false;'></a>" );
  // jQuery( "#cleanthemenu" )[0].click();
} );

jQuery( document ).ready( function () {
  setInterval( cleanMenu(), 1000 );
} );

(function ( $ ) {

  var $window = $( window ),
    navbar = $( '#navbar' ).outerHeight(),
    sticky = $( '#mini-panel-homepage_submenu' ).outerHeight();

  // Make Featured image full-screen.
  function fullscreenFeaturedImage () {
    var homePageHero = $( '#mini-panel-homepage_top_hero' );

    if ( ! homePageHero ) {
      return;
    }

    homePageHero.css( {
      'height': $window.height() - ( navbar + sticky ) + 'px'
    } );
  }

  fullscreenFeaturedImage();

})( jQuery );
