//比较两个线性表的大小
//A B m n
//A' B' ms ns  A'分别是 B'中除去最大公共前缀后的子表 ms ms分别是A' B'的长度 
	//思路
	//先找出A，B的最大公共前缀，求出A' B'
	//A>B返回1	
			//	A'=空表 B'≠空表 
			//	两者均不为空 且 A'首元素小于 B'首元素 
	//A=B返回0	A'=B'=空表 
	//A<B返回-1 
#include <stdio.h>
#include <stdlib.h>
int compare(int A[],int B[],int m,int n)
{
	int i=0,j,AS[20],BS[20],ms=0,ns=0;
	while(A[i]==B[i]) i++;
	//AS[]：A剩余 
	for(j=i;j<m;j++){
		AS[j-i]=A[j];
		ms++;
	}
	//BS[]: B剩余 
	for(j=i;j<n;j++){
		BS[j-i]=B[j];
		ns++;
	}
	if(ms==0 && ns==0)
		return 0;
	else if(ms==0 && ns>0  ||  ms>0 &&ns>0 && AS[0]<BS[0])
		return -1; 
	else
		return 1; 
}
int main(void)
{
	int i,j,m,n,result;
	int A[20],B[20];
	printf("请输入AB表的长度m,n:\n");
	scanf("%d%d",&m,&n);
	printf("请输入A表：\n");
	for(i=0;i<m;i++){
		scanf("%d",&A[i]);
	}
	printf("请输入B表：\n"); 
	for(j=0;j<n;j++){
		scanf("%d",&B[j]);
	}
	result=compare(A,B,m,n);
	printf("*********** %d ***********",result); 
	return 0;
}
//请输入AB表的长度m,n:
//5 5
//请输入A表：
//1 2 3 4 5
//请输入B表：
//1 2 3 4 5
//*********** 0 ***********

//请输入AB表的长度m,n:
//5 5
//请输入A表：
//1 2 3 4 5
//请输入B表：
//1 2 3 4 6
//*********** -1 ***********

//请输入AB表的长度m,n:
//5 6
//请输入A表：
//1 2 3 4 5
//请输入B表：
//6 5 4 3 1 0
//*********** -1 ***********

//请输入AB表的长度m,n:
//5 5
//请输入A表：
//1 2 3 4 5
//请输入B表：
//1 2 3 4 0
//*********** 1 ***********
