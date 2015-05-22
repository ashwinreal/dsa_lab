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
void bfs(long long ele)
{
	int flag[100000]={0};
	
	for(long i=0;i<100000;i++)
	flag[i]=0;
	
	node *q[100000];
	long long start=-1;
	long long end=-1;
	enq(q,start,end,arr[ele]);
	
	while(1)
	{
		node*temp=deq(q,start,end);
		if(temp==NULL)
		break;
		cout<<temp->vertex<<" ";
		flag[temp->vertex]=1;
		/*if(flag[arr[temp->vertex]->next->vertex]!=0)
		{
			cout<<"flag1"<<temp->vertex;
		}*/
		/*
		while(arr[temp->vertex]->next!=NULL && flag[arr[temp->vertex]->next->vertex]==0)
		{
			flag[arr[temp->vertex]->next->vertex]=1;
			enq(q,start,end,arr[temp->vertex]->next);
			temp=temp->next;
			 
		}*/
		node *n=temp->next;
		while(temp!=NULL)
		{
			if(flag[temp->vertex]==0)
			{
				flag[temp->vertex]=1;
				enq(q,start,end,arr[temp->vertex]);
			}
			temp=temp->next;
		}
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
	//edge edg[100000];
	
	for(long long i=0;i<n;i++)
	{
		arr[i]=make(i);
	}
	for(long long i=0;i<e;i++)
	{
		cin>>u1>>v1>>c1;
		if(u1<0 || u1 >n || v1<0 || v1 >n)
		{cout<<" nodes between 0 and "<<n-1;exit(0);}
		node *np1=make(u1);
		node *np2=make(v1);
		addit(u1,np2);
		addit(v1,np1);
	}
	/*for(long long i=0;i<n;i++)
	{
		cout<<endl<<i<<" : ";
		node *t=arr[i];
		while(t!=NULL)
		{
			cout<<t->vertex<<" ";
			t=t->next;
		}
		
	}*/
	
	
	
	long long ele;
	cin>>ele;
	bfs(ele);
	return 0;
}
