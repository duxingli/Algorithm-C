#include <stdio.h>
#include <stdlib.h>
// n�Ľ׳� 
int fact(int n)
{
	if(n==0)
		return 1;
	else
		return (n*fact(n-1));
 } 
int main(void)
{
	int x;
	scanf("%d",&x);
	printf("%d�Ľ׳�Ϊ��%d",x,fact(x));
	return 0;
}
