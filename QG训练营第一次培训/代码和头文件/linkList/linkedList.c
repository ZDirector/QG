#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"


/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value��ʼ��һ������������ֻ��ͷ�ڵ�û��ֵ
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) 
{
	(*L)=(LinkedList)(malloc(sizeof(LNode)));
	(*L)->next=NULL;
	return (*L)==NULL? ERROR:SUCCESS;
	
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes���������ͷ����нڵ�
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) 
{
 	LinkedList p;
 	while(*L)
 	{
  		p=*L;
 	 	*L=(*L)->next;
 		free(p);
 	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p�ڽڵ�p֮�����ڵ�q
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) 
{
	q->next=p->next;
	p->next=q;
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to eɾ���ڵ�p֮��ĵ�һ���ڵ㣬������ֵ����e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) 
{
	LinkedList q=p->next;
	*e=q->data;
	p->next=q->next;
	free(q);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit�����������ú�������
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) 
{
	L=L->next;
	while(L!=NULL)
	{
		visit(L->data);
		L=L->next;
	}
	printf("\n"); 
}

void visit(ElemType e)
{
	printf("%d ",e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e����e���������еĵ�һ���ڵ�
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) 
{
	int s=0;
	while(L!=NULL)
	{
		s++;
		if(L->data==e)
		{
			printf("Ҫ���ҵĽڵ��ڵ� %d ����\n",s);
			return SUCCESS;
		}
		L=L->next;
	}
	if(L==NULL)
	{
		printf("����ڵ㲻���ڣ�\n"); 
		return ERROR;
	}
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list��ת����
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) 
{
	LinkedList p=NULL,q=NULL;
    while((*L)->next!=NULL)
	{
        p=(*L)->next;
        (*L)->next=p->next;
        p->next=q;
        q=p;
    }
    (*L)->next=q;
}


LinkedList ReverseList1(LinkedList *L,int n)
{
	if(n==1) (*L)->next=ReverseList1(&((*L)->next),0);
	else
	{
		if ((*L) == NULL || (*L)->next == NULL) return (*L);
		LinkedList p = ReverseList1(&((*L)->next),0); 
		(*L)->next->next = (*L);                       
		(*L)->next = NULL;
		return p;
	}
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped�ж������Ƿ�ѭ��
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) 
{
	LinkedList fast=L,slow=L;
	while(fast!=NULL && fast->next != NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(fast == slow) return SUCCESS;
	}
	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3��ת�����б���ֵΪż���Ľڵ�
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) 
{
	LinkedList f=(*L)->next,s=(*L);
	LNode temp;
	while(f!=NULL)
	{
		s->next=f->next;
		f->next=f->next->next;
		s->next->next=f;
		s=f;
		f=f->next;
	}
	return (*L);
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list���������ҵ��м�ڵ�
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) 
{
	LinkedList fast=(*L),slow=(*L);
	while(fast!=NULL && fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}

