#include <iostream>
#include <cmath>
using namespace std;


void get_input(double& a, double& b, double& c);
//���������εı߳�

bool is_triangle(double a, double b, double c);
//�ж��Ƿ����㹹�������ε�����

void calcu_perimeter_area(double a, double b, double c, double& perimeter, double& area);
//���������εı߳������

int main()
{
	double a, b, c;
	double perimeter;
	double area;
	bool result;
	a = b = c = 0;
	get_input(a, b, c);
	result = is_triangle(a, b, c);
	while (!result)
	{
		get_input(a, b, c); 
		result = is_triangle(a, b, c);
		if (result)
			break;
	}
	calcu_perimeter_area(a, b, c, perimeter, area);//���ܷŵ�whileѭ���У������ڵ�һ��result=trueʱ�޷�ִ�иú���
	return 0;
}

//��������
void get_input(double& a, double& b, double& c)
{
	cout << "Enter three side lengths of triangle:\n";
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	//is_triangle(a, b, c);
}

bool is_triangle(double a, double b, double c)
{
	bool result;
	if ((a + b) > c && (a + c) > b && (b + c) > a)
	{
		result = true;
		cout << "Calculating...\n";		
	}
	else
	{
		result = false;
		cout << "Not meet the conditions to form a triangle, please try again.\n";		
	}
	return result;
}

void calcu_perimeter_area(double a, double b, double c, double& perimeter, double& area)
{
	double s;
	perimeter = a + b + c;
	s = perimeter / 2;
	area = sqrt(s*(s - a)*(s - b)*(s - c));
	cout << "Perimeter = " << perimeter << endl;
	cout << "Area = " << area << endl;
}