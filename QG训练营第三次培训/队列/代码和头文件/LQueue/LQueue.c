#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "LQueue.h"
void InitLQueue(LQueue *Q)
{
	if(Q->front == NULL)
	{
		Node *node = (Node*)(malloc(sizeof(Node)));
		node->next = NULL;
		Q->front = node;
		Q->rear = node;
		printf("��ʼ���ɹ���\n");
		system("pause");
	}
	else
	{
		printf("�Ѿ���ʼ�����У�\n");
		system("pause");
	}
}

void DestoryLQueue(LQueue *Q)
{
	if(Q->front != NULL)
	{
		Node *temp;
		while(Q->front != NULL)
		{
			temp = Q->front;
			Q->front = Q->front->next;
			free(temp);
			Q->length--;
		}
		printf("���ٳɹ���\n");
		system("pause");
	}
	else
	{
		printf("δ��ʼ�����У�\n");
		system("pause");
	}
}

Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->length == 0)
	{
		return TRUE;
	}
	else return FALSE;
}

Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(Q->front != NULL)
	{
		e = Q->front->data;
		type = datatype[0];
		if(type != '\0') LPrint(e);
		else printf("����Ϊ�գ�\n");
		system("pause");
		return TRUE;
	}
	else
	{
		printf("δ��ʼ�����У�\n");
		system("pause");
	}
}

int LengthLQueue(LQueue *Q)
{
	return Q->length;
}

Status EnLQueue(LQueue *Q, void *data)
{
	Node *temp;
	temp = (Node*)(malloc(sizeof(Node)));
	temp->next = NULL;
	Q->rear->data = data;
	Q->rear->next = temp;
	Q->rear = temp;
	Q->length++;
	return TRUE;
}

Status DeLQueue(LQueue *Q)
{
	int i;
	if(Q->front != NULL)
	{
		if(Q->length != 0)
		{
			Node *temp;
			temp = Q->front;
			Q->front = Q->front->next;
			free(temp);
			for(i = 0; i<=Q->length; i++) datatype[i]=datatype[i+1];
			Q->length--;
			return TRUE;
		}
		else
		{
			printf("����Ϊ�գ�\n");
			system("pause");
		}
	}
	else
	{
		printf("δ��ʼ�����У�\n");
		system("pause");
	}
}

void ClearLQueue(LQueue *Q)
{
	Node *temp;
	while(Q->length != 0)
	{
		temp = Q->front;
		Q->front = Q->front->next;
		free(temp);
		Q->length--;
	}
	memset(datatype,'\0',30);
	Q->front->data = NULL;
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	if(Q->front != NULL)
	{
		if(Q->length != 0)
		{
			Node *temp = Q->front;
			int i = 0;
			while(temp->next != NULL)
			{
				type = datatype[i++];
				foo(temp->data);
				temp = temp->next;
			}
			return TRUE;
		}
		else printf("����Ϊ�գ�");
	}
	else printf("δ��ʼ�����У�\n");
}

void LPrint(void *q)
{
	if(type == 'I')
	{
		printf("��������Ϊ��%d\n",*(int*)q);
	}else if(type == 'F')
	{
		printf("����������Ϊ��%f\n",*(float*)q);
	}else if(type == 'C')
	{
		printf("�ַ�������Ϊ��%c\n",*(char*)q);
	}else if(type == 'S')
	{
		printf("�ַ���������Ϊ��%s\n",(char*)q);
	}
}

