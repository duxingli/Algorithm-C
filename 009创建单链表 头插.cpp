//ͷ�� ������� һ��ָ�� ��ͷָ�룩 

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node*next;
}LNode,*LinkList;

//ȫ�ֱ������������޷����ض��ֵ 
int count=1;

//����һ��ָ������ 
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
		count++;	
	}
	return L;
	
}
void Print (LinkList p,int n) 
{
	//ͷ��ֻ�� �������
	for(int i=0;i<n;p=p->next){
		printf("%d ",p->data);
	}
}
int main(void)
{
	int flag;
	LinkList l;
	printf("���������ֹͣ����� ��־����\n");
	scanf("%d\n",&flag);
	l=Create_LinkList1(flag);
	printf("�������\n");		
	Print(l,count);		
	return 0;
 } 

//��־�� ����� 

//���������ֹͣ����� ��־����
//0
//1 2 3 4 5 6 7 8 9 0
//�������
//9 8 7 6 5 4 3 2 1
