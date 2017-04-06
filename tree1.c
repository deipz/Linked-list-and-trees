#include<stdio.h>
#include<stdlib.h>
struct node
{
int value;
struct node *left;
struct node *right;
};
typedef struct node node;

/*void insert(node ** tree,int val)
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
*/

void insert(node **tree,int val)
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
        else if(((*tree)->left)==NULL)
        {
          insert(&(*tree)->left,val);
        }
        else if(((*tree)->right)==NULL)
        {
          insert(&(*tree)->right,val);       
        }

}



void display(node *tree)
{
	if(tree)
	{
	  display(tree->left);
	  printf("%d ",tree->value);
	  display(tree->right);
return;
	}
}

void swap(node *tree)
{
node *temp=NULL;
		if(tree)
		{
		//swap(tree->left);
		//swap(tree->right);
		if((tree->left==NULL)&&(tree->right==NULL)) 
		{
		return;
		}
		temp=tree->left;
		tree->left=tree->right;
		tree->right=temp;
		swap(tree->left);
		swap(tree->right);  
		}
}


int main()
{
int i,n,value;
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
swap(root);
printf("\n MIRROR ORDER\n");
display(root);
}
