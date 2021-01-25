$(function () {
  var temp = $(location).attr("search");
  temp = temp.replace("?search=", "");
  if (temp != "") {
    //alert(a);
    temp = decodeURI(temp);
    $('input#search').val(temp);
    $('input#search').quicksearch('table tbody tr');
    if (temp == "IFWTEAM") {
      window.location = "../MEMBERS/MEMBER.html";
    }
    else if (temp == "TOOLS") {
      window.location = "../TOOLS/DOWNLOADTOOLS.html";
    }
    //alert(a);
  }
  else if (temp == "") {
    $('input#search').quicksearch('table tbody tr');
  }
});