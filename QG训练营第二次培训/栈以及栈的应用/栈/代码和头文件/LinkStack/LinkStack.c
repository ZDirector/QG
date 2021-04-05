#include<stdio.h>
#include<stdlib.h>
#include "LinkStack.h"


int judge_int()//输入
{ 
	char a[1024];
	int sum,i;
	while(1)
	{
		sum=0;
		gets(a);
		if(a[0] == '\0')
		{
			printf("输入错误,重新输入:");
			continue;
		}
		for(i = 0;a[i];i++)
		{
			if(a[i] < '0' || a[i] > '9') break;
			else
			{
				sum+=(a[i]-'0');
				sum*=10;
			}
	  	}
	  	if(!a[i]) break;
	  	else
	  	{
	  		printf("输入错误,重新输入:");
		}
	}
	return sum/10;
}


int main()
{
	system("color F0");
	LinkStack *s = (LinkStack*)(malloc(sizeof(LinkStack)));
	s->top = NULL;
	int mode;
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
		mode = judge_int();
		if(mode == 1)
		{
			if(s->top != NULL)
			{
				printf("已经初始化栈！\n");
				system("pause");
				continue;
			}
			if(initLStack(s))
			{
				printf("初始化成功！\n");
				system("pause");
				continue;
			}
			else
			{
				printf("初始化失败！\n");
				system("pause");
				continue;
			}
		}
		else if(mode == 2)
		{
			if(s->top == NULL)
			{
				printf("未初始化栈！\n");
				system("pause");
				continue;
			}
			if(isEmptyLStack(s))
			{
				printf("栈为空\n"); 
				system("pause");
				continue;
			}
			else
			{
				printf("栈不为空\n"); 
				system("pause");
				continue;
			}
		}
		else if(mode == 3)
		{
			ElemType e;
			if(s->top == NULL)
			{
				printf("未初始化栈！\n");
				system("pause");
				continue;
			}
			if(getTopLStack(s,&e) && !isEmptyLStack(s))
			{
				printf("栈顶元素为：%d\n",e);
				system("pause");
				continue;
			}
			else
			{
				printf("无栈顶元素，该栈为空\n");
				system("pause");
				continue;
			}
			
		}
		else if(mode == 4)
		{
			if(s->top == NULL)
			{
				printf("未初始化栈！\n");
				system("pause");
				continue;
			}
			if(!isEmptyLStack(s))
			{
				clearLStack(s);
				printf("清空成功！\n");
				system("pause");
				continue;
			}
			else
			{
				printf("该栈已为空\n");
				system("pause");
				continue;
			}
		}
		else if(mode == 5)
		{
			if(s->top == NULL)
			{
				printf("未初始化栈！\n");
				system("pause");
				continue;
			}
			destroyLStack(s);
			printf("销毁成功！\n");
			system("pause");
			continue;
		}
		else if(mode == 6)
		{
			int length;
			if(s->top == NULL)
			{
				printf("未初始化栈！\n");
				system("pause");
				continue;
			}
			LStackLength(s,&length);
			printf("栈的长度为：%d\n",length);
			system("pause");
			continue;
		}
		else if(mode == 7)
		{
			int data;
			if(s->top == NULL)
			{
				printf("未初始化栈！\n");
				system("pause");
				continue;
			}
			else
			{
				printf("请输入数据："); 
				data = judge_int();
				pushLStack(s,data);
			}
		}
		else if(mode == 8)
		{
			int data;
			if(s->top == NULL)
			{
				printf("未初始化栈！\n");
				system("pause");
				continue;
			}
			else
			{
				if(s->count == -1)
				{
					printf("该栈为空\n");
					system("pause");
					continue;
				}
				else
				{
					popLStack(s,&data);
					printf("销毁的数据为：%d\n",data);
					system("pause");
					continue;
				} 
			}
		}
		else if(mode == 0)
		{
			printf("欢迎下次使用！\n");
			system("pause");
			break;
		}
		else
		{
			printf("输入错误,重新输入!\n");
			continue;
		}
	}
	
}


Status initLStack(LinkStack *s)//初始化栈
{
	LinkStackPtr node;
	node = (StackNode*)(malloc(sizeof(StackNode)));
	node->next = NULL;
	node->data = 0;
	s->top = node;
	s->count = -1;
}


Status isEmptyLStack(LinkStack *s)//判断栈是否为空
{
	if(s->count == -1)
	{
		return SUCCESS;
	}
	else return ERROR;
}


Status getTopLStack(LinkStack *s,ElemType *e)//得到栈顶元素
{
	*e = s->top->data; 
	return SUCCESS;
}


Status clearLStack(LinkStack *s)//清空栈
{
	LinkStackPtr temp;
	while(s->count != 0)
	{
		temp = s->top;
		s->top = s->top->next;
		free(temp);
		s->count--;
	}
	s->top->data = 0;
	s->count = -1;
}


Status destroyLStack(LinkStack *s)//销毁栈
{
	LinkStackPtr temp;
	while(s->top != NULL)
	{
		temp = s->top;
		s->top = s->top->next;
		free(temp);
		s->count--;
	}
}


Status LStackLength(LinkStack *s,int *length)//检测栈长度
{
	*length = s->count+1;
}


Status pushLStack(LinkStack *s,ElemType data)//入栈
{
	LinkStackPtr temp;
	temp = (StackNode*)(malloc(sizeof(StackNode)));
	temp->next = s->top;
	temp->data = data;
	s->top = temp;
	s->count++;
}


Status popLStack(LinkStack *s,ElemType *data)//出栈
{
	LinkStackPtr temp;
	temp = s->top;
	*data = s->top->data;
	s->top = s->top->next;
	free(temp);
	s->count--;
}


