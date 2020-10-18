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
		
//		p=top->next;
//		free(top);
//		top=p; 

		p=top;
		top=top->next;
		free(p);
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
int main(void)
{
	//链表的头部做栈顶最为方便   top为栈顶指针        
	LinkStack top;
	top=Init_LinkStack(); 
	
//	if(!top){
//		printf("此栈初始化成功\n");
//	} 
	
//	if(Empty_LinkStack(top)){
//		printf("此栈为空\n");
//	}
//	else{
//		printf("此栈非空\n");
//	}

//	int x=3;
//	if(Push_LinkStack(top,x)){
//		printf("入栈成功\n");
//	}
//	else{
//		printf("入栈失败\n");
//	}

	for(int i=0;i<5;i++){
		top = Push_LinkStack(top,i+1);
	}
//	Traverse(top);//5 4 3 2 1 
	
//	int x=3;
//	if(Pop_LinkStack(top,&x)){
//		printf("删除成功 您删除的元素是%d",x);
//	}
//	else{
//		printf("删除失败");
//	}
	
	int y=4;
	top =  Pop_LinkStack(top,&y);
	Traverse(top);//4 3 2 1
	
	
	//返回栈顶元素 
	printf("\n%d",Top_LinkStack(top));
	return 0;
}
