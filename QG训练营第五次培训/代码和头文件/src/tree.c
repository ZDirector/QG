#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"


void InitQueue(LQueue *Q){
	Q->front = Q->rear = NULL;
	Q->length = 0;
}

void EnLQueue(LQueue *Q,NodePtr node){
	QNode *n = (QNode*)malloc(sizeof(QNode));
	n->next = NULL;
	n->data = node;
	if(Q->length == 0)
		Q->front = Q->rear = n;
	else{
		Q->rear->next = n;
		Q->rear = n;
	}
	Q->length++;
}

NodePtr DeLQueue(LQueue *Q,void (*visit)(NodePtr)){
	QNode *temp = Q->front;
	NodePtr t;
	Q->length--;
	t = temp->data;
	visit(temp->data);
	Q->front = temp->next;
	if(Q->length == 0)
		Q->front = Q->rear = NULL;
	return t;
}


Status BST_init(BinarySortTreePtr tree){
	NodePtr node;
	node = (NodePtr)(malloc(sizeof(Node)));
	node->left = NULL;
	node->right = NULL;
	node->value = 0;
	tree->root = node;
	return true;
}


Status BST_insert(BinarySortTreePtr tree, ElemType data){
	NodePtr temp = tree->root;
	if(!tree->root->value){
		tree->root->value = data;
	}else{
		while(temp != NULL){
			if(temp->value == data) return false;
			else if(temp->value > data){
				if(temp->left == NULL){
					NodePtr node;
					node = (NodePtr)(malloc(sizeof(Node)));
					node->left = NULL;
					node->right = NULL;
					node->value = data;
					temp->left = node;
					return true;
				}else temp = temp->left;
			}
			else {
				if(temp->right == NULL){
					NodePtr node;
					node = (NodePtr)(malloc(sizeof(Node)));
					node->left = NULL;
					node->right = NULL;
					node->value = data;
					temp->right = node;
					return true;
				}else temp = temp->right;
			}
		}
	}
}


Status BST_delete(BinarySortTreePtr tree, ElemType data){
	NodePtr temp = tree->root,p = tree->root;
	if(tree->root != NULL)
	{
		while(temp != NULL)
		{
			if(temp->value == data)
			{
				if(!temp->left && !temp->right)
				{
					if(p->left == temp) p->left = NULL;
					else p->right = NULL;
					printf("删除的数据为:%d\n",temp->value);
					free(temp);
					return true;
				}
				else if(temp->left && temp->right)
				{
					NodePtr q = temp,t;
					temp = temp->left;
					if(temp->right == NULL)
					{
						temp->right = q->right;
						if(p->value > data) p->left = temp;
						else p->right = temp;
					}
					else
					{
						while(temp->right != NULL)
						{
							t = temp;
							temp = temp->right;
						}
						if(temp->left) t->right = temp->left;
						else t->right = NULL;
						temp->left = q->left;
						temp->right = q->right;
						if(data < p->value) p->left = temp;
						else p->right = temp;
					}
					printf("删除的数据为:%d\n",q->value);
					free(q);
					return true;
				}
				else if(!temp->left || !temp->right)
				{
					if(p->value > data)
					{
						if(temp->left) p->left = temp->left;
						else p->left = temp->right;
					}
					else
					{
						if(temp->left) p->right = temp->left;
						else p->right = temp->right;
					}
					printf("删除的数据为:%d\n",temp->value);
					free(temp);
					return true;
				}
				
			}else{
				if(temp->value > data)
				{
					if(temp->left == NULL) return false;
					else
					{
						p = temp;
						temp = temp->left;
					}
				}
				else
				{
					if(temp->right == NULL) return false;
					else
					{
						p = temp;
						temp = temp->right;
					}
				}
			}
		}
	}
	else
	{
		printf("未初始化！\n");
		system("pause");
	}
}


Status BST_search(BinarySortTreePtr tree, ElemType data){
	NodePtr temp = tree->root;
	while(temp != NULL){
		if(data == temp->value) return true;
		else if(data < temp->value) temp = temp->left;
		else temp = temp->right;
	}
	return false;
}


Status BST_preorderI(BinarySortTreePtr tree, void (*visit)(NodePtr)){
	NodePtr *res = (NodePtr*)malloc(2048*sizeof(NodePtr)) ;
	NodePtr head = NULL;
	NodePtr *stack = (NodePtr*)malloc(2048*sizeof(NodePtr));
	int top = 0 ,i = 0;
	if(tree == NULL){
		printf("未初始化");
		free(res);
		free(stack);
		return failed;
	}
	else{
		head = tree->root;
		if(head == NULL)
			printf("无数据");
		else{
			while(top > 0 || head != NULL){
				while(head != NULL){
					res[i++] = head;
					stack[top++] = head;
					head = head->left;
				}
				head = stack[--top];
				head = head->right;
				}
				for(top=0;top<i;top++){
					visit(res[top]);
			}
		}
		free(res);
		free(stack);
		return succeed;
	}
}


