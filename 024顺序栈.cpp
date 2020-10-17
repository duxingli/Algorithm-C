#define MAXSIZE 6
#include <stdio.h>
#include <stdlib.h>
typedef struct Stack
{
	int data[MAXSIZE];
	int top;
}SeqStack;
//初始化空栈-->置空栈  无参数 
SeqStack* Init_Stack()
{
	SeqStack *s;
	s=(SeqStack*)malloc(sizeof(SeqStack));
	s->top=-1;
	return s;
}
//判断空栈
int Empty_Stack(SeqStack*s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
} 
//判断满栈
int Full_Stack(SeqStack*s)
{
	if(s->top==MAXSIZE-1)
		return 1;
	else
		return 0;
} 
//入栈 顶部插入
int Push_Stack(SeqStack*s,int x)
{
	if(Full_Stack(s))
		return 0;
	else{
		s->top++; // 先移动top再赋值 
		s->data[s->top]=x;
		return 1;
	}	
}
//出栈 顶部删除
int Pop_Stack(SeqStack*s,int *x)
{
	if(Empty_Stack(s))
		return 0;
	else{
		*x = s->data[s->top];
		s->top--;
		return 1; 
	} 
}
//返回栈顶元素
int Top_Stack(SeqStack*s)
{
	if(Empty_Stack(s))
		return 0;
	else
		return s->data[s->top];
} 
void TraverseStack(SeqStack*s)
{
//	for(int i=0;i<s->top+1;i++){
//		printf("%d ",s->data[i]);
//	}
	//栈倒序遍历比较合理 
	for(int i=s->top;i>=0;i--){
		printf("%d ",s->data[i]);
	}
}
int main(void)
{
	//指向顺序栈的指针 
	SeqStack *s;
	s=Init_Stack();
//	Push_Stack(s,1);
//	if(Empty_Stack(s)){
//		printf("此栈为空\n");
//	}
//	else{
//		printf("此栈非空\n");
//	} 

	Push_Stack(s,1);
	Push_Stack(s,2);
	Push_Stack(s,3);
	TraverseStack(s);
	
//	if(Full_Stack(s)){
//		printf("此栈已满\n");
//	}
//	else{
//		printf("此栈未满\n");
//	} 

//	int x=3;
//	if(Pop_Stack(s,&x)){
//		printf("删除成功，您删除的元素是：%d\n",x);
//	}
//	else{
//		printf("删除失败\n");
//	}
	return 0;
}
