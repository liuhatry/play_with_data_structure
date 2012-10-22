#include <iostream>
using namespace std;

#define MAXSIZE 20
typedef int ElemType;

typedef struct 
{
	ElemType data[MAXSIZE];
	int length;
}SqList;
typedef SqList * PList;

PList initList()
{
	PList l = new SqList();
	l->length = 0;
	return l;
}

int listLength(PList l)
{
	return l->length;
}

bool getElem(PList l, int i, ElemType *e)
{
	if (l->length == 0 || i < 1 || i > l->length)
		return false;
	*e = l->data[i-1];
	return true;
}

bool listInsert (PList l, int i, ElemType e)
{
	if (l->length == MAXSIZE)
		return false;
	if (i<1 || i>(l->length+1))
		return false;
	if (i<=l->length)
	{
		for (int k = l->length-1; k>=i-1; k--){
			l->data[k+1] = l->data[k];
		}
	}

	l->data[i-1] = e;
	l->length++;
	return true;
}

bool listDelete (PList l, int i, ElemType *e)
{
	if (l->length == 0)
		return false;
	if (i<1 || i>(l->length))
		return false;
	*e = l->data[i-1];

	if (i<l->length)
	{
		for ( int k = i; k<l->length;k++)
			l->data[k-1] = l->data[k];
	}

	l->length--;
	return true;
}

bool locateElem(PList l, ElemType e)
{
	for (int i=1; i<=listLength(l); i++)
	{
		if (l->data[i-1] == e)
			return true;
	}
	return false;
}
void unionL (PList la, PList lb)
{
	ElemType e;

	int La_len = listLength(la);
	int Lb_len = listLength(lb);

	for ( int i=1; i<=Lb_len; i++)
	{
		getElem (lb, i, &e);
		if (!locateElem(la, e))
			listInsert(la,++La_len, e);
	}
}

int main(){
	ElemType e;
	PList l = initList();
	for ( int i=0; i<10; i++)
	{
		e = i;
		listInsert(l,i+1,e);
	}
	PList lb = initList();
	for ( int i=10; i<20; i++)
	{
		e = i;
		listInsert(lb,i-10+1,e);
	}
	unionL (l, lb);
	listDelete(l,10,&e);
	listInsert(l,10,e);
	return 0;
}
