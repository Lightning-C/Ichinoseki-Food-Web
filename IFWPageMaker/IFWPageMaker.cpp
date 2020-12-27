﻿#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <Shlwapi.h>
#include <direct.h>
#include <sys/stat.h>

using namespace std;

//異常終了
int error_finish(int error_num)
{
	cout << "ERROR" << error_num << endl;
	return 0;
}

//CSVファイルの場所を入力
string input_csv_file_path()
{
	string csv_file_path ="";
	cout << "CSVファイルのPathを入力してください" << endl;
	cin >> csv_file_path;
	return csv_file_path;
}

//CSVファイルの存在確認
void csv_file_checker(string csv_path)
{
	cout << "CSVの存在を確認中" << endl;
	bool checker;
	ifstream path(csv_path);
	checker=path.is_open();
	if (!checker) error_finish(1);
	else cout << "CSVの存在を確認" << endl;
}

//CSVファイルを開く
void csv_file_open(string csv_path)
{
	cout << "CSVを開いています" << endl;
	ifstream path(csv_path);
}

//CSVファイルの行数を確かめる
int csv_file_lines(string csv_path)
{
	cout << "項目の個数を確認中"<< endl;
	string line;
	int lines=0;
	ifstream path(csv_path);
	while (!path.eof()) 
	{
		getline(path, line);
		lines++;
	}
	path.close();
	lines = lines-2;
	if (lines == 0) error_finish(1);
	else
	{
		cout <<lines<<"個の項目を確認" << endl;
		return lines;
	}
}

//テンプレートHTMLファイルの場所を入力
string input_ihtml_file_path()
{
	string html_file_path = "";
	cout << "テンプレートHTMLファイルのPathを入力してください" << endl;
	cin >> html_file_path;
	return html_file_path;
}

//テンプレートHTMLファイルの存在確認
void ihtml_file_checker(string html_path)
{
	bool checker;
	ifstream path(html_path);
	checker = path.is_open();
	if (!checker) error_finish(1);
}

//テンプレートHTMLファイルを開く
void ihtml_file_open(string html_path)
{
	ifstream path(html_path);
}

//テンプレートHTMLファイルの行数を確認
int ihtml_file_lines(string html_path)
{
	string line;
	int lines=0;
	ifstream path(html_path);
	while (!path.eof())
	{
		getline(path, line);
		cout << line << endl;
		lines++;
	}
	path.close();
	lines = lines--;
	if (lines == -1) error_finish(1);
	else return lines;
}

//ディレクトリ作成
string directory_maker(int csv_lines,string file_path)
{
	string a=file_path+"\\PAGES";
	const char* path;
	path = a.c_str();
	_mkdir(path);
	cout << "ディレクトリ" << path << "作成中" << endl;
	string dir = "\\";
	string fold_path;
	for (int i = 0; i < csv_lines; i++)
	{
		fold_path = path;
		string s = to_string(i);
		fold_path = fold_path +dir+ s;
		const char* folding = fold_path.c_str();
		_mkdir(folding);
		cout << "ディレクトリ" << fold_path << "作成中" << endl;
	}
	return fold_path;
}

//ディレクトリの存在確認
void directory_checker(int csv_lines,string folder)
{
	struct stat statBuf;
	string a = folder + "\\PAGES";
	const char* path;
	path = a.c_str();
	if (stat(path, &statBuf) == 0)
	{
		cout << "ディレクトリ" << a << "は正常に作成されました" << endl;
	}
	else
	{
		cout << "ディレクトリ" << a << "の作成に失敗しました 終了します" << endl;
	}
	string dir = "\\";
	string fold_path;
	for (int i = 0; i < csv_lines; i++)
	{
		fold_path = path;
		string s = to_string(i);
		fold_path = fold_path + dir + s;
		const char* folding = fold_path.c_str();
		if (stat(folding, &statBuf) == 0)
		{
			cout << "ディレクトリ" << fold_path << "は正常に作成されました" << endl;
		}
		else
		{
			cout << "ディレクトリ" << fold_path << "の作成に失敗しました 終了します" << endl;
		}
	}
		
	
}

//出力用HTMLファイルの作成
void output_file_maker(int csv_lines, string folder)
{
	struct stat statBuf;
	string s;
	string f;
	string dir = "\\";
	string fil = ".html";
	string file_name;
	for (int i = 0; i < csv_lines; i++)
	{
		const char* num;
		s = to_string(i);
		file_name = folder+"\\PAGES"+dir+s+dir+s+fil;
		const char* name = file_name.c_str();
		ofstream ofs(file_name);

		if (stat(name, &statBuf) == 0)
		{
			cout << "ファイル" << file_name << "は正常に作成されました" << endl;
		}
		else
		{
			cout << "ファイル" << file_name << "の作成に失敗しました 終了します" << endl;
		}
	}
}
/*//出力用HTMLファイルの存在確認
int output_file_checker()
{

}

//出力用HTMLファイルを開く
int output_file_open()
{

}

//出力用HTMLファイルに出力する
int output_file_output()
{

}
*/
int main()
{
	string pth;
	cin >> pth;
	directory_maker(8,pth);
	directory_checker(8, pth);
	output_file_maker(8, pth);
	return 0;
}