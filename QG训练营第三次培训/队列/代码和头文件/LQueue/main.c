#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "LQueue.h"

void judge_int(int *z,float *f){//输入数字 1->整形 2->浮点 
	char a[1024],*stop = NULL; 
	int i;
	while(1)
	{
		gets(a);
		fflush(stdin);
		if(a[0]=='\0')//如果数组内没有东西 
		{
			printf("输入错误,重新输入：");
			continue;
		}
		for(i = 0;a[i];i++){
			if(a[0]=='-'&&i==0)//如果第一个是 - 则跳过本次循环 
				continue;
			if(i!=0 && f != NULL && a[i] == '.')	continue;	//如果不是第一位且是输入浮点型且是一个“。”就跳过此次循环 
			if(a[i] < '0' || a[i] > '9')	break;
		}
		if(z != NULL && !a[i] && atoi(a)==strtol(a,&stop,10) && i < 10)
		{
			*z = atoi(a);
			return;
		}
		if(f != NULL && !a[i] && i < 10)
		{
			*f = atof(a);
			return;
		}
		else
			printf("输入错误,重新输入：");
	}
}

char Enter(LQueue *Q)	//入队界面 
{
	char a;
	int i,*tempInt;
	float *tempFloat;
	char enterChar[1024],*enter; 
	printf("请输入要输入的数据类型 1：整形数据  2：浮点型  3：字符型  4：字符串\n");
	judge_int(&i,NULL);
	while(i<1 || i>4)
	{
		printf("输入数字错误，请输入1-4\n");
		judge_int(&i,NULL);
	}
	switch(i)
	{
		case 1:
		{
			printf("请输入要输入的整形数据:");
			tempInt = (int*)malloc(sizeof(int));	//给整形数据分配一个内存 
			judge_int(tempInt,NULL);	//输入整形数据 
			datatype[Q->length] = 'I';
			if(EnLQueue(Q,tempInt))	//入队 
				printf("入队成功\n");
			else
				printf("入队失败\n");
			break; 
		}
		case 2:
		{
			printf("请输入要输入的浮点型数据:");
			tempFloat = (float*)malloc(sizeof(float));	//给浮点型数据分配一个内存 
			judge_int(NULL,tempFloat);	//输入浮点型数据 
			datatype[Q->length] = 'F';
			if(EnLQueue(Q,tempFloat))	//入队 
				printf("入队成功\n");
			else
				printf("入队失败\n");
			break;
		}
		case 3:
		{
			printf("请输入要输入的字符型数据:");
			enter = (char*)malloc(sizeof(char));	//给字符型数据分配一个内存 
			while(1)
			{
				gets(enterChar);	//输入字符型数据 
				if(enterChar[0] == '\0' || enterChar[1] != '\0')
					printf("输入错误重新输入：");
				else break;
			}
			memcpy(enter,&enterChar,sizeof(char));
			datatype[Q->length] = 'C';
			if(EnLQueue(Q,enter))	//入队 
				printf("入队成功\n");
			else
				printf("入队失败\n");
			break;
		}
		case 4:
		{
			printf("请输入要输入的字符串数据:");
			enter = (char*)malloc(1024*sizeof(char));	//给字符串数据分配一个内存 
			gets(enter);	//输入字符串数据 
			datatype[Q->length] = 'S';
			if(EnLQueue(Q,enter))	//入队 
				printf("入队成功\n");
			else
				printf("入队失败\n");
			break;
		}
	}
	system("pause");
}

int main()
{
	system("color F0");
	LQueue *Q = (LQueue*)(malloc(sizeof(LQueue)));
	Q->length = 0;
	void *e = malloc(1024);
	Q->front = NULL;
	Q->rear = NULL;
	int mode;
	while(1)
	{
		system("cls");
		printf("=============================================================\n");
		printf("=                                                           =\n");
		printf("=        1:初始化队列             2:销毁队列                =\n");
		printf("=                                                           =\n");
		printf("=        3:检查队列是否为空       4:查看队头元素            =\n");
		printf("=                                                           =\n");
		printf("=        5:确定队列长度           6:入队操作                =\n");
		printf("=                                                           =\n");
		printf("=        7:出队操作               8:清空队列                =\n");
		printf("=                                                           =\n");
		printf("=        9:遍历队列               0:退出程序                =\n");
		printf("=                                                           =\n");
		printf("=============================================================\n");
		printf("请输入你想要选择的功能:");
		judge_int(&mode,NULL);
		if(mode == 1) InitLQueue(Q);
		else if(mode == 2) DestoryLQueue(Q);
		else if(mode == 3)
		{
			if(Q->front != NULL)
			{
				if(IsEmptyLQueue(Q))
				{
					printf("队列为空\n"); 
					system("pause");
					continue;
				}
				else
				{
					printf("队列不为空\n"); 
					system("pause");
					continue;
				}
			}
			else
			{
				printf("未初始化队列！\n");
				system("pause");
			}
		}
		else if(mode == 4) GetHeadLQueue(Q,e);
		else if(mode == 5)
		{
			if(Q->front != NULL)
			{
				printf("队列长度为：%d\n",LengthLQueue(Q));
				system("pause");
			}
			else
			{
				printf("未初始化队列！\n");
				system("pause");
			}
		}
		else if(mode == 6)
		{
			char a[1024];
			memset(a,'\0',1024);
			if(Q->front != NULL)
			{
				if(Q->length < 29) Enter(Q);
				else
				{
					printf("队列已满！\n");
					system("pause");
				}
			}
			else
			{
				printf("未初始化队列！\n");
				system("pause");
			}
		}
		else if(mode == 7)
		{
			if(DeLQueue(Q))
			{
				printf("出列成功！\n");
				system("pause");
			}
		}
		else if(mode == 8)
		{
			if(Q->front != NULL)
			{
				ClearLQueue(Q);
				printf("清空成功！\n");
				system("pause");
			}
			else
			{
				printf("未初始化队列！\n");
				system("pause");
			}
		}
		else if(mode == 9)
		{
			TraverseLQueue(Q, LPrint);
			system("pause");
		}
		else if(mode == 0)
		{
			printf("欢迎下次使用！\n");
			break;
		}
		else
		{
			printf("输入错误请重新输入！\n");
			system("pause");
		}
	}
	
}
