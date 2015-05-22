#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int m;
double a=(sqrt(5)-1706)/2;
struct node
{
	int val;
	node *next; 	
};
int hash(int v,int m,int i)
{
	int p=floor(m*( (a*v)- (floor(a*v))  ));
	return ((v%m) + i*p)%m;
}
node *make(int v)
{
	node * np=new node;
	np->val=v;
	np->next=NULL;
	return np;
}
void insert( int arr[],int v)
{
	int i=0;
	int h=hash(v,m,i);

	while(arr[h]!=-1706)
	{
		cout<<h<<" ";
		i++;
		if(i>=m)
		break;
		h=hash(v,m,i);
	}
	if(arr[h]==-1706)
	{
		arr[h]=v;
		cout<<h<<endl;
		return;
	}
	cout<<"out of space\n";
}
void search(int arr[],int v)
{
	int i=0;
	int h=hash(v,m,i);
	
	int flag=0;
	
	while(arr[h]!=v)
	{
		i++;
		if(i>=m)
		{
			flag=1;
			break;
		}
		if(arr[h]==-1706)
		{flag=1;
		break;}
		//cout<<"!";
		cout<<h<<" ";
		h=hash(v,m,i);
		
	}
	if(flag==0)
	cout<<h<<"found\n";
	else
	cout<<h<<"not found\n";
}
void check(int v)
{
	char ch=getchar();
	if(ch=='\n'||ch==' ')
	return;
	if(ch=='.')
	cout<<"no floating point\n";
	else
	cout<<"no alphabets and spcl chars\n";
	exit(0);
}
int main()
{
	
	cin>>m;
	check(m);
	if(m<0)
	{
		cout<<"invalid capacity\n";
		exit(0);
	}
	if(m==0)
	{
		cout<<"0 capacity\n";
		exit(0);
	}
	int arr[100000]={-1706};
	for(int i=0;i<100000;i++)
	arr[i]=-1706;
	while(1)
	{
	
	int c;
	cin>>c;
	if(!cin)
	{
		cout<<"inappropriate choice\n";
		exit(0);
	}
	switch(c)
	{
		case 0:
			{
				exit(0);				
				break;
			}
		case 1:
			{
				int v;
				cin>>v;
				check(v);
				insert(arr,v);
				break;
			}
		case 2:
			{
				int v;
				cin>>v;
				check(v);
				search(arr,v);
				break;
			}
	}
	
	}
	
	return 0;
}			
