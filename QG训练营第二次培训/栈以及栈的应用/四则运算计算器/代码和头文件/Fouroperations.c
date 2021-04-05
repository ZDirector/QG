#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Fouroperations.h"


int calcuation(char temp[],float *k)
{
	char f[50];
	float sum,a,b,t[50];
	int i,top = -1, q = 0,l;
	for(i=0,sum=0;temp[i];i++)//����һ���׺���ʽ������ 
	{
		if(temp[i]=='^')//����Ƿָ����������� 
		{
			if(f[0])//���sum��Ϊ0 ˵��sum��ûѹ��ջ
			{
				if(f[0] == '0') for(l = 0; f[l];l++) if(f[l] >= '0' || f[l] <= '9') return 0;
				t[++top]=sum;
				sum=0; 
				q=0;
				memset(f,'\0',sizeof(f));
			}
			continue;
		}
		if(temp[i]>='0'&&temp[i]<='9')	//��������� 
		{
			f[q++] = temp[i];
			sum = atof(f);
		}
		else//���������� 
		{
			a=b=0;
			b=t[top--];
			a=t[top--];
			if(temp[i]=='+')	t[++top]=a+b;
			else if(temp[i]=='-')	t[++top]=a-b;
			else if(temp[i]=='*')	t[++top]=a*b;
			else if(temp[i]=='/')
			{
				if(b==0)	return 0;
				t[++top]=a/b;
			}
		}
	}
	*k = t[top--];
	return 1;
}

void judge(char *Formula)//���벢���Ƿ����� 
{
	int i,left,right;
	printf("��������Ҫ���м����ʽ�Ӹ�ʽΪ 6+(4+2)*3+9/3 ��");
	while(1)
	{
		i = 0;
		left = 0;
		right = 0;
		gets(Formula);
		if(Formula[0] == '\0') printf("�����ʽ�������������룺");
		else
		{
			while(Formula[i])
			{
				if(Formula[i] >= '0' && Formula[i] <= '9')
				{
					i++;
					continue;
				}
				else if(Formula[i] < '0' || Formula[i] > '9')
				{
					if(Formula[i] != '+' && Formula[i] != '-' && Formula[i] != '*' && Formula[i] != '/' && Formula[i] != '(' && Formula[i] != ')')
					{
						printf("�����ʽ�������������룺");
						break;
					}
					else if(Formula[i] == '(')
					{
						if(Formula[i-1] >= '0' && Formula[i-1] <= '9' || Formula[i+1] == ')')
						{
							printf("�����ʽ�������������룺");
							break;
						}
						else left++;
					}
					else if(Formula[i] == ')')
					{
						if(Formula[i-1] == '+' || Formula[i-1] == '-' || Formula[i-1] == '*' || Formula[i-1] == '/')
						{
							printf("�����ʽ�������������룺");
							break;
						}
						else
						{
							right++;
							if(right > left)
							{
								printf("�����ʽ�������������룺");
								break;
							}
						}
					}
					else if(Formula[i] == '+' || Formula[i] == '-' || Formula[i] == '*' || Formula[i] == '/')
					{
						if(Formula[i-1] != '\0' && Formula[i+1] != '\0')
						{
							if((Formula[i-1] < '0' || Formula[i-1] > '9') || (Formula[i+1] < '0' || Formula[i+1] > '9'))
							{
								if(Formula[i-1] == '+' || Formula[i+1] == '+' || Formula[i-1] == '-' || Formula[i+1] == '-' || Formula[i-1] == '*' || Formula[i+1] == '*' || Formula[i-1] == '/' || Formula[i+1] == '/' )
								{
									printf("�����ʽ�������������룺");
									break;
								}
								if(Formula[i-1] != ')' && Formula[i+1] != '(')
								{
									if(Formula[i] == '-')
									{
										if(Formula[i-1] != '(' && (Formula[i-1] < '0' || Formula[i-1] > '9'))
										{
											printf("�����ʽ�������������룺");
											break;
										}
									}
									else
									{
										printf("�����ʽ�������������룺");
										break;
									}
								}
							}
						}
						else 
						{
							printf("�����ʽ�������������룺");
							break;
						} 
					}
				}
				i++;
			}
			if(Formula[i] == '\0')
			{
				if(left != right)
				{
					printf("�����ʽ�������������룺");
					continue;
				}
				else break;
			}
		}
		
	} 	
}


