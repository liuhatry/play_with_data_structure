#include <iostream>
using namespace std;

const int MAXSIZE = 20;

typedef int SElemType;
typedef struct
{
	SElemType data[MAXSIZE];
	int top;
}SqStack;

bool push (SqStack *S, SElemType e)
{
	if (S->top == MAXSIZE-1)
	{
		return false;
	}
	S->top++;
	S->data[S->top]=e;
	return true;
}

bool pop (SqStack *S, SElemType *e)
{
	if (S->top == -1)
		return false;
	*e = S->data[S->top];
	S->top--;
	return true;
}

int main()
{
	SElemType *e;
	SqStack *myStack;
	myStack = new SqStack();
	myStack->top=-1;
	push(myStack,1);
	push(myStack,2);
	push(myStack,3);
	push(myStack,4);
	pop(myStack,e);
	pop(myStack,e);
	pop(myStack,e);
	
	delete myStack;
	return 0;
}
