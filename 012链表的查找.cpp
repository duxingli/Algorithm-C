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
	printf("��������������ݣ�\n");
	scanf("%d",&x);
	printf("�������û�н��\n"); 
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
	return L;
}

//����Ų���       !!!!
	//�ҵ���i��Ԫ�ؽ��,������ָ��,���򷵻ؿ� 

LNode* get_LinkList1(LinkList L,int i)
{
	LNode *p=L;
	int j=0;
	while(p->next!=NULL && j<i){
		//Ӧ���� i �����ڴ�������ʱ ѭ�������scanf("x")��û�н��� ����һ����� 
		//�����Ӿ����ǵ�i+1�����    
		//���Ե�һ���������� �س�һ�� 
		p=p->next;
		j++;
	}
	if(j==i){
		return p;
	}
	else{
		return NULL;
	} 
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
	while(p!=NULL && p->data!=x){
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
	int flag,i,x;
	LinkList L;
	LNode *p;
	printf("�������ʶ����\n");
	scanf("%d",&flag);
//	printf("������i��\n");
//	scanf("%d",&i);
	printf("������x:\n");
	scanf("%d",&x);
	L=Create_LinkList2(flag);
	
//	p = get_LinkList1(L,i);
//	p = get_LinkList2(L,i);
//	printf("���ҵ���ֵΪ��%d",p->data);

//	p = Locate_LinkList1(L,x);
	p = Locate_LinkList2(L,x);
	printf("���ҵ���ֵΪ��%d",p->data);
	return 0;
}

//get_LinkList
//�������ʶ����
//6
//������i��
//3
//��������������ݣ�
//1
//�������û�н��
//2 3 4 5 6 7 8
//���ҵ���ֵΪ��4


//Locate_LinkList
//�������ʶ����
//6
//������x:
//3
//��������������ݣ�
//1
//�������û�н��
//2 3 4 5 6
//���ҵ���ֵΪ��3


