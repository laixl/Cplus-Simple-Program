//计算一个个文件中包含的单词的平均长度
#include <fstream>	//文件流所需要的头文件
#include <iostream>	//cin、cout需要
#include <cstdlib>	//exit需要
using namespace std;

void averLength(ifstream& fin, ofstream& fout);
//计算输入文件fin的单词的平均长度，输出到fout文件中

int main()
{
	ifstream fin;
	ofstream fout;
	cout << "Begin editing files.\n";
	fin.open("aaa.dat");//要放到averagelength.cpp文件夹中
	if (fin.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}
	fout.open("aver_length.dat");
	if (fout.fail())
	{
		cout << "Output file opening failed.\n";
		exit(1);
	}
	averLength(fin, fout);//调用函数

	fin.close();
	fout.close();
	cout << "Ending of editing files.\n";
	return 0;
}

//一个单词的前后为空白字符、逗号、句号、行首或行尾的任何一个字符串
//但是没有限定在字母和数字之间
void averLength(ifstream& fin, ofstream& fout)
{
	char next;
	char before;	//用来存储next的前一个字符
	int number;		//记录单词数量
	double length;	//累计单词的长度
	double aver_length;

	length = 0;
	number = 0;
	aver_length = 0;

	fin.get(next);
	before = next;
	length++;
	while (!fin.eof())//判断从更需是否读文件完全部内容
	{
		//满足行尾是这些符号
		if (next == ' ' || next == ',' || next == '.' || next == '!' || next == '?' || next == '"')
		{
			//满足行首是这些符号
			if (before == ' ' || before == ',' || before == '.' || before == '!' || before == '?' || before == '"')
			{
				length--;
			}
			else
			{
				length--;
				number++;
			}
		}
		if (next == '\n')
		{
			length--;
		}
		before = next;
		fin.get(next);		
		length++;
	}
	aver_length = (length - 1) / number;//最后还有个结束符号要去掉
	cout.setf(ios::fixed);		//不采用e记数法
	cout.setf(ios::showpoint);	//显示小数点
	cout.precision(4);			//小数精确位数
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.precision(4);
	cout << "average length = " << aver_length << endl;
	fout << "average length = " << aver_length << endl;
}