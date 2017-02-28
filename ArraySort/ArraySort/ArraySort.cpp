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
//ð�����򷨣��Ӻ��濪ʼ

void insert_sort(int a[], int length);
//��������

void bubble_sort2(int *a, int length);
//����ð�����򷨣����±�Ϊ0��ʼ

void select_sort2(int *a, int length);
//����ѡ�����򷨣�д����һ��

void bubble2_sort(int *a, unsigned int length);
//˫��ð������

void merge_sort(int *a, unsigned int length);
//�������򷨣��飬�ݹ�

void adjust_array(int *a, int left, int right);
//���ڿ�������

void fast_sort(int *a, unsigned int length);
//�������򷨣��ڿ�����+���η�
//�÷����Ļ���˼���ǣ�
//1���ȴ�������ȡ��һ������Ϊ��׼����
//2���������̣���������������ȫ�ŵ������ұߣ�С�ڻ����������ȫ�ŵ�������ߡ�
//3���ٶ����������ظ��ڶ�����ֱ��������ֻ��һ������
//˼�������Ѱ����ѻ�׼����

void shell_sort(int* a, unsigned int length);
//ϣ�����򷨣���С��������
//�÷����Ļ���˼���ǣ�
//1���Ƚ���������Ԫ�����зָ�����ɸ������У������ĳ������������Ԫ����ɣ�
//2���ֱ����ֱ�Ӳ�������
//3���������������ٽ�������
//4�������������е�Ԫ�ػ������������㹻С��ʱ���ٶ�ȫ��Ԫ�ؽ���һ��ֱ�Ӳ�������
//˼������ηָ������У�

void shell_sort2(int *a, int length);
//ϣ�����򷨣�ֱ�ӽ����������޸ģ����벽��

void Adjust2MinHeap(int *a, int pos, int length);
//����С����

void Adjust2MaxHeap(int *a, int pos, int length);
//�����󶥶�

void heap_sort(int *a, int length);
//������
//�÷����Ļ���˼���ǣ�
//1�������鿴��˳��洢�Ķ�������������
//2��������С���ѣ���󶥶ѣ�
//3�������Ѷ�Ԫ�������һ��Ԫ��

void heap2_sort(int *a, int length);
//Ϊ�˲�������


int main()
{
	using namespace std;
	cout << "This program sorts numbers from lowest to highest.\n";

	//int sample_array[MAX_NUMBER_ARRAY], number_used;
	//fill_array(sample_array, MAX_NUMBER_ARRAY, number_used);
	//selection_sort(sample_array, number_used);
	//bubble_sort(sample_array, number_used);
	//insert_sort(sample_array, number_used);

	int sample_array[10] = { 100,1,32,4,14,73,6,18,29,70};
	int number_used = 10;
	heap_sort(sample_array, number_used);

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
	for (int i = length - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j + 1] < a[j])//��Ҫ�Ӵ�С���͸ĳ�>��
			{
				swap_values(a[j + 1], a[j]);
			}
		}
	}
}

void insert_sort(int a[], int length)
{
	using namespace std;
	cout << "****Insertion Sort.****\n";
	for (int i = 1; i < length; i++)
	{
		for (int j = i; j > 0; j--)//j=0,j<i;j++����������0��1���������
		{
			if (a[j] < a[j - 1])//��Ҫ�Ӵ�С���͸ĳ�>��
			{
				swap_values(a[j], a[j - 1]);
			}
		}
	}
}


void bubble_sort2(int *a, int length)
{
	//��ǰ��Ϊ�������С����Ļ����Ӻ�����ǰ��ȽϽϿ죬ʡȥ����
	//��������Ҳ��һ����������ʵ�������й�
	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap_values(a[j], a[j + 1]);
			}
		}
	}
}

