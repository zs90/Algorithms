#include <stdlib.h>
#include <stdio.h>

inline void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

//ѡ������
//���������Ϊǰ�����飬�ֱ����������δ����
//��δ���򲿷ֵ���Сֵ�ӵ������򲿷ֵ�ĩβ����
//ʱ�临�Ӷ�ΪO(n^2)
void SelectSort(int a[], int len)
{
	for(int i = 0; i < len; ++i)
	{
		int j = i;
		int min = a[j];
		int pos = j;
		for(; j < len; ++j)
		{
			//�ҵ�δ���򲿷���Сֵ
			if( a[j] < min)
			{
				min = a[j];
				pos = j;
			}
		}
		if(i != j)
		{
			//ֱ�ӽ����������ƶ�����
			Swap(a[i], a[pos]);
		}
	}
}

//��������
//���������Ϊǰ�����飬�ֱ����������δ����
//ѡ��δ���򲿷ֵĵ�һ�������������򲿷�
//ʱ�临�Ӷ�ΪO(n^2)
void InsertSort(int a[], int len)
{
	for(int i = 1; i < len; i++)
	{
		int j = i - 1;
		int temp = a[i];

		//�Ӻ���ǰ�ƶ�����Ҫ������ֻ��ֵ��
		for(; j >= 0; j--)
		{
			if(temp < a[j])
				a[j+1] = a[j];
			else
				break;
		}

		//�ճ����Ĳ����д������
		a[j+1] = temp;
	}
}

//ð������
//���������е�ÿ�����������֮ǰ����һ��С���ͽ�����������ð��
//ʱ�临�Ӷ�ΪO(n^2)
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

//�鲢����
//����ķ���˼�룬ʱ�临�Ӷ�ΪO(nlogn)
//Դ����a����Ϊ�����֣���ֹ�ֱ�Ϊ��start,end),(_start,_end)
void merge(int a[], int start, int end, int _start, int _end )
{
	//���ϲ��������ֵĳ��Ⱥ�
	int len = (_end - _start + 1)  + (end - start + 1);

	//��ʱ���鱣��˴κϲ������Ȼ�󿽱���ԭ����
	int *tmp = new int[len];

	int i = start;
	int j = _start;

	int k = 0;

	//ѡ���������н�С���Ǹ���ӵ�tmp����
	while( i <= end && j <= _end )
	{
		a[i] < a[j]?tmp[k++] = a[i++]:tmp[k++] = a[j++];
	}

	//������һ��û�п����꣬��ʣ�µĿ�����
	while( i <= end )
	{
			tmp[k++] = a[i++];
	}

	while( j <= _end )
	{
			tmp[k++] = a[j++];
	}

	//ע�⿽����Ŀ���ַ
	memcpy( a + start, tmp, len * sizeof(int));

	delete [] tmp;
}

void merge_sort(int a[], int start, int end)
{
	if(start >= end)
		return;

	int mid = start + (end - start)/2;

	//�ݹ���������������
	merge_sort(a, start, mid);
	merge_sort(a, mid + 1, end);

	//�ϲ��źõ�������
	merge(a, start, mid, mid+1, end); 
}

//���ýӿ�
void MergeSort(int a[], int len)
{
	merge_sort(a, 0, len-1);
}

//��������
//����˼�룬�������ռ䣬ʱ�临�Ӷ�O(nlogn)
void quick_sort(int a[], int start, int end)
{
	//�ݹ鷵������
	if( end <= start )
		return;

	//����
	int pivot = a[start];

	int i = start, j = end;

	while( i < j )
	{
		//��������ѭ�����ڲ���ҲҪʱ�̱Ƚ�i��j�Ĵ�С
		while( i < j && pivot < a[j] )
			j--;

		//��ֵ���i��Ҫ��1�����ܵ���
		if(i < j)
			a[i++] = a[j];

		while( i < j && a[i] < pivot )
			i++;

		//ͬ������jҪ��1
		if ( i < j)
			a[j--] = a[i];
	}

	a[i] = pivot;

	//�ݹ����
	quick_sort(a, start, i-1);
	quick_sort(a, i+1, end);
}

//���ýӿ�
void QuickSort(int a[], int len)
{
	quick_sort(a, 0, len-1);
}

//ϣ������
//ʱ�临�Ӷ�ΪO(nlogn)
void ShellSort(int a[], int len)
{
	//������ԭ����һ�뿪ʼ��ÿ���۰�ݼ���ֱ������Ϊ1
	for( int step = len / 2; step >= 1; step /= 2)
	{
		for(int i = step; i < len; i++)
		{
			int temp = a[i];
			//��a[i]��ʼ,��stepΪ����ǰ��ȡ����Ȼ�����Ʋ�������
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
			//ע����j+step
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

