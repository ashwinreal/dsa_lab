#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<limits.h>
using namespace std;

struct node
{
		int val;
		node *l;
		node *r;
	
};
node *root;
node *next1;
node *next2;
node *next3;
node *next4;
int M=0;


void debug()
{
int d=0;
d++;
d++;
d--;
//cout<<"reached here\n";
}

node *leftmost(node * root)
{
node *tmp=root;
while(tmp->l!=NULL)
tmp=tmp->l;
return tmp;	
}

node *rightmost(node * root)
{
node *tmp=root;
while(tmp->r!=NULL)
tmp=tmp->r;
return tmp;	
}

void finddeep(node *root,int &k,int min,int max,int ctr)
{
	if(root==NULL)
	return;
	
	if(root->l==NULL && root->r==NULL )
	return;
	
	
	
	
	debug();
	
	if(root->l!=NULL)
	if(root->r==NULL)
	if(root->l->val <= root->val)
	{
		//cout<<root->val<<" ";
		if(!(root->l->val >= min && root->l->val < max))
		return;
		
		debug();
		
		
		k=k+1;
		next1=root->l;
		
		debug();
		
		max=root->val;
		
		if(ctr==1)
		next3=root->l;

		finddeep(root->l,k,min,max,1);
		
		debug();
		
	}
	if(root->r!=NULL)
	if(root->l==NULL)
	if(root->r->val > root->val )
	{
		//cout<<root->val<<" ";
		if(!(root->r->val >= min && root->r->val < max))
		return;
		
		debug();
		
		k=k+1;
		next2=root->r;
		
		debug();
		
		min=root->val;

		if(ctr==2)
		next4=root->l;

		finddeep(root->r,k,min,max,2);
		
		debug();
		
	}
	if(root->l!=NULL)
	if(root->r!=NULL)
	if(root->l->val <= root->val && root->r->val > root->val )
	{
		debug();
		
		if(!(root->l->val >= min && root->l->val < max))
		return;
		if(!(root->r->val >= min && root->r->val < max))
		return;
		
		debug();
		
		//cout<<root->val<<" ";
		k=k+2;
		next1=root->l;
		
		next2=root->r;
		
		debug();
		if(ctr==1)
		next3=root->l;
		if(ctr==2)
		next4=root->r;
		finddeep(root->l,k,min,root->val,1);
		finddeep(root->r,k,root->val,max,2);
	}
	
}

void lbst(node *root)
{
	if(root==NULL)
	return;
	
	int k=1;
	int min,max;
	min=-1;
	max=10000;
	
		node *rm=rightmost(root);
	node *lm=leftmost(root);
	
	next1=next2=next3=next4=root;
	finddeep(root,k,min,max,3);
	//cout<<endl;
	

	
	//if(k>M &&next1->l==NULL && next1->l==NULL&&next1->r==NULL && next1->r==NULL)
	if(k>M && rm==next4 && lm==next3)
	M=k;
	lbst(next1->l);
	lbst(next2->r);
	
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

void checking(node *root,int &c)
{
	if(root!=NULL)
	{
			c++;
			checking(root->l,c);
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
void create(node *&root,int arr[],int i,int p,int n)
{
	if(i>=p)
	return;
	if(root==NULL)
	return;
	
	debug();
	
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


void check_check_whether_assigned1()
{
	int o=0;
	o++;
//cout<<"returning 0\n";	
}

void check_check_whether_assigned2()
{
	int o=0;
	o++;
//cout<<"calling again\n";	
}



int ansis = 0; 


void check_check_whether_assigned3()
{
	int o=0;
	o++;
//cout<<"callfinished\n";	
}

int functionto(int &minit, int &maxit,node *&root, bool &isit)
{
 
  if (root == NULL)
  {
	  debug();
     isit = 1; 
     debug();
     return 0;   
  }
 bool flgl = false;
 int nnn=0;
 int mmm=0;
  int min = INT_MAX;
 
  
  
 
  debug();
  
  bool flgr = false;
 int uu=0;
   int ls; 
 debug();
 int rs;
  maxit = INT_MIN;
  int ttt=0;;
  debug();
  
  
  check_check_whether_assigned2();
  ls = functionto( minit, maxit,root->l, isit);
  check_check_whether_assigned3();
  
  if (isit == 1 && root->val > maxit)
     {
		 debug();
		 flgl = true;
		 debug();
		 }
 
  
  min = minit;
 debug();
  
  minit =  INT_MAX;
  
  check_check_whether_assigned2();
  rs = functionto( minit, maxit,root->r, isit);
  check_check_whether_assigned3();
  
  debug();
  if (isit == 1 && root->val < minit)
     {
		 debug();
		 flgr = true;
		 debug();}
 
  
  if (min < minit)
     {minit = min;
		 debug();
		 }
  if (root->val < minit) 
     {minit = root->val;debug();}
  if (root->val > maxit)
     {debug();;maxit = root->val;
		 
		 debug();}
 
  
  if(flgl && flgr)
  {
	  int flagout=1;
	  //cout<<flagout;
     if (ls + rs + 1 > ansis)
        { ansis= ls + rs + 1;debug();}
        debug();
     return ls + rs + 1;
  }
  else
  {
    debug();
     isit = 0;
     check_check_whether_assigned1();
     return 0;
  }
}

int main()
{
root=NULL;
long long n=-115;
cin>>n;
if(n==-115)
{cout<<"empty\n";exit(0);}
if(n<0)
{cout<<"non neg\n";exit(0);}
createbt(n);
int c=0;
checking(root,c);
if(c!=n)
{cout<<"invalid input\n";exit(0);}

inorder(root);
//cout<<endl;
//lbst(root);
//cout<<"\nMax bst size is: "<<M<<endl;
int max = INT_MIN;  
bool is_bst = 0;

  int min = INT_MAX; 
  
 
   
  
 check_check_whether_assigned1();
  functionto(min, max, root,is_bst);
  debug();
	cout<<endl<<ansis<<endl;


return 0;
}
