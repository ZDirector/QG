#include<stdio.h>
#include<stdlib.h>
#include "duLinkedList.h"

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) 
{
	(*L)=(DuLinkedList)(malloc(sizeof(DuLNode)));
	(*L)->next=NULL;
	(*L)->prior=NULL;
	(*L)->data=0; 
	return (*L)==NULL? ERROR:SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) 
{
	DuLinkedList p;
	while((*L)->prior!=NULL) (*L)=(*L)->prior;
 	while(*L)
 	{
  		p=*L;
 	 	*L=(*L)->next;
 		free(p);
 	}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) 
{
	if(p->prior==NULL)
	{
		q->prior=NULL;
		q->next=p;
		p->prior=q;
	}
	else
	{
		q->prior=p->prior;
		p->prior->next=q;
		p->prior=q;
		q->next=p;
	}
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) 
{
	if(p->next==NULL)
	{
		p->next=q;
		q->prior=p;
		q->next=NULL;
	}
	else
	{
		q->next=p->next;
		p->next->prior=q;
		p->next=q;
		q->prior=p;
	}
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) 
{
	DuLinkedList q=p->next;
	*e=q->data;
	p->next=q->next;
	p->next->prior=p;
	free(q);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) 
{
	DuLinkedList p;
	while(L->prior!=NULL) L=L->prior;
	while(L!=NULL)
	{
		if(L->data!=0) visit(L->data);
		L=L->next;
	}
	printf("\n"); 
}


void visit(ElemType e)
{
	printf("%d ",e);
}
