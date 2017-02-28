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
//冒泡排序法，从后面开始

void insert_sort(int a[], int length);
//插入排序法

void bubble_sort2(int *a, int length);
//仍是冒泡排序法，从下标为0开始

void select_sort2(int *a, int length);
//仍是选择排序法，写到了一起

void bubble2_sort(int *a, unsigned int length);
//双向冒泡排序法

void merge_sort(int *a, unsigned int length);
//并归排序法，归，递归

void adjust_array(int *a, int left, int right);
//用于快速排序法

void fast_sort(int *a, unsigned int length);
//快速排序法，挖坑填数+分治法
//该方法的基本思想是：
//1．先从数列中取出一个数作为基准数。
//2．分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。
//3．再对左右区间重复第二步，直到各区间只有一个数。
//思考：如何寻找最佳基准数？

void shell_sort(int* a, unsigned int length);
//希尔排序法，缩小增量排序
//该方法的基本思想是：
//1、先将整个待排元素序列分割成若干个子序列（由相隔某个“增量”的元素组成）
//2、分别进行直接插入排序，
//3、依次缩减增量再进行排序，
//4、待整个序列中的元素基本有序（增量足够小）时，再对全体元素进行一次直接插入排序。
//思考：如何分割子序列？

void shell_sort2(int *a, int length);
//希尔排序法，直接将插入排序修改，加入步长

void Adjust2MinHeap(int *a, int pos, int length);
//构建小顶堆

void Adjust2MaxHeap(int *a, int pos, int length);
//构建大顶堆

void heap_sort(int *a, int length);
//堆排序
//该方法的基本思想是：
//1、将数组看做顺序存储的二叉树，构建堆
//2、调整成小顶堆（或大顶堆）
//3、交换堆顶元素与最后一个元素

void heap2_sort(int *a, int length);
//为了测试最大堆


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
	for (int i = length - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j + 1] < a[j])//若要从大到小，就改成>号
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
		for (int j = i; j > 0; j--)//j=0,j<i;j++，不过具体0、1视情况而定
		{
			if (a[j] < a[j - 1])//若要从大到小，就改成>号
			{
				swap_values(a[j], a[j - 1]);
			}
		}
	}
}


