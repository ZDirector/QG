#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Fouroperations.h"


int calcuation(char temp[],float *k)
{
	char f[50];
	float sum,a,b,t[50];
	int i,top = -1, q = 0,l;
	for(i=0,sum=0;temp[i];i++)//遍历一遍后缀表达式的数组 
	{
		if(temp[i]=='^')//如果是分隔符，则跳过 
		{
			if(f[0])//如果sum不为0 说明sum还没压入栈
			{
				if(f[0] == '0') for(l = 0; f[l];l++) if(f[l] >= '0' || f[l] <= '9') return 0;
				t[++top]=sum;
				sum=0; 
				q=0;
				memset(f,'\0',sizeof(f));
			}
			continue;
		}
		if(temp[i]>='0'&&temp[i]<='9')	//如果是数字 
		{
			f[q++] = temp[i];
			sum = atof(f);
		}
		else//如果是运算符 
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

void judge(char *Formula)//输入并检测非法输入 
{
	int i,left,right;
	printf("请输入想要进行计算的式子格式为 6+(4+2)*3+9/3 ：");
	while(1)
	{
		i = 0;
		left = 0;
		right = 0;
		gets(Formula);
		if(Formula[0] == '\0') printf("输入格式错误，请重新输入：");
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
						printf("输入格式错误，请重新输入：");
						break;
					}
					else if(Formula[i] == '(')
					{
						if(Formula[i-1] >= '0' && Formula[i-1] <= '9' || Formula[i+1] == ')')
						{
							printf("输入格式错误，请重新输入：");
							break;
						}
						else left++;
					}
					else if(Formula[i] == ')')
					{
						if(Formula[i-1] == '+' || Formula[i-1] == '-' || Formula[i-1] == '*' || Formula[i-1] == '/')
						{
							printf("输入格式错误，请重新输入：");
							break;
						}
						else
						{
							right++;
							if(right > left)
							{
								printf("输入格式错误，请重新输入：");
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
									printf("输入格式错误，请重新输入：");
									break;
								}
								if(Formula[i-1] != ')' && Formula[i+1] != '(')
								{
									if(Formula[i] == '-')
									{
										if(Formula[i-1] != '(' && (Formula[i-1] < '0' || Formula[i-1] > '9'))
										{
											printf("输入格式错误，请重新输入：");
											break;
										}
									}
									else
									{
										printf("输入格式错误，请重新输入：");
										break;
									}
								}
							}
						}
						else 
						{
							printf("输入格式错误，请重新输入：");
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
					printf("输入格式错误，请重新输入：");
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
		while(Formula[i] >= '0' && Formula[i] <= '9')//把数字全部放入temp中并用一个空格进行隔离方便后面计算 
		{
			temp[j++]=Formula[i++];
			if(Formula[i] < '0' || Formula[i] > '9') temp[j++] = '^';
		}
		if(Formula[i] == '(') pushLStack(s,Formula[i]);//左括号优先度是最高的直接放进栈中
		else if(Formula[i] == '*' || Formula[i] == '/')
		{
			if(s->top->data == '+' || s->top->data == '-' || s->top->data == '(' || isEmptyLStack(s)) pushLStack(s,Formula[i]);
			else
			{
				popLStack(s,&temp[j++]);
				pushLStack(s,Formula[i]);
			}
		} 
		else if(Formula[i] == ')')//如果是右括号就把左括号前面的所有运算符放入temp中
		{
			popLStack(s,&e);
			while(e!='(')
			{
				temp[j++] = e;
				popLStack(s,&e);
			}
		}
		else if(Formula[i] == '+' || Formula[i] == '-')//如果是加或减且栈为空时就放入栈中，否则就把栈内的符号全部放入temp中 
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
	while(!isEmptyLStack(s)) popLStack(s,&temp[j++]);//到最后把栈内所有符号放入temp中 
	if(calcuation(temp,&val)) printf("%s = %f\n",Formula,val);
	else printf("ERROR\n"); 
	system("pause");
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


Status pushLStack(LinkStack *s,char data)//入栈
{
	LinkStackPtr temp;
	temp = (StackNode*)(malloc(sizeof(StackNode)));
	temp->next = s->top;
	temp->data = data;
	s->top = temp;
	s->count++;
}


Status popLStack(LinkStack *s,char *data)//出栈
{
	LinkStackPtr temp;
	temp = s->top;
    *data = s->top->data;
	s->top = s->top->next;
	free(temp);
	s->count--;
}


Status isEmptyLStack(LinkStack *s)//判断栈是否为空
{
	if(s->count == -1)
	{
		return SUCCESS;
	}
	else return ERROR;
}



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
	char Formula[1024];
	int mode;
	while(1)
	{
		system("cls");
		printf("=============================================================\n");
		printf("=                                                           =\n");
		printf("=                                                           =\n");		
		printf("=           1:开始计算                  0:退出              =\n");
		printf("=                                                           =\n");
		printf("=                                                           =\n");
		printf("=============================================================\n");
		printf("请输入你想要选择的功能:");
		mode = judge_int();
		if(mode == 1)
		{
			initLStack(s);
			judge(Formula);
			transformation(s,Formula);
		}
		else if(mode == 0)
		{
			printf("欢迎再次使用！\n");
			break;
		}
	} 
}
