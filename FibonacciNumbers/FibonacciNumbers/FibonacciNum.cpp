//����쳲���������
//û�����飬û��ָ��

#include <iostream>
using namespace std;

int main()
{
	int previous_num, later_num, latest_num;
	int max_num;
	int count;
	previous_num = 1;
	later_num = 1;
	latest_num = later_num + previous_num;

	//�������ֵ�ı�ʾ
	/*count = 2;
	cout << "Enter the maximum of your Fibonacci numbers :\n";
	cin >> max_num;
	if (max_num > 2)
	{
		cout << previous_num << " ";
		cout << later_num << " ";
		while (latest_num < max_num)
		{
			previous_num = later_num;
			later_num = latest_num;
			cout << latest_num << " ";
			latest_num = later_num + previous_num;
			count++;
		}
		cout << "\n A total of " << count << " numbers\n";
	}
	else
	{
		cout << "Not an avaliable num.\n";
	}*/

	//����������Ŀ�ı�ʾ
	cout << "Enter the number of your Fibonacci numbers :\n";
	cin >> count;
	if(count>2)
	{ 
		cout << previous_num << " ";
		cout << later_num << " ";
		count = count - 2;
		while (count > 0)
		{
			previous_num = later_num;
			later_num = latest_num;
			cout << latest_num << " ";
			latest_num = later_num + previous_num;
			count--;
		}
	}
	else
	{
		cout << "Please larger than 2.\n";
	}

	return 0;
}