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
		printf("=        a:初始化链表             b:销毁链表                =\n");
		printf("=                                                           =\n");
		printf("=        c:链表节点前插入         d:链表节点后插入          =\n");
		printf("=                                                           =\n");
		printf("=        e:删除特定节点           f:遍历链表并输出          =\n");
		printf("=                                                           =\n");
		printf("=        0:退出程序                                         =\n");
		printf("=                                                           =\n");
		printf("=============================================================\n");
		printf("请输入你想要选择的功能:"); 
		scanf("%c",&mode);
		system("cls");
		fflush(stdin);
		if(mode=='a')
		{
			if(InitList_DuL(&L)) printf("链表创建成功！");
			else printf("链表创建失败！");
			system("pause");
			continue;
		}
		else if(mode == 'b')
		{
			if(L==NULL)
			{
				printf("未初始化链表或链表已删除！"); 
				system("pause");
				continue;
			}
			DestroyList_DuL(&L);
			printf("链表销毁成功！");
			system("pause");
			continue;
		}
		else if(mode == 'c')
		{
			if(L==NULL)
			{
				printf("未初始化链表或链表已删除！"); 
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
			printf("现有 %d 个有效节点，请输入你想要插入第几个节点:",s); 
			scanf("%d",&n);
			if(n>s)
			{
				printf("你输入的节点不存在！");
				system("pause");
				continue;
			}
			printf("请输入你想要插入节点的数据:");
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
				printf("插入成功！");
				system("pause");
				continue;
			}
		}
		else if(mode == 'd') 
		{
			if(L==NULL)
			{
				printf("未初始化链表或链表已删除！"); 
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
			printf("现有 %d 个有效节点，请输入你想要插入第几个节点:",s); 
			scanf("%d",&n);
			if(n>s)
			{
				printf("你输入的节点不存在！");
				system("pause");
				continue;
			}
			printf("请输入你想要插入节点的数据:");
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
				printf("插入成功！");
				system("pause");
				continue;
			}
		}
		else if(mode == 'e')
		{
			if(L==NULL)
			{
				printf("未初始化链表或链表已删除！"); 
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
			printf("现有 %d 个有效节点，请输入你想要删除哪个节点之后的节点:",s-1); 
			scanf("%d",&n);
			if(n>s-1)
			{
				printf("你输入的节点不存在！");
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
				printf("删除成功！");
				system("pause");
				continue;
			}
		}
		else if(mode == 'f')
		{
			if(L==NULL)
			{
				printf("未初始化链表或链表已删除！"); 
				system("pause");
				continue;
			}
			TraverseList_DuL(L,visit);
			system("pause");
			continue;
		}
		else if(mode == '0')
		{
			printf("感谢您的使用！");
			system("pause");
			return 0; 
		}
		else 
		{
			printf("输入格式错误请重新输入！\n");
			system("pause");
		}
	}
}
