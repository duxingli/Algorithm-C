//尾插 正着输出 两个指针 （头指针 尾指针） 

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node*next;
 }LNode,*LinkList; 

//LinkList 是一个结构体指针 
LinkList Create_LinkList2(int flag)
{
	LinkList L;
	LNode *s,*r;
	//初始 头指针、尾指针 赋空值 
	L=r=NULL;
	int x;
	scanf("%d",&x);
	while(x != flag){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
//		s->next=NULL;//没有必要 
		//头节点处理 
		if(!L){
			L=s; 
		}
		//其他节点的处理 
		else{
			//在链表尾部插入新的节点 
			r->next=s;
		}
		//移动尾指针 
		r=s; 
		scanf("%d",&x);
	} 
	//对于非空表，最后节点的指针域放空指针 
	if(r!=NULL)
		r->next=NULL; 
	return L; 
}

void Print(LinkList l)
{
	LinkList p;
	for(p=l;p;p=p->next){
		printf("%d ",p->data);
	}
}
int main(void)
{
	int flag;
	LinkList l;
	printf("请输入可以停止链表的 标志数：\n");
	scanf("%d\n",&flag);
	l=Create_LinkList2(flag);
	printf("输出链表：\n");		
	Print(l);
	return 0;
}
//
//请输入可以停止链表的 标志数：
//6
//1 2 3 4 5 6 7 8 9 0
//输出链表：
//1 2 3 4 5
