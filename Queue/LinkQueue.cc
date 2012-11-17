#include <iostream>
using namespace std;

typedef int QElemType;
//const int MAXSIZE = 20;
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front,rear;
}LinkQueue;

bool initQueue(LinkQueue *q)
{
	q->front = new QNode();
	q->rear = q->front;
	q->front->next = NULL;
	return true;
}

//int queueLength(LinkQueue *q)
//{
//	return (q->rear-q->front+MAXSIZE)%MAXSIZE;
//}

bool enQueue (LinkQueue *q, QElemType e)
{
	QueuePtr s = new QNode();
	s->data = e;
	s->next = NULL;
	q->rear->next = s;
	q->rear = s;
	return true;
}

bool deQueue (LinkQueue *q, QElemType *e)
{
	QueuePtr p;
	if (q->front == q->rear)
		return false;
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if(q->rear == p)
		q->rear = q->front;
	delete p;
	return true;
}

int main()
{
	LinkQueue * q = new LinkQueue();
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
