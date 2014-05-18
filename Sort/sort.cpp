#include <stdlib.h>
#include <stdio.h>

inline void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

//选择排序
//整个数组分为前后两块，分别是已排序和未排序
//将未排序部分的最小值加到已排序部分的末尾即可
//时间复杂度为O(n^2)
void SelectSort(int a[], int len)
{
	for(int i = 0; i < len; ++i)
	{
		int j = i;
		int min = a[j];
		int pos = j;
		for(; j < len; ++j)
		{
			//找到未排序部分最小值
			if( a[j] < min)
			{
				min = a[j];
				pos = j;
			}
		}
		if(i != j)
		{
			//直接交换，避免移动操作
			Swap(a[i], a[pos]);
		}
	}
}

//插入排序
//整个数组分为前后两块，分别是已排序和未排序
//选择未排序部分的第一个数插入已排序部分
//时间复杂度为O(n^2)
void InsertSort(int a[], int len)
{
	for(int i = 1; i < len; i++)
	{
		int j = i - 1;
		int temp = a[i];

		//从后向前移动，不要交换，只赋值。
		for(; j >= 0; j--)
		{
			if(temp < a[j])
				a[j+1] = a[j];
			else
				break;
		}

		//空出来的插入点写入数据
		a[j+1] = temp;
	}
}

//冒泡排序
//对于数组中的每个数，如果比之前的那一个小，就交换（即往上冒）
//时间复杂度为O(n^2)
void BubbleSort(int a[], int len)
{
	for( int i = 1; i < len; ++i)
	{
		int j = i-1;
		while( j >= 0 && a[j+1] < a[j])
		{
			Swap(a[j+1], a[j]);
			j--;
		}
	}
}

//归并排序
//经典的分治思想，时间复杂度为O(nlogn)
//源数组a被分为两部分，起止分别为（start,end),(_start,_end)
void merge(int a[], int start, int end, int _start, int _end )
{
	//待合并的两部分的长度和
	int len = (_end - _start + 1)  + (end - start + 1);

	//临时数组保存此次合并结果，然后拷贝回原数组
	int *tmp = new int[len];

	int i = start;
	int j = _start;

	int k = 0;

	//选择两部分中较小的那个添加到tmp数组
	while( i <= end && j <= _end )
	{
		a[i] < a[j]?tmp[k++] = a[i++]:tmp[k++] = a[j++];
	}

	//若其中一半没有拷贝完，则将剩下的拷贝完
	while( i <= end )
	{
			tmp[k++] = a[i++];
	}

	while( j <= _end )
	{
			tmp[k++] = a[j++];
	}

	//注意拷贝的目标地址
	memcpy( a + start, tmp, len * sizeof(int));

	delete [] tmp;
}

void merge_sort(int a[], int start, int end)
{
	if(start >= end)
		return;

	int mid = start + (end - start)/2;

	//递归排序左右两部分
	merge_sort(a, start, mid);
	merge_sort(a, mid + 1, end);

	//合并排好的两部分
	merge(a, start, mid, mid+1, end); 
}

//调用接口
void MergeSort(int a[], int len)
{
	merge_sort(a, 0, len-1);
}

//快速排序
//分治思想，无需额外空间，时间复杂度O(nlogn)
void quick_sort(int a[], int start, int end)
{
	//递归返回条件
	if( end <= start )
		return;

	//分组
	int pivot = a[start];

	int i = start, j = end;

	while( i < j )
	{
		//即便是在循环体内部，也要时刻比较i和j的大小
		while( i < j && pivot < a[j] )
			j--;

		//赋值完后i需要加1，不能掉！
		if(i < j)
			a[i++] = a[j];

		while( i < j && a[i] < pivot )
			i++;

		//同理，这里j要减1
		if ( i < j)
			a[j--] = a[i];
	}

	a[i] = pivot;

	//递归快排
	quick_sort(a, start, i-1);
	quick_sort(a, i+1, end);
}

//调用接口
void QuickSort(int a[], int len)
{
	quick_sort(a, 0, len-1);
}

//希尔排序
//时间复杂度为O(nlogn)
void ShellSort(int a[], int len)
{
	//步长从原长度一半开始，每次折半递减，直到步长为1
	for( int step = len / 2; step >= 1; step /= 2)
	{
		for(int i = step; i < len; i++)
		{
			int temp = a[i];
			//从a[i]开始,以step为步长前向取数，然后类似插入排序
			int j = i - step;
			for( ; j >= 0; j -= step)
			{
				if( temp < a[j] )
				{
					a[j + step] = a[j];
				}
				else
					break;
			}
			//注意是j+step
			a[j + step] = temp;
		}
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	int src[10] = {5,4,9,8,7,6,0,1,3,2}; 
	ShellSort(src, 10);
	for(int i = 0; i < 10; ++i)
		printf("%d ",src[i]);
	system("pause");
    return 0;
}

