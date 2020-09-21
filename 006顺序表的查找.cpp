//˳���Ĳ��ң� 
	//��ֵ�����±� 
	//��λ����ֵ 
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 6

typedef struct
{
	int data[MAXSIZE];
	int last;
 }SeqList;

//��ֵ�����±� 
int Locate_List(SeqList*L,int x)
{
	int i;
	for(i=0;i<L->last+1 && L->data[i]!=x;i++);
	if(i>=L->last+1)
		return -1;
	else
		return i;
}
//��λ����ֵ  1 <= i <= n 
int Get_List(SeqList*L,int i)
{
	if(i<1 || i>L->last+1)
		printf("��λ���Ҳ�����");
	return L->data[i-1]; 
}
int main(void)
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int i,x,n,index,value; 
	SeqList *L;
	L=(SeqList*)malloc(sizeof(SeqList));
	L->last=-1;
	printf("������˳���Ԫ�ظ���n:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++,L->last++){
		L->data[i]=a[i];
	}
	printf("������:\n�����ҵ�ֵx:\n������ֵ��λ�� i (1<=i<=n):\n");
	scanf("%d%d",&x,&i);
	index=Locate_List(L,x);
	printf("%d���±���%d\n",x,index);
	value=Get_List(L,i);
	printf("��%d��ֵ��%d\n",i,value);
	return 0;
}

//������˳���Ԫ�ظ���n:
//7
//������:
//�����ҵ�ֵx:
//������ֵ��λ�� i (1<=i<=n):
//4 6
//4���±���3
//��6��ֵ��6
