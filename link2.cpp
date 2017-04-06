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
void swap(int index)
{
	
	Node* cur = a1.head;
  for(int i=1;i<index;i++)
    {
    cur = cur->next;
}
Node* cur1=a1.head;
for(int i=1;i<(n-index)+1;i++)
{
	cur1=cur1->next;
}
int temp;
temp=cur->value;
cur->value=cur1->value;
cur1->value=temp;
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
   cout<<"Enter number";
   int ind;
   cin>>ind;
   swap(ind);
   cout<<"the result is";
   	Node* cur=a1.head;
   while(cur!=NULL)
   {
   	cout<<cur->value<<" ";
   	cur=cur->next;
   }	

  	
return 0;}    
