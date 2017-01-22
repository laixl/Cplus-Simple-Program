//�������������ѡ�����򷨡�ð������

#include <iostream>
const int MAX_NUMBER_ARRAY = 20;

void fill_array(int a[], int size, int& number_used);
//�Ӽ��̶����������������
//size������a[]�����ĳ���
//number_used������a[]ʵ�ʴ洢��ֵ����Ŀ

void selection_sort(int a[], int number_used);
//����ѡ�����򷨶�����a[]���½�������ʹ��a[0]<a[1]<...<a[number_used-1]
//number_used <= ����a[]����������
//����Ԫ��a[0]~a[number_used-1]�ѱ���ֵ

void swap_values(int& v1, int& v2);
//����v1��v2��ֵ

int index_of_smallest(const int a[], int start_index, int number_used);
//��ȡ����a[start_index]~a[number_used-1]����С����ֵ������������i

void bubble_sort(int a[], int length);
//ð������


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

//ʹ��iostream
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

//��һ������ʣ�µ�����Ԫ�����ҵ���Сֵ
//�ڶ��������ҵ�����Сֵ���Ӧ�±�index������������ȷ��ֵ����a[index]��
void selection_sort(int a[], int length)
{
	using namespace std;
	cout << "****Selection Sort.****\n";
	int index_of_next_smallest;
	//���һ����a[length - 1]����������
	for (int index = 0; index < length - 1; index++)
	{
		index_of_next_smallest = index_of_smallest(a, index, length);
		swap_values(a[index], a[index_of_next_smallest]);
		//a[0]<=a[1]<=...<a[index]����ԭʼ����Ԫ������С��Ԫ��
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
			//min��a[start_index]~a[number_used-1]����С��
		}
	}
	return index_of_min;
}

//��һ�����Ƚ���������Ԫ�ش�С�����ϴ����������
//�ڶ��������κ��ƱȽϵ�λ�ã�ֱ����һ�ֱȽϽ����ֵ�ŵ���Ӧ�±�Index�У��˴���j)
//������һ�ֱȽ�
void bubble_sort(int a[], int length)
{
	using namespace std;
	cout << "****Bubble Sort.****\n";
	for (int i = length - 1; i >0 ; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j+1] < a[j])//��Ҫ�Ӵ�С���͸ĳ�>��
			{
				swap_values(a[j+1], a[j]);
			}
		}		
	}
}