#define MAX_TREE_SIZE 100
typedef int TElemType;

//parent tree
typedef struct PTNode
{
	TElemType data;
	int parent;
	int firstchild;
	int rightsib;
}PTNode;
typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int r,n;
}PTree;


//child tree
typedef struct CTNode
{
	int child;
	struct CTNode * next;
}*ChildPtr;
typedef struct
{
	TElemType data;
	ChildPtr firstchild;
}CTBox;
typdef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int r,n;
}CTree;


//cs tree
typedef struct CSNode
{
	TElemType data;
	struct CSNode * firstchild,*rightsib;
}CSNode,*CSTree;
