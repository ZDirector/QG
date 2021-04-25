#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"

int judge_int()//输入
{ 
	char a[1024];
	int sum,i;
	while(1)
	{
		sum=0;
		gets(a);
		if(a[0] == '\0')
		{
			printf("输入错误,重新输入:");
			continue;
		}
		for(i = 0;a[i];i++)
		{
			if(a[i] < '0' || a[i] > '9') break;
			else
			{
				sum+=(a[i]-'0');
				sum*=10;
			}
	  	}
	  	if(!a[i]) break;
	  	else
	  	{
	  		printf("输入错误,重新输入:");
		}
	}
	return sum/10;
}

void visit(NodePtr t){
	printf("%d ",t->value);
}

int main() {
	int mode;
    system("color F0");
    BinarySortTreePtr tree = (BinarySortTree*)(malloc(sizeof(BinarySortTree)));
    int data;
    tree->root = NULL;
	while(1)
	{
		system("cls");
		printf("===================================================================\n");
		printf("=                                                                 =\n");
		printf("=             1:初始化树                   2:插入                 =\n");
		printf("=                                                                 =\n");		
		printf("=             3:删除                       4:查询                 =\n");
		printf("=                                                                 =\n");		
		printf("=             5:前序遍历(非递归)           6:前序遍历(递归)       =\n");
		printf("=                                                                 =\n");
		printf("=             7:中序排序(非递归)           8:中序遍历(递归)       =\n");
		printf("=                                                                 =\n");
		printf("=             9:后序遍历(非递归)           10:后序遍历(递归)      =\n");
		printf("=                                                                 =\n");
		printf("=             11:层次遍历                  0:退出                 =\n");
		printf("=                                                                 =\n");
		printf("===================================================================\n");
		printf("请输入你想要选择的功能:");
		mode = judge_int();
		if(mode == 1){
			if(tree->root == NULL){
				if(BST_init(tree)){
				printf("初始化成功！\n");
				system("pause");
				}
				else{
					printf("初始化失败！\n");
					system("pause");
				}
			}else{
				printf("已初始化！\n");
				system("pause");
			}
			
		}else if(mode == 2){
			if(tree->root != NULL){
				printf("请输入你想要插入的数据:");
				data = judge_int();
				if(BST_insert(tree,data)){
					printf("插入成功！\n");
					system("pause");
				}
				else{
					printf("插入失败,该数据已存在！\n");
					system("pause");
				}
			}else{
				printf("未初始化！\n");
				system("pause");
			}
			
		}else if(mode == 3){
			if(tree->root != NULL){
				printf("请输入你想要删除的数据:");
				data = judge_int();
				if(BST_delete(tree,data)){
					system("pause");
				}else{
					printf("该数据不存在！");
					system("pause");
				}
			}else{
				printf("未初始化！\n");
				system("pause");
			}
		}else if(mode == 4){
			if(tree->root != NULL){
				printf("请输入你想要查询的数据:");
				data = judge_int();
				if(BST_search(tree,data)){
				printf("该数据存在！\n");
				system("pause");
				}
				else{
					printf("该数据不存在！\n");
					system("pause");
				}
			}else{
				printf("未初始化！\n");
				system("pause");
			}
		}else if(mode == 5){
			BST_preorderI(tree,visit);
			printf("\n");
			system("pause");
		}else if(mode == 6){
			BST_preorderR(tree,visit);
			printf("\n");
			system("pause");
		}else if(mode == 7){
			BST_inorderI(tree,visit);
			printf("\n");
			system("pause");
		}else if(mode == 8){
			BST_inorderR(tree,visit);
			printf("\n");
			system("pause");
		}else if(mode == 9){
			BST_postorderI(tree,visit);
			printf("\n");
			system("pause");
		}else if(mode == 10){
			BST_postorderR(tree,visit);
			printf("\n");
			system("pause");
		}else if(mode == 11){
			BST_levelOrder(tree,visit);
			printf("\n");
			system("pause");
		}else if(mode == 0){
			printf("欢迎下次使用！\n");
			system("pause");
			break;
		}else{
			printf("输入错误请重新输入！\n");
			system("pause");
			continue;
		}
		
	}
}
