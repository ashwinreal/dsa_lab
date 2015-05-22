#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define limit 100000
struct edge
{
	long long u;
	long long v;
	long long cost;

};

edge* makedge(long long u1,long long v1,long long c1)
{
	edge* np=new edge;
	np->u=u1;
	np->v=v1;
	np->cost=c1;
	return np;
}


struct node
{
	long long vertex;
	node* p;
};
node *arr[100000];


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
	find(y)->p=find(x);
}






node* make(long long val)
{
	node* np=new node;
	np->vertex=val;
	np->p=np;
	return np;
}

void addit(long long v,node *h)
{
	long long index=v;
		
	if(arr[index]==NULL)
	{
	
		arr[index]=h;
	}
	else
	{
		;
		
	}
}

	
	
	
edge* c[100000];
void merge(edge* arr[],long long start,long long end)
{
	
	long long add=start+end;
	long long mid=(add)/2;
	long long i,k;
		i=k=start;
	long long j=mid+1;
	while(i<=mid&&j<=end)
	{
		if(arr[i]->cost < arr[j]->cost)
		{
		c[k++]=arr[i];
		i++;
	    }
		else
		{
		
		c[k]=arr[j++];
		k++;
		}
	}
	while(i<=mid){
		c[k++]=arr[i];
		i++;
	}
	while(j<=end)
	{
		c[k]=arr[j++];
		k++;
	}
	for(long long p=start;p<=end;p++)
	arr[p]=c[p];
	;
}
void mergesort(edge* arr[],long long start,long long end)
{
	if(start<end)
	{
		long long mid =(start+end)/2;
		mergesort(arr,start,mid);
		mergesort(arr,mid+1,end);
		merge(arr,start,end);
	}
}	
	
	

int main()
{
	long long e,n,u1,v1,c1;
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
	edge* edg[100000];
	
	for(long long i=0;i<n;i++)
	{
		arr[i]=make(i);
	}                                   // comment this for and see
	long long t;
	for( t=0;t<e;t++)
	{
		cin>>u1>>v1>>c1;
		if(u1<0 || u1 >n || v1<0 || v1 >n)
		{cout<<" nodes between 0 and "<<n-1;exit(0);}
		node *np1=make(u1);    // comment them and see
		node *np2=make(v1);	//
		edg[t]=makedge(u1,v1,c1);
		addit(u1,np1);
		addit(v1,np2);
		
	}
	
	// sort edg
	mergesort(edg,0,e-1);
	
	edge *ans[100000];
	long long ctr=0;
	
	for( long long i=0;i<t;i++)
	{
		long long u1=edg[i]->u;
		long long v1=edg[i]->v;
		if(find(arr[u1])!=find(arr[v1]))
		{
		unions(arr[u1],arr[v1]);
		
		ans[ctr++]=edg[i];	
		}
	}
	
	long long tot=0;
	
	
	long long m[200][200];
	
	
	for( long long i=0;i<n;i++)
	for( long long j=0;j<n;j++)
	m[i][j]=0;
	
	for( long long i=0;i<ctr;i++)
	{
		tot+=ans[i]->cost;
		long long u1=ans[i]->u;
		long long v1=ans[i]->v;
		m[u1][v1]=ans[i]->cost;
		m[v1][u1]=ans[i]->cost;
		
	}
	
	cout<<tot<<endl;
	for( long long i=0;i<n;i++)
	{cout<<endl;
		for( long long j=0;j<n;j++)
	{
		cout<<m[i][j]<<" ";
	}}
	
	
	
	
	
	return 0;
}

