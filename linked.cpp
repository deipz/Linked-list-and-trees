#include<iostream>
using namespace std;

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
int getnth(int index)
{
	
	Node* cur = a1.head;
  for(int i=0;i<index;i++)
    {
    cur = cur->next;
}
return cur->value;
}

int main()
{
	int n,value;
	cout<<"Enter the no of nodes";
	cin>>n;
	cout<<"Enter the values";
	for(int i=0;i<n;i++)
	{
		cin>>value;
	a1.append(value);
	}
   cout<<"Enter index";
   int ind;
   cin>>ind;
   value=getnth(ind);
   cout<<"the result is"<<value;	

  	
return 0;}    
