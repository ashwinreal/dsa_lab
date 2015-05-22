#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstdio>
using namespace std;
int check(long long n)
{
	char ch=getchar();
	if(ch=='.')
	{
		cout<<"error-floating point not allowed\n";
		return 0;
	}
	else
	if(ch!='\n' && ch!=EOF)
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

void push()
{
	long long v;
	cin>>v;
	check(v);
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
void show()
{
	if(top==NULL)
	cout<<"Empty\n";
	else
	{
		node *temp=top;
		while(temp!=NULL)
		{
			cout<<temp->val<<" ";
			temp=temp->next;	
		}
		cout<<endl;
	}
}

int main()
{
	
	
	
	while(1)
	{
		int c;
		cin>>c;
		switch(c)
		{
			case 1 :
				{
				push();
				
				break;
			}
			case 2 :
			{
				long long cp=pop();
				if(cp==-1)
				cout<<"EMPTY!!\n";
				else
				{
				cout<<cp<<endl;
				}
				break;
			}
			case 3 :
				{
				long long co=peek();
				if(co==-1)
				cout<<"EMPTY\n";
				else
				cout<<co<<endl;
				break;
				}
			case 4 :
				{
				show();
				break;
				}
			case 0 :
				{
				exit(0);
				break;
				}
			default:
				cout<<"invalid choice\n";
		}
		
	}
	return 0;
}
