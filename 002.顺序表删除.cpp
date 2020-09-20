#include <stdio.h>
#include <stdlib.h>
//#define MAXSIZE 6
const int MAXSIZE = 6;
//����˳��� SeqList L 
//���� (*L).last  ���� L->last+1
//�±꣺i-1  !!!    
//˳��ɾ  ������ 
typedef struct
{
	int data[MAXSIZE];
	int last;
 }SeqList;
 
//˳���ĳ�ʼ��
SeqList* init_SeqList()
{
	SeqList*L;
	L = (SeqList*)malloc(sizeof(SeqList));
	L ->last = -1;
	return L;
 }
  
//�������� �ڱ�ĵ�i��λ�ò���ֵΪx����Ԫ��   ��+1  
// 1 <= i <= n+1 
int Insert_SeqList(SeqList*L,int i, int x)
{
	int j;
	if(L->last == MAXSIZE-1){
		printf("����");
		return 0;
	} 
	if(i<1 || i>L->last+2){
		printf("λ�ô�");
		return 0;
	}
	//ѭ�����ƣ����ţ� ���� 
	for(j=L->last;j>=i-1;j--){ 
	//ֻ��ͨ��L->lastȷ��λ��  ��� n-1 ~ 0 
		L->data[j+1] = L->data[j];
	}
	L->data[i-1] = x; 
	L->last++; 
	return 1;		
 } 
void print(SeqList*L)
{
	for(int i=0; i<L->last+1; i++){
		printf("%5d ",L->data[i]);
	} 
}
int main(void)
{
	int x,i,n;//i  x ���ǲ�������� 
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	printf("����������n (n<7)�� i �� x: \n");					
	scanf("%d%d%d",&n,&i,&x);
	//˳���ĳ�ʼ�� 
	SeqList *L;
	L = (SeqList *)malloc(sizeof(SeqList));
	L->last = -1;
	//��˳���ֵn���� 
	for(int i=0; i < n;i++,L->last++){
		L->data[i] =a[i];
	} 
	if(Insert_SeqList(L,i,x))
		print(L);
	return 0;
}
//����������n (n<7)�� i �� x:
//5 6 0
//1     2     3     4     5     0
    
//7 0 1
//λ�ô�    
    
//6 6 0
//����

//1 1 0
//0     1
