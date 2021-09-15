<?php
function AddMenuItem($item, $page, $current)
{
    if ($current == 1)
        print("<tr class = 'menu_current'>");
    else
        print("<tr class = 'menu_item'>");
    print("<td>");
    print("<a href=");
    print($page);
    if ($current == 1)
        print(" class = 'menu_current_text'>");
    else
        print(" class = 'menu_item_text'>");
    print($item);
    print("</a>");
    print("</td></tr>");
}
function InitMenu($page_id)
{
    AddMenuItem("Солнечная система", "index.php", $page_id == 0);
    AddMenuItem("Солнце", "sun.php", $page_id == 1);
    AddMenuItem("Планеты земной группы", "earthlike.php", $page_id == 2);
    AddMenuItem("---- Меркурий", "mercury.php", $page_id == 3);
    AddMenuItem("---- Венера", "venus.php", $page_id == 4);
    AddMenuItem("---- Марс", "mars.php", $page_id == 5);
    AddMenuItem("Газовые гиганты", "gasgiants.php", $page_id == 6);
    AddMenuItem("---- Юпитер", "jupiter.php", $page_id == 7);
    AddMenuItem("---- Сатурн", "saturn.php", $page_id == 8);
    AddMenuItem("---- Уран", "uran.php", $page_id == 9);
    AddMenuItem("---- Нептун", "neptune.php", $page_id == 10);
}
function PageBegin($title, $page_id)
{
    include 'templates/1.html';
    print($title);
    include 'templates/2.html';
    print($title);
    include 'templates/3.html';
    InitMenu($page_id);
    include 'templates/4.html';
}
function PageEnd($image)
{
    print("<button href='sun.php'></button>");
    include 'templates/5.html';
    print("<center><img class='img_out' src='media/");
    print($image);
    print(".jpg' width='256' height='256'/></center>");
    include 'templates/6.html';
}
function PageEndNoPrev()
{
    include 'templates/5.html';
    include 'templates/6.html';
}
?>