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
	printf("请输入链表的数据：\n");
	scanf("%d",&x);
	printf("这个数据没有结点\n"); 
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
	return L;
}

//按序号查找       !!!!
	//找到第i个元素结点,返回其指针,否则返回空 

LNode* get_LinkList1(LinkList L,int i)
{
	LNode *p=L;
	int j=0;
	while(p->next!=NULL && j<i){
		//应该是 i 但是在创建链表时 循环外面的scanf("x")是没有结点的 少了一个结点 
		//所以视觉上是第i+1个结点    
		//所以第一个数据输完 回车一下 
		p=p->next;
		j++;
	}
	if(j==i){
		return p;
	}
	else{
		return NULL;
	} 
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
	while(p!=NULL && p->data!=x){
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
	int flag,i,x;
	LinkList L;
	LNode *p;
	printf("请输入标识符：\n");
	scanf("%d",&flag);
//	printf("请输入i：\n");
//	scanf("%d",&i);
	printf("请输入x:\n");
	scanf("%d",&x);
	L=Create_LinkList2(flag);
	
//	p = get_LinkList1(L,i);
//	p = get_LinkList2(L,i);
//	printf("查找到的值为：%d",p->data);

//	p = Locate_LinkList1(L,x);
	p = Locate_LinkList2(L,x);
	printf("查找到的值为：%d",p->data);
	return 0;
}

//get_LinkList
//请输入标识符：
//6
//请输入i：
//3
//请输入链表的数据：
//1
//这个数据没有结点
//2 3 4 5 6 7 8
//查找到的值为：4


//Locate_LinkList
//请输入标识符：
//6
//请输入x:
//3
//请输入链表的数据：
//1
//这个数据没有结点
//2 3 4 5 6
//查找到的值为：3


