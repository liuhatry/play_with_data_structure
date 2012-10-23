#include <iostream>
#include <malloc.h>
using namespace std;

typedef int ElemType;

typedef struct Node 
{
	ElemType data;
	struct Node * next;
}Node;
typedef Node * LinkList;

//LinkList initList()
//{
//	LinkList l = new SqList();
//	l->length = 0;
//	return l;
//}
//
//int listLength(LinkList l)
//{
//	return l->length;
//}
void createListHead(LinkList *l, int n)
{
	LinkList p;
	*l = (LinkList)malloc(sizeof(Node));
	(*l)->next = NULL;
	for (int i=0;i<n;i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = i;
		p->next = (*l)->next;
		(*l)->next = p;
	}
}

void createListTail(LinkList l, int n)
{
	LinkList p,temp;
	l = (LinkList)malloc(sizeof(Node));
	temp = l;
	for (int i=0;i<n;i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = i;
		temp->next =p;
		temp = p;
	}
	temp->next = NULL;
}
bool getElem(LinkList l, int i, ElemType *e)
{
	LinkList p = l->next;
	for(int j=1;j<i,p!=NULL;j++)
	{
		p = p->next;
	}
	if (!p)
		return false;
	*e = p->data;
	return true;
}

bool listInsert (LinkList *l, int i, ElemType e)
{
	LinkList p = *l;
	for (int j=1;j<i&&p!=NULL;j++)
	{
		p = p->next;
	}

	if(!p)
		return false;
	LinkList s = (LinkList)malloc (sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool listDelete (LinkList *l, int i, ElemType *e)
{
	LinkList p = *l;
	LinkList q;
	for (int j=1;j<i&&p!=NULL;j++)
	{
		p = p->next;
	}
	if (!(p->next))
		return false;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return true;
}

bool clearList(LinkList l)
{
	LinkList p =l->next;
	LinkList q;
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	l->next = NULL;
	return true;
}

void displayList(LinkList l)
{
	LinkList p = l;
	p = p->next;
	cout<<"LinkList:"<<endl;
	while (p!=NULL)
	{
		cout<<p->data<<endl;
		p = p->next;
	}

}
//bool locateElem(LinkList l, ElemType e)
//{
//	for (int i=1; i<=listLength(l); i++)
//	{
//		if (l->data[i-1] == e)
//			return true;
//	}
//	return false;
//}
//void unionL (LinkList la, LinkList lb)
//{
//	ElemType e;
//
//	int La_len = listLength(la);
//	int Lb_len = listLength(lb);
//
//	for ( int i=1; i<=Lb_len; i++)
//	{
//		getElem (lb, i, &e);
//		if (!locateElem(la, e))
//			listInsert(la,++La_len, e);
//	}
//}

int main(){
	ElemType e;
	LinkList l;
	createListHead(&l,20);
	displayList(l);
	listDelete(&l,5,&e);
	displayList(l);
	if(listInsert(&l,10,e))
		cout<<"Insert succesfully!"<<endl;
	displayList(l);
	clearList(l);
	displayList(l);
	return 0;
}
