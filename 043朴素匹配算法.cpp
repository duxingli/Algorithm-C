//串的模式匹配算法（子串定位 ） 
//主串：s
//子串：t （t:模式） 
//在s中寻找t的过程称为模式匹配
//如果在s中找到等于t的子串，匹配成功，函数返回t在s中的首次出现的存储位置（序号） 
//否则匹配失败，返回-1 
 
//模式匹配-朴素匹配算法(BF算法)
//1.在串S和串T中设比较的起始下标i和j
//2.循环直到S或T的所有字符均未比较完
//	如果S[i]=T[j],继续比较S和T的下一个字符
//	否则，将i和j回溯，准备下一趟比较
//3.如果T中所有字符均比较完，则匹配成功，返回
//匹配的起始比较下标;否则，匹配失败，返回-1

#include <stdio.h>
#include <string.h>
int BF1(char *s,char *t)
{
	//这里用s[0] 存储了字符串的长度   与字符串类型不一致??? 
	//把ij看成第几个位置 
	int i=1,j=1;
	while(i<=s[0] && j<=t[0]){
		if(s[i] == t[j]){
			i++;
			j++;
		}
		else{
			// i-(j-1)+1 起始+1 
			i=i-j+2;
			j=1;
		}
	}
	if(j>t[0]) //到了长度+1 
		return(i-t[0]); //t[0] 为子串长度 
	else
		return (-1);
}
int BF2(char *s,char *t)
{
	int i,j,start;
	i=j=start=0;
	while(s[i] && t[j]){
		if(s[i] == t[j]){
			i++;
			j++;
		}
		else{
			start++;
			i=start;
			j=0;
		}
	}
	if(t[j] == '\0')
		return start;
	else
		return -1;
}

int BF3(char *s,char *t)
{
	int i,j;
	i=j=0;
	while(s[i] && t[j]){
		if(s[i] == t[j]){
			i++;
			j++;
		}
		else{
			i=i-j+1;
			j=0;
		}
	}
	if(t[j] == '\0')
		return i-j;
		//i-j是开始位置   i-j+1是下一次匹配的位置 
	else
		return -1;
}
 
int main(void)
{
//	char s[255] = "ababcabcacbab";	
//	char t[255] = "abcac";

	//测试BF1先输入长度 
	char s[255];
	char t[255];
	int m,n;
	printf("请分别输入s和t的长度:\n");
	scanf("%d %d",&m,&n);
	printf("请输入s的串：\n");
	for(int i=1;i<=m;i++){
		scanf("%c",&s[i]);
	} 
	s[0]=m;
	//保证真实长度 ：s[0]+1 
	s[m+1] = '\0'; 
	printf("请输入t的串：\n");
	for(int i=1;i<=n;i++){
		scanf("%c",&t[i]);
	}
	t[0]=n;
	t[n+1] = '\0';
	int idx;
	idx = BF1(s,t);
	printf("%d",idx);
	return 0;
}
