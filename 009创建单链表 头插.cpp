//头插 倒着输出 一个指针 （头指针） 

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node*next;
}LNode,*LinkList;

//全局变量，，函数无法返回多个值 
int count=1;

//返回一个指针类型 
LinkList Create_LinkList1(int flag)
{
	LinkList L=NULL;
	LNode *s;
	int x;
	scanf("%d",&x);
	while(x != flag){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=L;
		L=s;
		scanf("%d",&x);	
		count++;	
	}
	return L;
	
}
void Print (LinkList p,int n) 
{
	//头插只能 倒着输出
	for(int i=0;i<n;p=p->next){
		printf("%d ",p->data);
	}
}
int main(void)
{
	int flag;
	LinkList l;
	printf("请输入可以停止链表的 标志数：\n");
	scanf("%d\n",&flag);
	l=Create_LinkList1(flag);
	printf("输出链表：\n");		
	Print(l,count);		
	return 0;
 } 

//标志数 不输出 

//请输入可以停止链表的 标志数：
//0
//1 2 3 4 5 6 7 8 9 0
//输出链表：
//9 8 7 6 5 4 3 2 1
