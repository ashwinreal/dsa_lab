#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int m;
struct node
{
	int val;
	node *next; 	
};
int hash(int v,int m)
{
	return v%m;
}
node *make(int v)
{
	node * np=new node;
	np->val=v;
	np->next=NULL;
	return np;
}
void insert(node *arr[],int v)
{
	int h=hash(v,m);
	node *np=make(v);
	if(arr[h]==NULL)
	{
		arr[h]=np;
		cout<<h<<endl;
	}
	else
	{
		node *nxt=arr[h];
		arr[h]=np;
		cout<<h<<endl;
		np->next=nxt;
	}
}
void search(node *arr[],int v)
{
	int h=hash(v,m);
	if(arr[h]==NULL)
	{
		cout<<h<<" not found\n";	
		return;
	}	
	else
	{
		node * tmp=arr[h];
		while(tmp!=NULL)
		{
			if(tmp->val==v)
			{
			cout<<h<<" found\n";
			return;
			}
			else
			{
			
			tmp=tmp->next;
		}
		}
	}
	cout<<h<<" not found\n";
}
void check(int v)
{
	char ch=getchar();
	if(ch=='\n'||ch==' ')
	return;
	if(ch=='.')
	cout<<"no floating point\n";
	else
	cout<<"no alphabets and spcl chars\n";
	exit(0);
}
int main()
{
	
	cin>>m;
	check(m);
	if(m<0)
	{
		cout<<"invalid capacity\n";
		exit(0);
	}
	if(m==0)
	{
		cout<<"0 capacity\n";
		exit(0);
	}
	node *arr[100000];
	for(int i=0;i<100000;i++)
	arr[i]=NULL;
	while(1)
	{
	
	char c;
	cin>>c;

	switch(c)
	{
		case '0':
			{
				exit(0);				
				break;
			}
		case '1':
			{
				int v;
				cin>>v;
				check(v);
				insert(arr,v);
				break;
			}
		case '2':
			{
				int v;
				cin>>v;
				check(v);
				search(arr,v);
				break;
			}
	}
	
	}
	
	return 0;
}
