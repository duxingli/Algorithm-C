//��˳���A��B����Ԫ�ؾ�����С������������У�
//�����Ǻϲ���һ��˳���C��Ҫ��C��Ԫ��Ҳ�Ǵ�С������������С�

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
typedef struct
{
	int data[MAXSIZE];
	int last;	
}SeqList; 

// SeqList*C    C->data[i]            SeqList C     C.data[i]
void merge(SeqList *A,SeqList *B,SeqList*C)
{
	int i,j,k;
	i=j=k=0;
	while(i<A->last+1 && j<B->last+1)
		if(A->data[i] < B->data[j])
			C->data[k++]=A->data[i++];
		else
			C->data[k++]=B->data[j++];
		while(i<A->last+1)
			C->data[k++]=A->data[i++];
		while(j<B->last+1)
			C->data[k++]=B->data[j++];
			//kָ��C�������ݵ���һ����λ 
		C->last=k-1; 
		//ʹkָ�����һ�����ݵ� 
}
void Print(SeqList*L)
{
	for(int i=0;i<L->last+1;i++){
		printf("%5d",L->data[i]); 
	}
}
int main(void)
{
	SeqList *A,*B,*C;
	int m,n,i,j;
	int a[20]={1,3,5,7,9,11,13,15,17,19,
				2,4,6,8,10,12,14,16,18,20};
	A=(SeqList*)malloc(sizeof(SeqList));
	B=(SeqList*)malloc(sizeof(SeqList));
	C=(SeqList*)malloc(sizeof(SeqList));
	A->last=-1;
	B->last=-1;
	C->last=-1;
	printf("��ֱ�����A��B�ĳ���m��n��(������10):\n");
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++,A->last++){
		A->data[i] = a[i]; 
	}
	printf("\n");
	for(j=0;j<n;j++,B->last++){
		B->data[j] = a[j+10];
	}
	merge(A,B,C);
	Print(C);
	return 0;
}

//��ֱ�����A��B�ĳ���m��n��(������10):
//7 7
//
//    1    2    3    4    5    6    7    8    9   10   11   12   13   14