void bubble_sort2(int *a, int length)
{
	//以前认为，如果从小到大的话，从后面往前面比较较快，省去交换
	//后来觉得也不一定，这是与实际数据有关
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

	//减一的原因是，只需要排列到a[length-2],最后一个数a[length-1]自然就是最大（小）值
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
	//有错要改
	//unsigned int i;//次数
	////unsigned int count;//统计总次数
	//bool flag;//true为偶数，false为奇数
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
	int flag;//标志正序逆序

	while (left < right)
	{
		//从右到左，正向比较
		for (int i = right - 1; i >= left; i--)
		{
			if (a[i] > a[i + 1])
			{
				swap_values(a[i], a[i + 1]);
				flag = i;
			}
		}
		left = flag;

		//从左到右，反向比较
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
	int base_num;//基准数
	int i, j;

	if (left >= right)
		return;

	i = left;
	j = right;
	base_num = a[i];//获取基准数

	//不是if，if只有一次操作，while是将数组中所有满足不小于基准数的数全部放到他的右边
	//所有小于他的数放到他的左边
	while (i < j)
	{
		//此处i<j是避免j减到与i相等了仍要进到循环体中再j--（且i值也会变大）
		//从数组右边开始寻找小于他的数，此处while是:只要a[j]大于等于基准数，就会跳过该数执行j--
		//直到j<=i或找到小于基准数的数
		while (i < j&&a[j] >= base_num)
		{
			j--;
		}
		if (i < j)//不可省，避免j减到j<=i了，仍要将a[j]填入a[i]中
			a[i++] = a[j];
		while (i < j&&a[i] < base_num)//基准数左边都是不小于他的数
		{
			i++;
		}
		if (i < j)//不可省
			a[j--] = a[i];
	}
	a[i] = base_num;
	adjust_array(a, left, i - 1);//递归，对基准数左边的数再操作一遍
	adjust_array(a, i + 1, right);
}

//之所要分开写，是想让快速排序法看起来与其他排序法用法一样
void fast_sort(int *a, unsigned int length)
{
	adjust_array(a, 0, length - 1);
}

void shell_sort(int* a, unsigned int length)
{
	unsigned int step;//每次缩小的步长
	unsigned int gap;//步长长度

	step = 2;

	for (gap = length / step; gap > 0; gap = gap / step)
	{
		for (unsigned int i = 0; i < length; i++)
		{
			for (unsigned int j = i; j < length - gap; j = j + gap)//j代表每个子序列的连续数据的下标
			{
				if (a[j] > a[j + gap])//其实j+gap==i
					swap_values(a[j], a[j + gap]);
			}
		}
	}
}

void shell_sort2(int *a, int length)
{
	unsigned int step;//每次缩小的步长
	unsigned int gap;//步长长度

	step = 2;

	for (gap = length / step; gap > 0; gap = gap / step)
	{
		for (int i = gap; i < length; i++)
		{
			//此处不同
			for (int j = i; j > 0; j = j - gap)
			{
				if (a[j] < a[j - gap])//若要从大到小，就改成>号
				{
					swap_values(a[j], a[j - gap]);
				}
			}
		}
	}
}

//调整为最小堆
void Adjust2MinHeap(int *a, int father, int length)
{
	int child;//左孩子结点的标号
	int temp; //保存当前父结点的值

	//一般用数组来表示堆，若根结点存在序号0处， 数组下标为i的结点的父结点下标就为(i - 1) / 2
	//其左右子结点下标分别为2*i + 1和2*i + 2
	//（注：如果根结点是从1开始，则左右孩子结点分别是2i和2i + 1）
	for (temp = a[father]; 2 * father + 1 <= length; father = child)
	{
		child = 2 * father + 1;//左孩子
		if ((child + 1 < length) && (a[child] > a[child + 1]))//当有右孩子存在且右孩子比左孩子小时，选取右孩子
			child++;

		if (a[child] < temp)//当孩子结点的值小于父结点时，将孩子结点赋值给父结点
			a[father] = a[child];
		else
			break;//当父结点的值比孩子结点小时，跳出循环
	}//此时temp里的值应该是数组的最小数
	a[father] = temp;
}
void heap_sort(int *a, int length)
{
	int i;
	//？？？i一开始从length/2开始
	//因为child=2*i+1，且child<length，得到i<(length-1)/2<length/2，就算i取得大，这样的孩子结点也不存在
	//这里的2*i<=length.改成i<(length-1)/2也行
	//循环建立最小堆
	for (i = length / 2; i >= 0; i--)
		Adjust2MinHeap(a, i, length - 1);

	//交换对顶和最后一个数之后，再调整堆
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
		// 如果有右孩子结点，并且右孩子结点的值大于左孩子结点，则选取右孩子结点
		if (child + 1 < length&&a[child + 1] > a[child])
		{
			child++;
		}

		// 如果父结点的值已经大于孩子结点的值，则直接结束
		if (a[child] < temp)
		{
			break;
		}

		// 把孩子结点的值赋给父结点
		a[father] = a[child];

		// 选取孩子结点的左孩子结点,继续向下筛选
		father = child;
		child = 2 * father + 1;
	}

	a[father] = temp;
}

void heap2_sort(int *a, int length)
{
	int i;

	//循环建立最大堆
	for (i = length / 2; i >= 0; i--)
	{
		Adjust2MaxHeap(a, i, length - 1);
	}
		
	//交换对顶和最后一个数之后，再调整堆
	for (i = length - 1; i > 0; i--)
	{
		swap_values(a[0], a[i]);
		Adjust2MaxHeap(a, 0, i);
	}
}