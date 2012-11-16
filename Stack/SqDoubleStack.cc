#include <iostream>
using namespace std;

const int MAXSIZE = 20;

typedef int SElemType;
typedef struct
{
	SElemType data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;

bool push (SqDoubleStack *S, SElemType e,int stackNumber)
{
	if (S->top1+1 == S->top2)
	{
		return false;
	}
	if(stackNumber == 1)
		S->data[++S->top1]=e;
	else if(stackNumber == 2)
		S->data[--S->top2]=e;

	return true;
}

bool pop (SqDoubleStack *S, SElemType *e, int stackNumber)
{
	if(stackNumber == 1)
	{
		if (S->top1 == -1)
			return false;
		*e = S->data[S->top1];
		S->top1--;
		return true;
	}
	else if(stackNumber == 2)
	{
		if (S->top2 == MAXSIZE)
			return false;
		*e = S->data[S->top2];
		S->top2++;
		return true;
	}
}
int main()
{
	SElemType *e;
	SqDoubleStack *myStack;
	myStack = new SqDoubleStack();
	myStack->top1=-1;
	myStack->top2=MAXSIZE;
	push(myStack,1,1);
	push(myStack,2,1);
	push(myStack,3,1);
	push(myStack,4,1);
	pop(myStack,e,1);
	pop(myStack,e,1);
	pop(myStack,e,1);
	
	delete myStack;
	return 0;
}