void transformation(LinkStack *s,char *Formula)
{
	int i = 0,j = 0;
	char temp[1024] = {'\0'},e;
	float val;
	while(Formula[i] != '\0')
	{
		while(Formula[i] >= '0' && Formula[i] <= '9')//������ȫ������temp�в���һ���ո���и��뷽�������� 
		{
			temp[j++]=Formula[i++];
			if(Formula[i] < '0' || Formula[i] > '9') temp[j++] = '^';
		}
		if(Formula[i] == '(') pushLStack(s,Formula[i]);//���������ȶ�����ߵ�ֱ�ӷŽ�ջ��
		else if(Formula[i] == '*' || Formula[i] == '/')
		{
			if(s->top->data == '+' || s->top->data == '-' || s->top->data == '(' || isEmptyLStack(s)) pushLStack(s,Formula[i]);
			else
			{
				popLStack(s,&temp[j++]);
				pushLStack(s,Formula[i]);
			}
		} 
		else if(Formula[i] == ')')//����������žͰ�������ǰ����������������temp��
		{
			popLStack(s,&e);
			while(e!='(')
			{
				temp[j++] = e;
				popLStack(s,&e);
			}
		}
		else if(Formula[i] == '+' || Formula[i] == '-')//����Ǽӻ����ջΪ��ʱ�ͷ���ջ�У�����Ͱ�ջ�ڵķ���ȫ������temp�� 
		{
			if(isEmptyLStack(s)) pushLStack(s,Formula[i]);
			else
			{
				do
				{
					popLStack(s,&e);
					if(e=='(') pushLStack(s,e);
					else temp[j++] = e;
				}while(!isEmptyLStack(s) && e != '(' );
				pushLStack(s,Formula[i]);
			}
		}
		else if(Formula[i] == '\0') break;
		i++; 
	}
	while(!isEmptyLStack(s)) popLStack(s,&temp[j++]);//������ջ�����з��ŷ���temp�� 
	if(calcuation(temp,&val)) printf("%s = %f\n",Formula,val);
	else printf("ERROR\n"); 
	system("pause");
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


Status pushLStack(LinkStack *s,char data)//��ջ
{
	LinkStackPtr temp;
	temp = (StackNode*)(malloc(sizeof(StackNode)));
	temp->next = s->top;
	temp->data = data;
	s->top = temp;
	s->count++;
}


Status popLStack(LinkStack *s,char *data)//��ջ
{
	LinkStackPtr temp;
	temp = s->top;
    *data = s->top->data;
	s->top = s->top->next;
	free(temp);
	s->count--;
}


Status isEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ��
{
	if(s->count == -1)
	{
		return SUCCESS;
	}
	else return ERROR;
}



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
	char Formula[1024];
	int mode;
	while(1)
	{
		system("cls");
		printf("=============================================================\n");
		printf("=                                                           =\n");
		printf("=                                                           =\n");		
		printf("=           1:��ʼ����                  0:�˳�              =\n");
		printf("=                                                           =\n");
		printf("=                                                           =\n");
		printf("=============================================================\n");
		printf("����������Ҫѡ��Ĺ���:");
		mode = judge_int();
		if(mode == 1)
		{
			initLStack(s);
			judge(Formula);
			transformation(s,Formula);
		}
		else if(mode == 0)
		{
			printf("��ӭ�ٴ�ʹ�ã�\n");
			break;
		}
	} 
}
