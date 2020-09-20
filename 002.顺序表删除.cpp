#include <stdio.h>
#include <stdlib.h>
//#define MAXSIZE 6
const int MAXSIZE = 6;
//定义顺序表 SeqList L 
//表长： (*L).last  或者 L->last+1
//下标：i-1  !!!    
//顺着删  倒着添 
typedef struct
{
	int data[MAXSIZE];
	int last;
 }SeqList;
 
//顺序表的初始化
SeqList* init_SeqList()
{
	SeqList*L;
	L = (SeqList*)malloc(sizeof(SeqList));
	L ->last = -1;
	return L;
 }
  
//插入运算 在表的第i个位置插入值为x的新元素   表长+1  
// 1 <= i <= n+1 
int Insert_SeqList(SeqList*L,int i, int x)
{
	int j;
	if(L->last == MAXSIZE-1){
		printf("表满");
		return 0;
	} 
	if(i<1 || i>L->last+2){
		printf("位置错");
		return 0;
	}
	//循环右移（倒着） 插入 
	for(j=L->last;j>=i-1;j--){ 
	//只能通过L->last确定位置  最长从 n-1 ~ 0 
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
	int x,i,n;//i  x 都是插入的数据 
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	printf("请依次输入n (n<7)、 i 、 x: \n");					
	scanf("%d%d%d",&n,&i,&x);
	//顺序表的初始化 
	SeqList *L;
	L = (SeqList *)malloc(sizeof(SeqList));
	L->last = -1;
	//给顺序表赋值n个数 
	for(int i=0; i < n;i++,L->last++){
		L->data[i] =a[i];
	} 
	if(Insert_SeqList(L,i,x))
		print(L);
	return 0;
}
//请依次输入n (n<7)、 i 、 x:
//5 6 0
//1     2     3     4     5     0
    
//7 0 1
//位置错    
    
//6 6 0
//表满

//1 1 0
//0     1
