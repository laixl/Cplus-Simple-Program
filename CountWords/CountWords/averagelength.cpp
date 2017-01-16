//����һ�����ļ��а����ĵ��ʵ�ƽ������
#include <fstream>	//�ļ�������Ҫ��ͷ�ļ�
#include <iostream>	//cin��cout��Ҫ
#include <cstdlib>	//exit��Ҫ
using namespace std;

void averLength(ifstream& fin, ofstream& fout);
//���������ļ�fin�ĵ��ʵ�ƽ�����ȣ������fout�ļ���

int main()
{
	ifstream fin;
	ofstream fout;
	cout << "Begin editing files.\n";
	fin.open("aaa.dat");//Ҫ�ŵ�averagelength.cpp�ļ�����
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
	averLength(fin, fout);//���ú���

	fin.close();
	fout.close();
	cout << "Ending of editing files.\n";
	return 0;
}

//һ�����ʵ�ǰ��Ϊ�հ��ַ������š���š����׻���β���κ�һ���ַ���
//����û���޶�����ĸ������֮��
void averLength(ifstream& fin, ofstream& fout)
{
	char next;
	char before;	//�����洢next��ǰһ���ַ�
	int number;		//��¼��������
	double length;	//�ۼƵ��ʵĳ���
	double aver_length;

	length = 0;
	number = 0;
	aver_length = 0;

	fin.get(next);
	before = next;
	length++;
	while (!fin.eof())//�жϴӸ����Ƿ���ļ���ȫ������
	{
		//������β����Щ����
		if (next == ' ' || next == ',' || next == '.' || next == '!' || next == '?' || next == '"')
		{
			//������������Щ����
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
	aver_length = (length - 1) / number;//����и���������Ҫȥ��
	cout.setf(ios::fixed);		//������e������
	cout.setf(ios::showpoint);	//��ʾС����
	cout.precision(4);			//С����ȷλ��
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.precision(4);
	cout << "average length = " << aver_length << endl;
	fout << "average length = " << aver_length << endl;
}