//对数组进行排序：选择排序法、冒泡排序法

#include <iostream>
const int MAX_NUMBER_ARRAY = 20;

void fill_array(int a[], int size, int& number_used);
//从键盘读入整数来填充数组
//size是数组a[]声明的长度
//number_used是数组a[]实际存储的值的数目

void selection_sort(int a[], int number_used);
//采用选择排序法对数组a[]重新进行排序，使得a[0]<a[1]<...<a[number_used-1]
//number_used <= 数组a[]的声明长度
//数组元素a[0]~a[number_used-1]已被赋值

void swap_values(int& v1, int& v2);
//交换v1与v2的值

int index_of_smallest(const int a[], int start_index, int number_used);
//获取数组a[start_index]~a[number_used-1]中最小的数值，返回其索引i

void bubble_sort(int a[], int length);
//冒泡排序法


int main()
{
	using namespace std;
	cout << "This program sorts numbers from lowest to highest.\n";

	int sample_array[MAX_NUMBER_ARRAY], number_used;
	fill_array(sample_array, MAX_NUMBER_ARRAY, number_used);
	//selection_sort(sample_array, number_used);
	bubble_sort(sample_array, number_used);

	cout << "In sorted order the numbers are:\n";
	for (int index = 0; index < number_used; index++)
	{
		cout << sample_array[index] << " ";
	}
	cout << endl;

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

//第一步，在剩下的数组元素中找到最小值
//第二步，将找到的最小值与对应下标index交换，即将正确的值放在a[index]中
void selection_sort(int a[], int length)
{
	using namespace std;
	cout << "****Selection Sort.****\n";
	int index_of_next_smallest;
	//最后一个数a[length - 1]不用再排序
	for (int index = 0; index < length - 1; index++)
	{
		index_of_next_smallest = index_of_smallest(a, index, length);
		swap_values(a[index], a[index_of_next_smallest]);
		//a[0]<=a[1]<=...<a[index]都是原始数组元素中最小的元素
	}
}

void swap_values(int& v1, int& v2)
{
	int temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
}

int index_of_smallest(const int a[], int start_index, int number_used)
{
	int min, index_of_min;
	min = a[start_index];
	index_of_min = start_index;

	for (int index = start_index + 1; index < number_used; index++)
	{
		if (a[index] < min)
		{
			min = a[index];
			index_of_min = index;
			//min是a[start_index]~a[number_used-1]中最小的
		}
	}
	return index_of_min;
}

//第一步，比较相邻两个元素大小，将较大的数往后排
//第二步，依次后移比较的位置，直到这一轮比较将最大值放到相应下标Index中（此处是j)
//进行下一轮比较
void bubble_sort(int a[], int length)
{
	using namespace std;
	cout << "****Bubble Sort.****\n";
	for (int i = length - 1; i >0 ; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j+1] < a[j])//若要从大到小，就改成>号
			{
				swap_values(a[j+1], a[j]);
			}
		}		
	}
}