//头指针：通常使用“头指针”来标识一个链表，如单链表L，头指针为NULL的时表示一个空链表。
//头结点：在单链表的第一个结点之前附加一个结点，称为头结点。
		//头结点的Data域可以不设任何信息，也可以记录表长等相关信息。
//[注意]：无论是否有头结点，头指针始终指向链表的第一个结点。如果有头结点，头指针就指向头结点。


//是带头结点时不管是否为空表，头指针的值都不会变化，都指向头结点。
//而不带头结点则需要根据不同情况来修改头指针的值。
//所以绝大数时候使用带头结点的方式较为方便。

//引入头结点的优势
//1个位置的插入删除更加方便
	//	若使用头结点，则第1个位置的插入和删除都是对p—>next进行操作，而不用动p本身
//统一空表和非空表的处理
	//	若使用头结点，无论表是否为空，头指针都指向头结点，也就是*LNode类型，对于空表和非空表的操作是一致的。
	//	若不使用头结点，当表非空时，头指针指向第1个结点的地址，即*LNode类型，
	//	但是对于空表，头指针指向的是NULL，此时空表和非空表的操作是不一致的。

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}*LinkList,LNode;
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
	}
	return L;
	
}
LinkList Create_LinkList2(int flag) 
{
	LinkList L=NULL;
	LNode *s,*r=NULL;
	int x;
	scanf("%d",&x);
	while (x!=flag){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		if(!L){
			L=s;
		}
		else{
			r->next=s;
		}
		r=s;
		scanf("%d",&x);
	}
	if(r!=NULL)
		r->next=NULL;
	return L;
}

//设L是带头结点的单链表
//此时头指针指向头结点
//h->headnode->a1->a2->a3->……　　　　　 
// 头指针存放的是头结点的地址，也就是说（*h）表示的是头结点
int length_LinkList1(LinkList L)
{
	LNode *p=L;
	int j = 0;
	while(p->next){
		p=p->next;
		j++;
	}
	return j;
}
//优化代码 
int length_LinkList11(LinkList L)
{
	LNode *p;
	int j;
	for(j=-1,p=L;p;p=p->next,j++);
	return j;
}

//设L是不带头结点的单链表 
//h->a1->a2->a3->……　　　　　　　　　　　
// 头指针存放的是第一个节点的地址，即h，也就是说（*h）表示的是第一个节点
int length_LinkList2(LinkList L)
{
	LNode *p=L;
	int j;
	if(p==NULL)
		return 0;
	j=1;
	while(p->next){
		p=p->next;
		j++;
	}
	return j;
}
//优化代码 
int length_LinkList22(LinkList L)
{
	LNode *p;
	int j;
	for(j=0,p=L;p;p=p->next,j++);
	return j; 
}
int main(void)
{
	LinkList l;
	int flag,length;
	printf("请输入 暂停标识符：");
	scanf("%d\n",&flag);
	l=Create_LinkList2(flag);
//	length = length_LinkList1(l);
	length = length_LinkList2(l);
	printf("链表长度为：%d",length);
	return 0;
}
//result:
//请输入 暂停标识符：6
//1 2 3 4 5 6
//链表长度为：5


//Create_Link2
//length_LinkList1(l)
//请输入 暂停标识符：6
//1 2 3 4 5 6
//链表长度为：4
//length_LinkList2(l)
//请输入 暂停标识符：6
//1 2 3 4 5 6
//链表长度为：5

//Create_LinkList1(flag)
//length_LinkList1(l)
//请输入 暂停标识符：6
//1 2 3 4 5 6 
//链表长度为：4
//length_LinkList2(l)
//请输入 暂停标识符：6
//1 2 3 4 5 6
//链表长度为：5

//所以两种创建链表 头插、尾插都是不带头节点的，头指针直接放到了第一个节点上。 
