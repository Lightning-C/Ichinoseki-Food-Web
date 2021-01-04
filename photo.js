$(function(){
  $('.slider-show').slick({
      slidesToShow: 1,
      slidesToScroll: 1,
      arrows: false,
      fade: true,
      asNavFor: '.slider'
    });
    $('.slider').slick({
      slidesToShow: 5,
      slidesToScroll: 1,
      asNavFor: '.slider-show',
      dots: true,
      centerMode: true,
      focusOnSelect: true
    });
});