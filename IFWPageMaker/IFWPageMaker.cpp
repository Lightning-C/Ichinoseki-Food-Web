//	Software Details				//
//	Name:IFW_Page_Maker 			//
//	Date:2020/12/28					//
// 	Developed by RikuWorks(TMC-Soft)//

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
	cout << " |  III    FFFFF   W   W   PPPP    M   M |" << endl;
	cout << " |   I     F       W W W   P   P   MM MM |" << endl;
	cout << " |   I     FFFF    W W W   PPPP    MM MM |" << endl;
	cout << " |   I     F        W W    P       M M M |" << endl;
	cout << " |  III    F        W W    P       M   M |" << endl;
	cout << " |                                       |" << endl;
	cout << "  ￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣" << endl;
	cout << "      Ichinoseki-Food-Web-Page-Maker      " << endl;
	cout << "               version:1.0                " << endl;
	cout << "                TMC-Soft                  " << endl<<endl;
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
	cout << "CSVファイルのPathを入力してください" << endl<<">";
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
		cout << "CSVの存在を確認!" << endl<<endl;
}

//CSVファイルを開く
void csv_file_open(string csv_path)
{
	cout << "CSVを開いています..." << endl;
	ifstream path(csv_path);
	cout << "CSVを開きました!" << endl<<endl;
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
		cout << lines << "個の項目を確認!" << endl<<endl;
		return lines;
	}
}

//テンプレートHTMLファイルの場所を入力
string input_ihtml_file_path()
{
	string html_file_path = "";
	cout << "テンプレートHTMLファイルのPathを入力してください" << endl<<">";
	cin >> html_file_path;
	return html_file_path;
}

//テンプレートHTMLファイルの存在確認
void ihtml_file_checker(string html_path)
{
	cout << "テンプレートHTMLの存在を確認中..." << endl;
	bool checker;
	ifstream path(html_path);
	checker = path.is_open();
	if (!checker)
		error_finish(1);
	cout << "テンプレートHTMLの存在を確認しました!" << endl<<endl;
}

//テンプレートHTMLファイルを開く
void ihtml_file_open(string html_path)
{
	cout << "テンプレートHTMLを開いています..." << endl;
	ifstream path(html_path);
	cout << "テンプレートHTMLを開きました!" << endl<<endl;
}

//テンプレートHTMLファイルの行数を確認
int ihtml_file_lines(string html_path)
{
	cout << "テンプレートHTMLの行数を確認しています..." << endl;
	string line;
	int lines = 0;
	ifstream path(html_path);
	while (!path.eof())
	{
		getline(path, line);
		cout <<lines<<"  "<< line << endl;
		lines++;
	}
	path.close();
	lines = lines--;
	if (lines == -1)
		error_finish(1);
	else
		cout << lines << "個の項目を確認!" << endl << endl;
		return lines;
}

//ディレクトリの作成場所を入力
string input_dir_path()
{
	string csv_file_path = "";
	cout << "ディレクトリの場所を入力してください" << endl<<">";
	cin >> csv_file_path;
	return csv_file_path;
}

//ディレクトリ作成
void directory_maker(int csv_lines, string file_path)
{
	string a = file_path + "\\PAGES";
	const char *path;
	path = a.c_str();
	_mkdir(path);
	cout << "ディレクトリ" << path << "作成中" << endl;
	string dir = "\\";
	string fold_path;
	for (int i = 0; i < csv_lines; i++)
	{
		fold_path = path;
		string s = to_string(i);
		fold_path = fold_path + dir + s;
		const char *folding = fold_path.c_str();
		_mkdir(folding);
		cout << "ディレクトリ" << fold_path << "作成中" << endl;
	}
}

