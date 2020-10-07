//链表的插入 
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
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
			r->next = s;
		}
		r=s;
		scanf("%d",&x);
	}
	if(r!=NULL){
		r->next =NULL;
		//r指针域放空指针 
	}
	return L;
}

//按序号查找       !!!!
	//找到第i个元素结点,返回其指针,否则返回空 
	
	//优化版 
LNode* get_LinkList2(LinkList L,int i)
{
	int j;
	LNode *p;
	//j=1才能运行
	for(j=1,p=L;p->next&&j<i;p=p->next,j++);
	return p; 
}

//后插  直接插 
//前插 	找前驱节点

//在单链表L的第i个位置上插入值为x的元素  成功返回1 失败返回0
//这里是  前插 
int Insert_LinkList(LinkList L,int i,int x)
{
	LNode *p,*s;
	p=get_LinkList2(L, i-1);
	if(!p){
		printf("参数i错\n");
		return 0;
	} 
	else{
		s=(LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = p->next; //先连接后面，再前面 
		p->next = s;
		return 1; 
	}
 } 
 
void PrintLink(LinkList L)
{
	LNode* p;
	for(p=L;p;p=p->next){
		printf("%d ",p->data);
	}
}

int main(void)
{
	int flag,i,x;
	int result;
	LinkList L;
	LNode *p;
	printf("请输入标志符：\n");
	scanf("%d",&flag);
	printf("请输入i和x：\n");
	scanf("%d%d",&i,&x);
	printf("请输入链表的数据：\n");
	L=Create_LinkList2(flag);
	result = Insert_LinkList(L,i,x);
	printf("result = %d\n",result);
	PrintLink(L);
	return 0;
}


//请输入标志符：
//6
//请输入i和x：
//2 3
//请输入链表的数据：    (链表数据是没有 最后的 标志符6的)
//0 9 8 7 4 3 6
//result = 1
//0 3 9 8 7 4 3


//bug 无法插入标志符   创建链表的问题 
 
//请输入标志符：
//5
//请输入i和x：
//3 6
//请输入链表的数据：
//1 2 3 4 5 6
//result = 1
//1 2 6 3 4
