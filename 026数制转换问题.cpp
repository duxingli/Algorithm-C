//用顺序栈实现 
#include <stdio.h>
#include <stdlib.h>
#define L 10 

void conversion(int n,int r)
{
	int s[L],top=-1;
	int x;
	while(n){
		s[++top] = n%r;
		n/=r;
	}
	while(top!=-1){
		x=s[top--];
		printf("%d",x);
	}
}
int main(void)
{
	//n是输入的十进制数 r是进制数 
	int n,r;
	scanf("%d%d",&n,&r);
	conversion(n,r); 
	return 0;
 } 
 
 
//23425 8
//55601
