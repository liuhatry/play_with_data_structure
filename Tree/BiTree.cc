typedef int TElemType;
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode ,*BiTree;

void PreOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	cout<<T->data<<endl;
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

void CreateBiTree(BiTree *T)
{
	TELemType ch;
	cin>>ch;
	if(ch=='#')
		*T=NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}