void select_sort2(int *a, int length)
{
	int temp;
	int j;
	int index_smallest;

	//��һ��ԭ���ǣ�ֻ��Ҫ���е�a[length-2],���һ����a[length-1]��Ȼ�������С��ֵ
	for (int i = 0; i < length - 1; i++)
	{
		temp = a[i];
		index_smallest = i;
		for (j = i; j < length - 1; j++)
		{
			if (a[j + 1] < temp)
			{
				temp = a[j + 1];
				index_smallest = j + 1;
			}
		}
		swap_values(a[i], a[index_smallest]);
	}
}


void bubble2_sort(int *a, unsigned int length)
{
	//�д�Ҫ��
	//unsigned int i;//����
	////unsigned int count;//ͳ���ܴ���
	//bool flag;//trueΪż����falseΪ����
	//for (i = 0; i < length; i++)
	//{
	//	if ((i % 2) == 0)
	//		flag = true;
	//	else
	//		flag = false;
	//	if (flag = true)
	//	{
	//		for (unsigned int j = i; j < length - i; j++)
	//		{
	//			for (unsigned int k = j; k < length - i - j - 1; k++)
	//			{
	//				if (a[k] < a[k + 1])
	//					swap_values(a[k], a[k + 1]);
	//			}
	//			flag = false;
	//		}
	//	}
	//	else
	//	{
	//		for (unsigned int j = length - i; j < i; j--)
	//		{
	//			for (unsigned int k = j; k < length - i - j-1; k++)
	//			{
	//				if (a[k] > a[k + 1])
	//					swap_values(a[k], a[k + 1]);
	//			}
	//		}
	//	}
	//}

	int left = 0;
	int right = length - 1;
	int flag;//��־��������

	while (left < right)
	{
		//���ҵ�������Ƚ�
		for (int i = right - 1; i >= left; i--)
		{
			if (a[i] > a[i + 1])
			{
				swap_values(a[i], a[i + 1]);
				flag = i;
			}
		}
		left = flag;

		//�����ң�����Ƚ�
		for (int i = left; i < right; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap_values(a[i], a[i + 1]);
				flag = i;
			}
		}
		right = flag;
	}
}

void merge_sort(int *a, unsigned int length)
{

}

void adjust_array(int *a, int left, int right)
{
	int base_num;//��׼��
	int i, j;

	if (left >= right)
		return;

	i = left;
	j = right;
	base_num = a[i];//��ȡ��׼��

	//����if��ifֻ��һ�β�����while�ǽ��������������㲻С�ڻ�׼������ȫ���ŵ������ұ�
	//����С���������ŵ��������
	while (i < j)
	{
		//�˴�i<j�Ǳ���j������i�������Ҫ����ѭ��������j--����iֵҲ����
		//�������ұ߿�ʼѰ��С�����������˴�while��:ֻҪa[j]���ڵ��ڻ�׼�����ͻ���������ִ��j--
		//ֱ��j<=i���ҵ�С�ڻ�׼������
		while (i < j&&a[j] >= base_num)
		{
			j--;
		}
		if (i < j)//����ʡ������j����j<=i�ˣ���Ҫ��a[j]����a[i]��
			a[i++] = a[j];
		while (i < j&&a[i] < base_num)//��׼����߶��ǲ�С��������
		{
			i++;
		}
		if (i < j)//����ʡ
			a[j--] = a[i];
	}
	a[i] = base_num;
	adjust_array(a, left, i - 1);//�ݹ飬�Ի�׼����ߵ����ٲ���һ��
	adjust_array(a, i + 1, right);
}

//֮��Ҫ�ֿ�д�������ÿ������򷨿����������������÷�һ��
void fast_sort(int *a, unsigned int length)
{
	adjust_array(a, 0, length - 1);
}

void shell_sort(int* a, unsigned int length)
{
	unsigned int step;//ÿ����С�Ĳ���
	unsigned int gap;//��������

	step = 2;

	for (gap = length / step; gap > 0; gap = gap / step)
	{
		for (unsigned int i = 0; i < length; i++)
		{
			for (unsigned int j = i; j < length - gap; j = j + gap)//j����ÿ�������е��������ݵ��±�
			{
				if (a[j] > a[j + gap])//��ʵj+gap==i
					swap_values(a[j], a[j + gap]);
			}
		}
	}
}

