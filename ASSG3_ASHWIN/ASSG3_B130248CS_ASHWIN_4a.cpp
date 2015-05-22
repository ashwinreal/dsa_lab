#include<iostream>
using namespace std;
#include<cstdlib>
#include<fstream>
#include<cstdio>
int check(long long n)
{
	char ch=getchar();
	if(ch=='.')
	{
		cout<<"error-floating point not allowed\n";
		return 0;
	}
	else
	if(ch!='\n' && ch!=EOF && ch!=' ')
	{
		cout<<"characters and special symbols not allowed\n";
		return 0;
	}else
	return 1;
}
struct node
{
	long long val;
	node *next;
};

node* top=NULL;

node* create_new(long long v)
{
	node *np=new node;
	//newnode=new node;
	np->val=v;
	np->next=NULL;
	
	return np;
}

void push(long long v)
{
	//long long v;
	//cin>>v;
	node *np=create_new(v);
	np->next=top;
	top=np;
	//cout<<top->val;
}
long long pop()
{
	if(top==NULL)
	{
		return -1;
	}
	else
	{
		long long tempv=top->val;
		node *dp=top;
		top=top->next;
		delete dp;
		return tempv;
		
	}
	
}
long long peek()
{
	if(top==NULL)
	return -1;
	
	return top->val;
}
void traverse()
{
	
	if(top==NULL)
	cout<<"Empty\n";
	else
	{
		long long ctr=0;
		node *temp=top;
		while(temp!=NULL)
		{
			if(temp->val > 10)
			ctr++;
			temp=temp->next;	
		}
		cout<<ctr<<endl;
	}
}

int main()
{
	long long n,v;
	cin>>n;
	check(n);
	for(long long i=0;i<n;i++)
	{
		cin>>v;
		check(v);
		push(v);
	}
	traverse();
	return 0;
}
