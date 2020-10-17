#define MAXSIZE 6
#include <stdio.h>
#include <stdlib.h>
typedef struct Stack
{
	int data[MAXSIZE];
	int top;
}SeqStack;
//��ʼ����ջ-->�ÿ�ջ  �޲��� 
SeqStack* Init_Stack()
{
	SeqStack *s;
	s=(SeqStack*)malloc(sizeof(SeqStack));
	s->top=-1;
	return s;
}
//�жϿ�ջ
int Empty_Stack(SeqStack*s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
} 
//�ж���ջ
int Full_Stack(SeqStack*s)
{
	if(s->top==MAXSIZE-1)
		return 1;
	else
		return 0;
} 
//��ջ ��������
int Push_Stack(SeqStack*s,int x)
{
	if(Full_Stack(s))
		return 0;
	else{
		s->top++; // ���ƶ�top�ٸ�ֵ 
		s->data[s->top]=x;
		return 1;
	}	
}
//��ջ ����ɾ��
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
//����ջ��Ԫ��
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
	//ջ��������ȽϺ��� 
	for(int i=s->top;i>=0;i--){
		printf("%d ",s->data[i]);
	}
}
int main(void)
{
	//ָ��˳��ջ��ָ�� 
	SeqStack *s;
	s=Init_Stack();
//	Push_Stack(s,1);
//	if(Empty_Stack(s)){
//		printf("��ջΪ��\n");
//	}
//	else{
//		printf("��ջ�ǿ�\n");
//	} 

	Push_Stack(s,1);
	Push_Stack(s,2);
	Push_Stack(s,3);
	TraverseStack(s);
	
//	if(Full_Stack(s)){
//		printf("��ջ����\n");
//	}
//	else{
//		printf("��ջδ��\n");
//	} 

//	int x=3;
//	if(Pop_Stack(s,&x)){
//		printf("ɾ���ɹ�����ɾ����Ԫ���ǣ�%d\n",x);
//	}
//	else{
//		printf("ɾ��ʧ��\n");
//	}
	return 0;
}
