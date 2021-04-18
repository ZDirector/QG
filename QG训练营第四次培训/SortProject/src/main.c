#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include"qgsort.h"

int main()
{
	menu();
}

void menu()
{
	int choose,Static = 0,len,temp;
	int *data,*t;
	system("color F0");
	while(1)
	{
		system("cls");
		printf("===========================================================================\n");
		printf("=                                                                         =\n");
		printf("=        1:产生随机数             2:插入排序算法                          =\n");
		printf("=                                                                         =\n");		
		printf("=        3:归并排序               4:快速排序（递归版）                    =\n");
		printf("=                                                                         =\n");		
		printf("=        5:快速排序（非递归版）   6:计数排序                              =\n");
		printf("=                                                                         =\n");
		printf("=        7:基数计数排序           8:颜色排序                              =\n");
		printf("=                                                                         =\n");
		printf("=        9:在一个无序序列中找到第K大的数                                  =\n");
		printf("=                                                                         =\n");
		printf("=        10:在不同大数据下的用时                                          =\n");
		printf("=                                                                         =\n");
		printf("=        11: 上述排序函数在大量小数组下的排序用时(100数据*10k次排序)      =\n");
		printf("=                                                                         =\n");
		printf("=        0:退出                                                           =\n");
		printf("=                                                                         =\n");
		printf("===========================================================================\n");
		printf("请输入你想要选择的功能:");
		judge_int(&choose,NULL);
		switch(choose)
		{
			case 1:{
				Static = 1;
				printf("请输入产生随机数的个数");
				judge_int(&len,NULL); 
				Random(len,1);
				data = (int*) malloc (len*sizeof(int));
				Readdata(data,len);
				printf("SUCCESS\n");
				printf("数组为:");
				Print(data,len);
				getch();
				break;
			}
			case 2:{
				if(Static == 0)
					printf("未初始化产生随机数");
				else
				{
					printf("原数组为:");
					Print(data,len);
					insertSort(data,len);		//插入排序 
					printf("\n排序后数组为:");
					Print(data,len);
				}
				getch();
				break;
			}
			case 3:{
				if(Static == 0)
					printf("未初始化产生随机数");
				else
				{
					printf("原数组为:");
					Print(data,len);
					t = (int*)malloc(len*sizeof(int));
					MergeSort(data,0,len-1,t);	//归并排序 
					free(t);
					t= NULL;
					printf("\n排序后数组为:");
					Print(data,len);
				}
				getch();
				break;
			}
			case 4:{
				if(Static == 0)
					printf("未初始化产生随机数");
				else
				{
					printf("原数组为:");
					Print(data,len);
					QuickSort_Recursion(data,0,len-1);	//快排递归 
					printf("\n排序后数组为:");
					Print(data,len);
				}
				getch();
				break;
			}
			case 5:{
				if(Static == 0)
					printf("未初始化产生随机数");
				else
				{
					printf("原数组为:");
					Print(data,len);
					QuickSort(data,len);		//快排非递归 
					printf("\n排序后数组为:");
					Print(data,len);
				}
				getch();
				break;
			}
			case 6:{
				if(Static == 0)
						printf("未初始化产生随机数");
				else
				{
					printf("原数组为:");
					Print(data,len);
					temp = data[0];
					for(choose = 0;choose<len;choose++)
						if(data[choose]>temp)
							temp = data[choose];
					CountSort(data,len,temp++);	//计数排序 
					printf("\n排序后数组为:");
					Print(data,len);
				}
				getch();
				break;
			}
			case 7:{
				if(Static == 0)
						printf("未初始化产生随机数");
				else
				{
					printf("原数组为:");
					Print(data,len);
					RadixCountSort(data,len);	//基数排序 
					printf("\n排序后数组为:");
					Print(data,len);
				}
				getch();
				break;
			}
			case 8:{
				if(Static == 0)
						printf("未初始化产生随机数");
				else
				{
					Random(len,2);
					Readdata(data,len);
					printf("原数组为:");
					Print(data,len);
					ColorSort(data,len);	// 颜色 
					printf("\n排序后数组为:");
					Print(data,len);
				}
				getch();
				break;
			}
			case 9:{
				if(Static == 0)
						printf("未初始化产生随机数");
				else
				{
					printf("原数组为:");
					Print(data,len);
					printf("\n请输入你想要找大还是小的数（1->大,2->小）:");
					t = (int*)malloc(sizeof(int));
					judge_int(t,NULL);
					printf("请输入你想要查找第几个（大/小）数:");
					judge_int(&choose,NULL);
					if(*t == 2)
						choose = len - choose+1;
					printf("此数为：%d",foundNumber(data,len,choose));
				} 
				free(t);
				t=NULL;
				getch();
				break;
			}
			case 10:{
				calculation(10000,2);	
				calculation(20000,2);
				calculation(30000,2);
				
				getch();
				break; 
			}
			case 11:{
				calculation(100,1);
				break;
			}
			case 0:{
				printf("欢迎下次使用！\n");
				getch();
				return; 
			}
			default:printf("输入错误哈"); getch();
		}
	}
}

