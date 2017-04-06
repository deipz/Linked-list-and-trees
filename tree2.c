#include<stdio.h>
#include<stdlib.h>
struct node
{
int value;
struct node *left;
struct node *right;
};
typedef struct node node;

void insert(node ** tree,int val)
{
	node *temp=NULL;
	if(!(*tree))
	{
	  temp=(node *)malloc(sizeof(node));
	  temp->left=temp->right=NULL;
	  temp->value=val;
	  *tree=temp;
	  return;
	}
	else if(val<(*tree)->value)
	{
	  insert(&(*tree)->left,val);
	}
	else if(val>(*tree)->value)
	{
	  insert(&(*tree)->right,val);
	}
}

int ancestor(int val1,int val2,node *tree)
{
//printf("\n ROOT VALUE%d",tree->value);
	if(((val1>tree->value)&&(val2<tree->value))||((val1<tree->value)&&(val2>tree->value)))
	{
	return(tree->value);
	}
	else if((val1>tree->value)&&(val2>tree->value))
	{
	ancestor(val1,val2,tree->right);
	}
	else if((val1<tree->value)&&(val2<tree->value))
        {
        ancestor(val1,val2,tree->left);
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

int main()
{
int i,n,value,val1,val2,anc;
node *root;
root=NULL;
printf("enter the number of nodes:\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&value);
insert(&root,value);
}
display(root);
printf("\n ENTER THE TWO VALUES IN BST \n");
scanf("%d %d",&val1,&val2);
anc=ancestor(val1,val2,root);
printf("COMMON ANCESTOR IS %d",anc);
}
