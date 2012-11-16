#include <iostream>
using namespace std;

//const int MAXSIZE = 20;

typedef int SElemType;
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
}LinkStack;

bool push (LinkStack *S, SElemType e)
{
	LinkStackPtr s = new StackNode();
	s->data = e;
	s->next=S->top;
	S->top=s;
	S->count++;
	return true;
}

bool pop (LinkStack *S, SElemType *e)
{
	LinkStackPtr p;
	if (S->count == 0)
		return false;
	*e = S->top->data;
	p = S->top;
	S->top = S->top->next;
	delete p;
	S->count--;
	return true;
}

int main()
{
	SElemType *e = new SElemType();
	LinkStack *myStack;
	myStack = new LinkStack();
	myStack->count=0;
	push(myStack,1);
	push(myStack,2);
	push(myStack,3);
	push(myStack,4);
	pop(myStack,e);
	pop(myStack,e);
	pop(myStack,e);
	
	delete myStack;
	delete e;
	return 0;
}
