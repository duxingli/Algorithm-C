//����Ĳ��� 
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
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
			r->next = s;
		}
		r=s;
		scanf("%d",&x);
	}
	if(r!=NULL){
		r->next =NULL;
		//rָ����ſ�ָ�� 
	}
	return L;
}

//����Ų���       !!!!
	//�ҵ���i��Ԫ�ؽ��,������ָ��,���򷵻ؿ� 
	
	//�Ż��� 
LNode* get_LinkList2(LinkList L,int i)
{
	int j;
	LNode *p;
	//j=1��������
	for(j=1,p=L;p->next&&j<i;p=p->next,j++);
	return p; 
}

//���  ֱ�Ӳ� 
//ǰ�� 	��ǰ���ڵ�

//�ڵ�����L�ĵ�i��λ���ϲ���ֵΪx��Ԫ��  �ɹ�����1 ʧ�ܷ���0
//������  ǰ�� 
int Insert_LinkList(LinkList L,int i,int x)
{
	LNode *p,*s;
	p=get_LinkList2(L, i-1);
	if(!p){
		printf("����i��\n");
		return 0;
	} 
	else{
		s=(LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = p->next; //�����Ӻ��棬��ǰ�� 
		p->next = s;
		return 1; 
	}
 } 
 
void PrintLink(LinkList L)
{
	LNode* p;
	for(p=L;p;p=p->next){
		printf("%d ",p->data);
	}
}

int main(void)
{
	int flag,i,x;
	int result;
	LinkList L;
	LNode *p;
	printf("�������־����\n");
	scanf("%d",&flag);
	printf("������i��x��\n");
	scanf("%d%d",&i,&x);
	printf("��������������ݣ�\n");
	L=Create_LinkList2(flag);
	result = Insert_LinkList(L,i,x);
	printf("result = %d\n",result);
	PrintLink(L);
	return 0;
}


//�������־����
//6
//������i��x��
//2 3
//��������������ݣ�    (����������û�� ���� ��־��6��)
//0 9 8 7 4 3 6
//result = 1
//0 3 9 8 7 4 3


//bug �޷������־��   ������������� 
 
//�������־����
//5
//������i��x��
//3 6
//��������������ݣ�
//1 2 3 4 5 6
//result = 1
//1 2 6 3 4
