#include <stdio.h>
#include <stdlib.h>
#define N 8
typedef struct node{
	int data;
	int times;
	struct node *next;
}ElemSN;
ElemSN *CreateLink1(int a[])
{
	ElemSN *p,*tail,*h;
	//创建头节点 不用查找 
	h=tail=(ElemSN*)malloc(sizeof(ElemSN));
	h->data=a[0];
	h->times=1;
	h->next=NULL;	
	for(int i=1; i<N; i++){
		for(p=h;p && p->data-a[i]; p=p->next);
		if(p){
			p->times++;
		}
		//p==NULL 创建节点 挂链 
		else{
			//没必要newp 
			p=(ElemSN*)malloc(sizeof(ElemSN));		
			p->data = a[i];
			p->times = 1;
			p->next = NULL;
			tail=tail->next=p;
		}		
	}
	return h;
}
ElemSN* CreateLink2(int a[])
{
	ElemSN *h=NULL,*p,*tail;
	for(int i=0; i<N; i++){
		for(p=h;p && p->data-a[i]; p=p->next);
		if(p)
			(p->times)++;
		//p==NULL 创建节点 挂链 
		else{
			//没必要用newp  
			p=(ElemSN*)malloc(sizeof(ElemSN));
			p->data = a[i];
			p->times = 1;
			p->next = NULL;
			if(!h)
				h=tail=p;		
			else
				tail=tail->next=p;
		}		
	}
	return h;
}
void PrintLink(ElemSN *h)
{
	ElemSN*p;
	for(p=h;p;p=p->next){
		printf("元素：%d  出现次数：%d\n",p->data,p->times);
	}
}
int main(void)
{
	int a[N] = {3,2,3,8,3,8,6,2};
	ElemSN *head;
	head=CreateLink2(a);
	PrintLink(head);
	return 0;
}
//元素：3  出现次数：3
//元素：2  出现次数：2
//元素：8  出现次数：2
//元素：6  出现次数：1
