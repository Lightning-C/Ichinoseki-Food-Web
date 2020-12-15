#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const char* fileName = "C:\\test.html";
ofstream ofs(fileName);
string title;
string name ;
string area ;
string address ;
int start_time_hour;
int start_time_min;
int over_time_hour;
int over_time_min;
string tel;
string genre;
string comment;
string holiday;
int error_finish()
{
    return -1;
}
void file_checker()
{
    if (!ofs)
    {
        cout << "ファイルが開けませんでした。" << endl;
        cin.get();
        error_finish();
    }

}
void input_title()
{
    cout << "タイトルを入力してください" << endl;
    cin >> title;
}
void input_name()
{
    cout << "店名を入力してください" << endl;
    cin >> name;
    if (name == "0")
    {
        cout << "" << endl;
        error_finish();
    }
}
void input_area()
{
    
    int area_num=0;
    cout << "地域番号を入力してください" << endl;
    cout << "1:藤沢 " <<endl<< "2:大東 " <<endl<< "3:千厩 " <<endl<< "4:室根 " <<endl<< "5:一関市内 " <<endl<< "6:川崎 " <<endl<<"7:東山 "<<endl<<"8:花泉 "<< endl;
    cin >> area_num;
    switch (area_num)
    {
    case 1:
        area = "藤沢";
        break;
    case 2:
        area = "大東";
        break;
    case 3:
        area = "千厩";
        break;
    case 4:
        area = "室根";
        break;
    case 5:
        area = "一関市内";
        break;
    case 6:
        area = "川崎";
        break;
    case 7:
        area = "東山";
        break;
    case 8:
        area = "花泉";
        break;
    default:
        cout << "エラー:値を入力してください(終了します)" << endl;
        error_finish();
        break;
    }
}
void input_address()
{
    cout << "住所を入力してください" << endl;
    cin >> address;
    if (address == "0")
    {
        cout << "" << endl;
        error_finish();
    }
}
void input_time()
{
    cout << "営業時間の入力(24時間表記)" << endl;
    cout<<"開始時刻(時)を入力してください"<<endl;
    cin >> start_time_hour;
    cout << "開始時刻(分)を入力してください" << endl;
    cin >> start_time_min;
    cout << "終了時刻(時)を入力してください" << endl;
    cin >> over_time_hour;
    cout << "終了時刻(分)を入力してください" << endl;
    cin >> over_time_min;
}
void input_tel()
{
    cout << "電話番号を入力してください" << endl;
    cin >> tel;
}
void input_genre()
{
    cout << "ジャンルを入力してください" << endl;
    cin >> genre;
}
void input_review()
{
    cout << "ひと言コメントを入力してください" << endl;
    cin >> comment;
}
void input_holiday()
{
    cout << "定休日を入力してください" << endl;
    cin >> holiday;
}
void output_html() 
{
    ofs << "<!DOCTYPE html>" << endl;
    ofs << "<html lang = 'ja'>" << endl;
    ofs << "<head>" << endl;
    ofs << "<meta charset='UTF - 8'>" << endl;
    ofs << "<meta name='viewport' content='width = device - width, initial - scale = 1.0'>" << endl;
    ofs << "<link rel='stylesheet' href='template_stylesheet.css'>" << endl;
    ofs << "<title>"<<title<<"</title>" << endl;
    ofs << "</head>" << endl;
    ofs << "<body>" << endl;
    ofs << "<ul class ='cp_breadcrumb'>" << endl;
    ofs << "</ul>" << endl;
    ofs << "<header>" << endl;
    ofs << "<h1>" << name << "</h1>" << endl;
    ofs << "</header>" << endl;
    ofs << "<h2>店舗情報</h2>" << endl;
    ofs << "<main1>" << endl;
    ofs << "<ul>" << endl;
    ofs << "<li>" << comment << "</li>" << endl;
    ofs << "</ul>" << endl;
    ofs << "<table>" << endl;
    ofs << "<tr>" << endl;
    ofs << "<th>店名</th>" << endl;
    ofs << "<td>"<<name<<"</td>" << endl;
    ofs << "</tr>" << endl;
    ofs << "<tr>" << endl;
    ofs << "<th>ジャンル</th>" << endl;
    ofs << "<td>"<<genre<<"</td>" << endl;
    ofs << "</tr>" << endl;
    ofs << "<tr>" << endl;
    ofs << "<th>電話番号</th>" << endl;
    ofs << "<td>"<<tel<<"</td>" << endl;
    ofs << "</tr>" << endl;
    ofs << "<tr>" << endl;
    ofs << "<th>住所</th>" << endl;
    ofs << "<td>"<<address<<"</td>" << endl;
    ofs << "</tr>" << endl;
    ofs << "<tr>" << endl;
    ofs << "<th>営業時間</th>" << endl;
    ofs << "<td>"<<start_time_hour<<":"<<start_time_min<<"～"<<over_time_hour<<":"<<over_time_min<<"</td>" << endl;
    ofs << "</tr>" << endl;
    ofs << "<tr>" << endl;
    ofs << "<th>定休日</th>" << endl;
    ofs << "<td>"<<holiday<<"</td>" << endl;
    ofs << "</tr>" << endl;
    ofs << "</table>" << endl;
    ofs <<"</main1><br>"<<endl;
    ofs <<"<main2>"<< endl;
    ofs <<"<img src='. / img / nijisora.JPG' width='50 % ' height='50 % '>"<< endl;
    ofs <<"<iframe src='https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d3103.971443096614!2d141.1075043!3d38.9246302!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x5f88d09d6f0b0357%3A0x7ecc4e362c08f769!2z5LiA6Zai5bel5qWt6auY562J5bCC6ZaA5a2m5qCh!5e0!3m2!1sja!2sjp!4v1607392765253!5m2!1sja!2sjp' width='400' height='300' frameborder='0' style='border:0' allowfullscreen='' aria-hidden='false' tabindex='0'></iframe>"<< endl;
    ofs <<"</main2>"<< endl;
    ofs << "</body>" << endl;
    ofs << "</html>" << endl;
}
int main()
{
    file_checker();
    input_name();
    input_area();
    input_address();
    input_time();
    input_tel();
    input_genre();
    input_review();
    input_holiday();
    output_html();
    return 0;
}