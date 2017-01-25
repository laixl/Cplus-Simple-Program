#include <iostream>
const int MAX_ARRAY_SIZE = 20;

//从键盘输入数组，数组长度最大为size，使用长度为nunber_used
void fill_array(int a[], int size, int& number_used);

//搜索目标值为target的元素，返回a[index]==target的第一个索引，若不存在返回-1
int search(const int a[], int number_used, int target);

int main()
{
	using namespace std;
	int arr[MAX_ARRAY_SIZE];
	int number_used, target;

	fill_array(arr, MAX_ARRAY_SIZE, number_used);

	char ans;
	int result;

	do
	{
		cout << "Enter a number to search for:\n";
		cin >> target;

		result = search(arr, number_used, target);
		if (result == -1)
		{
			cout << target << " is not on the list.\n";
		}
		else
		{
			cout << target << " is stored in array position "
				<< result << endl
				<< "(Remember: the first position is 0.\n";
		}

		cout << "Rearch again?(y/n followed by return):";
		cin >> ans;
	} while ((ans != 'n') || (ans != 'N'));

	cout << "End of program.\n";
	return 0;
}

//使用iostream
void fill_array(int a[], int size, int& number_used)
{
	using namespace std;
	cout << "Enter up to " << size << " nonnegative whole numbers.\n"
		<< "Mark the end of the list with a negative number.\n";
	int next, index;
	index = 0;
	cin >> next;
	while ((next >= 0) && (index < size))
	{
		a[index] = next;
		index++;
		cin >> next;
	}
	number_used = index;
}

int search(const int a[], int number_used, int target)
{
	int index = 0;

	bool found = false;
	while ((!found) && (index < number_used))
	{
		if (target == a[index])
			found = true;
		else
			index++;
	}

	if (found)
		return index;
	else
		return -1;
}