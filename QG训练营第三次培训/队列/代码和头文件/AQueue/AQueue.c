#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"AQueue.h"
 
void InitAQueue(AQueue *Q)	//��ʼ������
{
	
	Q->front = Q->length = 0;		//ͷ��β�����ȶ�Ϊ0 
	Q->rear = -1; 
	printf("��ʼ���ɹ�");
}

void DestoryAQueue(AQueue *Q)	// ���ٶ���
{
	if(Q == NULL)
	{
		printf("δ��ʼ������");
		return;
	} 
	free(Q);
}

Status IsFullAQueue(const AQueue *Q)	// �������Ƿ�����
{
	if( Q->length == MAXQUEUE )
		return TRUE;
	return FALSE;
}

Status IsEmptyAQueue(const AQueue *Q)	//	�������Ƿ�Ϊ��
{
	if( Q->length == 0)
		return TRUE;
	return FALSE;
} 

Status GetHeadAQueue(AQueue *Q, void *e)	//�鿴��ͷԪ��
{
	if(Q == NULL)	//�����Ƿ��ʼ�� 
	{
		printf("δ��ʼ��");
		return FALSE; 
	}
	if(IsEmptyAQueue(Q))	//�����Ƿ�Ϊ�� 
	{
		printf("����Ϊ��");
		return FALSE;
	}
	memcpy(e,Q->data[Q->front],MAXQUEUE);	//�� Q->data[Q->front](��ͷ)���ڴ渴��һ�ݵ�eָ����ڴ� 
	return TRUE;
}

int LengthAQueue(AQueue *Q)	//ȷ�����г���
{
	if(Q == NULL)	//�����Ƿ��ʼ�� 
	{
		printf("δ��ʼ��");
		return -1; 
	}
	return Q->length;	//���ض��еĳ��� 
}

Status EnAQueue(AQueue *Q, void *data)	//��Ӳ���
{
	if(Q == NULL)	//�����Ƿ��ʼ�� 
	{
		printf("δ��ʼ��");
		return FALSE; 
	}
	if(IsFullAQueue(Q))
	{
		printf("��������");
		return FALSE;
	}
	Q->data[Q->rear] = data;
	Q->length++;
	return TRUE;
}

Status DeAQueue(AQueue *Q)	//���Ӳ���
{
	int i = 0;
	void *data,*temp;
	if(Q == NULL)	//�����Ƿ��ʼ�� 
	{
		printf("δ��ʼ��");
		return FALSE; 
	}
	if(IsEmptyAQueue(Q))	//�����Ƿ�Ϊ�� 
	{
		printf("����Ϊ��");
		return FALSE;
	}
	data = Q->data[Q->front];	//����һ������
	type = datatype[0];
	APrint(data);
	Q->length--;
	for( i =0 ; i< MAXQUEUE; i++)	//��������ǰ��һ�� 
	{
		temp = Q->data[i+1];
		Q->data[i] = temp;
	}
	for(i = 0 ; i < MAXQUEUE ; i++)	//��datatype�е���������Ҳ��ǰ�ƶ� 
		datatype[i] = datatype[i+1];
	Q->rear--;
	return TRUE;
}

void ClearAQueue(AQueue *Q)	//��ն���
{
	int i=0;
	Q->front = Q->length = 0;
	Q->rear = -1;
	while(i<MAXQUEUE)
		Q->data[i++] = NULL;
	memset(datatype,'\0',sizeof(datatype));
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))	//������������
{
	int start;
	if(Q == NULL)	//�����Ƿ��ʼ�� 
	{
		printf("δ��ʼ��");
		return FALSE; 
	}
	if(IsEmptyAQueue(Q))	//�����Ƿ�Ϊ�� 
	{
		printf("����Ϊ��");
		return FALSE;
	}
	for(start = Q->front ; start <= Q->rear ; start++)
	{
		type = datatype[start];
		foo(Q->data[start]);	//����ӡ 
		printf("\n");
	}
	return TRUE; 
}

void APrint(void *q)	//��������
{
	if(type == 'I')
		printf("��������Ϊ��%d\n",*(int*)q);
	else if(type == 'C')
		printf("�ַ�����Ϊ��%c\n",*(char*)q);
	else if(type == 'F')
		printf("����������Ϊ��%.2f\n",*(float*)q);
	else if(type == 'S')
		printf("�ַ�����Ϊ��%s\n",(char*)q);
}

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

