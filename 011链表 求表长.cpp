//ͷָ�룺ͨ��ʹ�á�ͷָ�롱����ʶһ�������絥����L��ͷָ��ΪNULL��ʱ��ʾһ��������
//ͷ��㣺�ڵ�����ĵ�һ�����֮ǰ����һ����㣬��Ϊͷ��㡣
		//ͷ����Data����Բ����κ���Ϣ��Ҳ���Լ�¼���������Ϣ��
//[ע��]�������Ƿ���ͷ��㣬ͷָ��ʼ��ָ������ĵ�һ����㡣�����ͷ��㣬ͷָ���ָ��ͷ��㡣


//�Ǵ�ͷ���ʱ�����Ƿ�Ϊ�ձ�ͷָ���ֵ������仯����ָ��ͷ��㡣
//������ͷ�������Ҫ���ݲ�ͬ������޸�ͷָ���ֵ��
//���Ծ�����ʱ��ʹ�ô�ͷ���ķ�ʽ��Ϊ���㡣

//����ͷ��������
//1��λ�õĲ���ɾ�����ӷ���
	//	��ʹ��ͷ��㣬���1��λ�õĲ����ɾ�����Ƕ�p��>next���в����������ö�p����
//ͳһ�ձ�ͷǿձ�Ĵ���
	//	��ʹ��ͷ��㣬���۱��Ƿ�Ϊ�գ�ͷָ�붼ָ��ͷ��㣬Ҳ����*LNode���ͣ����ڿձ�ͷǿձ�Ĳ�����һ�µġ�
	//	����ʹ��ͷ��㣬����ǿ�ʱ��ͷָ��ָ���1�����ĵ�ַ����*LNode���ͣ�
	//	���Ƕ��ڿձ�ͷָ��ָ�����NULL����ʱ�ձ�ͷǿձ�Ĳ����ǲ�һ�µġ�

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}*LinkList,LNode;
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
	}
	return L;
	
}
LinkList Create_LinkList2(int flag) 
{
	LinkList L=NULL;
	LNode *s,*r=NULL;
	int x;
	scanf("%d",&x);
	while (x!=flag){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		if(!L){
			L=s;
		}
		else{
			r->next=s;
		}
		r=s;
		scanf("%d",&x);
	}
	if(r!=NULL)
		r->next=NULL;
	return L;
}

//��L�Ǵ�ͷ���ĵ�����
//��ʱͷָ��ָ��ͷ���
//h->headnode->a1->a2->a3->�������������� 
// ͷָ���ŵ���ͷ���ĵ�ַ��Ҳ����˵��*h����ʾ����ͷ���
int length_LinkList1(LinkList L)
{
	LNode *p=L;
	int j = 0;
	while(p->next){
		p=p->next;
		j++;
	}
	return j;
}
//�Ż����� 
int length_LinkList11(LinkList L)
{
	LNode *p;
	int j;
	for(j=-1,p=L;p;p=p->next,j++);
	return j;
}

//��L�ǲ���ͷ���ĵ����� 
//h->a1->a2->a3->��������������������������
// ͷָ���ŵ��ǵ�һ���ڵ�ĵ�ַ����h��Ҳ����˵��*h����ʾ���ǵ�һ���ڵ�
int length_LinkList2(LinkList L)
{
	LNode *p=L;
	int j;
	if(p==NULL)
		return 0;
	j=1;
	while(p->next){
		p=p->next;
		j++;
	}
	return j;
}
//�Ż����� 
int length_LinkList22(LinkList L)
{
	LNode *p;
	int j;
	for(j=0,p=L;p;p=p->next,j++);
	return j; 
}
int main(void)
{
	LinkList l;
	int flag,length;
	printf("������ ��ͣ��ʶ����");
	scanf("%d\n",&flag);
	l=Create_LinkList2(flag);
//	length = length_LinkList1(l);
	length = length_LinkList2(l);
	printf("������Ϊ��%d",length);
	return 0;
}
//result:
//������ ��ͣ��ʶ����6
//1 2 3 4 5 6
//������Ϊ��5


//Create_Link2
//length_LinkList1(l)
//������ ��ͣ��ʶ����6
//1 2 3 4 5 6
//������Ϊ��4
//length_LinkList2(l)
//������ ��ͣ��ʶ����6
//1 2 3 4 5 6
//������Ϊ��5

//Create_LinkList1(flag)
//length_LinkList1(l)
//������ ��ͣ��ʶ����6
//1 2 3 4 5 6 
//������Ϊ��4
//length_LinkList2(l)
//������ ��ͣ��ʶ����6
//1 2 3 4 5 6
//������Ϊ��5

//�������ִ������� ͷ�塢β�嶼�ǲ���ͷ�ڵ�ģ�ͷָ��ֱ�ӷŵ��˵�һ���ڵ��ϡ� 
