#define MAXSIZE 6
#include <stdio.h>
#include <stdlib.h>
//ѭ������ 
typedef struct
{
	int data[MAXSIZE];
	int rear,front;
	int num; //ѭ����  ���� 
}c_SeQueue; //circle:ѭ��
//�ÿն���
c_SeQueue* Init_SeQueue()
{
	c_SeQueue *q;
	q=(c_SeQueue*)malloc(sizeof(c_SeQueue));
	q->front = q->rear = MAXSIZE-1;//��һλ��0 
	q->num = 0;
	return q;
}
//�ж��п�
int Empty_SeQueue(c_SeQueue *q)
{
	if(q->num == 0)
		return 1;
	else
		return 0;
 } 
//��������
int Full_SeQueue(c_SeQueue *q)
{
	if(q->num == MAXSIZE)
		return 1;
	else
		return 0;
 } 
//����� ���� 
int In_SeQueue(c_SeQueue*q,int x)
{
	//ֱ�� num == MAXSIZE
	if(Full_SeQueue(q)){
		return 0;
	}
	else{
		//�൱��rear++ ����һλ 
		q->rear = (q->rear+1)%MAXSIZE; 
		q->data[q->rear] = x;
		q->num++;
		return 1;
	}
}
//������ �п� 
int Out_SeQueue(c_SeQueue *q,int *x)
{
	//����ֱ��num == 0
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
	//��ͷ����ʼ���� 
	for(int i=0;i<q->num;i++){
		q->front = (q->front+1)%MAXSIZE; 
		//(���ű���)  (q->front-1)%MAXSIZE
		printf("%d ",q->data[q->front]);
	}
}
int main(void)
{
	c_SeQueue *sq;

//	if(Init_SeQueue()){
//		printf("��ջ��ʼ���ɹ�");
//	}
//	else{
//		printf("��ջδ��ʼ��");
//	} 
	sq=Init_SeQueue();
//	if(In_SeQueue(sq,1)){
//		printf("��ջ�ɹ�");
//	}
//	else{
//		printf("��ջʧ��");
//	}
	In_SeQueue(sq,1);
	In_SeQueue(sq,2);
	In_SeQueue(sq,3);
	In_SeQueue(sq,4);
	In_SeQueue(sq,5);
	Traverse(sq);
	
	int val;
	if(Out_SeQueue(sq,&val)){
		printf("��ջ�ɹ���ɾ����Ԫ����%d\n",val);
	}
	else{
		printf("��ջʧ��\n");
	}
	Traverse(sq);
//	1 2 3 4 5 ��ջ�ɹ���ɾ����Ԫ����5
//	1 2 3 4
	return 0;
}


//ѭ�����еĽ���:
//1.��̬����Ϊʲô������ѭ������
//2.ѭ��������Ҫ����������ȷ�� 
//	��Ҫ2��������ȷ��front rear
//3.ѭ�����и��������ĺ���
//	2��������ͬ�����в�ͬ�ĺ���
//	�����ѧ���ȼ�ס��Ȼ���������
//	1)���г�ʼ�� 
//		front��rearΪ0
//	2)���зǿ� 
//		front������Ƕ��еĵ�һ��Ԫ��
//		rear������Ƕ��е����һ����ЧԪ�ص���һ��Ԫ��
//	3)���п�
//		front��rear��ֵ��ȣ�����һ������
//4.ѭ���������α�㷨����
//	�������:
//	1.��ֵ����r�������λ��
//	2.�����д��rear=rear+1;  ��ȷ��д����: rear = (rear+ 1) %����ĳ�
//
//5.ѭ�����г���α�㷨����
//	front=(front+1) %����ĳ���
//
//6.����ж�ѭ�������Ƿ�Ϊ��
//	���front��rear ��ֵ�����ö��о�һ��Ϊ��
//
//7.����ж�ѭ�������Ƿ�����
//	Ԥ��֪ʶ:
//	front��ֵ���ܱ�rear��,Ҳ��ȫ�п��ܱ�rearС,��ȻҲ�������
//	���ַ�ʽ:
//	1.������һ�����ʶ����
//	2.����һ��Ԫ��[ͨ��ʹ�õڶ��ַ�ʽ]
//		���r��f��ֵ�����ţ���������� 
//		if ( (r+1)%���鳤��==f )���� //׷β
//		else����
