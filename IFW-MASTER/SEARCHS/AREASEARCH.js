$(function () {
  var temp = $(location).attr("search");
  temp = temp.replace("?search=", "");
  if (temp != "") {
    //alert(a);
    temp = decodeURI(temp);
    $('input#search').val(temp);
    $('input#search1').quicksearch('table tbody tr');
    $('input#search2').quicksearch('table tbody tr');
    $('input#search3').quicksearch('table tbody tr');
    $('input#search4').quicksearch('table tbody tr');
    $('input#search5').quicksearch('table tbody tr');
    $('input#search6').quicksearch('table tbody tr');
    $('input#search7').quicksearch('table tbody tr');
    $('input#search8').quicksearch('table tbody tr');
    $('input#search').quicksearch('table tbody tr');
    //alert(a);
  }
  else if (temp == "") {
    $('input#search').quicksearch('table tbody tr');
    $('input#search1').quicksearch('table tbody tr');
    $('input#search2').quicksearch('table tbody tr');
    $('input#search3').quicksearch('table tbody tr');
    $('input#search4').quicksearch('table tbody tr');
    $('input#search5').quicksearch('table tbody tr');
    $('input#search6').quicksearch('table tbody tr');
    $('input#search7').quicksearch('table tbody tr');
    $('input#search8').quicksearch('table tbody tr');
  }
});