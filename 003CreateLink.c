#include <stdio.h>
#include <stdlib.h>
#define N 6
typedef struct node
{
	int data;
	struct ElemSN* next;
}ElemSN;
ElemSN* CreateLink1(int a[])
{
	ElemSN *h,*tail,*p;
	int i;
	//创建头节点 
	h= tail = (ElemSN *)malloc(sizeof(ElemSN));
	h->data = a[0];
	h->next = NULL;
	//创建其他节点
	for(i=1;i<N;i++){
		p = (ElemSN *)malloc(sizeof(ElemSN));
		p->data = a[i];
		//要尾插 
		p->next = NULL;
		//挂链 
		tail->next = p;
		//挪尾指针 
		tail=p;
	} 
	return h;
}
ElemSN* CreateLink2(int a[])
{
	int i;
	ElemSN *h=NULL,*tail,*p;
	//创建所有节点 
	for(i=0;i<N;i++){
		p=(ElemSN*)malloc(sizeof(ElemSN));
		p->data=a[i];
		p->next=NULL;
		if(!h){
			h=tail=p;
		}
		else{
			tail=tail->next=p;
		}
	} 
	return h;
}
ElemSN* CreateLink3(int *a)
{
	//没有p  用tail代替 
	ElemSN *h,*tail;
	int i;
	h=tail=(ElemSN*)malloc(sizeof(ElemSN));
	h->data=a[0];
	h->next=NULL;
	for(i=1;i<N;i++){
		tail=tail->next=(ElemSN*)malloc(sizeof(ElemSN));
		tail->data=a[i];
		tail->next=NULL;
	}
	return h;
}
void PrintLink (ElemSN *h)
{
	ElemSN *p;
	for(p=h;p;p=p->next)
		printf("%5d",p->data);
	return;
}
int main(void)
{
	int a[N]={3,2,5,8,4,7};
	ElemSN *head;
	head = CreateLink3(a);
	PrintLink(head);
	return 0;
}