void shell_sort2(int *a, int length)
{
	unsigned int step;//ÿ����С�Ĳ���
	unsigned int gap;//��������

	step = 2;

	for (gap = length / step; gap > 0; gap = gap / step)
	{
		for (int i = gap; i < length; i++)
		{
			//�˴���ͬ
			for (int j = i; j > 0; j = j - gap)
			{
				if (a[j] < a[j - gap])//��Ҫ�Ӵ�С���͸ĳ�>��
				{
					swap_values(a[j], a[j - gap]);
				}
			}
		}
	}
}

//����Ϊ��С��
void Adjust2MinHeap(int *a, int father, int length)
{
	int child;//���ӽ��ı��
	int temp; //���浱ǰ������ֵ

	//һ������������ʾ�ѣ��������������0���� �����±�Ϊi�Ľ��ĸ�����±��Ϊ(i - 1) / 2
	//�������ӽ���±�ֱ�Ϊ2*i + 1��2*i + 2
	//��ע�����������Ǵ�1��ʼ�������Һ��ӽ��ֱ���2i��2i + 1��
	for (temp = a[father]; 2 * father + 1 <= length; father = child)
	{
		child = 2 * father + 1;//����
		if ((child + 1 < length) && (a[child] > a[child + 1]))//�����Һ��Ӵ������Һ��ӱ�����Сʱ��ѡȡ�Һ���
			child++;

		if (a[child] < temp)//�����ӽ���ֵС�ڸ����ʱ�������ӽ�㸳ֵ�������
			a[father] = a[child];
		else
			break;//��������ֵ�Ⱥ��ӽ��Сʱ������ѭ��
	}//��ʱtemp���ֵӦ�����������С��
	a[father] = temp;
}
void heap_sort(int *a, int length)
{
	int i;
	//������iһ��ʼ��length/2��ʼ
	//��Ϊchild=2*i+1����child<length���õ�i<(length-1)/2<length/2������iȡ�ô������ĺ��ӽ��Ҳ������
	//�����2*i<=length.�ĳ�i<(length-1)/2Ҳ��
	//ѭ��������С��
	for (i = length / 2; i >= 0; i--)
		Adjust2MinHeap(a, i, length - 1);

	//�����Զ������һ����֮���ٵ�����
	for (i = length - 1; i > 0; i--)
	{
		swap_values(a[0], a[i]);
		Adjust2MinHeap(a, 0, i - 1);
	}
}

void Adjust2MaxHeap(int *a, int father, int length)
{
	int child;
	int temp;

	child = 2 * father + 1;
	temp = a[father];

	while (child < length)
	{
		// ������Һ��ӽ�㣬�����Һ��ӽ���ֵ�������ӽ�㣬��ѡȡ�Һ��ӽ��
		if (child + 1 < length&&a[child + 1] > a[child])
		{
			child++;
		}

		// ���������ֵ�Ѿ����ں��ӽ���ֵ����ֱ�ӽ���
		if (a[child] < temp)
		{
			break;
		}

		// �Ѻ��ӽ���ֵ���������
		a[father] = a[child];

		// ѡȡ���ӽ������ӽ��,��������ɸѡ
		father = child;
		child = 2 * father + 1;
	}

	a[father] = temp;
}

void heap2_sort(int *a, int length)
{
	int i;

	//ѭ����������
	for (i = length / 2; i >= 0; i--)
	{
		Adjust2MaxHeap(a, i, length - 1);
	}
		
	//�����Զ������һ����֮���ٵ�����
	for (i = length - 1; i > 0; i--)
	{
		swap_values(a[0], a[i]);
		Adjust2MaxHeap(a, 0, i);
	}
}