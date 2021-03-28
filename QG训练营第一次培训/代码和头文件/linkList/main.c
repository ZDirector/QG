#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"
int main()
{
	system("color F0");
	LinkedList L=NULL,p,q,midNode;
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
		printf("=        c:����ڵ����           d:ɾ���ض��ڵ�            =\n");
		printf("=                                                           =\n");
		printf("=        e:�����������         f:��������                =\n");
		printf("=                                                           =\n");
		printf("=        g:��ת����               h:�ж������Ƿ�ѭ��        =\n");
		printf("=                                                           =\n");
		printf("=        i:��ת�������ڽڵ�       j:�ҵ������м�ڵ�        =\n");
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
			if(InitList(&L)) printf("�������ɹ���");
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
			DestroyList(&L);
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
			LinkedList temp=L;
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
			p=L;
			while(p!=NULL)
			{
				if(n==i) break;
				p=p->next;
				i++;
			}
			q=(LinkedList)(malloc(sizeof(LNode)));
			q->data=data;
			q->next=NULL;
			if(InsertList(p,q))
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
			LinkedList temp=L;
			int s=0,n,i=1;
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
			p=L;
			while(p!=NULL)
			{
				if(n==i) break;
				p=p->next;
				i++;
			}
			if(DeleteList(p,&e))
			{
				printf("ɾ���ɹ���");
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
			TraverseList(L,visit);
			system("pause");
			continue;
		}
		else if(mode == 'f')
		{
			if(L==NULL)
			{
				printf("δ��ʼ�������������ɾ����"); 
				system("pause");
				continue;
			}
			int e;
			printf("����������Ҫ���ҵĽڵ�����ݣ�"); 
			scanf("%d",&e);
			SearchList(L,e);
			system("pause");
			continue;
		}
		else if(mode == 'g')
		{
			char mode1;
			if(L==NULL)
			{
				printf("δ��ʼ�������������ɾ����"); 
				system("pause");
				continue;
			}
			printf("      a:�ǵݹ鷴ת      b:�ݹ鷴ת       \n");
			printf("����������Ҫѡ���ģʽ:"); 
			scanf("%c",&mode1);
			printf("\n");
			if(mode1 == 'a')
			{
				TraverseList(L,visit);
				ReverseList(&L);
				TraverseList(L,visit);
				system("pause");
				continue;
			}
			else if(mode1 == 'b')
			{
				TraverseList(L,visit);
				ReverseList1(&L,1);
				TraverseList(L,visit);
				system("pause");
				continue;
			}
			else printf("�����ʽ�������������룡");
		}
		else if(mode == 'h')
		{
			if(L==NULL)
			{
				printf("δ��ʼ�������������ɾ����"); 
				system("pause");
				continue;
			}
			char mode1;
			printf("�Ƿ�ѡ�񹹽����α�(Y or N)");
			scanf("%c",&mode1);
			printf("\n");
			LinkedList temp=L;
			if(mode1 == 'Y')
			{
				while(temp->next!=NULL) temp=temp->next;
				temp->next=L;
				printf("�����ɹ���\n");
				system("pause");
			}
			else if(mode1 == 'N');
			else
			{
				printf("�����ʽ�������������룡");
				system("pause");
				continue;
			}
			if(IsLoopList(L))
			{
				printf("������Ϊ��������\n");
				temp->next=NULL;
				system("pause");
				continue;
			}
			else
			{
				printf("�������ǻ�������\n");
				system("pause");
				continue;
			}
		}
		else if(mode == 'i')
		{
			if(L==NULL)
			{
				printf("δ��ʼ�������������ɾ����"); 
				system("pause");
				continue;
			}
			TraverseList(L,visit);
			L=ReverseEvenList(&L);
			TraverseList(L,visit);
			system("pause");
			continue;
		}
		else if(mode == 'j')
		{
			if(L==NULL)
			{
				printf("δ��ʼ�������������ɾ����"); 
				system("pause");
				continue;
			}
			midNode=FindMidNode(&L);
			printf("�м�ڵ�Ϊ %d\n",midNode->data);
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
