#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 6

typedef struct
{
	int data[MAXSIZE];
	int last;
 }SeqList;
 
//顺序表的删除  删除第i个元素 1 <= i <=n 
int Delete_SeqList(SeqList*L,int i)
{
	int j;
	if(i<1 || i>L->last+1){
		printf("不存在第i个元素\n");
		return 0;
	}

//	for(j=i;j<=L->last;j++){
//		L->data[j-1] = L->data[j];
//	}
	for(j=i-1;j<L->last;j++){
		L->data[j] = L->data[j+1];
	} //这样比较好理解 
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
	printf("请输入n、i:(n<7)\n");
	scanf("%d%d",&n,&i);
	for(int i=0;i<n;i++,L->last++){
		L->data[i]=a[i];
	}
	Delete_SeqList(L,i);
	Print(L);
	return 0;
}

//请输入n、i:(n<7)
//6 4
//    1    2    3    5    6

//请输入n、i:(n<7)
//6 8
//不存在第i个元素
//    1    2    3    4    5    6

//请输入n、i:(n<7)
//4 1
//    2    3    4

