#include<stdio.h>
#include<stdlib.h>
#include"SqStack.h"

Status initStack(SqStack *s,int sizes)//��ʼ��ջ
{ 
	s->elem = (ElemType*) malloc (sizes * sizeof(ElemType));//�����ڴ� 
	s->top = -1;//ջ��Ϊ-1 
	s->size = sizes;//ջ�ĳ���Ϊ.. 
}

Status isEmptyStack(SqStack *s)//�ж�ջ�Ƿ�Ϊ��
{
	if( s->top == -1 )	//���ջ�������ݣ���top���䣬Ϊ-1 
		return SUCCESS;
	return ERROR;
}

Status getTopStack(SqStack *s,ElemType *e) //�õ�ջ��Ԫ��
{
	if(isEmptyStack(s))	//���ջ��Ϊ�գ���õ�ջ��Ԫ�� 
		return ERROR;
	*e = s->elem[s->top];//��ջ��Ԫ�ش��� 
	return SUCCESS;
}

Status clearStack(SqStack *s)//���ջ
{
	free(s->elem);//��ջ��� 
	if(s->elem == NULL)	return ERROR;//���ջ 
	s->elem = (ElemType*) malloc (s->size * sizeof(ElemType));	//���������ڴ� 
	s->top = -1;
	return SUCCESS;
}

Status destroyStack(SqStack *s)//����ջ
{
	free(s);
	return SUCCESS;
}

Status stackLength(SqStack *s,int *length)//���ջ����
{
	*length = s->top+1;
	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data)//��ջ
{
	if(s->top == s->size-1)
	{
		printf("ջ��������ջʧ��\n");
		return ERROR;
	}
	s->top++;
	s->elem[s->top] = data;
	return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data)//��ջ
{
	if(s->top == -1)
	{
		printf("ջΪ�գ�������");
		return ERROR;
	}
	*data = s->elem[s->top--];
	return SUCCESS;
}

int judge_int()//����
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
			printf("�������,�������룺");
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
			printf("�������,�������룺");
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
		temp = judge_int();
		if(temp<0||temp>8)
		{
			printf("�������������1-9");
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
					printf("�ѳ�ʼ����ջ��������ջ�ٳ�ʼ��ջ");
					getch();
					break;
				}
				printf("������˳��ջ�ĳ��ȣ�");
				temp = judge_int();
				if(initStack(stack,temp))//�жϳ�ʼ�����޳ɹ� 
					printf("SUCCESS");
				else
					printf("ERROR");
				getch();
				break;
			}
			case 2:
			{
				if(stack == NULL)
					printf("δ��ʼ��ջ");
				else
				{
					if(isEmptyStack(stack))
						printf("��һ���յ�ջ");
					else
						printf("����һ����ջ");
				}
				getch();
				break;
			}
			case 3:
			{
				if(stack == NULL)
					printf("δ��ʼ��ջ");
				else
				{
					if(getTopStack(stack,&e))
						printf("ջ��Ԫ��Ϊ:%d",e);
					else
						printf("ջΪ��,��ȡջ��Ԫ��ʧ��");
				}
				getch();
				break;
			}
			case 4:
			{
				if(stack == NULL)
					printf("δ��ʼ��ջ");
				else
				{
					if(clearStack(stack))
						printf("���ջ�ɹ�");
					else
						printf("���ջʧ��");
				}
				getch();
				break;
			}
			case 5:
			{
				if(stack == NULL)
					printf("δ��ʼ��ջ");
				else
				{
					if(destroyStack(stack))
					{
						printf("����ջ�ɹ�");
						stack = NULL;
					}
					else
						printf("����ջʧ��");
				}
				getch();
				break;
			}
			case 6:
			{
				if(stack == NULL)
					printf("δ��ʼ��ջ");
				else
				{
					if(stackLength(stack,&temp))
						printf("ջ�ĳ���Ϊ%d",temp);
					else
						printf("���ջ�ĳ���ʧ��");
				}
				getch();
				break;
			}
			case 7:
			{
				if(stack == NULL)
					printf("δ��ʼ��ջ");
				else
				{
					printf("������Ҫ����ջ�е�����:");
					temp = judge_int();
					if(pushStack(stack,temp))
						printf("��ջ�ɹ�");
					else
						printf("��ջʧ��");
				}
				getch();
				break;
			}
			case 8:
			{
				if(stack == NULL)
					printf("δ��ʼ��ջ");
				else
				{
					if(popStack(stack,&e))
						printf("��ջ�ɹ�������Ϊ%d",e);
					else
						printf("��ջʧ��");
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
