#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void judge_int(int *z,float *f){//输入数字 1->整形 2->浮点 
	char a[1024],*stop = NULL; 
	int i,sum = 0;
	while(1)
	{
		gets(a);
		fflush(stdin);
		if(a[0]=='\0')//如果数组内没有东西 
		{
			printf("输入错误,重新输入：");
			continue;
		}
		for(i = 0;a[i];i++){
			if(a[0]=='-'&&i==0)//如果第一个是 - 则跳过本次循环 
				continue;
			if(i!=0 && f != NULL && a[i] == '.')	//如果不是第一位且是输入浮点型且是一个“。”就跳过此次循环 
			{
				if(sum == 1)	break;
				sum = 1;
				continue; 
			}
			if(a[i] < '0' || a[i] > '9')	break;
		}
		if(z != NULL && !a[i] && atoi(a)==strtol(a,&stop,10) && i < 10)
		{
			*z = atoi(a);
			return;
		}
		if(f != NULL && !a[i] && i < 10)
		{
			*f = atof(a);
			return;
		}
		else
			printf("输入错误,重新输入：");
	}
}

void Random(int datasize,int a)
{
	FILE *fp;
	int i;
	int random;
    srand((unsigned)time(NULL));
	fp=fopen("testdata.txt","w+");
	if(fp == NULL)
	{
		printf("文件打开错误！");
		exit(1);
	}
	for(i = 1;i<=datasize;i++)
	{
		if(a==1)
			random = rand()%10000+1;
		else
			random = rand()%3;
		fprintf(fp,"%d ",random);
	}
	fclose(fp);
}


void Readdata(int *data,int len)
{
	FILE *fp;
	int i=0;
	fp=fopen("testdata.txt","r");
	if(fp == NULL)
	{
		printf("文件打开错误！");
		exit(1);
	}
	while(!feof(fp)) 
		fscanf(fp,"%d",&data[i++]);
	fclose(fp);
}

void Print(int data[],int len)
{
	int i=0;
	while(i<len)
		printf("%d  ",data[i++]);
}
