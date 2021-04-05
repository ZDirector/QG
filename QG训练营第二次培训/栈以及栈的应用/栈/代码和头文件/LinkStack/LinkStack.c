#include<stdio.h>
#include<stdlib.h>
#include "LinkStack.h"


int judge_int()//����
{ 
	char a[1024];
	int sum,i;
	while(1)
	{
		sum=0;
		gets(a);
		if(a[0] == '\0')
		{
			printf("�������,��������:");
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
	  		printf("�������,��������:");
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
		printf("=        1:��ʼ��ջ             2:�ж�ջ�Ƿ�Ϊ��            =\n");
		printf("=                                                           =\n");
		printf("=        3:�õ�ջ��Ԫ��         4:���ջ                    =\n");
		printf("=                                                           =\n");
		printf("=        5:����ջ               6:���ջ����                =\n");
		printf("=                                                           =\n");
		printf("=        7:��ջ                 8:��ջ                      =\n");
		printf("=                                                           =\n");
		printf("=        0:�˳�����                                         =\n");
		printf("=                                                           =\n");
		printf("=============================================================\n");
		printf("����������Ҫѡ��Ĺ���:");
		mode = judge_int();
		if(mode == 1)
		{
			if(s->top != NULL)
			{
				printf("�Ѿ���ʼ��ջ��\n");
				system("pause");
				continue;
			}
			if(initLStack(s))
			{
				printf("��ʼ���ɹ���\n");
				system("pause");
				continue;
			}
			else
			{
				printf("��ʼ��ʧ�ܣ�\n");
				system("pause");
				continue;
			}
		}
		else if(mode == 2)
		{
			if(s->top == NULL)
			{
				printf("δ��ʼ��ջ��\n");
				system("pause");
				continue;
			}
			if(isEmptyLStack(s))
			{
				printf("ջΪ��\n"); 
				system("pause");
				continue;
			}
			else
			{
				printf("ջ��Ϊ��\n"); 
				system("pause");
				continue;
			}
		}
		else if(mode == 3)
		{
			ElemType e;
			if(s->top == NULL)
			{
				printf("δ��ʼ��ջ��\n");
				system("pause");
				continue;
			}
			if(getTopLStack(s,&e) && !isEmptyLStack(s))
			{
				printf("ջ��Ԫ��Ϊ��%d\n",e);
				system("pause");
				continue;
			}
			else
			{
				printf("��ջ��Ԫ�أ���ջΪ��\n");
				system("pause");
				continue;
			}
			
		}
		else if(mode == 4)
		{
			if(s->top == NULL)
			{
				printf("δ��ʼ��ջ��\n");
				system("pause");
				continue;
			}
			if(!isEmptyLStack(s))
			{
				clearLStack(s);
				printf("��ճɹ���\n");
				system("pause");
				continue;
			}
			else
			{
				printf("��ջ��Ϊ��\n");
				system("pause");
				continue;
			}
		}
		else if(mode == 5)
		{
			if(s->top == NULL)
			{
				printf("δ��ʼ��ջ��\n");
				system("pause");
				continue;
			}
			destroyLStack(s);
			printf("���ٳɹ���\n");
			system("pause");
			continue;
		}
		else if(mode == 6)
		{
			int length;
			if(s->top == NULL)
			{
				printf("δ��ʼ��ջ��\n");
				system("pause");
				continue;
			}
			LStackLength(s,&length);
			printf("ջ�ĳ���Ϊ��%d\n",length);
			system("pause");
			continue;
		}
		else if(mode == 7)
		{
			int data;
			if(s->top == NULL)
			{
				printf("δ��ʼ��ջ��\n");
				system("pause");
				continue;
			}
			else
			{
				printf("���������ݣ�"); 
				data = judge_int();
				pushLStack(s,data);
			}
		}
		else if(mode == 8)
		{
			int data;
			if(s->top == NULL)
			{
				printf("δ��ʼ��ջ��\n");
				system("pause");
				continue;
			}
			else
			{
				if(s->count == -1)
				{
					printf("��ջΪ��\n");
					system("pause");
					continue;
				}
				else
				{
					popLStack(s,&data);
					printf("���ٵ�����Ϊ��%d\n",data);
					system("pause");
					continue;
				} 
			}
		}
		else if(mode == 0)
		{
			printf("��ӭ�´�ʹ�ã�\n");
			system("pause");
			break;
		}
		else
		{
			printf("�������,��������!\n");
			continue;
		}
	}
	
}


Status initLStack(LinkStack *s)//��ʼ��ջ
{
	LinkStackPtr node;
	node = (StackNode*)(malloc(sizeof(StackNode)));
	node->next = NULL;
	node->data = 0;
	s->top = node;
	s->count = -1;
}


Status isEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ��
{
	if(s->count == -1)
	{
		return SUCCESS;
	}
	else return ERROR;
}


Status getTopLStack(LinkStack *s,ElemType *e)//�õ�ջ��Ԫ��
{
	*e = s->top->data; 
	return SUCCESS;
}


Status clearLStack(LinkStack *s)//���ջ
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


Status destroyLStack(LinkStack *s)//����ջ
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


Status LStackLength(LinkStack *s,int *length)//���ջ����
{
	*length = s->count+1;
}


Status pushLStack(LinkStack *s,ElemType data)//��ջ
{
	LinkStackPtr temp;
	temp = (StackNode*)(malloc(sizeof(StackNode)));
	temp->next = s->top;
	temp->data = data;
	s->top = temp;
	s->count++;
}


Status popLStack(LinkStack *s,ElemType *data)//��ջ
{
	LinkStackPtr temp;
	temp = s->top;
	*data = s->top->data;
	s->top = s->top->next;
	free(temp);
	s->count--;
}