void calculation(int len,int mode)
{
	int *data,*temp,i=0,p,q,sum,k;
	time_t start,end;
	if(mode == 1)
		printf("在%d个大大数据量100k次下的用时;\n",len);
	else 
		printf("在%d个大大数据量下的用时;\n",len);
	while(i<7)	//七次 
	{
		data = (int*)malloc(len*sizeof(int));
		Random(len,1);//产生随机数 
		Readdata(data,len);//读取
		if(i==0)
		{
			if(mode == 1)
			{
				for(k=0,sum=0;k<10000;k++)
				{
					Random(len,1);//产生随机数 
					Readdata(data,len);//读取
					start = clock();
					insertSort(data,len);		//插入排序 
					end = clock();
					sum += end-start;
				}
				printf("插入排序用时：%dms\n",sum);
			}
			else
			{
				start = clock();
				insertSort(data,len);		//插入排序 
				end = clock();
				printf("插入排序用时：%dms\n",end-start);
			}
		} 
		else if(i==1)
		{
			temp = (int*)malloc(len*sizeof(int));
			if(mode == 1)
			{
				for(k=0,sum=0;k<10000;k++)
				{
					Random(len,1);//产生随机数 
					Readdata(data,len);//读取
					start = clock();
					MergeSort(data,0,len-1,temp);	//归并排序 
					end = clock();
					sum += end-start;
				}
				printf("归并排序用时：%dms\n",sum);
			}
			else
			{
				start = clock();
				MergeSort(data,0,len-1,temp);	//归并排序 
				end = clock();
				printf("归并排序用时：%dms\n",end-start);
			}
			free(temp);
		}
		else if(i==2)
		{
			if(mode == 1)
			{
				for(k=0,sum=0;k<10000;k++)
				{
					Random(len,1);//产生随机数 
					Readdata(data,len);//读取
					start = clock();
					QuickSort_Recursion(data,0,len-1);	//快排递归 
					end = clock();
					sum += end-start;
				}
				printf("快排（递归）排序用时：%dms\n",sum);
			}
			else
			{
				start = clock();
				QuickSort_Recursion(data,0,len-1);	//快排递归 
				end = clock();
				printf("快排（递归）排序用时：%dms\n",end-start);
			}
		}
		else if(i==3)
		{
			if(mode == 1)
			{
				for(k=0,sum=0;k<10000;k++)
				{
					Random(len,1);//产生随机数 
					Readdata(data,len);//读取
					start = clock();
					QuickSort(data,len);		//快排非递归 
					end = clock();
					sum += end-start;
				}
				printf("快排（非递归）排序用时：%dms\n",sum);
			}
			else
			{
				start = clock();
				QuickSort(data,len);		//快排非递归 
				end = clock();
				printf("快排（非递归）排序用时：%dms\n",end-start);
			}
		}
		else if(i==4)
		{
			if(mode == 1)
			{
				for(k=0,sum=0;k<10000;k++)
				{
					Random(len,1);//产生随机数 
					Readdata(data,len);//读取
					p = data[0];
					for(q = 0;q<len;q++)
						if(data[q]>p)
							p = data[q];
					start = clock();
					CountSort(data,len,p+10);	//计数排序 
					end = clock();
					sum += end-start;
				}
				printf("计数排序用时：%dms\n",sum);
			}
			else
			{
				p = data[0];
				for(q = 0;q<len;q++)
					if(data[q]>p)
						p = data[q];
				start = clock();
				CountSort(data,len,p++);	//计数排序 
				end = clock();
				printf("计数排序 用时：%dms\n",end-start);
			}
		}
		else if(i==5)
		{
			if(mode == 1)
			{
				for(k=0,sum=0;k<10000;k++)
				{
					Random(len,1);//产生随机数 
					Readdata(data,len);//读取
					start = clock();
					RadixCountSort(data,len);	//基数排序 
					end = clock();
					sum += end-start;
				}
				printf("基数排序用时：%dms\n",sum);
			}
			else
			{
				start = clock();
				RadixCountSort(data,len);	//基数排序 
				end = clock();
				printf("基数排序用时：%dms\n",end-start);
			}
		}
		else if(i==6)
		{
			if(mode == 1)
			{
				for(k=0,sum=0;k<10000;k++)
				{
					Random(len,2);//产生随机数 
					Readdata(data,len);//读取
					start = clock();
					ColorSort(data,len);	// 颜色
					end = clock();
					sum += end-start;
				}
				printf("颜色排序用时：%dms\n\n",sum);
			}
			else
			{
				Random(len,2);
				Readdata(data,len);
				start = clock();
				RadixCountSort(data,len);	//基数排序 
				end = clock();
				printf("颜色排序用时：%dms\n\n",end-start);
			}
		}
		i++; 
	}
	system("pause");
}


