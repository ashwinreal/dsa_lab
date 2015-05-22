
// check for empty file !!!!!!!!!!!!!!!11

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
node *stack[1000];
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
	
	node *np=new node;
	np->l=NULL;
	np->r=NULL;
	np->val=v;
	
	return np;
}


void createbstnw(node *root,int arr[],int start,int end)
{
	/*int min=findfirstmin(arr,start,end);
	int max=findfirstmax(arr,start,end);*/
	int min,max;
	if(min!=-1)
	{
		node *np=make(arr[min]);
		root->l=np;
		createbstnw(root->l,arr,min+1,max-1);
	}
	if(max!=10000)
	{
		node *np=make(arr[min]);
		root->r=np;
		createbstnw(root->r,arr,max+1,end);
	}
}

void inorder(node *root)
{
	if(root!=NULL)
	{
			cout<<"(";
			cout<<root->val<<" ";
			inorder(root->l);
			inorder(root->r);
			cout<<")";
	}
	else
	cout<<"()";
}


void createbst(int arr[],int i,int top,int v)
{
	int y;
while(i<v)  // should I give top >=0 ??
{
	debug();
	//cout<<arr[i]<<endl;;
	//inorder(root);
	//cout<<endl;
node* n=make(arr[i]);
int f=0;

while(  top >= 0 && stack[top]->val < arr[i]) 
		{top--;f=1;}
		
		debug();
		//cout<<top<<" "<<arr[i]<<endl;
	/*if(f==1){
	stack[top+1]->r=n;
	top++;
	stack[top]=n;
	i++;}*/
	//createbst(arr,++i,top,v);	
	if(f==1)
	{stack[top+1]->r=n;top++;stack[top]=n;}
else
{
	//cout<<arr[i]<<endl;;
	debug();
	stack[top]->l=n;
	top++;
	stack[top]=n;
	debug();
	//createbst(arr,++i,top,v);
	}
i++;
debug();	
		
		
	
}



}

int main()
{
	for(int i=0;i<1000;i++)
stack[i]=NULL;
int arr[1000];
int i=0;
int v;
while(cin>>v)
{
	if(v<0)
	{cout<<"no neg values\n";exit(0);}
	arr[i++]=v;
}
if(i==0)
{cout<<"empty\n";exit(0);}
root=make(arr[0]);
stack[0]=root;
int top=0;
int h=1;
cout<<"creating\n";
createbst(arr,h,top,i);
cout<<"created\n";
inorder(root);
return 0;	
}
