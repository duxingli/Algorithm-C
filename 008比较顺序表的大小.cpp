//�Ƚ��������Ա�Ĵ�С
//A B m n
//A' B' ms ns  A'�ֱ��� B'�г�ȥ��󹫹�ǰ׺����ӱ� ms ms�ֱ���A' B'�ĳ��� 
	//˼·
	//���ҳ�A��B����󹫹�ǰ׺�����A' B'
	//A>B����1	
			//	A'=�ձ� B'�ٿձ� 
			//	���߾���Ϊ�� �� A'��Ԫ��С�� B'��Ԫ�� 
	//A=B����0	A'=B'=�ձ� 
	//A<B����-1 
#include <stdio.h>
#include <stdlib.h>
int compare(int A[],int B[],int m,int n)
{
	int i=0,j,AS[20],BS[20],ms=0,ns=0;
	while(A[i]==B[i]) i++;
	//AS[]��Aʣ�� 
	for(j=i;j<m;j++){
		AS[j-i]=A[j];
		ms++;
	}
	//BS[]: Bʣ�� 
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
	printf("������AB��ĳ���m,n:\n");
	scanf("%d%d",&m,&n);
	printf("������A��\n");
	for(i=0;i<m;i++){
		scanf("%d",&A[i]);
	}
	printf("������B��\n"); 
	for(j=0;j<n;j++){
		scanf("%d",&B[j]);
	}
	result=compare(A,B,m,n);
	printf("*********** %d ***********",result); 
	return 0;
}
//������AB��ĳ���m,n:
//5 5
//������A��
//1 2 3 4 5
//������B��
//1 2 3 4 5
//*********** 0 ***********

//������AB��ĳ���m,n:
//5 5
//������A��
//1 2 3 4 5
//������B��
//1 2 3 4 6
//*********** -1 ***********

//������AB��ĳ���m,n:
//5 6
//������A��
//1 2 3 4 5
//������B��
//6 5 4 3 1 0
//*********** -1 ***********

//������AB��ĳ���m,n:
//5 5
//������A��
//1 2 3 4 5
//������B��
//1 2 3 4 0
//*********** 1 ***********
