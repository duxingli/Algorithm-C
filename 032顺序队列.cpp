#define MAXSIZE 6
#include <stdio.h>
#include <stdlib.h>
//循环队列 
typedef struct
{
	int data[MAXSIZE];
	int rear,front;
	int num; //循环队  计数 
}c_SeQueue; //circle:循环
//置空队列
c_SeQueue* Init_SeQueue()
{
	c_SeQueue *q;
	q=(c_SeQueue*)malloc(sizeof(c_SeQueue));
	q->front = q->rear = MAXSIZE-1;//下一位是0 
	q->num = 0;
	return q;
}
//判队列空
int Empty_SeQueue(c_SeQueue *q)
{
	if(q->num == 0)
		return 1;
	else
		return 0;
 } 
//队列判满
int Full_SeQueue(c_SeQueue *q)
{
	if(q->num == MAXSIZE)
		return 1;
	else
		return 0;
 } 
//入队列 判满 
int In_SeQueue(c_SeQueue*q,int x)
{
	//直接 num == MAXSIZE
	if(Full_SeQueue(q)){
		return 0;
	}
	else{
		//相当于rear++ 后移一位 
		q->rear = (q->rear+1)%MAXSIZE; 
		q->data[q->rear] = x;
		q->num++;
		return 1;
	}
}
//出队列 判空 
int Out_SeQueue(c_SeQueue *q,int *x)
{
	//可以直接num == 0
	if(Empty_SeQueue(q)){
		return 0;
	}
	else{
		*x = q->data[q->front];
		q->front = (q->front+1)%MAXSIZE;
		q->num--;
		return 1;
	}
}
void Traverse(c_SeQueue *q)
{
	//从头部开始遍历 
	for(int i=0;i<q->num;i++){
		q->front = (q->front+1)%MAXSIZE; 
		//(倒着遍历)  (q->front-1)%MAXSIZE
		printf("%d ",q->data[q->front]);
	}
}
int main(void)
{
	c_SeQueue *sq;

//	if(Init_SeQueue()){
//		printf("此栈初始化成功");
//	}
//	else{
//		printf("此栈未初始化");
//	} 
	sq=Init_SeQueue();
//	if(In_SeQueue(sq,1)){
//		printf("入栈成功");
//	}
//	else{
//		printf("入栈失败");
//	}
	In_SeQueue(sq,1);
	In_SeQueue(sq,2);
	In_SeQueue(sq,3);
	In_SeQueue(sq,4);
	In_SeQueue(sq,5);
	Traverse(sq);
	
	int val;
	if(Out_SeQueue(sq,&val)){
		printf("出栈成功，删除的元素是%d\n",val);
	}
	else{
		printf("出栈失败\n");
	}
	Traverse(sq);
//	1 2 3 4 5 出栈成功，删除的元素是5
//	1 2 3 4
	return 0;
}


//循环队列的讲解:
//1.静态队列为什么必须是循环队列
//2.循环队列需要几个参数来确定 
//	需要2个参数来确定front rear
//3.循环队列各个参数的含义
//	2个参数不同场合有不同的含义
//	建议初学者先记住，然后慢慢体会
//	1)队列初始化 
//		front和rear为0
//	2)队列非空 
//		front代表的是队列的第一个元素
//		rear代表的是队列的最后一个有效元素的下一个元素
//	3)队列空
//		front和rear的值相等，但不一定是零
//4.循环队列入队伪算法讲解
//	两步完成:
//	1.将值存入r所代表的位置
//	2.错误的写法rear=rear+1;  正确的写法是: rear = (rear+ 1) %数组的长
//
//5.循环队列出队伪算法讲解
//	front=(front+1) %数组的长度
//
//6.如何判断循环队列是否为空
//	如果front与rear 的值相等则该队列就一定为空
//
//7.如何判断循环队列是否已满
//	预备知识:
//	front的值可能比rear大,也完全有可能比rear小,当然也可能相等
//	两种方式:
//	1.多增加一个表标识参数
//	2.少用一个元素[通常使用第二种方式]
//		如果r和f的值紧挨着，则队列已满 
//		if ( (r+1)%数组长度==f )已满 //追尾
//		else不满
