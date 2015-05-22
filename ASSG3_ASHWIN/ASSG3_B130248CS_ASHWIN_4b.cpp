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
	node *prev;
};

node* top=NULL;

node* create_new(long long v)
{
	node *np=new node;
	//newnode=new node;
	np->val=v;
	np->next=NULL;
	np->prev=NULL;
	
	return np;
}

void push(long long v)
{
	//long long v;
	//cin>>v;
	if(top!=NULL)
	{
	
	node *np=create_new(v);
	top->next=np;
	np->prev=top;
	
	top=np;
	//cout<<top->val;
	}
	else
	{
	node *np=create_new(v);
	top=np;
	}
}                                                                           

void traverse_n_del()
{
	
	if(top==NULL)
	cout<<"Empty\n";
	else
	{
		
		 node *temp=top;
		
		long long ctr=0;
		while(temp!=NULL)
		{
			ctr++;
			if(ctr%2==0)
			{
			if(temp!=top && temp->next!=NULL && temp->prev!=NULL)
			{
			//cout<<ctr;
			node *tp,*tn,*t3;
			t3=temp;
			
			tn=temp->next;
			tp=temp->prev;
			
			tp->next=tn;
			tn->prev=tp;
			
			temp=temp->prev;
			delete t3;
			//cout<<"n";
			}
			else if(temp==top)   /// this will never happen!!!!!
			{
			//cout<<"t"<<ctr;
			node *tp,*t2;
			tp=temp->prev;
			tp->next=NULL;
			top=tp;
			t2=temp;
			temp=temp->prev;
			delete t2;
			
			}
			else
			{
				//cout<<ctr;
				node *tn,*t2;
				tn=temp->next;
				tn->prev=NULL;
				t2=temp;
				temp=temp->prev;
				delete t2;
			}
			
			}
			else
			{
				temp=temp->prev;
			}
		//cout<<"no inf\n";	
		}
		
	}
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
			temp=temp->prev;
			//if(temp->next!=NULL)
			//cout<<temp->next->val;	
		}
		cout<<endl;
		
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
	traverse_n_del();
	show();
	return 0;
}