Status BST_preorderR(BinarySortTreePtr tree, void (*visit)(NodePtr)){
	if(tree->root != NULL){
		visit(tree->root);
		if(tree->root->left) BST_preorderR1(tree->root->left,visit);
		if(tree->root->right) BST_preorderR1(tree->root->right,visit);
	}else{
		printf("未初始化！\n");
		system("pause");
	}
}


Status BST_inorderI(BinarySortTreePtr tree, void (*visit)(NodePtr)){
	int i = 0, top = 0;
	NodePtr* res =(NodePtr*) malloc(2048*sizeof(NodePtr)); 		//申请个顺序栈
	NodePtr* stack = (NodePtr*) malloc(2048*sizeof(NodePtr));		//申请个顺序栈
	NodePtr head = NULL;
	
	if(tree == NULL){
		printf("未初始化");
		free(res);
		free(stack);
		return failed;
	}else{
		head = tree->root;
		if(head == NULL)
			printf("无数据");
		else{
			while(top >0 || head != NULL){
				while(head != NULL){
					stack[top++] = head ;	//入栈
					head = head->left;	//继续向左 
				}
				head = stack[--top];	
				res[i++] = head;
				head = head->right;	//向右寻找 
			}
		}
		for(top = 0;top < i; top++){
			visit(res[top]);
		}
		free(res);
		free(stack);
		return succeed;
	}
}


Status BST_inorderR(BinarySortTreePtr tree, void (*visit)(NodePtr)){
	if(tree->root != NULL){
		if(tree->root->left) BST_inorderR1(tree->root->left,visit);
		visit(tree->root);
		if(tree->root->right) BST_inorderR1(tree->root->right,visit);
	}else{
		printf("未初始化！\n");
		system("pause");
	}
}


Status BST_postorderI(BinarySortTreePtr tree, void (*visit)(NodePtr)){
	NodePtr* res =(NodePtr*) malloc(2048*sizeof(NodePtr));
	NodePtr* stack = (NodePtr*) malloc(2048*sizeof(NodePtr));
	NodePtr head = NULL, temp = NULL;
	int i = 0,top = 0;
	if(tree == NULL){
		printf("未初始化");
		free(res);
		free(stack);
		return failed;
	}else{
		head = tree->root;
		if(head == NULL)
			printf("无数据");
		else{
			while(head != NULL || top >0){
				while(head != NULL){
					stack[top++] = head;
					head = head->left;
				}
				head = stack[--top];
				if(head->right ==NULL || head->right == temp){
					res[i++] = head;
					temp = head;
					head=NULL;
				}
				else{
					stack[top++] = head;
					head = head->right;
				}
			}
			for(top=0 ; top <i ;top++)
				visit(res[top]);
		}
		free(res);
		free(stack);
		return succeed;
	}
}


Status BST_postorderR(BinarySortTreePtr tree, void (*visit)(NodePtr)){
	if(tree->root != NULL){
		if(tree->root->left) BST_postorderR1(tree->root->left,visit);
		if(tree->root->right) BST_postorderR1(tree->root->right,visit);
		visit(tree->root);
	}else{
		printf("未初始化！\n");
		system("pause");
	}
}


Status BST_levelOrder(BinarySortTreePtr tree, void (*visit)(NodePtr)){
	if(tree == NULL){
		printf("未初始化");
		return failed;
	}
	else{
		NodePtr head = tree->root;
		if(head == NULL){
			printf("无数据");
			return succeed;
		}
		else{
			LQueue *Q = (LQueue*)malloc(sizeof(LQueue));
			InitQueue(Q);
			EnLQueue(Q,head);
			while(Q->length!=0){
				head = DeLQueue(Q,visit);
				if(head->left != NULL)
					EnLQueue(Q,head->left);
				if(head->right != NULL)
					EnLQueue(Q,head->right);
			}
		}
	}
}


Status BST_preorderR1(NodePtr root, void (*visit)(NodePtr)){
	visit(root);
	if(root->left) BST_preorderR1(root->left,visit);
	if(root->right) BST_preorderR1(root->right,visit);
}


Status BST_inorderR1(NodePtr root, void (*visit)(NodePtr)){
	if(root->left) BST_inorderR1(root->left,visit);
	visit(root);
	if(root->right) BST_inorderR1(root->right,visit);
}


Status BST_postorderR1(NodePtr root, void (*visit)(NodePtr)){
	if(root->left) BST_postorderR1(root->left,visit);
	if(root->right) BST_postorderR1(root->right,visit);
	visit(root);
}



