//有顺序表A和B，其元素均按从小到大的升序排列，
//将它们合并成一个顺序表C，要求C的元素也是从小到大的升序排列。

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
			//k指向C所有数据的下一个空位 
		C->last=k-1; 
		//使k指向最后一个数据的 
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
	printf("请分别输入A、B的长度m、n：(不超过10):\n");
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

//请分别输入A、B的长度m、n：(不超过10):
//7 7
//
//    1    2    3    4    5    6    7    8    9   10   11   12   13   14
