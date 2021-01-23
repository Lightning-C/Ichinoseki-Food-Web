$(function () {
  var temp = $(location).attr("search");
  temp = temp.replace("?search=", "");
  if (temp != "") {
    //alert(a);
    temp = decodeURI(temp);
    $('input#search').val(temp);
    $('input#search').quicksearch('table tbody tr');
    if (temp == "いなり") {
      alert("いなりがはいってないやん");
    }
    //alert(a);
  }
  else if (temp == "") {
    $('input#search').quicksearch('table tbody tr');
  }
});