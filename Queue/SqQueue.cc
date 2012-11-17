#include <iostream>
using namespace std;

typedef int QElemType;
const int MAXSIZE = 20;
typedef struct 
{
	QElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

bool initQueue(SqQueue *q)
{
	q->front = 0;
	q->rear = 0;
	return true;
}

int queueLength(SqQueue *q)
{
	return (q->rear-q->front+MAXSIZE)%MAXSIZE;
}

bool enQueue (SqQueue *q, QElemType e)
{
	if ((q->rear+1)%MAXSIZE == q->front)
		return false;
	q->data[q->rear] = e;
	q->rear = (q->rear+1)%MAXSIZE;
	return true;
}

bool deQueue (SqQueue *q, QElemType *e)
{
	if (q->front == q->rear)
		return false;
	*e = q->data[q->front];
	q->front = (q->front+1)%MAXSIZE;
	return true;
}

int main()
{
	SqQueue * q = new SqQueue();
	QElemType *e = new QElemType;
	initQueue(q);
	enQueue(q,1);
	enQueue(q,2);
	enQueue(q,3);
	enQueue(q,4);

	deQueue(q,e);
	deQueue(q,e);
	deQueue(q,e);
	deQueue(q,e);

	delete e;
	delete q;
}
