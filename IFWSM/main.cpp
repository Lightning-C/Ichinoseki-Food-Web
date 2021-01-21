//	Software Details				//
//	Name:IFW_Search_Maker 			//
//	Date:2021/1/19					//
// 	Programmed by RikuWorks(TMC-Soft)//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <Shlwapi.h>
#include <direct.h>
#include <sys/stat.h>
#include <locale.h>

using namespace std;

//スタート画面
void start()
{
	cout << "  _______________________________________ " << endl;
	cout << " |                                       |" << endl;
	cout << " |  III    FFFFF   W   W    SSSS   M   M |" << endl;
	cout << " |   I     F       W W W   S       MM MM |" << endl;
	cout << " |   I     FFFF    W W W    SSS    MM MM |" << endl;
	cout << " |   I     F        W W        S   M M M |" << endl;
	cout << " |  III    F        W W    SSSS    M   M |" << endl;
	cout << " |                                       |" << endl;
	cout << "  ￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣" << endl;
	cout << "     Ichinoseki-Food-Web-Search-Maker     " << endl;
	cout << "               version:0.7                " << endl;
	cout << "                TMC-Soft                  " << endl << endl;
}

//異常終了
int error_finish(int error_num)
{
	cout << "ERROR" << error_num << endl;
	return 0;
}

//CSVファイルの場所を入力
string input_csv_file_path()
{
	string csv_file_path = "";
	cout << "CSVファイルのPathを入力してください" << endl << ">";
	cin >> csv_file_path;
	return csv_file_path;
}

//CSVファイルの存在確認
void csv_file_checker(string csv_path)
{
	cout << "CSVの存在を確認中..." << endl;
	bool checker;
	ifstream path(csv_path);
	checker = path.is_open();
	if (!checker)
		error_finish(1);
	else
		cout << "CSVの存在を確認!" << endl << endl;
}

//CSVファイルを開く
void csv_file_open(string csv_path)
{
	cout << "CSVを開いています..." << endl;
	ifstream path(csv_path);
	cout << "CSVを開きました!" << endl << endl;
}

//CSVファイルの行数を確かめる
int csv_file_lines(string csv_path)
{
	cout << "項目の個数を確認中..." << endl;
	string line;
	int lines = 0;
	ifstream path(csv_path);
	while (!path.eof())
	{
		getline(path, line);
		lines++;
	}
	path.close();
	lines = lines - 1;
	if (lines == 0)
		error_finish(1);
	else
	{
		cout << lines << "個の項目を確認!" << endl << endl;
		return lines;
	}
}



//文字列置き換え
string ReplaceString(string String1, string String2, string String3)
{
	std::string::size_type Pos(String1.find(String2));

	while (Pos != std::string::npos)
	{
		String1.replace(Pos, String2.length(), String3);
		Pos = String1.find(String2, Pos + String3.length());
	}

	return String1;
}

//CSVのデータを取得
string get_csv_data(int row, int col, string csv_path, int csv_lines)
{
	ifstream file(csv_path);
	string line_data;
	string delim = ",";
	string main_data[80][14];
	int now_row = 0;
	int now_col;
	while (getline(file, line_data))
	{
		now_col = 0;
		for (string::size_type spos, epos = 0; (spos = line_data.find_first_not_of(delim, epos)) != string::npos;)
		{
			string token = line_data.substr(spos, (epos = line_data.find_first_of(delim, spos)) - spos);
			main_data[now_row][now_col++] = (token);
		}
		now_row++;
	}
	return main_data[row + 1][col + 1];
}

//営業時間変換
string get_time(int line, string csv_path, int csv_lines)
{
	string oh, om, ch, cm, time;
	oh = get_csv_data(line, 3, csv_path, csv_lines);
	om = get_csv_data(line, 4, csv_path, csv_lines);
	ch = get_csv_data(line, 5, csv_path, csv_lines);
	cm = get_csv_data(line, 6, csv_path, csv_lines);
	time = oh + ":" + om + "~" + ch + ":" + cm;
	return time;
}

//出力用HTMLファイルに出力する
void output_file_output(int csv_lines,string csv_path)
{
	string txt[6]
	{
		"<tr>",
		  "<td><a href = 'PAGES/hogefile/hogefile.html' ><img src = '../img/hogehogearea/hogehogename/(1).jpg'  height = '10%'  onError=\"this.onerror = null; this.src = '../img/noimage.png';\" ></a></td>",
		  "<td>hogehogename</td>",
		  "<td>hogehogearea</td>",
		  "<td>hogehogegenre</td>",
		"</tr>"
	};
	string now_line;
	for (int i = 0; i < csv_lines; i++)
	{
		for (int ohl = 0; ohl < 6; ohl++)
		{
			now_line = txt[ohl];
			now_line = ReplaceString(now_line, ("hogehogename"), get_csv_data(i, 0, csv_path, csv_lines));
			now_line = ReplaceString(now_line, ("hogehogegenre"), get_csv_data(i, 1, csv_path, csv_lines));
			now_line = ReplaceString(now_line, ("hogehogetel"), get_csv_data(i, 2, csv_path, csv_lines));
			now_line = ReplaceString(now_line, ("hogehogetime"), get_time(i, csv_path, csv_lines));
			now_line = ReplaceString(now_line, ("hogehogeholiday"), get_csv_data(i, 7, csv_path, csv_lines));
			now_line = ReplaceString(now_line, ("hogehogeaddress"), get_csv_data(i, 8, csv_path, csv_lines));
			now_line = ReplaceString(now_line, ("hogehogearea"), get_csv_data(i, 9, csv_path, csv_lines));
			now_line = ReplaceString(now_line, ("hogehogecomment0"), get_csv_data(i, 10, csv_path, csv_lines));
			now_line = ReplaceString(now_line, ("hogehogecomment1"), get_csv_data(i, 11, csv_path, csv_lines));
			now_line = ReplaceString(now_line, ("hogehogecomment2"), get_csv_data(i, 12, csv_path, csv_lines));
			now_line = ReplaceString(now_line, ("hogefile"), get_csv_data(i, -1, csv_path, csv_lines));
			cout << now_line << endl;
		}
	}
}

//メインプロセス
int main()
{
	start();
	string csv_path;
	int csv_lines;
	csv_path = input_csv_file_path();
	csv_file_checker(csv_path);
	csv_file_open(csv_path);
	csv_lines = csv_file_lines(csv_path);
	output_file_output(csv_lines,csv_path);
	return 0;
}
