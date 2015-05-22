#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int check(long long n)
{
	if(n<0)
	{
		cout<<"only +ve \n";
		exit(0);
		}
	
	char ch=getchar();
	if(ch=='.')
	{
		cout<<"error-floating point not allowed\n";
		 exit(0);
	}
	else
	if(ch!='\n' && ch!=EOF)
	{
		cout<<"characters and special symbols not allowed\n";
		exit(0);
	}else
	return 1;
}

struct node
{
	int val;
	node* child;
	node* next;
};
node *start=NULL;
node* createnew(int v)
{
	node *np=new node;
	//newnode=new node;
	np->val=v;
	np->next=NULL;
	np->child=NULL;
	
	return np;
}

void createm(int m[],int ss,int ctr,node *&t)
{
	//cout<<ss;
	if(ctr<ss)
	{
		node *np=createnew(m[ctr]);
		//cout<<ctr;
		if(t==NULL)
		{
		t=np;
		createm(m,ss,ctr+1,np);
	    }
		else
		{
			//cout<<"else";
			t->next=np;
			
			createm(m,ss,ctr+1,np);
		}
	}
}
void createm2(int m2[],int ss,int ctr,node *&t)
{
	//cout<<ss;
	if(ctr<ss)
	{
		node *np=createnew(m2[ctr]);
		//cout<<ctr;
		/*if(t==NULL)
		{
		t=np;
		createm(m2,ss,ctr+1,np);
	    }
		else*/
		{
			//cout<<"else";
			t->child=np;
			
			createm2(m2,ss,ctr+1,np);
		}
	}
}

node* traverse(int v)
{
	
	if(start==NULL)
	return NULL;
	else
	{
		long long ctr=0;
		node *temp=start;
		while(temp!=NULL)
		{
			if(temp->val == v)
			return temp;
			else
			temp=temp->next;	
		}
		
	}
}


node *start2;

//node *end2=start;

void show()
{
	node* st=start;
	if(st==NULL)
	{
		cout<<"empty";
	}
	
	while(st!=NULL)
	{
		cout<<st->val;
		if(st->next!=NULL)
		cout<<"->";
		st=st->next;
	}
}
void showall(node *t)
{
	if(t!=NULL)
	{
		cout<<t->val<<" ";
		if(t->child!=NULL)
		showall(t->child);
		if(t->next!=NULL)
		showall(t->next);
	}
}
node* traversef(int v)
{
	
	if(start==NULL)
	return NULL;
	else
	{
		
		node *temp=start;
		node *prev=NULL;
		while(temp!=NULL)
		{
			if(temp->val > v)
			return prev;
			else
			{
			prev=temp;
			temp=temp->next;
			}
		}
		
	}
}

void flattenit()
{
	node*temp=start;
	//int nochild=1;
	while(temp!=NULL)
	{
		//cout<<start->val<<endl;
		node *t,*store;
		t=temp->child;
		int ctr=0;
		while(t!=NULL)
		{
			//cout<<ctr;
			//cout<<t->val<<"!";
			if(t->child==NULL)
			;//cout<<ctr<<endl;
			
			node *add =traversef(t->val);
			//cout<<add->val;	
				if(add==NULL)
				{
					if(t->val<start->val)
					{
					
					t->next=start;
					store=t->child;
					t->child=NULL;
					start=t;
					t=store;
					}
					else
					{
					node *e=start;
					while(e->next!=NULL)
					{
						e=e->next;
					}
					t->next=NULL;
					e->next=t;
					store=t->child;
					t->child=NULL;
					t=store;
					}
				}
				else
				{
				
			t->next=add->next;
			add->next=t;
			store=t->child;
			t->child=NULL;
			//cout<<store->val;
			t=store;
		}
			
		ctr++;	
		}
		
		temp=temp->next;	
	}	
}
int main()
{
	int m[100];
	int i=0;
	char ch;
	do
	{
		int n;
		cin>>n;
		if(cin)
		{
			m[i++]=n;
		}
		
		ch=getchar();
	}while(ch!='\n');
	//cout<<i;
	createm(m,i,0,start);
	//show();
	int ctr=0;
	while(1)
	{
	int i=0;
	//cout<<ctr;
	int m2[100];
	do
	{
		int n;
		cin>>n;
		if(cin)
		{
			m2[i++]=n;
		}
		
		ch=getchar();
	}while(ch!='\n' && ch!=EOF);
		
		node *t=traverse(m2[0]);
		//cout<<i<<"!";
		createm2(m2,i,1,t);
		
		
		if(ch==EOF || ctr==3)
		break;
	   ctr++;
	}
	
	/*node*temp=start;
	node *t,*store;
	t=temp->child;
	cout<<t->val<<"!";*/
	
	
	flattenit();

	
	//cout<<"output\n";
	show();
	
	
	
	
	//showall(start);

	/*node one;
	node  two;
	node *op=&one;
	node *ot=&two;
	op->val=4;
	ot=op;
	cout<<ot->val;
	op->val=5;
	cout<<ot->val;*/
	



	return 0;
}
