#include <stdio.h>
#include <stdlib.h>
#define maxsize 1024
typedef char Elemtype;


typedef struct{
   char list[maxsize];
   int length;  
}sqlist;

// 创建顺序表
void createsqlist(sqlist *l){
    int n;
    char tmp;
    printf("请输入数据个数：");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("list[%d]=",i);
        fflush(stdin);
        scanf("%c",&tmp);
        l->list[i]=tmp;
    }
    l->length=n-1;
    printf("\n");
}

//输出顺序表
void printout(sqlist *l){
    int i;
    for(i=0;i<=l->length;i++){
        printf("list[%d]",i);
        printf("%c\n",l->list[i]);
    }
}

//插入元素
void insertsqlist(sqlist *l,char x,int i){
    int j;
    for(j=l->length;j>=i-1;j--){
    l->list[j+1]=l->list[j];
}
    l->list[i-1]=x; 
    l->length=l->length+1;
}


//删除元素
void deletesplist(sqlist *l,int i){
    if((i<0)||(i>l->length)){
        printf("error");
        return;
    }
    else{
        for(;i<=l->length;i++)
        l->list[i-1]=l->list[i];
    }
    l->length=l->length-1;
    return;
}


void main()
{
	sqlist *l;
	char x,cmd;
	int i;
	l=(sqlist *)malloc(sizeof(sqlist));
	createsqlist(l);
	printout(l);

do
	{
		printf("i,I...插入\n");
		printf("d,D...删除\n");
		printf("q,Q...退出\n");
		do
		{
			fflush(stdin);
			scanf("%c",&cmd);
		}
	
while((cmd!='d')&&(cmd!='D')&&(cmd!='q')&&
           (cmd!='Q')&&(cmd!='i')&&(cmd!='I'));
switch(cmd){
		case 'i':
		case'I':
			printf("请输入你要插入的数据：");
			fflush(stdin);
			scanf("%c",&x);
			printf("请输入你要插入的位置：");
			scanf("%d",&i);
			insertsqlist(l,x,i);
			printout(l);
			break;
		case'd':
		case'D':
			printf("请输入你要删除的数据的位置：");
			fflush(stdin);
			scanf("%d",&i);
			deletesplist(l,i);
			printout(l);
			break;
		}}while((cmd!='q')&&(cmd!='Q'));}
