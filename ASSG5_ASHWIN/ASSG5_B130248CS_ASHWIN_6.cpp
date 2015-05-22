#include<iostream>
#include<cstdio>
#include<climits>
#include<cstdlib>
using namespace std;

struct node
{
	long long vertex;
	long long d;// initially inf
	node *p;  //initially null
	
};
node *arr_nodes[10000];

node *makenode(long long v)
{
node *np=new node;
np->vertex=v;
np->d=INT_MAX;
np->p=NULL;
return np;	
}

struct hash
{
	hash *next;
	node *add;
	long long cost;
	long long vertex;
};
hash *arr_hash[10000];
hash *makehash(node* np,long long c)
{
hash*h=new hash;
h->vertex=np->vertex;
h->add=np;
h->cost=c;
h->next=NULL;
return h;	
}


void addit(hash *arr_hash[],long long u,long long v,long long c)
{
	//cout<<c;
	hash *h=makehash(arr_nodes[v],c);
	if(arr_hash[u]->next==NULL)
	{
		arr_hash[u]->next=h;
	}
	else
	{
		hash *k=arr_hash[u]->next;
		arr_hash[u]->next=h;
		h->next=k;
	}
	
}

void relax(node *u,node *v,long long cuv)
{
	if(v->d > u->d + cuv)
	{
		v->d=u->d + cuv;
		v->p=u;
		}
}





void swap(node* arr[],long long a,long long b)
{
	node* temp =arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}

void heapit(long long s,node* arr[],long long index)
{
	long long m=index;
	if(2*index<=s)
	{
		if(arr[m]->d > arr[2*index]->d)
		{
		m=2*index;	
		}
		if(2*index+1<=s)
		{
		
		if(arr[m]->d > arr[2*index +1]->d)
		{
		m=2*index + 1;	
		}
		}
		swap(arr,m,index);
		
		if(m!=index)
		heapit(s,arr,m);
	}
}
void build(node* arr[],long long s)
{
	for(long long i=s/2;i>=1;i--)
	{
		heapit(s,arr,i);
	}
}
void inc_pri(node* arr[],long long index)//array passed after change
{

	long long parent=index/2;
	if(parent>=1)
	if(arr[parent]->d> arr[index]->d)
	{
		swap(arr,parent,index);
		
		inc_pri(arr,parent);
	}
}


node* remov(node* arr[],long long &n)//remove max priority
{
	if(n==0)
	return NULL;//cout<<"Empty\n";
	else{
	//cout<<arr[1]<<" "<<"("<<key[1]<<")"<<endl;
	node *t=arr[1];
	swap(arr,n,1);
	
	n--;
	heapit(n,arr,1);
	return t;
	}
}


long long searchpq(node *pq[],long long v,long long sz)
{
for(long long i=1;i<=sz;i++)
if(pq[i]->vertex==v)
return i;

return -1;	
}
int main()
{
	long long n,e,u,v,c;
	cin>>n;
	if(n<0)
	{cout<<"negative n!";exit(0);}
	if(n==0)
	{cout<<"no graph!";exit(0);}
	cin>>e;
	if(e<0)
	{cout<<"negative 2!";exit(0);}
	if(e==0)
	{cout<<"no graph!";exit(0);}
	for(long long i=0;i<n;i++)
	{arr_nodes[i]=NULL;
	arr_hash[i]=NULL;
}
	long long s;   
	//cout<<"e="<<e<<"\n";
	for(long long i=0;i<e;i++)
	{
		//cout<<i<<endl;
		cin>>u;
		cin>>v;
		cin>>c;
	if(u<0 || u >n || v<0 || v >n)
		{cout<<" nodes between 0 and "<<n-1;exit(0);}
		if(arr_nodes[u]==NULL)
		{arr_nodes[u]=makenode(u);
		 arr_hash[u]=makehash(arr_nodes[u],c);
		}
		if(arr_nodes[v]==NULL)
		{arr_nodes[v]=makenode(v);
		arr_hash[v]=makehash(arr_nodes[v],c);	
		}
		//cout<<i;
		addit(arr_hash,u,v,c);
		addit(arr_hash,v,u,c);
		
		//cout<<i<<" "<<c<<" "<<(i<e)<<endl;
	}
	
	
	
	
	   
    s=1;
	cin>>s;             
	
	
	if(arr_nodes[s]==NULL)
	{
		cout<<"no such vertex";
		exit(0);
	}
	arr_nodes[s]->d=0;
	
	node *pq[10000];
	long long sz=0;;
	for(long long i=0;i<n;i++)
	{
		if(arr_nodes[i]!=NULL)
		{
			sz++;
			pq[i+1]=arr_nodes[i];
			}
	}
	
	build(pq,sz);
	
	
	//// prim
	while(sz!=0)
	{
		//cout<<sz<<" ";
		node *np=remov(pq,sz);
		hash *h=arr_hash[np->vertex];
		h=h->next;
		while(h!=NULL)
		{
		
			//relax(arr_nodes[np->vertex],arr_nodes[h->vertex],h->cost);
			long long index=searchpq(pq,h->vertex,sz); // what if index is not present i.e already removed!!
			if(index!=-1 && arr_nodes[h->vertex]->d > h->cost )
			{
				arr_nodes[h->vertex]->p=np;
				arr_nodes[h->vertex]->d=h->cost;
				inc_pri(pq,index);
				}
			
			h=h->next;
		}
	}
	
	
	cout<<endl;
	
	long long m[100][100];
	
	for(long long i=0;i<n;i++)
	for(long long j=0;j<n;j++)
	{
	 	m[i][j]=0;
	}
	long long ttt=0;
	for(long long i=0;i<n;i++)
	{;
		//cout<<arr_nodes[i]->vertex<<" "<<arr_nodes[i]->p->vertex<<endl;
		
	if(arr_nodes[i]!=NULL && arr_nodes[i]->p!=NULL )
	{
		ttt+=arr_nodes[i]->d;
		m[arr_nodes[i]->vertex][arr_nodes[i]->p->vertex]=arr_nodes[i]->d;
		m[arr_nodes[i]->p->vertex][arr_nodes[i]->vertex]=arr_nodes[i]->d;}
	}
	cout<<endl<<ttt<<endl;
	for(long long i=0;i<n;i++)
	{ cout<<endl;
		for(long long j=0;j<n;j++)
	{
	 	cout<<m[i][j]<<" ";
	}}
	cout<<endl;
	
	
	
	
	
	
	return 0;
}

