//顺序表的查找： 
	//按值查找下标 
	//按位查找值 
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 6

typedef struct
{
	int data[MAXSIZE];
	int last;
 }SeqList;

//按值查找下标 
int Locate_List(SeqList*L,int x)
{
	int i;
	for(i=0;i<L->last+1 && L->data[i]!=x;i++);
	if(i>=L->last+1)
		return -1;
	else
		return i;
}
//按位查找值  1 <= i <= n 
int Get_List(SeqList*L,int i)
{
	if(i<1 || i>L->last+1)
		printf("该位置找不到！");
	return L->data[i-1]; 
}
int main(void)
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int i,x,n,index,value; 
	SeqList *L;
	L=(SeqList*)malloc(sizeof(SeqList));
	L->last=-1;
	printf("请输入顺序表元素个数n:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++,L->last++){
		L->data[i]=a[i];
	}
	printf("请输入:\n待查找的值x:\n待查找值的位置 i (1<=i<=n):\n");
	scanf("%d%d",&x,&i);
	index=Locate_List(L,x);
	printf("%d的下标是%d\n",x,index);
	value=Get_List(L,i);
	printf("第%d个值是%d\n",i,value);
	return 0;
}

//请输入顺序表元素个数n:
//7
//请输入:
//待查找的值x:
//待查找值的位置 i (1<=i<=n):
//4 6
//4的下标是3
//第6个值是6
