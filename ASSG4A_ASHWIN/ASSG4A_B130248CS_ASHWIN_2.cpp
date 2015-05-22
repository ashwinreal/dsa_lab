
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;




struct node
{
		int val;
		node *l;
		node *r;
	
};
node *root;


void debug()
{
int d=0;
d++;
d++;
d--;
}



node *make(int v)
{
	if(v==-1)
	return NULL;
	
	node *np=new node;
	np->l=NULL;
	np->r=NULL;
	np->val=v;
	
	return np;
}


int M=0;

void makeandinsert(node *&roo,node *np)
{
	node *na=make(np->val);
	//cout<<np->val<<"! ";
	if(roo==NULL)
	{roo=na;return;}
	
	debug();
	
	node* temp=roo;
	while(temp->l!=NULL)
	{
		//cout<<"d";
		temp=temp->l;
	}
	temp->l=na;
	
	debug();
	
}

void makelist(node *root,int k,node *list[])
{
	if(root!=NULL)
	{
			//cout<<root->val<<" "<<k<<" ";
			
			makeandinsert(list[k],root);
			
			debug();
			
			makelist(root->l,k+1,list);
			
			debug();
			
			makelist(root->r,k+1,list);
	}
}





void checking(node *root,int &c)
{
	if(root!=NULL)
	{
			c++;
			checking(root->l,c);
			debug();
			checking(root->r,c);
	}
}

void inorder(node *root)
{
	if(root!=NULL)
	{
			inorder(root->l);
			cout<<root->val<<" ";
			inorder(root->r);
	}
}
void inorder2(node *root)
{
	if(root!=NULL)
	{
			inorder2(root->r);
			cout<<root->val<<"";
			if(root->l!=NULL)
			cout<<"->";
			inorder2(root->l);
	}
}


void create(node *&root,int arr[],int i,int p,int n)
{
	if(i>=p)
	return;
	if(root==NULL)
	return;
	if(2*i+1<p)
	{
		node *np=new node;
		np=make(arr[2*i+1]);
		
		debug();
		
		root->l=np;
		create(root->l,arr,2*i + 1,p,n);
	}
	if(2*i+2<p)
	{
		node *np=new node;
		np=make(arr[2*i+2]);
		
		debug();
		
		root->r=np;
		create(root->r,arr,2*i + 2,p,n);
	}
}


void createbt(int n)
{
	int v;
	int ctr=0;
	int arr[1000];
	int p=0;
	while(cin>>v)
	{
		//cout<<"working !!";
		//cout<<v<<" ";
			if(v!=-1)
			ctr++;	
			if(ctr>n)
			{
				cout<<"more nos given\n"; exit(0);
			}
			if(v!=-1)
			if(v<0)
			{cout<<"no neg nos\n"; exit(0);}
			
			arr[p++]=v;
			
			
	}
	if(ctr!=n)
	{
		cout<<"number of nodes != given number\n"; exit(0);
	}
	
	if(arr[0]==-1 &&  n!=0)
	{cout<<"invalid input\n"; exit(0);}
	
	node *np=make(arr[0]);
	root=np;
	//cout<<root->val;
	create(root,arr,0,p,n);
	
}

int main()
{
node *list[1000];
for(int i=0;i<1000;i++)
list[i]=NULL;
root=NULL;
long long n=-115;
cin>>n;

if(n==-115)
{cout<<"empty\n";exit(0);}
if(n<0)
{cout<<"no neg\n";exit(0);}
createbt(n);

debug();

int c=0;
checking(root,c);
if(c!=n)
{cout<<"invalid input\n";exit(0);}

debug();

inorder(root);
cout<<endl;
makelist(root,0,list);

int h=0;
while(1)
{
	if(list[h]==NULL)
	break;
	inorder2(list[h]);
	h++;
	cout<<endl;
	
	debug();
}
return 0;
}
