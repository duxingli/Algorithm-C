#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 6

typedef struct
{
	int data[MAXSIZE];
	int last;
 }SeqList;
 
//˳����ɾ��  ɾ����i��Ԫ�� 1 <= i <=n 
int Delete_SeqList(SeqList*L,int i)
{
	int j;
	if(i<1 || i>L->last+1){
		printf("�����ڵ�i��Ԫ��\n");
		return 0;
	}

//	for(j=i;j<=L->last;j++){
//		L->data[j-1] = L->data[j];
//	}
	for(j=i-1;j<L->last;j++){
		L->data[j] = L->data[j+1];
	} //�����ȽϺ���� 
	L->last--; 
	return 1;
}

void Print(SeqList*L)
{
	for(int i=0;i<L->last+1;i++){
		printf("%5d",L->data[i]); 
	}
}
int main(void)
{
	int i,n;
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	SeqList *L;
	L=(SeqList*)malloc(sizeof(SeqList));
	L->last=-1;
	printf("������n��i:(n<7)\n");
	scanf("%d%d",&n,&i);
	for(int i=0;i<n;i++,L->last++){
		L->data[i]=a[i];
	}
	Delete_SeqList(L,i);
	Print(L);
	return 0;
}

//������n��i:(n<7)
//6 4
//    1    2    3    5    6

//������n��i:(n<7)
//6 8
//�����ڵ�i��Ԫ��
//    1    2    3    4    5    6

//������n��i:(n<7)
//4 1
//    2    3    4

