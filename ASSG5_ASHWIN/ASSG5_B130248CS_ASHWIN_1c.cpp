#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
long long MAX=99999;
struct node
{
	long long rank;
	node* p;
	long long data;
};

void debug()
{
	cout<<"here\n";
}
struct hashnode
{
	node* add;
	hashnode* next;

};
hashnode *hash[100000];

long long hashf(long long v)
{
	return v%MAX;
}
void addtohash(node *x)
{
	long long index=hashf(x->data);
		hashnode *h=new hashnode;;
		h->next=NULL;
		h->add=x;
	if(hash[index]==NULL)
	{
	
		hash[index]=h;
	}
	else
	{
		hashnode *temp=hash[index];
		hash[index]=h;
		h->next=temp;
		
	}
}
node *searchhash(long long v)
{
	long long index=hashf(v);
	if(hash[index]==NULL)
	{
		cout<<"not in table\n";
		return NULL;
	}
	else
	{
		while(hash[index]->add->data!=v)
		{
		hash[index]=hash[index]->next;
		if(hash[index]==NULL)
		{
			cout<<"not in table\n";
			return NULL;
		}
		
	}
		//cout<<"returning";
		return hash[index]->add;
	}
}

node *makesets(long long v)
{
	node *np=new node;
	np->p=np;
	np->rank=0;
	np->data=v;
	return np;
}
node *find(node *x)
{
	while(x->p!=x)
	{
		x=x->p;
	}
	return x;
}
void unions(node *x,node *y)
{
	if(x->rank > y->rank)
	find(y)->p=find(x);
	else
	{
		if(x->rank == y->rank)
		y->rank++;
		find(x)->p=find(y);
		
	}
}

int main()
{
	for(long long i=0;i<100000;i++)
	hash[i]=NULL;
	
	while(1)
	{
		long long c;
		cin>>c;
		switch(c)
		{
			case 0:{
				exit(0);
				break;
			}
			case 1:{
				long long k;
				cin>>k;
				addtohash(makesets(k));
				//cout<<hash[hashf(k)]->add->data;
				break;
			}
			case 2:{
				long long k;
				cin>>k;
				node*temp=searchhash(k);
				if(temp==NULL)
				{
					cout<<"not found\n";
					
				}
				else
				{
					cout<<find(temp)->data<<endl;
				}
				
				break;
			}
			case 3:{
				long long v,u;
				cin>>u>>v;
				node*temp1=searchhash(u);
				node*temp2=searchhash(v);
				if(temp1==NULL||temp2==NULL)
				{
					cout<<"invalid\n";
				}else{
				
				unions(temp1,temp2);
				
				}
				break;
			}
			default:{
				cout<<"worng choice\n";
				break;
			}
				
		}
	}
	
	
	return 0 ;
}
