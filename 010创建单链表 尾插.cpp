//β�� ������� ����ָ�� ��ͷָ�� βָ�룩 

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node*next;
 }LNode,*LinkList; 

//LinkList ��һ���ṹ��ָ�� 
LinkList Create_LinkList2(int flag)
{
	LinkList L;
	LNode *s,*r;
	//��ʼ ͷָ�롢βָ�� ����ֵ 
	L=r=NULL;
	int x;
	scanf("%d",&x);
	while(x != flag){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
//		s->next=NULL;//û�б�Ҫ 
		//ͷ�ڵ㴦�� 
		if(!L){
			L=s; 
		}
		//�����ڵ�Ĵ��� 
		else{
			//������β�������µĽڵ� 
			r->next=s;
		}
		//�ƶ�βָ�� 
		r=s; 
		scanf("%d",&x);
	} 
	//���ڷǿձ����ڵ��ָ����ſ�ָ�� 
	if(r!=NULL)
		r->next=NULL; 
	return L; 
}

void Print(LinkList l)
{
	LinkList p;
	for(p=l;p;p=p->next){
		printf("%d ",p->data);
	}
}
int main(void)
{
	int flag;
	LinkList l;
	printf("���������ֹͣ����� ��־����\n");
	scanf("%d\n",&flag);
	l=Create_LinkList2(flag);
	printf("�������\n");		
	Print(l);
	return 0;
}
//
//���������ֹͣ����� ��־����
//6
//1 2 3 4 5 6 7 8 9 0
//�������
//1 2 3 4 5
