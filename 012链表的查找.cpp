//����Ų���
//��ֵ���� 
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node*next;
}*LinkList,LNode;

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
	} //rָ����ſ�ָ�� 
}

//����Ų���       !!!!
	//�ҵ���i��Ԫ�ؽ��,������ָ��,���򷵻ؿ� 

LNode* get_LinkList1(LinkList L,int i)
{
	int j=0;
	LNode *p=L;       
	while(p->next && j<i){
		p=p->next;
		j++;
	} 
	if(j==i)
		return p;
	else
		return NULL;
}	
	//�Ż� 
LNode* get_LinkList2(LinkList L,int i)
{
	int j;
	LNode *p;       
	for(j=0,p=L;p->next&&j<i;p=p->next,j++);
	return p;
}
//��ֵ����
	//�������в���ֵΪx�Ľ��,�ҵ��󷵻���ָ��,���򷵻ؿ�
LNode *Locate_LinkList1(LinkList L,int x)
{
	LNode *p=L->next;
	while(p && p->data!=x){
		p=p->next;
	}
	return p;
}	
	//�Ż� 
LNode *Locate_LinkList2(LinkList L,int x)
{
	LNode *p;
	for(p=L;p->next&&p->data!=x;p=p->next);
	return p;
}
int main(void)
{
	int flag,i;
	LinkList L;
	LNode *p;
	printf("�������ʶ����\n");
	scanf("%d\n",&flag);
	printf("������i��\n");
	L=Create_LinkList2(flag);
	p = get_LinkList(L,i);
	printf("%d",p->data);
	return 0;
}
