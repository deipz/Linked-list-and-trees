#include<stdio.h>
#include<stdlib.h>
struct node
{
int value;
struct node *left;
struct node *right;
};
typedef struct node node;

int n,arr[20],v,flag=0;
void insert(node **tree,int index)
{		if(index<n)
{
	
     node *temp=NULL;
        if(!(*tree))
        {
          temp=(node *)malloc(sizeof(node));
          temp->left=temp->right=NULL;
          temp->value=arr[index];
          *tree=temp;
		}
          insert(&(*tree)->left,2*index+1);
        
        
          insert(&(*tree)->right,2*index+2);       
        
}
}

void display(node *tree)
{
	if(tree)
	{
	  display(tree->left);
	  printf("%d ",tree->value);
	  display(tree->right);
	}
}

int getvalue(node *tree)
{
	if(tree)
	{
	v=tree->value;
	return v;
	}
	else return 1000;
}

void BSTCheck(node *tree)
{
	int l,r;
	if(tree)
	{
		l=getvalue(tree->left);
		r=getvalue(tree->right);
		if(l==1000)
			l=-l;
		if((tree->value>l)&&(tree->value<r))
		{
		BSTCheck(tree->left);
		BSTCheck(tree->right);
		}
	else
	{
			flag=1;
	}}
}

int main()
{
int i;
node *root;
root=NULL;
printf("enter the number of nodes:\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
insert(&root,0);
//display(root);
BSTCheck(root);
if(flag==0)
	printf("VALID BINARY SEARCH TREE");
	else
		printf("INVALID BINARY SEARCH TREE");
getch();
}

