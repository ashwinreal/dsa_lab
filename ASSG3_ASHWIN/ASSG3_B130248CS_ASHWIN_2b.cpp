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

node* tail=NULL;
node* head=NULL;

node* create_new(long long v)
{
	node *np=new node;
	//newnode=new node;
	np->val=v;
	np->next=NULL;
	
	return np;
}

void enq()
{
	long long v;
	cin>>v;
	check(v);
	node *np=create_new(v);
	if(head==NULL)
	{
		head=tail=np;
	}else
	{
	
	tail->next=np;
	tail=np;
	//cout<<top->val;
	}
}
long long dq()
{
	if(head==NULL)
	{
		return -1;
	}
	if(head==tail)
	{
		long long tempv=head->val;
		node *dp=head;
		head=head->next;
		delete dp;
		head=tail=NULL;
		return tempv;
	}
	else
	{
		long long tempv=head->val;
		node *dp=head;
		head=head->next;
		delete dp;
		return tempv;
		
	}
	
}
long long peek()
{
	if(head==NULL)
	return -1;
	
	return head->val;
}
void show()
{
	if(head==NULL)
	cout<<"Empty\n";
	else
	{
		node *temp=head;
		while(1)
		{
			
			
			cout<<temp->val<<" ";
			temp=temp->next;	
			
			if(temp==tail)
			break;
		}
		cout<<temp->val<<" "<<endl;
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
				enq();
				
				break;
			}
			case 2 :
			{
				long long cp=dq();
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
