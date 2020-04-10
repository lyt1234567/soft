#include<stdio.h>
#include<stdlib.h>
typedef struct tnode
{
	char data;
	struct tnode *lchild,*rchild;
}tnode,*BiTree;
typedef struct qnode
{
	BiTree t;
	struct qnode *next;
}qnode,*Queue;
struct queue
{
	Queue front;
	Queue rear;
};
void Enqueue(queue &q,BiTree &T)
{
	qnode *p;
	p=(qnode *)malloc(sizeof(qnode));
	p->t=T;
	p->next=NULL;
	q.rear->next=p;
	q.rear=p;
	return ;
}
void Dequeue(queue &q,BiTree &T)
{
	qnode *p;
	p=q.front->next;
	T=p->t;
	q.front->next=p->next;
	if(q.rear==p)
		q.rear=q.front;
	free(p);
	return ;
}
void GreateBiTree(BiTree &T)
{
	char c,a;
	scanf("%c%c",&c,&a);
	if(c=='*')
		T=NULL;
	else
	{
		T=(tnode *)malloc(sizeof(tnode));
		if(T==NULL)
			exit(-1);
		T->data=c;
		GreateBiTree(T->lchild);
		GreateBiTree(T->rchild);
	}
	return ;
}
void Preorder(BiTree &T,void(*visit)(char &ch))
{
	if(T!=NULL)
	{
		visit(T->data);
		Preorder(T->lchild,visit);
		Preorder(T->rchild,visit);
	}
	return ;
}
void Inorder(BiTree &T,void(*visit)(char &ch))
{
	if(T!=NULL)
	{
		Inorder(T->lchild,visit);
		visit(T->data);
		Inorder(T->rchild,visit);
	}
	return ;
}
void Postorder(BiTree &T,void(*visit)(char &ch))
{
	if(T!=NULL)
	{
		Postorder(T->lchild,visit);
		Postorder(T->rchild,visit);
		visit(T->data);
	}
	return ;
}
void visit(char &ch)
{
	printf("%c ",ch);
	return ;
}
void Order(BiTree &T)
{
	if(T!=NULL)
	{
	queue q;
	BiTree tree;
	q.front=q.rear=(qnode *)malloc(sizeof(qnode));
	q.front->next=NULL;
	Enqueue(q,T);
	while(q.front!=q.rear)
	{
		Dequeue(q,tree);
		visit(tree->data);
		if(tree->lchild!=NULL)
			Enqueue(q,tree->lchild);
		if(tree->rchild!=NULL)
			Enqueue(q,tree->rchild);
	}
	}
	return ;
}
int main()
{
	BiTree Tree;
	GreateBiTree(Tree);
	Preorder(Tree,visit);
	printf("\n");
	Inorder(Tree,visit);
	printf("\n");
	Postorder(Tree,visit);
	printf("\n");
	Order(Tree);
	printf("\n");
	return 1;
}
/*#include<stdio.h>
#include<stdlib.h>
struct tnode
{
	char data;
	struct tnode *lchild,*rchild;
};
struct tnode * Greatetree(struct tnode *T)
{
	char c;
	scanf("%c",&c);
	if(c=='*')
		T=NULL;
	else
	{
		T=(tnode *)malloc(sizeof(tnode));
		if(T==NULL)
			exit(-1);
		T->data=c;
		T=Greatetree(T->lchild);
		T=Greatetree(T->rchild);
	}
	return T;
}
void Postorder(struct tnode *T,void(*visit)(char &ch))
{
	if(T!=NULL)
	{
		Postorder(T->lchild,visit);
		Postorder(T->rchild,visit);
		visit(T->data);
	}
	return ;
}
void visit(char &ch)
{
	printf("%c ",ch);
	return ;
}
int main()
{
	struct tnode *Tree=NULL;
	Tree=Greatetree(Tree);
	Postorder(Tree,visit);
	return 1;
}*/



