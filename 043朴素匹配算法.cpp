//����ģʽƥ���㷨���Ӵ���λ �� 
//������s
//�Ӵ���t ��t:ģʽ�� 
//��s��Ѱ��t�Ĺ��̳�Ϊģʽƥ��
//�����s���ҵ�����t���Ӵ���ƥ��ɹ�����������t��s�е��״γ��ֵĴ洢λ�ã���ţ� 
//����ƥ��ʧ�ܣ�����-1 
 
//ģʽƥ��-����ƥ���㷨(BF�㷨)
//1.�ڴ�S�ʹ�T����Ƚϵ���ʼ�±�i��j
//2.ѭ��ֱ��S��T�������ַ���δ�Ƚ���
//	���S[i]=T[j],�����Ƚ�S��T����һ���ַ�
//	���򣬽�i��j���ݣ�׼����һ�˱Ƚ�
//3.���T�������ַ����Ƚ��꣬��ƥ��ɹ�������
//ƥ�����ʼ�Ƚ��±�;����ƥ��ʧ�ܣ�����-1

#include <stdio.h>
#include <string.h>
int BF1(char *s,char *t)
{
	//������s[0] �洢���ַ����ĳ���   ���ַ������Ͳ�һ��??? 
	//��ij���ɵڼ���λ�� 
	int i=1,j=1;
	while(i<=s[0] && j<=t[0]){
		if(s[i] == t[j]){
			i++;
			j++;
		}
		else{
			// i-(j-1)+1 ��ʼ+1 
			i=i-j+2;
			j=1;
		}
	}
	if(j>t[0]) //���˳���+1 
		return(i-t[0]); //t[0] Ϊ�Ӵ����� 
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
		//i-j�ǿ�ʼλ��   i-j+1����һ��ƥ���λ�� 
	else
		return -1;
}
 
int main(void)
{
//	char s[255] = "ababcabcacbab";	
//	char t[255] = "abcac";

	//����BF1�����볤�� 
	char s[255];
	char t[255];
	int m,n;
	printf("��ֱ�����s��t�ĳ���:\n");
	scanf("%d %d",&m,&n);
	printf("������s�Ĵ���\n");
	for(int i=1;i<=m;i++){
		scanf("%c",&s[i]);
	} 
	s[0]=m;
	//��֤��ʵ���� ��s[0]+1 
	s[m+1] = '\0'; 
	printf("������t�Ĵ���\n");
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
