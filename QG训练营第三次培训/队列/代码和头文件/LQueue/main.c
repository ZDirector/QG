#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "LQueue.h"

void judge_int(int *z,float *f){//�������� 1->���� 2->���� 
	char a[1024],*stop = NULL; 
	int i;
	while(1)
	{
		gets(a);
		fflush(stdin);
		if(a[0]=='\0')//���������û�ж��� 
		{
			printf("�������,�������룺");
			continue;
		}
		for(i = 0;a[i];i++){
			if(a[0]=='-'&&i==0)//�����һ���� - ����������ѭ�� 
				continue;
			if(i!=0 && f != NULL && a[i] == '.')	continue;	//������ǵ�һλ�������븡��������һ���������������˴�ѭ�� 
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
			printf("�������,�������룺");
	}
}

char Enter(LQueue *Q)	//��ӽ��� 
{
	char a;
	int i,*tempInt;
	float *tempFloat;
	char enterChar[1024],*enter; 
	printf("������Ҫ������������� 1����������  2��������  3���ַ���  4���ַ���\n");
	judge_int(&i,NULL);
	while(i<1 || i>4)
	{
		printf("�������ִ���������1-4\n");
		judge_int(&i,NULL);
	}
	switch(i)
	{
		case 1:
		{
			printf("������Ҫ�������������:");
			tempInt = (int*)malloc(sizeof(int));	//���������ݷ���һ���ڴ� 
			judge_int(tempInt,NULL);	//������������ 
			datatype[Q->length] = 'I';
			if(EnLQueue(Q,tempInt))	//��� 
				printf("��ӳɹ�\n");
			else
				printf("���ʧ��\n");
			break; 
		}
		case 2:
		{
			printf("������Ҫ����ĸ���������:");
			tempFloat = (float*)malloc(sizeof(float));	//�����������ݷ���һ���ڴ� 
			judge_int(NULL,tempFloat);	//���븡�������� 
			datatype[Q->length] = 'F';
			if(EnLQueue(Q,tempFloat))	//��� 
				printf("��ӳɹ�\n");
			else
				printf("���ʧ��\n");
			break;
		}
		case 3:
		{
			printf("������Ҫ������ַ�������:");
			enter = (char*)malloc(sizeof(char));	//���ַ������ݷ���һ���ڴ� 
			while(1)
			{
				gets(enterChar);	//�����ַ������� 
				if(enterChar[0] == '\0' || enterChar[1] != '\0')
					printf("��������������룺");
				else break;
			}
			memcpy(enter,&enterChar,sizeof(char));
			datatype[Q->length] = 'C';
			if(EnLQueue(Q,enter))	//��� 
				printf("��ӳɹ�\n");
			else
				printf("���ʧ��\n");
			break;
		}
		case 4:
		{
			printf("������Ҫ������ַ�������:");
			enter = (char*)malloc(1024*sizeof(char));	//���ַ������ݷ���һ���ڴ� 
			gets(enter);	//�����ַ������� 
			datatype[Q->length] = 'S';
			if(EnLQueue(Q,enter))	//��� 
				printf("��ӳɹ�\n");
			else
				printf("���ʧ��\n");
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
		printf("=        1:��ʼ������             2:���ٶ���                =\n");
		printf("=                                                           =\n");
		printf("=        3:�������Ƿ�Ϊ��       4:�鿴��ͷԪ��            =\n");
		printf("=                                                           =\n");
		printf("=        5:ȷ�����г���           6:��Ӳ���                =\n");
		printf("=                                                           =\n");
		printf("=        7:���Ӳ���               8:��ն���                =\n");
		printf("=                                                           =\n");
		printf("=        9:��������               0:�˳�����                =\n");
		printf("=                                                           =\n");
		printf("=============================================================\n");
		printf("����������Ҫѡ��Ĺ���:");
		judge_int(&mode,NULL);
		if(mode == 1) InitLQueue(Q);
		else if(mode == 2) DestoryLQueue(Q);
		else if(mode == 3)
		{
			if(Q->front != NULL)
			{
				if(IsEmptyLQueue(Q))
				{
					printf("����Ϊ��\n"); 
					system("pause");
					continue;
				}
				else
				{
					printf("���в�Ϊ��\n"); 
					system("pause");
					continue;
				}
			}
			else
			{
				printf("δ��ʼ�����У�\n");
				system("pause");
			}
		}
		else if(mode == 4) GetHeadLQueue(Q,e);
		else if(mode == 5)
		{
			if(Q->front != NULL)
			{
				printf("���г���Ϊ��%d\n",LengthLQueue(Q));
				system("pause");
			}
			else
			{
				printf("δ��ʼ�����У�\n");
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
					printf("����������\n");
					system("pause");
				}
			}
			else
			{
				printf("δ��ʼ�����У�\n");
				system("pause");
			}
		}
		else if(mode == 7)
		{
			if(DeLQueue(Q))
			{
				printf("���гɹ���\n");
				system("pause");
			}
		}
		else if(mode == 8)
		{
			if(Q->front != NULL)
			{
				ClearLQueue(Q);
				printf("��ճɹ���\n");
				system("pause");
			}
			else
			{
				printf("δ��ʼ�����У�\n");
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
			printf("��ӭ�´�ʹ�ã�\n");
			break;
		}
		else
		{
			printf("����������������룡\n");
			system("pause");
		}
	}
	
}
