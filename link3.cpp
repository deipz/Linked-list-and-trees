#include<iostream>
using namespace std;
int n;
struct Node
{
	int value;
	Node *next;
}a2;

struct link
{
	Node *head=NULL;
	
	void append(int);
}a1;

void link::append(int data)
{
	//cout<<"Enter";
	Node* cur = head;
  Node* tmp = new Node;
  tmp->value = data;
  tmp->next = NULL;
  //Node *cur=tmp;
  if(cur== NULL) {
    head  = tmp;
  }
  else {
    while(cur->next != NULL){
      cur = cur->next;
    }
    cur->next = tmp;

  }
  //cur=head;
}
void duplicate()
{
	cout<<"ENTER";
	int i;
	Node* cur = a1.head;
  	while(cur!=NULL)
  	{
  		Node* cur1=cur->next;
		i=cur->value;
		while(cur1!=NULL)
		{
			if(i==cur1->value)
			{
				cur->next=cur1->next;
				cur1=cur->next;
				
			}
			else
			{
			cur1=cur1->next;
			}	
			
			
		}
		cur=cur->next;
  	}
}

int main()
{
	int value;
	cout<<"Enter the no of nodes";
	cin>>n;
	cout<<"Enter the values";
	for(int i=0;i<n;i++)
	{
		cin>>value;
	a1.append(value);
	}
   duplicate();
   cout<<"the result is";
   Node* cur=a1.head;
   while(cur!=NULL)
   {
   	cout<<cur->value<<" ";
   	cur=cur->next;
   }	

  
return 0;}    
