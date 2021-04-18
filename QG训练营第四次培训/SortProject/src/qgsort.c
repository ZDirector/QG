#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"qgsort.h"

void insertSort(int *a,int n)		//插入排序 
{
	int i,j,temp;
	for(i=1;i<n;++i)
	{
		j=i-1;
		temp=a[i];
		while(j>=0&&temp<a[j])
		{
			a[j+1]=a[j];
			--j;
		}
		a[j+1]=temp;
	}
}

void MergeSort(int *a,int begin,int end,int *temp)	//归并排序 
{
	if(begin < end)
    {
        int mid = (begin + end) / 2;
        MergeSort(a, begin, mid, temp);
        MergeSort(a, mid + 1, end, temp);
        MergeArray(a, begin, mid, end, temp);
    }
}

void MergeArray(int *a,int begin,int mid,int end,int *temp)	//数组的合并 
{
	int i = begin, j = mid + 1;
	int m =mid,n =end;
	int k = 0;
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j]) temp[k++] = a[i++];
		else temp[k++] = a[j++];
	}
	while (i <= m) temp[k++] = a[i++];
	while (j <= n) temp[k++] = a[j++];
	for (i = 0; i < k; i++) a[begin + i] = temp[i];
}

void QuickSort_Recursion(int *a, int begin, int end)	//快速排序（递归版）
{
    if(begin > end) return;
    int temp = a[begin];
    int i = begin;
    int j = end;
    while(i != j)
	{
        while(a[j] >= temp && j > i) j--;	//j向中间走 ，找到.. 
        while(a[i] <= temp && j > i) i++;	//i向中间走 
        if(j > i)
		{
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[begin] = a[i];
    a[i] = temp;
    QuickSort_Recursion(a, begin, i-1);	//左半边排序 
    QuickSort_Recursion(a, i+1, end);	//右半边排序 
}

void QuickSort(int *a,int size)			//*******************************************************************
{
	int *stack = (int*)malloc((size+1) * sizeof(int));		//分配栈 
    int top = -1;		//栈无元素 
    int left = 0,right = size-1;	
    if (left < right)
	{
        stack[++top] = right;
        stack[++top] = left;
        while (top > -1)
		{
            int l = stack[top--];
            int r = stack[top--];
            int mid = Partition(a, l, r);
            if (l < (mid-1) )
			{
                stack[++top] = mid-1;
                stack[++top] = l;
            }
            if ( (mid+1) < r)
			{
                stack[++top] = r;
                stack[++top] = mid+1;
            }
        }
    }
    free(stack);
}

int Partition(int *a, int begin, int end)
{
	int temp = a[begin];
    while (begin < end)
    {
        while (begin < end && a[end] >= temp) end--;
        a[begin] = a[end];
        while (begin < end && a[begin] <= temp) begin++;
        a[end] = a[begin];
    }
    a[begin] = temp;
    return begin;
}

void CountSort(int *a, int size , int max)	//计数排序
{	
	int *c, *b;
	int i;
	c = (int *)malloc(sizeof(int)*max);/*临时数组,注意它的大小是待排序序列中值最大的那个。如假定该排序序列中最大值为1000000，则该数组需要1000000*sizeof(int)个存储单元*/
	b = (int *)malloc(sizeof(int)*size); /*存放排序结果的数组*/
	for (i = 0; i < max; i++)
		c[i] = 0;		 /*初始化*/
	for (i = 0; i < size; i++)
		c[a[i]] += 1;		 /*统计数组A中每个值为i的元素出现的次数*/
	for (i = 1; i < max; i++)
		c[i] = c[i - 1] + c[i];		/*确定值为i的元素在数组c中出现的位置*/
	for (i = size - 1; i >= 0; i--)
	{
		b[c[a[i]] - 1] = a[i]; 		/*对A数组，从后向前确定每个元素所在的最终位置;*/
		c[a[i]] -= 1;
	}
	for (i = 0; i < size; i++)
		a[i] = b[i]; 		/*这个目的是返回A数组作为有序序列*/
	free(c);
	free(b);
}

void RadixCountSort(int *a,int size)
{ 
	int *radixarray[10];
	int i,j,pos;
	int num,index;
	
	for(i = 0 ; i < 10 ; i++) 		//十个位分别记录基数0-9 
	{
		radixarray[i] = (int*)malloc((size+1)*sizeof(int));		//建立size+1大小的数组 第一位用来记录个数
		radixarray[i][0] = 0; 
	}
	
	for(pos =1; pos < 11 ; pos++)		//t代表第几位
	{
		for(i=0 ; i<size ; i++)		//遍历原数组 
		{
			num = a[i]/(int)pow(10,pos-1) % 10;	//得到第pos位数 
			index = ++radixarray[num][0];	//记录pos这一位有多少个数了 
			radixarray[num][index] = a[i];		//丢进相应的数组 
		}
		for(i=0,j=0 ; i < 10 ; i++)
		{
			for(index = 1 ; index <= radixarray[i][0] ; index++)
				a[j++] = radixarray[i][index];	//收集回去 
			radixarray[i][0]=0;		//复位 
		}
	}
}

void ColorSort(int *a,int size)
{
	int i = 0, j = 0, k = size - 1, left = 0, right = size - 1, index = 0,temp;
	while(a[left] == 0) left++;
	while(a[right] == 2) right--;
    while(left < right) 
	{
        for(i = left; i <= right; i++) 
		{
            if(a[i] == 2) {
                temp = a[i];
			    a[i] = a[k];
			    a[k] = temp;
                k--;
                break;
            }
            else if(a	[i] == 0 && i > j) 
			{
                temp = a[i];
			    a[i] = a[j];
			    a[j] = temp;
                j++;
                break;
            } 
        }
        left = i;
        for(i = right; i >= left; i--) 
		{
            if(a[i] == 0) {
                temp = a[i];
			    a[i] = a[j];
			    a[j] = temp;
                j++;
                break;
            }
            else if(a[i] == 2 && i < k) 
			{
                temp = a[i];
			    a[i] = a[k];
			    a[k] = temp;
                k--;
                break;
            } 
        }
        right = i; 
    }
}

int foundNumber(int *a,int size,int k)		//第k个... 
{
	int temp;
	if (a == NULL || size <= 0 || k <= 0 || size < k) return 0;		//出错处理 
	int i = 0, j = size - 1;		//一左一右 
	while (i < j) 
	{
		while (i < j && a[i] >= a[j]) j--;
		if (i < j) 
		{
			temp = a[i];
		    a[i] = a[j];
		    a[j] = temp;
			i++;
		}
		while (i < j && a[i] >= a[j]) i++;
		if (i < j) 
		{
			temp = a[i];
		    a[i] = a[j];
		    a[j] = temp;
			j--;
		}
	}
	if (i == k - 1) 
		return a[i];
 	else if (i > k - 1)
	 	return foundNumber(a, i, k);
	else
	   return foundNumber(a + i + 1, size - i - 1, k - i - 1);
}
