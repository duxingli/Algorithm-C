#include <stdio.h>
#include <stdlib.h>
// nµÄ½×³Ë 
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
	printf("%dµÄ½×³ËÎª£º%d",x,fact(x));
	return 0;
}