char Enter(AQueue *Q)	//��ӽ��� 
{
	char a;
	int i,*tempInt;
	float *tempFloat;
	char enterChar[1024],*enter; 
	printf("������Ҫˢ����������� 1 -> �������� 2 -> ������ 3 -> �ַ��� 4 -> �ַ���");
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
			datatype[++Q->rear] = 'I';
			if(EnAQueue(Q,tempInt))	//��� 
				printf("��ӳɹ�");
			else
				printf("���ʧ��");
			break; 
		}
		case 2:
		{
			printf("������Ҫ����ĸ���������:");
			tempFloat = (float*)malloc(sizeof(float));	//�����������ݷ���һ���ڴ� 
			judge_int(NULL,tempFloat);	//���븡�������� 
			datatype[++Q->rear] = 'F';
			if(EnAQueue(Q,tempFloat))	//��� 
				printf("��ӳɹ�");
			else
				printf("���ʧ��");
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
					printf("���������������");
				else break;
			}
			memcpy(enter,&enterChar,sizeof(char));
			datatype[++Q->rear] = 'C';
			if(EnAQueue(Q,enter))	//��� 
				printf("��ӳɹ�");
			else
				printf("���ʧ��");
			break;
		}
		case 4:
		{
			printf("������Ҫ������ַ�������:");
			enter = (char*)malloc(1024*sizeof(char));	//���ַ������ݷ���һ���ڴ� 
			gets(enter);	//�����ַ������� 
			
			datatype[++Q->rear] = 'S';
			if(EnAQueue(Q,enter))	//��� 
				printf("��ӳɹ�");
			else
				printf("���ʧ��");
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
		printf("=        1:��ʼ������             2:���ٶ���                =\n");
		printf("=                                                           =\n");
		printf("=        3:�������Ƿ�����       4:�������Ƿ�Ϊ��        =\n");
		printf("=                                                           =\n");
		printf("=        5:�鿴��ͷԪ��           6:ȷ�����г���            =\n");
		printf("=                                                           =\n");
		printf("=        7:��Ӳ���               8:���Ӳ���                =\n");
		printf("=                                                           =\n");
		printf("=        9:��ն���               10:��������               =\n");
		printf("=                                                           =\n");
		printf("=        0:�˳�����                                         =\n");
		printf("=                                                           =\n");
		printf("=============================================================\n");
		printf("����������Ҫѡ��Ĺ���:");
		judge_int(&choose,NULL);
		switch(choose)
		{
			case 1://��ʼ������
			{
				if(Q != NULL)
					printf("�ѳ�ʼ��\n");
				else
				{
					Q = (AQueue*)malloc(sizeof(AQueue));	//����һ�����е��ڴ�
					InitAQueue(Q);
				}
				getch();
				break;
			}
			case 2://�����ٶ���
			{
				if(Q == NULL)
					printf("δ��ʼ��\n");
				else
				{
					DestoryAQueue(Q);
					printf("�ݻٶ��гɹ�");
					Q=NULL;
				}
				getch();
				break;
			}
			case 3://�������Ƿ�����
			{
				if(Q == NULL)
					printf("δ��ʼ��\n");
				else 
				{
					if(IsFullAQueue(Q))
						printf("����Ϊ��"); 
					else printf("���в�Ϊ��"); 
				}
				getch();
				break;
			}
			case 4://�������Ƿ�Ϊ��
			{
				if(Q == NULL)
					printf("δ��ʼ��\n");
				else 
				{
					if(IsEmptyAQueue(Q))
						printf("����Ϊ��"); 
					else printf("���в�Ϊ��"); 
				}
				getch();
				break;
			}
			case 5://�鿴��ͷԪ��
			{
				if(GetHeadAQueue(Q,e))
				{
					type = datatype[0];//��ͷ 
					APrint(e);
				}
				else
					printf("��ȡͷԪ��ʧ��");
				getch();
				break;
			}
			case 6:	//ȷ�����г���
			{
				if(LengthAQueue(Q) != -1)
					printf("���г���Ϊ%d",LengthAQueue(Q));
				getch();
				break;
			}
			case 7://��Ӳ���
			{
				if(Q == NULL)
					printf("δ��ʼ��\n");
				else
					Enter(Q);
				getch();
				break;
			}
			case 8://���Ӳ���
			{
				if(!DeAQueue(Q))
					printf("����ʧ��");
				getch();
				break;
			}
			case 9:		// ��ն��� 
			{
				if(Q == NULL)
					printf("δ��ʼ������");
				else
				{
					ClearAQueue(Q);
					printf("��ճɹ�");
				}
				getch();
				break;
			}
			case 10:	//������������
			{
				if(TraverseAQueue(Q,&APrint))
					printf("�����ɹ�");
				else
					printf("����ʧ��");
				getch();
				break; 
			} 
			case 0:free(e);return ;
			default :
				{
					printf("����������������룡");
					getch();
				}
		}
	}
}

