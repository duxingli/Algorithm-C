#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node*next;
}StackNode,*LinkStack;
//�ÿ�ջ
LinkStack Init_LinkStack()
{
	return NULL; 
} 
//�п�ջ
int Empty_LinkStack(LinkStack top)
{
	if(top == NULL)
		return 1;
	else
		return 0;
}
//��ʽջ�����ж���ջ

//��ջ �����ж���ջ 	//��ջ���Ǵ��׽�����s��� 
LinkStack Push_LinkStack(LinkStack top,int x)
{
	StackNode *s;
	//���� (StackNode*)  LinkStack
	s=(StackNode*)malloc(sizeof(StackNode)); 
	s->data=x;
	s->next=top;
	top=s; //top����ǰһ����� 
	return top; 
} 

//��ջ
//��ջ���Ǵ�ͷ���ɾ��
LinkStack Pop_LinkStack(LinkStack top,int* val)
{
	//ɾ��ͷ��Ҫ��һ������ p ����ʣ��ڵ� ���� ����ͷ�ڵ� 
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

//ȡջ��Ԫ��
int Top_LinkStack(LinkStack top)
{
	if(Empty_LinkStack(top))
		return NULL;
	else
		return top->data;
} 

void Traverse(LinkStack top)
{
	//˳�ű���  ���ݾ��Ƿ��ģ������õ�ͷ�巨 
	LinkStack p;
	int i=0;
	for(p=top;p;p=p->next){
		printf("%d ",p->data);
	}
}
int main(void)
{
	//�����ͷ����ջ����Ϊ����   topΪջ��ָ��        
	LinkStack top;
	top=Init_LinkStack(); 
	
//	if(!top){
//		printf("��ջ��ʼ���ɹ�\n");
//	} 
	
//	if(Empty_LinkStack(top)){
//		printf("��ջΪ��\n");
//	}
//	else{
//		printf("��ջ�ǿ�\n");
//	}

//	int x=3;
//	if(Push_LinkStack(top,x)){
//		printf("��ջ�ɹ�\n");
//	}
//	else{
//		printf("��ջʧ��\n");
//	}

	for(int i=0;i<5;i++){
		top = Push_LinkStack(top,i+1);
	}
//	Traverse(top);//5 4 3 2 1 
	
//	int x=3;
//	if(Pop_LinkStack(top,&x)){
//		printf("ɾ���ɹ� ��ɾ����Ԫ����%d",x);
//	}
//	else{
//		printf("ɾ��ʧ��");
//	}
	
	int y=4;
	top =  Pop_LinkStack(top,&y);
	Traverse(top);//4 3 2 1
	
	
	//����ջ��Ԫ�� 
	printf("\n%d",Top_LinkStack(top));
	return 0;
}
