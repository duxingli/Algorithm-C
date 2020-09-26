//按序号查找
//按值查找 
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node*next;
}*LinkList,LNode;

LinkList Create_LinkList2(int flag)
{
	int x;
	LinkList L=NULL;
	LNode*s,*r=NULL;
	scanf("%d",&x);
	while(x!=flag){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		if(!L){
			L=s;
		}
		else{
			r->next =s;
		}
		r=s;
		scanf("%d",&x);
	}
	if(r!=NULL){
		r->next=NULL;
	} //r指针域放空指针 
}

//按序号查找       !!!!
	//找到第i个元素结点,返回其指针,否则返回空 

LNode* get_LinkList1(LinkList L,int i)
{
	int j=0;
	LNode *p=L;       
	while(p->next && j<i){
		p=p->next;
		j++;
	} 
	if(j==i)
		return p;
	else
		return NULL;
}	
	//优化 
LNode* get_LinkList2(LinkList L,int i)
{
	int j;
	LNode *p;       
	for(j=0,p=L;p->next&&j<i;p=p->next,j++);
	return p;
}
//按值查找
	//在链表中查找值为x的结点,找到后返回其指针,否则返回空
LNode *Locate_LinkList1(LinkList L,int x)
{
	LNode *p=L->next;
	while(p && p->data!=x){
		p=p->next;
	}
	return p;
}	
	//优化 
LNode *Locate_LinkList2(LinkList L,int x)
{
	LNode *p;
	for(p=L;p->next&&p->data!=x;p=p->next);
	return p;
}
int main(void)
{
	int flag,i;
	LinkList L;
	LNode *p;
	printf("请输入标识符：\n");
	scanf("%d\n",&flag);
	printf("请输入i：\n");
	L=Create_LinkList2(flag);
	p = get_LinkList(L,i);
	printf("%d",p->data);
	return 0;
}
