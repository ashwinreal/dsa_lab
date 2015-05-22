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
	long long color[100000]={0};
	for(long i=0;i<100000;i++)
	flag[i]=0;
	
	
	node *q[100000];
	long long start=-1;
	long long end=-1;
	enq(q,start,end,arr[ele]);
	long long cc=1;
	color[ele]=cc;
	bool an=true;
	while(1)
	{
		node*temp=deq(q,start,end);
		if(temp==NULL)
		break;
		//cout<<temp->vertex<<" ";
		flag[temp->vertex]=1;
		
		
		node *n=temp;
		temp=temp->next;
		while(temp!=NULL)
		{
			if(flag[temp->vertex]==0)
			{
				flag[temp->vertex]=1;
				//color[temp->vertex]=cc+1;
				color[temp->vertex]=color[n->vertex]+1;
				enq(q,start,end,arr[temp->vertex]);
			}
			else
			{
					
					if(n!=temp && (color[n->vertex]+1)%2 != color[temp->vertex]%2) // if(n!=temp && (cc+1)%2 != color[temp->vertex]%2)
					{an=false;
						//cout<<"child: "<<temp->vertex<<"parent: "<<n->vertex<<endl;
					
					}
			}
			
			temp=temp->next;
		}
		cc++;
	}
	
	//for(int i=1;i<=4;i++)
	//cout<<color[i]<<" ";
	
	cout<<endl;
	if(an==false)
	cout<<"NO\n";
	else
	cout<<"YES\n";
}
int main()
{
	long long e,n,u1,v1,c1;
	cin>>n;
	if(!cin)
	{cout<<"empty";exit(0);}
	if(n<0)
	{cout<<"negative n!";exit(0);}
	if(n==0)
	{cout<<"no graph!";exit(0);}
	//edge edg[100000];
	cin>>e;
	if(e<0)
	{cout<<"negative 2!";exit(0);}
	if(e==0)
	{cout<<"no graph!";exit(0);}
	for(long long i=0;i<=n;i++)
	{
		arr[i]=make(i);
	}
	long long ele;
	for(long long i=0;i<e;i++)
	{
		cin>>u1>>v1;
			if(u1<=0 || u1 >n || v1<=0 || v1 >n)
		{cout<<" nodes between 1 and "<<n;exit(0);}
		ele=u1;
		
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
	
	for(long long i=1;i<=n;i++)
	{
		node *temp=arr[i];
		while(temp!=NULL)
		{
			//cout<<temp->vertex<<" ";
			temp=temp->next;
		}
		//cout<<endl;
	}
	
	
	
	bfs(ele);
	return 0;
}
