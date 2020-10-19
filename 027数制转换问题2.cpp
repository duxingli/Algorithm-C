//用链式栈实现  粘贴 025 
#include <stdio.h>
#include <stdlib.h> 
typedef struct node
{
	int data;
	struct node*next;
}StackNode,*LinkStack;
//置空栈
LinkStack Init_LinkStack()
{
	return NULL; 
} 
//判空栈
int Empty_LinkStack(LinkStack top)
{
	if(top == NULL)
		return 1;
	else
		return 0;
}
//链式栈不用判断满栈

//入栈 不用判断满栈 	//入栈就是从首结点插入s结点 
LinkStack Push_LinkStack(LinkStack top,int x)
{
	StackNode *s;
	//或者 (StackNode*)  LinkStack
	s=(StackNode*)malloc(sizeof(StackNode)); 
	s->data=x;
	s->next=top;
	top=s; //top移向前一个结点 
	return top; 
} 

//出栈
//出栈就是从头结点删除
LinkStack Pop_LinkStack(LinkStack top,int* val)
{
	//删除头先要用一个变量 p 保留剩余节点 或者 保留头节点 
	StackNode *p;
	if(top == NULL)
		return NULL;
	else{
		*val=top->data;
		
		p=top->next;
		free(top);
		top=p; 

//		p=top;
//		top=top->next;
//		free(p);
		return top;
	}	
} 

//取栈顶元素
int Top_LinkStack(LinkStack top)
{
	if(Empty_LinkStack(top))
		return NULL;
	else
		return top->data;
} 

void Traverse(LinkStack top)
{
	//顺着遍历  数据就是反的，，，用的头插法 
	LinkStack p;
	int i=0;
	for(p=top;p;p=p->next){
		printf("%d ",p->data);
	}
}

void conversion(int n,int r)
{
	LinkStack s;
	int x;
	s=Init_LinkStack();
	while(n){
		x=n%r;
		s=Push_LinkStack(s,x);
		n/=r;
	}
//	Traverse(s);
	while(!Empty_LinkStack(s)){
		s=Pop_LinkStack(s,&x);
		printf("%d",x);	
	}
}
int main(void)
{
	//n是输入的十进制数 r是进制数 
	int n,r;
	scanf("%d%d",&n,&r);
	conversion(n,r); 
	return 0;
 } 
 
//555555 8
//2075043


