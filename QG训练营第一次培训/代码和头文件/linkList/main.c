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
		printf("=        a:初始化链表             b:销毁链表                =\n");
		printf("=                                                           =\n");
		printf("=        c:链表节点插入           d:删除特定节点            =\n");
		printf("=                                                           =\n");
		printf("=        e:遍历链表并输出         f:查找链表                =\n");
		printf("=                                                           =\n");
		printf("=        g:反转链表               h:判断链表是否循环        =\n");
		printf("=                                                           =\n");
		printf("=        i:反转链表相邻节点       j:找到链表中间节点        =\n");
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
			if(InitList(&L)) printf("链表创建成功！");
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
			DestroyList(&L);
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
			LinkedList temp=L;
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
			LinkedList temp=L;
			int s=0,n,i=1;
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
			p=L;
			while(p!=NULL)
			{
				if(n==i) break;
				p=p->next;
				i++;
			}
			if(DeleteList(p,&e))
			{
				printf("删除成功！");
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
			TraverseList(L,visit);
			system("pause");
			continue;
		}
		else if(mode == 'f')
		{
			if(L==NULL)
			{
				printf("未初始化链表或链表已删除！"); 
				system("pause");
				continue;
			}
			int e;
			printf("请输入你想要查找的节点的数据："); 
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
				printf("未初始化链表或链表已删除！"); 
				system("pause");
				continue;
			}
			printf("      a:非递归反转      b:递归反转       \n");
			printf("请输入你想要选择的模式:"); 
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
			else printf("输入格式错误请重新输入！");
		}
		else if(mode == 'h')
		{
			if(L==NULL)
			{
				printf("未初始化链表或链表已删除！"); 
				system("pause");
				continue;
			}
			char mode1;
			printf("是否选择构建环形表？(Y or N)");
			scanf("%c",&mode1);
			printf("\n");
			LinkedList temp=L;
			if(mode1 == 'Y')
			{
				while(temp->next!=NULL) temp=temp->next;
				temp->next=L;
				printf("构建成功！\n");
				system("pause");
			}
			else if(mode1 == 'N');
			else
			{
				printf("输入格式错误请重新输入！");
				system("pause");
				continue;
			}
			if(IsLoopList(L))
			{
				printf("该链表为环形链表！\n");
				temp->next=NULL;
				system("pause");
				continue;
			}
			else
			{
				printf("该链表不是环形链表！\n");
				system("pause");
				continue;
			}
		}
		else if(mode == 'i')
		{
			if(L==NULL)
			{
				printf("未初始化链表或链表已删除！"); 
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
				printf("未初始化链表或链表已删除！"); 
				system("pause");
				continue;
			}
			midNode=FindMidNode(&L);
			printf("中间节点为 %d\n",midNode->data);
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
