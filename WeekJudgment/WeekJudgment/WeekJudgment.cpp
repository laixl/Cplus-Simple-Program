//该程序输入日期（如 July 4,2008），输出那个日期是星期几
//算法参考：https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week

#include <iostream>
using namespace std;

bool isLeapYear(int year);
//判断闰年，如果year是闰年，返回true，否则返回false
int getCenturyValue(int year);
//获取年份的前两位，进行一系列计算，返回计算得到值
int getYearValue(int year);
//判断一个年份相对于本世纪元年过了多少年，并相应地计算出一个值
int getMonthValue(int month, int year);
//参照某个列表返回值
bool isDecimal(int number);
//判断是否是小数
bool isValidYear(int year);
//判断用户输入的年份是否有效
bool isValidMonth(int month);
//判断输入的月份是否有效
bool isValidDay(int day, int month, int year);
//判断输入的日期是否有效

int main()
{
	int year;
	int month;
	int day;
	int century_value;
	int year_value;
	int month_value;
	int weekday;
	//bool isLeapYr;
	bool isValidNum;
	//int year2;

	cout << "Please enter year month day:\n";
	cin >> year;
	isValidNum = isValidYear(year);
	while (!isValidNum)//防止无效输入，输入 < 0或是小数
	{
		cout << "Please enter a valid year:\n";
		cin >> year;
		isValidNum = isValidYear(year);
	}
	cin >> month;
	isValidNum = isValidMonth(month);
	while (!isValidNum)//防止无效输入，输入不在0~12或是小数
	{
		cout << "Please enter a valid month:\n";
		cin >> month;
		isValidNum = isValidMonth(month);
	}
	cin >> day;
	isValidNum = isValidDay(day, month, year);
	while (!isValidNum)//防止无效输入，输入1~31或是小数
	{
		cout << "Please enter a valid day:\n";
		cin >> day;
		isValidNum = isValidDay(day, month, year);
	}

	//isLeapYr = isLeapYear(year);//test
	//cout << isLeapYr << endl;
	//century_value = getCenturyValue(year);//test
	//cout << century_value << endl;
	//year_value = getYearValue(year);//test
	//cout << year_value << endl;
	//month_value = getMonthValue(month,year);//test
	//cout << month_value << endl;

	century_value = getCenturyValue(year);
	year_value = getYearValue(year);
	month_value = getMonthValue(month, year);
	weekday = (century_value + year_value + month_value + day) % 7;

	switch (weekday)
	{
	case 0:
		cout << "Sunday\n";
		break;
	case 1:
		cout << "Monday\n";
		break;
	case 2:
		cout << "Tuesday\n";
		break;
	case 3:
		cout << "Wednesday\n";
		break;
	case 4:
		cout << "Thursday\n";
		break;
	case 5:
		cout << "Friday\n";
		break;
	case 6:
		cout << "Saturday\n";
		break;
	default:
		cout << "Baby something's wrong.\n";
		break;
	}
	return 0;
}


/***********函数定义*************/
bool isLeapYear(int year)
{
	if (year % 400 == 0)
	{
		return true;
	}
	else if ((year % 4 == 0) && (year % 100 != 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int getCenturyValue(int year)
{
	int century_value;
	int result;
	century_value = year / 100;
	result = 3 - (century_value % 4);
	result = result * 2;
	return result;
}

int getYearValue(int year)
{
	int year_value;
	int temp;
	year_value = year - 100 * (year / 100);
	temp = year_value / 4;
	year_value = temp + year_value;
	return year_value;
}

int getMonthValue(int month, int year)
{
	int month_value;
	bool leap_year;
	month_value = 0;//initial
	switch (month)
	{
	case 1:
		leap_year = isLeapYear(year);
		if (leap_year)
			month_value = 6;
		else
			month_value = 0;
		break;
	case 2:
		leap_year = isLeapYear(year);
		if (leap_year)
			month_value = 2;
		else
			month_value = 3;
		break;
	case 3:
		month_value = 3;
		break;
	case 4:
		month_value = 6;
		break;
	case 5:
		month_value = 1;
		break;
	case 6:
		month_value = 4;
		break;
	case 7:
		month_value = 6;
		break;
	case 8:
		month_value = 2;
		break;
	case 9:
		month_value = 5;
		break;
	case 10:
		month_value = 0;
		break;
	case 11:
		month_value = 3;
		break;
	case 12:
		month_value = 5;
		break;
	default:
		break;
	}
	return month_value;
}

//判断输入是否合理
//判断小数
bool isDecimal(int number)
{
	char symbol;//获取输入的每一个字符
	bool isDecimal;
	isDecimal = false;
	cin.get(symbol);//因为number是int型，这里直接get到小数点，
	if (symbol == '.')
	{
		do//丢弃多余输入的值
		{
			cin.get(symbol);
		} while (symbol != '\n');
		cout << "No decimal! Please input an integer.\n";
		isDecimal = true;
	}
	return isDecimal;
}

//无效情况：小数，< 0
bool isValidYear(int year)
{
	bool isValidNum;
	isValidNum = true;
	if (year < 0)
	{
		cout << "Invalid Input. Please >0.\n";
		isValidNum = false;
	}
	if (isDecimal(year))
		isValidNum = false;
	return isValidNum;
}

//月份无效：不在1~12范围内，小数
bool isValidMonth(int month)
{
	bool isValidNum;
	isValidNum = true;
	if (month < 1 || month>12)
	{
		cout << "Invalid Input. Please within 1~12.\n";
		isValidNum = false;
	}
	if (isDecimal(month))
		isValidNum = false;
	return isValidNum;
}

bool isValidDay(int day, int month, int year)
{
	bool isValidNum;
	isValidNum = true;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day < 1 || day>31)
		{
			cout << "Invalid Input. Please within 1~31.\n";
			isValidNum = false;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day < 1 || day>30)
		{
			cout << "Invalid Input. Please within 1~30.\n";
			isValidNum = false;
		}
		break;
	case 2://分闰年和非闰年情况
		if (isLeapYear(year))
		{
			if (day < 1 || day>29)
			{
				cout << "Invalid Input. Please within 1~29.\n";
				isValidNum = false;
			}
		}
		else
		{
			if (day < 1 || day>28)
			{
				cout << "Invalid Input. Please within 1~28.\n";
				isValidNum = false;
			}
		}
		break;
	default:
		cout << "Invalid Month Input. Please within 1~12.\n";
		break;
	}
	if (isDecimal(day))
		isValidNum = false;

	return isValidNum;
}