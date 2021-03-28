#include<stdio.h>
#include<stdlib.h>
#include "duLinkedList.h"
int main()
{
	system("color F0");
	DuLinkedList L=NULL,p,q;
	ElemType e;
	char mode;
	while(1)
	{
		fflush(stdin);
		system("cls");
		printf("=============================================================\n");
		printf("=                                                           =\n");
		printf("=        a:��ʼ������             b:��������                =\n");
		printf("=                                                           =\n");
		printf("=        c:����ڵ�ǰ����         d:����ڵ�����          =\n");
		printf("=                                                           =\n");
		printf("=        e:ɾ���ض��ڵ�           f:�����������          =\n");
		printf("=                                                           =\n");
		printf("=        0:�˳�����                                         =\n");
		printf("=                                                           =\n");
		printf("=============================================================\n");
		printf("����������Ҫѡ��Ĺ���:"); 
		scanf("%c",&mode);
		system("cls");
		fflush(stdin);
		if(mode=='a')
		{
			if(InitList_DuL(&L)) printf("�������ɹ���");
			else printf("������ʧ�ܣ�");
			system("pause");
			continue;
		}
		else if(mode == 'b')
		{
			if(L==NULL)
			{
				printf("δ��ʼ�������������ɾ����"); 
				system("pause");
				continue;
			}
			DestroyList_DuL(&L);
			printf("�������ٳɹ���");
			system("pause");
			continue;
		}
		else if(mode == 'c')
		{
			if(L==NULL)
			{
				printf("δ��ʼ�������������ɾ����"); 
				system("pause");
				continue;
			}
			int n,data,i=1,s=0;
			DuLinkedList temp=L,head;
			while(temp->prior!=NULL) temp=temp->prior; 
			head=temp;
			while(temp!=NULL)
			{
				s++;
				temp=temp->next;
			}
			printf("���� %d ����Ч�ڵ㣬����������Ҫ����ڼ����ڵ�:",s); 
			scanf("%d",&n);
			if(n>s)
			{
				printf("������Ľڵ㲻���ڣ�");
				system("pause");
				continue;
			}
			printf("����������Ҫ����ڵ������:");
			scanf("%d",&data);
			p=head;
			while(p!=NULL)
			{
				if(n==i) break;
				p=p->next;
				i++;
			}
			q=(DuLinkedList)(malloc(sizeof(DuLNode)));
			q->data=data;
			q->next=NULL;
			if(InsertBeforeList_DuL(p,q))
			{
				printf("����ɹ���");
				system("pause");
				continue;
			}
		}
		else if(mode == 'd') 
		{
			if(L==NULL)
			{
				printf("δ��ʼ�������������ɾ����"); 
				system("pause");
				continue;
			}
			int n,data,i=1,s=0;
			DuLinkedList temp=L,head;
			while(temp->prior!=NULL) temp=temp->prior; 
			head=temp;
			while(temp!=NULL)
			{
				s++;
				temp=temp->next;
			}
			printf("���� %d ����Ч�ڵ㣬����������Ҫ����ڼ����ڵ�:",s); 
			scanf("%d",&n);
			if(n>s)
			{
				printf("������Ľڵ㲻���ڣ�");
				system("pause");
				continue;
			}
			printf("����������Ҫ����ڵ������:");
			scanf("%d",&data);
			p=head;
			while(p!=NULL)
			{
				if(n==i) break;
				p=p->next;
				i++;
			}
			q=(DuLinkedList)(malloc(sizeof(DuLNode)));
			q->data=data;
			q->next=NULL;
			if(InsertAfterList_DuL(p,q))
			{
				printf("����ɹ���");
				system("pause");
				continue;
			}
		}
		else if(mode == 'e')
		{
			if(L==NULL)
			{
				printf("δ��ʼ�������������ɾ����"); 
				system("pause");
				continue;
			}
			DuLinkedList temp=L,head;
			int s=0,n,i=1;
			while(temp->prior!=NULL) temp=temp->prior; 
			head=temp;
			while(temp!=NULL)
			{
				s++;
				temp=temp->next;
			}
			printf("���� %d ����Ч�ڵ㣬����������Ҫɾ���ĸ��ڵ�֮��Ľڵ�:",s-1); 
			scanf("%d",&n);
			if(n>s-1)
			{
				printf("������Ľڵ㲻���ڣ�");
				system("pause");
				continue;
			}
			p=head;
			while(p!=NULL)
			{
				if(n==i) break;
				p=p->next;
				i++;
			}
			if(DeleteList_DuL(p,&e))
			{
				printf("ɾ���ɹ���");
				system("pause");
				continue;
			}
		}
		else if(mode == 'f')
		{
			if(L==NULL)
			{
				printf("δ��ʼ�������������ɾ����"); 
				system("pause");
				continue;
			}
			TraverseList_DuL(L,visit);
			system("pause");
			continue;
		}
		else if(mode == '0')
		{
			printf("��л����ʹ�ã�");
			system("pause");
			return 0; 
		}
		else 
		{
			printf("�����ʽ�������������룡\n");
			system("pause");
		}
	}
}
