$(function(){
    $('.thumbnails img').click(function(){
     var $thisImg = $(this).attr('src');
     var $thisAlt = $(this).attr('alt');
     $('.mainImage img').attr({src:$thisImg,alt:$thisAlt});
    });
   });