//按序号查找
//按值查找 
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node*next;
}*LinkList,LNode;

//*p指针可以直接使用  *s是节点就要malloc分配空间 

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
	return L;
}

//按序号查找       !!!!
	//找到第i个元素结点,返回其指针,否则返回空 
	
	//优化 
LNode* get_LinkList2(LinkList L,int i)
{
	int j;
	LNode *p; //j=1才可以  课本是j=0       ???????????/
	for(j=1,p=L;p->next&&j<i;p=p->next,j++);
	return p;
}

//删除单链表L上的第i个数据结点 
//成功返回 1 前驱结点不存在返回 -1  前驱结点存在但是待删结点不存在返回 0 
int Del_LinkList(LinkList L,int i)
{
	LinkList p,s;
	//找到前一个结点 
	p=get_LinkList2(L,i-1);
	if(!p){
		printf("第i-1个结点不存在\n"); 
		return -1;
	}
	else{
		if(p->next == NULL){
			printf("第i个结点不存在,不用删\n");
			return 0;
		}
		else{
//			p->next=p->next->next;
//			free(s);
			
			//用 s 存储待删结点 
			s=p->next;
			p->next=s->next;
			free(s);
			return 1; 
		}
	}
}

void PrintLink(LinkList L)
{
	LinkList p;
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
	printf("请输入标识符：\n");
	scanf("%d",&flag);
	printf("请输入待删结点i：\n");
	scanf("%d",&i);
	printf("请输入链表的数据：\n");
	L=Create_LinkList2(flag);
	result=Del_LinkList(L,i);
	printf("result = %d\n",result);
	PrintLink(L);
	return 0;
}

//请输入标识符：
//6
//请输入待删结点i：
//3
//请输入链表的数据：
//1 2 3 4 5 6 (最后一个结点不存在)
//result = 1
//1 2 4 5


