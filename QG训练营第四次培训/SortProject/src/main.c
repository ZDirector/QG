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
		printf("=        1:���������             2:���������㷨                          =\n");
		printf("=                                                                         =\n");		
		printf("=        3:�鲢����               4:�������򣨵ݹ�棩                    =\n");
		printf("=                                                                         =\n");		
		printf("=        5:�������򣨷ǵݹ�棩   6:��������                              =\n");
		printf("=                                                                         =\n");
		printf("=        7:������������           8:��ɫ����                              =\n");
		printf("=                                                                         =\n");
		printf("=        9:��һ�������������ҵ���K�����                                  =\n");
		printf("=                                                                         =\n");
		printf("=        10:�ڲ�ͬ�������µ���ʱ                                          =\n");
		printf("=                                                                         =\n");
		printf("=        11: �����������ڴ���С�����µ�������ʱ(100����*10k������)      =\n");
		printf("=                                                                         =\n");
		printf("=        0:�˳�                                                           =\n");
		printf("=                                                                         =\n");
		printf("===========================================================================\n");
		printf("����������Ҫѡ��Ĺ���:");
		judge_int(&choose,NULL);
		switch(choose)
		{
			case 1:{
				Static = 1;
				printf("���������������ĸ���");
				judge_int(&len,NULL); 
				Random(len,1);
				data = (int*) malloc (len*sizeof(int));
				Readdata(data,len);
				printf("SUCCESS\n");
				printf("����Ϊ:");
				Print(data,len);
				getch();
				break;
			}
			case 2:{
				if(Static == 0)
					printf("δ��ʼ�����������");
				else
				{
					printf("ԭ����Ϊ:");
					Print(data,len);
					insertSort(data,len);		//�������� 
					printf("\n���������Ϊ:");
					Print(data,len);
				}
				getch();
				break;
			}
			case 3:{
				if(Static == 0)
					printf("δ��ʼ�����������");
				else
				{
					printf("ԭ����Ϊ:");
					Print(data,len);
					t = (int*)malloc(len*sizeof(int));
					MergeSort(data,0,len-1,t);	//�鲢���� 
					free(t);
					t= NULL;
					printf("\n���������Ϊ:");
					Print(data,len);
				}
				getch();
				break;
			}
			case 4:{
				if(Static == 0)
					printf("δ��ʼ�����������");
				else
				{
					printf("ԭ����Ϊ:");
					Print(data,len);
					QuickSort_Recursion(data,0,len-1);	//���ŵݹ� 
					printf("\n���������Ϊ:");
					Print(data,len);
				}
				getch();
				break;
			}
			case 5:{
				if(Static == 0)
					printf("δ��ʼ�����������");
				else
				{
					printf("ԭ����Ϊ:");
					Print(data,len);
					QuickSort(data,len);		//���ŷǵݹ� 
					printf("\n���������Ϊ:");
					Print(data,len);
				}
				getch();
				break;
			}
			case 6:{
				if(Static == 0)
						printf("δ��ʼ�����������");
				else
				{
					printf("ԭ����Ϊ:");
					Print(data,len);
					temp = data[0];
					for(choose = 0;choose<len;choose++)
						if(data[choose]>temp)
							temp = data[choose];
					CountSort(data,len,temp++);	//�������� 
					printf("\n���������Ϊ:");
					Print(data,len);
				}
				getch();
				break;
			}
			case 7:{
				if(Static == 0)
						printf("δ��ʼ�����������");
				else
				{
					printf("ԭ����Ϊ:");
					Print(data,len);
					RadixCountSort(data,len);	//�������� 
					printf("\n���������Ϊ:");
					Print(data,len);
				}
				getch();
				break;
			}
			case 8:{
				if(Static == 0)
						printf("δ��ʼ�����������");
				else
				{
					Random(len,2);
					Readdata(data,len);
					printf("ԭ����Ϊ:");
					Print(data,len);
					ColorSort(data,len);	// ��ɫ 
					printf("\n���������Ϊ:");
					Print(data,len);
				}
				getch();
				break;
			}
			case 9:{
				if(Static == 0)
						printf("δ��ʼ�����������");
				else
				{
					printf("ԭ����Ϊ:");
					Print(data,len);
					printf("\n����������Ҫ�Ҵ���С������1->��,2->С��:");
					t = (int*)malloc(sizeof(int));
					judge_int(t,NULL);
					printf("����������Ҫ���ҵڼ�������/С����:");
					judge_int(&choose,NULL);
					if(*t == 2)
						choose = len - choose+1;
					printf("����Ϊ��%d",foundNumber(data,len,choose));
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
				printf("��ӭ�´�ʹ�ã�\n");
				getch();
				return; 
			}
			default:printf("��������"); getch();
		}
	}
}

