//����Ų���
//��ֵ���� 
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node*next;
}*LinkList,LNode;

//*pָ�����ֱ��ʹ��  *s�ǽڵ��Ҫmalloc����ռ� 

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
	return L;
}

//����Ų���       !!!!
	//�ҵ���i��Ԫ�ؽ��,������ָ��,���򷵻ؿ� 
	
	//�Ż� 
LNode* get_LinkList2(LinkList L,int i)
{
	int j;
	LNode *p; //j=1�ſ���  �α���j=0       ???????????/
	for(j=1,p=L;p->next&&j<i;p=p->next,j++);
	return p;
}

//ɾ��������L�ϵĵ�i�����ݽ�� 
//�ɹ����� 1 ǰ����㲻���ڷ��� -1  ǰ�������ڵ��Ǵ�ɾ��㲻���ڷ��� 0 
int Del_LinkList(LinkList L,int i)
{
	LinkList p,s;
	//�ҵ�ǰһ����� 
	p=get_LinkList2(L,i-1);
	if(!p){
		printf("��i-1����㲻����\n"); 
		return -1;
	}
	else{
		if(p->next == NULL){
			printf("��i����㲻����,����ɾ\n");
			return 0;
		}
		else{
//			p->next=p->next->next;
//			free(s);
			
			//�� s �洢��ɾ��� 
			s=p->next;
			p->next=s->next;
			free(s);
			return 1; 
		}
	}
}

void PrintLink(LinkList L)
{
	LinkList p;
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
	printf("�������ʶ����\n");
	scanf("%d",&flag);
	printf("�������ɾ���i��\n");
	scanf("%d",&i);
	printf("��������������ݣ�\n");
	L=Create_LinkList2(flag);
	result=Del_LinkList(L,i);
	printf("result = %d\n",result);
	PrintLink(L);
	return 0;
}

//�������ʶ����
//6
//�������ɾ���i��
//3
//��������������ݣ�
//1 2 3 4 5 6 (���һ����㲻����)
//result = 1
//1 2 4 5


