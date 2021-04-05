#include<stdio.h>
#include<stdlib.h>
#include"SqStack.h"

Status initStack(SqStack *s,int sizes)//初始化栈
{ 
	s->elem = (ElemType*) malloc (sizes * sizeof(ElemType));//申请内存 
	s->top = -1;//栈底为-1 
	s->size = sizes;//栈的长度为.. 
}

Status isEmptyStack(SqStack *s)//判断栈是否为空
{
	if( s->top == -1 )	//如果栈中无数据，则top不变，为-1 
		return SUCCESS;
	return ERROR;
}

Status getTopStack(SqStack *s,ElemType *e) //得到栈顶元素
{
	if(isEmptyStack(s))	//如果栈不为空，则得到栈顶元素 
		return ERROR;
	*e = s->elem[s->top];//让栈顶元素传出 
	return SUCCESS;
}

Status clearStack(SqStack *s)//清空栈
{
	free(s->elem);//将栈清空 
	if(s->elem == NULL)	return ERROR;//如果栈 
	s->elem = (ElemType*) malloc (s->size * sizeof(ElemType));	//重新申请内存 
	s->top = -1;
	return SUCCESS;
}

Status destroyStack(SqStack *s)//销毁栈
{
	free(s);
	return SUCCESS;
}

Status stackLength(SqStack *s,int *length)//检测栈长度
{
	*length = s->top+1;
	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data)//入栈
{
	if(s->top == s->size-1)
	{
		printf("栈已满，入栈失败\n");
		return ERROR;
	}
	s->top++;
	s->elem[s->top] = data;
	return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data)//出栈
{
	if(s->top == -1)
	{
		printf("栈为空，无数据");
		return ERROR;
	}
	*data = s->elem[s->top--];
	return SUCCESS;
}

int judge_int()//输入
{ 
	char a[1024];
	int sum,i;
	while(1)
	{
		sum=0;
		gets(a);
		fflush(stdin);
		if(a[0]=='\0')
		{
			printf("输入错误,重新输入：");
			continue;
		}
		for(i = 0;a[i];i++)
		{
			if(a[i] < '0' || a[i] > '9')	break;
			else
			{
				sum+=(a[i]-'0');
				sum*=10;
			}
		}
		if(!a[i])
			break;
		else
			printf("输入错误,重新输入：");
	}
	return sum/10;
}


int main()
{
	SqStack *stack = NULL;
	ElemType e ;
	int temp;
	system("color F0");
	while(1)
	{
		system("cls");
		printf("=============================================================\n");
		printf("=                                                           =\n");
		printf("=        1:初始化栈             2:判断栈是否为空            =\n");
		printf("=                                                           =\n");
		printf("=        3:得到栈顶元素         4:清空栈                    =\n");
		printf("=                                                           =\n");
		printf("=        5:销毁栈               6:检测栈长度                =\n");
		printf("=                                                           =\n");
		printf("=        7:入栈                 8:出栈                      =\n");
		printf("=                                                           =\n");
		printf("=        0:退出程序                                         =\n");
		printf("=                                                           =\n");
		printf("=============================================================\n");
		printf("请输入你想要选择的功能:");
		temp = judge_int();
		if(temp<0||temp>8)
		{
			printf("输入错误，需输入1-9");
			getch(); 
			continue;
		}
		switch(temp)
		{
			case 1:
			{
				if(stack == NULL)
				{
					stack = (SqStack*)malloc(sizeof(SqStack)); 
				}
				else
				{
					printf("已初始化过栈，需销毁栈再初始化栈");
					getch();
					break;
				}
				printf("请输入顺序栈的长度：");
				temp = judge_int();
				if(initStack(stack,temp))//判断初始话有无成功 
					printf("SUCCESS");
				else
					printf("ERROR");
				getch();
				break;
			}
			case 2:
			{
				if(stack == NULL)
					printf("未初始化栈");
				else
				{
					if(isEmptyStack(stack))
						printf("是一个空的栈");
					else
						printf("不是一个空栈");
				}
				getch();
				break;
			}
			case 3:
			{
				if(stack == NULL)
					printf("未初始化栈");
				else
				{
					if(getTopStack(stack,&e))
						printf("栈顶元素为:%d",e);
					else
						printf("栈为空,获取栈顶元素失败");
				}
				getch();
				break;
			}
			case 4:
			{
				if(stack == NULL)
					printf("未初始化栈");
				else
				{
					if(clearStack(stack))
						printf("清空栈成功");
					else
						printf("清空栈失败");
				}
				getch();
				break;
			}
			case 5:
			{
				if(stack == NULL)
					printf("未初始化栈");
				else
				{
					if(destroyStack(stack))
					{
						printf("销毁栈成功");
						stack = NULL;
					}
					else
						printf("销毁栈失败");
				}
				getch();
				break;
			}
			case 6:
			{
				if(stack == NULL)
					printf("未初始化栈");
				else
				{
					if(stackLength(stack,&temp))
						printf("栈的长度为%d",temp);
					else
						printf("检测栈的长度失败");
				}
				getch();
				break;
			}
			case 7:
			{
				if(stack == NULL)
					printf("未初始化栈");
				else
				{
					printf("请输入要放入栈中的数据:");
					temp = judge_int();
					if(pushStack(stack,temp))
						printf("入栈成功");
					else
						printf("入栈失败");
				}
				getch();
				break;
			}
			case 8:
			{
				if(stack == NULL)
					printf("未初始化栈");
				else
				{
					if(popStack(stack,&e))
						printf("出栈成功，数据为%d",e);
					else
						printf("出栈失败");
				}
				getch();
				break;
			}
			case 0:
			{
				return 0;
				break;
			}
		}
	}
	
}
