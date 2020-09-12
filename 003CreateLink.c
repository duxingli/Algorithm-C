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
	//����ͷ�ڵ� 
	h= tail = (ElemSN *)malloc(sizeof(ElemSN));
	h->data = a[0];
	h->next = NULL;
	//���������ڵ�
	for(i=1;i<N;i++){
		p = (ElemSN *)malloc(sizeof(ElemSN));
		p->data = a[i];
		//Ҫβ�� 
		p->next = NULL;
		//���� 
		tail->next = p;
		//Ųβָ�� 
		tail=p;
	} 
	return h;
}
ElemSN* CreateLink2(int a[])
{
	int i;
	ElemSN *h=NULL,*tail,*p;
	//�������нڵ� 
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
	//û��p  ��tail���� 
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
