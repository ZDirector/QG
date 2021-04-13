#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"AQueue.h"
 
void InitAQueue(AQueue *Q)	//初始化队列
{
	
	Q->front = Q->length = 0;		//头、尾、长度都为0 
	Q->rear = -1; 
	printf("初始化成功");
}

void DestoryAQueue(AQueue *Q)	// 销毁队列
{
	if(Q == NULL)
	{
		printf("未初始化队列");
		return;
	} 
	free(Q);
}

Status IsFullAQueue(const AQueue *Q)	// 检查队列是否已满
{
	if( Q->length == MAXQUEUE )
		return TRUE;
	return FALSE;
}

Status IsEmptyAQueue(const AQueue *Q)	//	检查队列是否为空
{
	if( Q->length == 0)
		return TRUE;
	return FALSE;
} 

Status GetHeadAQueue(AQueue *Q, void *e)	//查看队头元素
{
	if(Q == NULL)	//队列是否初始化 
	{
		printf("未初始化");
		return FALSE; 
	}
	if(IsEmptyAQueue(Q))	//队列是否为空 
	{
		printf("队列为空");
		return FALSE;
	}
	memcpy(e,Q->data[Q->front],MAXQUEUE);	//将 Q->data[Q->front](队头)的内存复制一份到e指向的内存 
	return TRUE;
}

int LengthAQueue(AQueue *Q)	//确定队列长度
{
	if(Q == NULL)	//队列是否初始化 
	{
		printf("未初始化");
		return -1; 
	}
	return Q->length;	//返回队列的长度 
}

Status EnAQueue(AQueue *Q, void *data)	//入队操作
{
	if(Q == NULL)	//队列是否初始化 
	{
		printf("未初始化");
		return FALSE; 
	}
	if(IsFullAQueue(Q))
	{
		printf("队列已满");
		return FALSE;
	}
	Q->data[Q->rear] = data;
	Q->length++;
	return TRUE;
}

Status DeAQueue(AQueue *Q)	//出队操作
{
	int i = 0;
	void *data,*temp;
	if(Q == NULL)	//队列是否初始化 
	{
		printf("未初始化");
		return FALSE; 
	}
	if(IsEmptyAQueue(Q))	//队列是否为空 
	{
		printf("队列为空");
		return FALSE;
	}
	data = Q->data[Q->front];	//将第一个出列
	type = datatype[0];
	APrint(data);
	Q->length--;
	for( i =0 ; i< MAXQUEUE; i++)	//将数据向前移一格 
	{
		temp = Q->data[i+1];
		Q->data[i] = temp;
	}
	for(i = 0 ; i < MAXQUEUE ; i++)	//将datatype中的数据类型也向前移动 
		datatype[i] = datatype[i+1];
	Q->rear--;
	return TRUE;
}

void ClearAQueue(AQueue *Q)	//清空队列
{
	int i=0;
	Q->front = Q->length = 0;
	Q->rear = -1;
	while(i<MAXQUEUE)
		Q->data[i++] = NULL;
	memset(datatype,'\0',sizeof(datatype));
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))	//遍历函数操作
{
	int start;
	if(Q == NULL)	//队列是否初始化 
	{
		printf("未初始化");
		return FALSE; 
	}
	if(IsEmptyAQueue(Q))	//队列是否为空 
	{
		printf("队列为空");
		return FALSE;
	}
	for(start = Q->front ; start <= Q->rear ; start++)
	{
		type = datatype[start];
		foo(Q->data[start]);	//逐层打印 
		printf("\n");
	}
	return TRUE; 
}

void APrint(void *q)	//操作函数
{
	if(type == 'I')
		printf("整形数据为：%d\n",*(int*)q);
	else if(type == 'C')
		printf("字符数据为：%c\n",*(char*)q);
	else if(type == 'F')
		printf("浮点型数据为：%.2f\n",*(float*)q);
	else if(type == 'S')
		printf("字符数据为：%s\n",(char*)q);
}

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

