//����ʽջʵ��  ճ�� 025 
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
		
		p=top->next;
		free(top);
		top=p; 

//		p=top;
//		top=top->next;
//		free(p);
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
	//n�������ʮ������ r�ǽ����� 
	int n,r;
	scanf("%d%d",&n,&r);
	conversion(n,r); 
	return 0;
 } 
 
//555555 8
//2075043