//ディレクトリの存在確認
void directory_checker(int csv_lines, string folder)
{
	struct stat statBuf;
	string a = folder + "\\PAGES";
	const char *path;
	path = a.c_str();
	if (stat(path, &statBuf) == 0)
	{
		cout << "親ディレクトリ" << a << "は正常に作成されました" << endl;
	}
	else
	{
		cout << "親ディレクトリ" << a << "の作成に失敗しました 終了します" << endl;
	}
	string dir = "\\";
	string fold_path;
	for (int i = 0; i < csv_lines; i++)
	{
		fold_path = path;
		string s = to_string(i);
		fold_path = fold_path + dir + s;
		const char *folding = fold_path.c_str();
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
		const char *num;
		s = to_string(i);
		file_name = folder + "\\PAGES" + dir + s + dir + s + fil;
		const char *name = file_name.c_str();
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
//出力用HTMLファイルの存在確認
void output_file_checker(int csv_lines, string folder)
{
	string s;
	string f;
	string dir = "\\";
	string fil = ".html";
	string file_name;
	for (int i = 0; i < csv_lines; i++)
	{
		const char *num;
		s = to_string(i);
		file_name = folder + "\\PAGES" + dir + s + dir + s + fil;
		const char *name = file_name.c_str();
		bool checker;
		ifstream path(name);
		checker = path.is_open();

		if (checker != 0)
		{
			cout << "ファイル" << file_name << "は正常に作成されました" << endl;
		}
		else
		{
			cout << "ファイル" << file_name << "の作成に失敗しました 終了します" << endl;
		}
	}
}

//出力用HTMLファイルを開く
void output_file_open(int csv_lines, string folder)
{
	string s;
	string f;
	string dir = "\\";
	string fil = ".html";
	string file_name;
	for (int i = 0; i < csv_lines; i++)
	{
		const char *num;
		s = to_string(i);
		file_name = folder + "\\PAGES" + dir + s + dir + s + fil;
		const char *name = file_name.c_str();
		cout << name << "を開いています..." << endl;
		ifstream path(name);
		cout << name << "を開きました!" << endl;
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
string get_csv_data(int row ,int col,string csv_path,int csv_lines)
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
	return main_data[row+1][col+1];
}

//営業時間変換
string get_time(int line,string csv_path, int csv_lines)
{
	string oh, om, ch, cm,time;
	oh = get_csv_data(line, 3, csv_path, csv_lines);
	om = get_csv_data(line, 4, csv_path, csv_lines);
	ch = get_csv_data(line, 5, csv_path, csv_lines);
	cm = get_csv_data(line, 6, csv_path, csv_lines);
	time = oh + ":" + om + "~" + ch + ":" + cm;
	return time;
}

//出力用HTMLファイルに出力する
void output_file_output(int csv_lines, int html_lines, string folder, string html_path,string csv_path)
{
	string s;
	string f;
	string dir = "\\";
	string fil = ".html";
	string file_name;
	vector<string> vstr;
	for (int i = 0; i < csv_lines; i++)
	{
		const char *num;
		s = to_string(i);
		file_name = folder + "\\PAGES" + dir + s + dir + s + fil;
		const char *name = file_name.c_str();
		cout << name << "への書き込みの開始..." << endl;
		ifstream path(html_path);
		ofstream opath(name, ios::app);
		string tmp;
		while (getline(path, tmp))
			vstr.push_back(tmp);
		for (int ohl = 0; ohl < html_lines; ohl++)
		{
			string now_line = vstr[ohl];
			now_line = ReplaceString(now_line, ("hogehogename"),get_csv_data(i,0,csv_path,csv_lines));
			now_line = ReplaceString(now_line, ("hogehogegenre"), get_csv_data(i,1, csv_path, csv_lines));
			now_line = ReplaceString(now_line, ("hogehogetel"), get_csv_data(i,2, csv_path, csv_lines));
			now_line = ReplaceString(now_line, ("hogehogetime"), get_time(i,csv_path,csv_lines));
			now_line = ReplaceString(now_line, ("hogehogeholiday"), get_csv_data(i,7, csv_path, csv_lines));
			now_line = ReplaceString(now_line, ("hogehogeaddress"), get_csv_data(i,8, csv_path, csv_lines));
			now_line = ReplaceString(now_line, ("hogehogearea"), get_csv_data(i,9, csv_path, csv_lines));
			now_line = ReplaceString(now_line, ("hogehogecomment0"), get_csv_data(i,10, csv_path, csv_lines));
			now_line = ReplaceString(now_line, ("hogehogecomment1"), get_csv_data(i,11, csv_path, csv_lines));
			now_line = ReplaceString(now_line, ("hogehogecomment2"), get_csv_data(i,12, csv_path, csv_lines));
			opath << now_line << endl;
		}
		path.close();
		cout << name << "への書き込みが終了しました!" << endl;
	}
}

//メインプロセス
int main()
{
	start();
	string csv_path, ihtml_path, dir_path;
	int csv_lines,ihtml_lines;
	csv_path = input_csv_file_path();
	ihtml_path = input_ihtml_file_path();
	dir_path = input_dir_path();
	csv_file_checker(csv_path);
	csv_file_open(csv_path);
	csv_lines=csv_file_lines(csv_path);
	ihtml_file_checker(ihtml_path);
	ihtml_file_open(ihtml_path);
	ihtml_lines = ihtml_file_lines(ihtml_path);
	directory_maker(csv_lines, dir_path);
	directory_checker(csv_lines, dir_path);
	output_file_maker(csv_lines, dir_path);
	output_file_checker(csv_lines, dir_path);
	output_file_open(csv_lines, dir_path);
	output_file_output(csv_lines, ihtml_lines, dir_path, ihtml_path, csv_path);
	return 0;
}