void calculation(int len,int mode)
{
	int *data,*temp,i=0,p,q,sum,k;
	time_t start,end;
	if(mode == 1)
		printf("��%d�����������100k���µ���ʱ;\n",len);
	else 
		printf("��%d������������µ���ʱ;\n",len);
	while(i<7)	//�ߴ� 
	{
		data = (int*)malloc(len*sizeof(int));
		Random(len,1);//��������� 
		Readdata(data,len);//��ȡ
		if(i==0)
		{
			if(mode == 1)
			{
				for(k=0,sum=0;k<10000;k++)
				{
					Random(len,1);//��������� 
					Readdata(data,len);//��ȡ
					start = clock();
					insertSort(data,len);		//�������� 
					end = clock();
					sum += end-start;
				}
				printf("����������ʱ��%dms\n",sum);
			}
			else
			{
				start = clock();
				insertSort(data,len);		//�������� 
				end = clock();
				printf("����������ʱ��%dms\n",end-start);
			}
		} 
		else if(i==1)
		{
			temp = (int*)malloc(len*sizeof(int));
			if(mode == 1)
			{
				for(k=0,sum=0;k<10000;k++)
				{
					Random(len,1);//��������� 
					Readdata(data,len);//��ȡ
					start = clock();
					MergeSort(data,0,len-1,temp);	//�鲢���� 
					end = clock();
					sum += end-start;
				}
				printf("�鲢������ʱ��%dms\n",sum);
			}
			else
			{
				start = clock();
				MergeSort(data,0,len-1,temp);	//�鲢���� 
				end = clock();
				printf("�鲢������ʱ��%dms\n",end-start);
			}
			free(temp);
		}
		else if(i==2)
		{
			if(mode == 1)
			{
				for(k=0,sum=0;k<10000;k++)
				{
					Random(len,1);//��������� 
					Readdata(data,len);//��ȡ
					start = clock();
					QuickSort_Recursion(data,0,len-1);	//���ŵݹ� 
					end = clock();
					sum += end-start;
				}
				printf("���ţ��ݹ飩������ʱ��%dms\n",sum);
			}
			else
			{
				start = clock();
				QuickSort_Recursion(data,0,len-1);	//���ŵݹ� 
				end = clock();
				printf("���ţ��ݹ飩������ʱ��%dms\n",end-start);
			}
		}
		else if(i==3)
		{
			if(mode == 1)
			{
				for(k=0,sum=0;k<10000;k++)
				{
					Random(len,1);//��������� 
					Readdata(data,len);//��ȡ
					start = clock();
					QuickSort(data,len);		//���ŷǵݹ� 
					end = clock();
					sum += end-start;
				}
				printf("���ţ��ǵݹ飩������ʱ��%dms\n",sum);
			}
			else
			{
				start = clock();
				QuickSort(data,len);		//���ŷǵݹ� 
				end = clock();
				printf("���ţ��ǵݹ飩������ʱ��%dms\n",end-start);
			}
		}
		else if(i==4)
		{
			if(mode == 1)
			{
				for(k=0,sum=0;k<10000;k++)
				{
					Random(len,1);//��������� 
					Readdata(data,len);//��ȡ
					p = data[0];
					for(q = 0;q<len;q++)
						if(data[q]>p)
							p = data[q];
					start = clock();
					CountSort(data,len,p+10);	//�������� 
					end = clock();
					sum += end-start;
				}
				printf("����������ʱ��%dms\n",sum);
			}
			else
			{
				p = data[0];
				for(q = 0;q<len;q++)
					if(data[q]>p)
						p = data[q];
				start = clock();
				CountSort(data,len,p++);	//�������� 
				end = clock();
				printf("�������� ��ʱ��%dms\n",end-start);
			}
		}
		else if(i==5)
		{
			if(mode == 1)
			{
				for(k=0,sum=0;k<10000;k++)
				{
					Random(len,1);//��������� 
					Readdata(data,len);//��ȡ
					start = clock();
					RadixCountSort(data,len);	//�������� 
					end = clock();
					sum += end-start;
				}
				printf("����������ʱ��%dms\n",sum);
			}
			else
			{
				start = clock();
				RadixCountSort(data,len);	//�������� 
				end = clock();
				printf("����������ʱ��%dms\n",end-start);
			}
		}
		else if(i==6)
		{
			if(mode == 1)
			{
				for(k=0,sum=0;k<10000;k++)
				{
					Random(len,2);//��������� 
					Readdata(data,len);//��ȡ
					start = clock();
					ColorSort(data,len);	// ��ɫ
					end = clock();
					sum += end-start;
				}
				printf("��ɫ������ʱ��%dms\n\n",sum);
			}
			else
			{
				Random(len,2);
				Readdata(data,len);
				start = clock();
				RadixCountSort(data,len);	//�������� 
				end = clock();
				printf("��ɫ������ʱ��%dms\n\n",end-start);
			}
		}
		i++; 
	}
	system("pause");
}


