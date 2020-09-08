#include <stdio.h>
#define n 3
void MatrixMultiply(int A[n][n], int B[n][n], int C[n][n])
{
	int i, j, k;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			C[i][j] = 0;
			for(k=0; k<n; k++){
				C[i][j] = C[i][j] + A[i][k] * B[k][j]; 
			}
		}
	}
}
void Print(int X[n][n])
{
	printf("C = A x B��ֵΪ��\n");
	int i,j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%5d",X[i][j]);
		}
		printf("\n");
	}
}
int main(void)
{
	int A[n][n],B[n][n],C[n][n];
	printf("������A����\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d",&A[i][j]);
		}
	}
	printf("������B����\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d",&B[i][j]);
		}
	}
	MatrixMultiply(A, B, C);
	Print(C);
	return 0;
}

//������A����
//1 2 3
//2 3 1
//4 3 1
//������B����
//4 6 7
//5 3 2
//3 1 9
//C = A x B��ֵΪ��
//   23   15   38
//   26   22   29
//   34   34   43
