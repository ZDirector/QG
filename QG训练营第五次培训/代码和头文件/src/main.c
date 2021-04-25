#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"

int judge_int()//����
{ 
	char a[1024];
	int sum,i;
	while(1)
	{
		sum=0;
		gets(a);
		if(a[0] == '\0')
		{
			printf("�������,��������:");
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
	  		printf("�������,��������:");
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
		printf("=             1:��ʼ����                   2:����                 =\n");
		printf("=                                                                 =\n");		
		printf("=             3:ɾ��                       4:��ѯ                 =\n");
		printf("=                                                                 =\n");		
		printf("=             5:ǰ�����(�ǵݹ�)           6:ǰ�����(�ݹ�)       =\n");
		printf("=                                                                 =\n");
		printf("=             7:��������(�ǵݹ�)           8:�������(�ݹ�)       =\n");
		printf("=                                                                 =\n");
		printf("=             9:�������(�ǵݹ�)           10:�������(�ݹ�)      =\n");
		printf("=                                                                 =\n");
		printf("=             11:��α���                  0:�˳�                 =\n");
		printf("=                                                                 =\n");
		printf("===================================================================\n");
		printf("����������Ҫѡ��Ĺ���:");
		mode = judge_int();
		if(mode == 1){
			if(tree->root == NULL){
				if(BST_init(tree)){
				printf("��ʼ���ɹ���\n");
				system("pause");
				}
				else{
					printf("��ʼ��ʧ�ܣ�\n");
					system("pause");
				}
			}else{
				printf("�ѳ�ʼ����\n");
				system("pause");
			}
			
		}else if(mode == 2){
			if(tree->root != NULL){
				printf("����������Ҫ���������:");
				data = judge_int();
				if(BST_insert(tree,data)){
					printf("����ɹ���\n");
					system("pause");
				}
				else{
					printf("����ʧ��,�������Ѵ��ڣ�\n");
					system("pause");
				}
			}else{
				printf("δ��ʼ����\n");
				system("pause");
			}
			
		}else if(mode == 3){
			if(tree->root != NULL){
				printf("����������Ҫɾ��������:");
				data = judge_int();
				if(BST_delete(tree,data)){
					system("pause");
				}else{
					printf("�����ݲ����ڣ�");
					system("pause");
				}
			}else{
				printf("δ��ʼ����\n");
				system("pause");
			}
		}else if(mode == 4){
			if(tree->root != NULL){
				printf("����������Ҫ��ѯ������:");
				data = judge_int();
				if(BST_search(tree,data)){
				printf("�����ݴ��ڣ�\n");
				system("pause");
				}
				else{
					printf("�����ݲ����ڣ�\n");
					system("pause");
				}
			}else{
				printf("δ��ʼ����\n");
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
			printf("��ӭ�´�ʹ�ã�\n");
			system("pause");
			break;
		}else{
			printf("����������������룡\n");
			system("pause");
			continue;
		}
		
	}
}
