#include<string>
#include<cstring>
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
node *arr_nodes[1000];
char corresponding[1000][20];
long long corsize;
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
hash *arr_hash[1000];
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

node* topsorted[10000];
long long ts=0;


int ff[10000]={0};
int flag[10000]={0};
void dfs(long long ele)                      /////////// IS IT CORRECT ??
{
		topsorted[ts++]=arr_nodes[ele];
		flag[arr_hash[ele]->vertex]=1;
		ff[arr_hash[ele]->vertex]=2;
		
		hash *n=arr_hash[ele]->next;
		while(n!=NULL)
		{
			if(flag[n->vertex]==0)
			{
				
				dfs(n->vertex);	
			}	
			n=n->next;
		}
	
}
	

void printpath(node *t,node *dest)
{
	if(t!=NULL){
		printpath(t->p,dest);
		cout<<corresponding[t->vertex];
		if(t!=dest)
		cout<<"->";
		}
	}
	
int searchcorr(char u[20])
{
	for(long long i=1;i<=corsize;i++)
	{
		if(strcmp(u,corresponding[i])==0)
		return 1;
	}
	//cout<<u;
	return 0;
}
long long givecorr(char u[20])
{
long long i;
for(i=1;i<=corsize;i++)
	{
		if(strcmp(u,corresponding[i])==0)
		return i;
	}
	cout<<"error!\n";
	exit(0);
	return 0;	
}
int main()
{
	long long n,e,c;
	//long long u,v;
	char u[20],v[20];
	cin>>n;
	if(!cin)
	{cout<<"empty";exit(0);}
	if(n<0)
	{cout<<"negative n!";exit(0);}
	if(n==0)
	{cout<<"no graph!";exit(0);}
	cin>>e;
	if(e<0)
	{cout<<"negative e!";exit(0);}
	if(e==0)
	{cout<<"no graph!";exit(0);}
	for(long long i=0;i<=n;i++)
	{arr_nodes[i]=NULL;
	arr_hash[i]=NULL;
}
	for(long long i=0;i<=n;i++)
	corresponding[i][0]='\0';
	corsize=0;
	/*long long s,dest;   
	cin>>s;             
	cin>>dest;*/
	char s[20],dest[20];
	cin>>s>>dest;
	//cout<<"hello";
	//cout<<"e="<<e<<"\n";
	for(long long i=0;i<e;i++)
	{
		//cout<<i<<endl;
		cin>>u;
		cin>>v;
		cin>>c;
	/*if(u<=0 || u >n || v<=0 || v >n)
		{cout<<" nodes between 1 and "<<n;exit(0);}*/
		if(c<0)
		{cout<<"cannot be negative ";exit(0);}
		
		if(!searchcorr(u))
		{
			strcpy(corresponding[++corsize],u);
			}
		if(!searchcorr(v))
		{
			strcpy(corresponding[++corsize],v);
			}
		
		if(arr_nodes[givecorr(u)]==NULL)
		{arr_nodes[givecorr(u)]=makenode(givecorr(u));
		 arr_hash[givecorr(u)]=makehash(arr_nodes[givecorr(u)],c);
		}
		if(arr_nodes[givecorr(v)]==NULL)
		{arr_nodes[givecorr(v)]=makenode(givecorr(v));
		arr_hash[givecorr(v)]=makehash(arr_nodes[givecorr(v)],c);	
		}
		//cout<<i;
		addit(arr_hash,givecorr(u),givecorr(v),c);
		 //addit(arr_hash,givecorr(v),givecorr(u),c);
		
		//cout<<i<<" "<<c<<" "<<(i<e)<<endl;
	}
	
	
	
	
	   
   
	//cout<<"hello";
	
	if(arr_nodes[givecorr(s)]==NULL || arr_nodes[givecorr(dest)]==NULL)
	{
		cout<<"no such vertex";
		exit(0);
	}
	arr_nodes[givecorr(s)]->d=0;
	
	
	
	// topological sort
	dfs(givecorr(s));
	for(long long i=1;i<=n;i++)
	if(ff[i]==1)
	{
	dfs(i);}
	
	
	
	
	
	
	
	//// algorithm
	long long y=0;
	while(y!=ts)
	{
		//cout<<sz<<" ";
		node *np=topsorted[y++];
		hash *h=arr_hash[np->vertex];
		h=h->next;
		while(h!=NULL)
		{
		
			relax(arr_nodes[np->vertex],arr_nodes[h->vertex],h->cost);

			h=h->next;
		}
	}
	
	cout<<endl;
	/*for(long long i=1;i<=n;i++)
	{
		if(arr_nodes[i]!=NULL)
	 	cout<<arr_nodes[i]->d<<" ";
	}*/
	node *t=arr_nodes[givecorr(dest)];
	if(arr_nodes[givecorr(dest)]->p==NULL)
	cout<<"no path\n";
	else
	{printpath(t,arr_nodes[givecorr(dest)]);
	cout<<endl;
	cout<<arr_nodes[givecorr(dest)]->d;
	}
	
	
	
	
	
	
	return 0;
}
