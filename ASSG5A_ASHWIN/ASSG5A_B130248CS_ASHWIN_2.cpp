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


struct node
{
	
	long long vertex;
	node* next;
};
node *arr[100000];

node* make(long long val)
{
	node* np=new node;
	np->vertex=val;
	np->next=NULL;
	
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
		node *t=arr[index];
		while(t->next!=NULL)
		t=t->next;
		
		t->next=h;
		
	}
}
/*
void enq(node *q[],long long &start,long long &end,node *x)
{
	if(!(end<100000))
	{
		cout<<"overflow\n";
		exit(0);
	}
	
	if(start==-1)
	{
		q[++start]=x;
		q[++end]=x;
	}
	else
	{
		q[++end]=x;
	}
}
node *deq(node *q[],long long &start,long long &end)
{
	if(start==-1)
	return NULL;
	if(start==end)
	{
		node *temp=q[start];
		start=end=-1;
		return temp;
	}
	node *temp=q[start];
	start++;
	return temp;
}*/
void enq(node* q[],long long &head,long long &tail,node* ele)//head point to first input
{
		if(tail + 1>= limit)
		{
			cout<<"overflow!!\n";
		}
		else
		{
			
		if(head==-1)
		{
			head++;
		}
				
		if(tail>=limit)
		cout<<"overflow\n";
		else{
		tail++;
		q[tail]=ele;
		
		}
		}
}
node* deq(node* q[],long long &head,long long &tail)
{
	if(head==-1)
	{
	
	return NULL;
	}
	if(head==tail)
	{
		long long temp =head;
		head=tail=-1;
		return q[temp];
		
	}
	else
	{
	long long temp =head; 
	node* sh=q[temp];//
	
	head++;
	//
	for(int i=0;i<tail;i++)
	q[i]=q[i+1];
	
	head--;
	tail--;
	//
//	return q[temp];//
 return sh; 
	}
	
	
}
struct A
{
	long long u;
	long long v;
	};
A ans[100000];
int ff[100000]={0};
int flag[100000]={0};
int dtime[100000]={0};
int lowest[100000]={0};
int parent[100000]={0};
long long k;
void dfs(long long ele,long long &t)
{
	
	
	
		flag[arr[ele]->vertex]=1;
		ff[arr[ele]->vertex]=2;
		dtime[ele]=++t;
		lowest[ele]=t;
		node *n=arr[ele]->next;
		while(n!=NULL)
		{
			if(flag[n->vertex]==0)
			{
				parent[n->vertex]=ele;
				dfs(n->vertex,t);	
				if(lowest[ele]>lowest[n->vertex])
				lowest[ele]=lowest[n->vertex];
				
				
				if(dtime[ele]<lowest[n->vertex])
				{
					ans[k].u=ele;
					ans[k].v=n->vertex;
					k++;
					}
			}
			else
			if(parent[ele]!=n->vertex)
			{
				if(lowest[ele]>dtime[n->vertex])
				lowest[ele]=dtime[n->vertex];
				}
			n=n->next;
		}
	
}
int main()
{
	for(long i=0;i<100000;i++)
	flag[i]=0;
	long long e,n,u1,v1,c1;
	cin>>n;
	if(!cin)
	{cout<<"empty";exit(0);}
	if(n<0)
	{cout<<"negative n!";exit(0);}
	if(n==0)
	{cout<<"no graph!";exit(0);}
	cin>>e;
	if(e<0)
	{cout<<"negative 2!";exit(0);}
	if(e==0)
	{cout<<"no graph!";exit(0);}
	//edge edg[100000];
	
	for(long long i=0;i<=n;i++)
	{
		arr[i]=make(i);
		parent[i]=-1;
	}
	
	
	long long ele;
	for(long long i=0;i<e;i++)
	{
		cin>>u1>>v1;
		if(u1<=0 || u1 >n || v1<=0 || v1 >n)
		{cout<<" nodes between 1 and "<<n;exit(0);}
		ff[u1]=1;
		ff[v1]=1;
		node *np1=make(u1);
		node *np2=make(v1);
		ele=u1;
		addit(u1,np2);
		addit(v1,np1);
	}

	
	k=0;
	
	//cin>>ele;
	long long t=0;
	dfs(ele,t);
	for(long long i=1;i<=n;i++)
	if(ff[i]==1)
	{
	dfs(i,t);}
	cout<<endl;
	
	cout<<k<<endl;
	for(long long i=0;i<k;i++)
	{
		cout<<ans[i].u<<" "<<ans[i].v<<endl;
		}
	return 0;
}