char Enter(AQueue *Q)	//入队界面 
{
	char a;
	int i,*tempInt;
	float *tempFloat;
	char enterChar[1024],*enter; 
	printf("请输入要刷入的数据类型 1 -> 整形数据 2 -> 浮点型 3 -> 字符型 4 -> 字符串");
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
			datatype[++Q->rear] = 'I';
			if(EnAQueue(Q,tempInt))	//入队 
				printf("入队成功");
			else
				printf("入队失败");
			break; 
		}
		case 2:
		{
			printf("请输入要输入的浮点型数据:");
			tempFloat = (float*)malloc(sizeof(float));	//给浮点型数据分配一个内存 
			judge_int(NULL,tempFloat);	//输入浮点型数据 
			datatype[++Q->rear] = 'F';
			if(EnAQueue(Q,tempFloat))	//入队 
				printf("入队成功");
			else
				printf("入队失败");
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
					printf("输入错误重新输入");
				else break;
			}
			memcpy(enter,&enterChar,sizeof(char));
			datatype[++Q->rear] = 'C';
			if(EnAQueue(Q,enter))	//入队 
				printf("入队成功");
			else
				printf("入队失败");
			break;
		}
		case 4:
		{
			printf("请输入要输入的字符串数据:");
			enter = (char*)malloc(1024*sizeof(char));	//给字符串数据分配一个内存 
			gets(enter);	//输入字符串数据 
			
			datatype[++Q->rear] = 'S';
			if(EnAQueue(Q,enter))	//入队 
				printf("入队成功");
			else
				printf("入队失败");
			break;
		}
	}
}

void menu()
{
	void *e = malloc(1024);
	int choose;
	AQueue *Q = NULL;
	system("color F0");
	while(1)
	{
		system("cls");
		printf("=============================================================\n");
		printf("=                                                           =\n");
		printf("=        1:初始化队列             2:销毁队列                =\n");
		printf("=                                                           =\n");
		printf("=        3:检查队列是否已满       4:检查队列是否为空        =\n");
		printf("=                                                           =\n");
		printf("=        5:查看队头元素           6:确定队列长度            =\n");
		printf("=                                                           =\n");
		printf("=        7:入队操作               8:出队操作                =\n");
		printf("=                                                           =\n");
		printf("=        9:清空队列               10:遍历队列               =\n");
		printf("=                                                           =\n");
		printf("=        0:退出程序                                         =\n");
		printf("=                                                           =\n");
		printf("=============================================================\n");
		printf("请输入你想要选择的功能:");
		judge_int(&choose,NULL);
		switch(choose)
		{
			case 1://初始化队列
			{
				if(Q != NULL)
					printf("已初始化\n");
				else
				{
					Q = (AQueue*)malloc(sizeof(AQueue));	//分配一个队列的内存
					InitAQueue(Q);
				}
				getch();
				break;
			}
			case 2://判销毁队列
			{
				if(Q == NULL)
					printf("未初始化\n");
				else
				{
					DestoryAQueue(Q);
					printf("摧毁队列成功");
					Q=NULL;
				}
				getch();
				break;
			}
			case 3://检查队列是否已满
			{
				if(Q == NULL)
					printf("未初始化\n");
				else 
				{
					if(IsFullAQueue(Q))
						printf("队列为满"); 
					else printf("队列不为满"); 
				}
				getch();
				break;
			}
			case 4://检查队列是否为空
			{
				if(Q == NULL)
					printf("未初始化\n");
				else 
				{
					if(IsEmptyAQueue(Q))
						printf("队列为空"); 
					else printf("队列不为空"); 
				}
				getch();
				break;
			}
			case 5://查看队头元素
			{
				if(GetHeadAQueue(Q,e))
				{
					type = datatype[0];//队头 
					APrint(e);
				}
				else
					printf("获取头元素失败");
				getch();
				break;
			}
			case 6:	//确定队列长度
			{
				if(LengthAQueue(Q) != -1)
					printf("队列长度为%d",LengthAQueue(Q));
				getch();
				break;
			}
			case 7://入队操作
			{
				if(Q == NULL)
					printf("未初始化\n");
				else
					Enter(Q);
				getch();
				break;
			}
			case 8://出队操作
			{
				if(!DeAQueue(Q))
					printf("出队失败");
				getch();
				break;
			}
			case 9:		// 清空队列 
			{
				if(Q == NULL)
					printf("未初始化队列");
				else
				{
					ClearAQueue(Q);
					printf("清空成功");
				}
				getch();
				break;
			}
			case 10:	//遍历函数操作
			{
				if(TraverseAQueue(Q,&APrint))
					printf("遍历成功");
				else
					printf("遍历失败");
				getch();
				break; 
			} 
			case 0:free(e);return ;
			default :
				{
					printf("输入错误请重新输入！");
					getch();
				}
		}
	}
}

