#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<fstream>
using namespace std;
char arr[100001][100];
void checkint(long long n)
{
	char ch=getchar();
	if(ch=='.')
	{
		cout<<"error-floating point not allowed\n";
		exit(0);
	}
	else
	if(ch!='\n' && ch!=EOF)
	{
		cout<<"characters and special symbols not allowed only integers\n";
		exit(0);
	}
	
}
void swap(char arr[][100],int a,int b)
{
	char temp[100];
	strcpy(temp,arr[a]);
	strcpy(arr[a],arr[b]);
	strcpy(arr[b],temp);
}/*
void heapit(long long s,long long arr[],long long index)
{
	long long max=index;
	bool heap=true;
	if(key[2*index]>key[index])
	{
	heap=false;
	max=2*index;
	}
	if(2*index+1<=s)
	{
		if(key[max]<key[2*index +1])
		{
		max=2*index + 1;	
		heap=false;
		}
	}
	if(heap==false)
	{
		swap(arr,max,index);
		swap(key,max,index);
		heapit(s,arr,max);
	}
}
void build(long long arr[],int s)
{
	for(long long i=s/2;i>=1;i--)
	{
		heapit(s,arr,i);
	}
}
*/

/*void heapit(int arr[],int s)   // min heap indexes [0....n]
{
	for(int i=s/2-1;i>=0;i--)
	{
		int node=arr[i];
		int k=i;
		int j;
		bool heap=false;
		while(heap==false&&2*k+1<s)
		{
			j=2*k+1;
			if(j+1<s)
			if(arr[j]>arr[j+1])
			j=j+1;
			if(arr[j]<node)
			{
			arr[k]=arr[j];
			k=j;
		}else
		heap=true;
		}
		arr[k]=node;
	}
	
}
*/
//array indexing from [1....s]
void heapit(char arr[][100],int s) // create a maximum heap.... the parent is greater than children
{
	int i,j,k;
	char node[100];
	bool heaped;
	for(int i=(s)/2;i>=1;i--)
	{
		k=i;
		strcpy(node,arr[i]);
	    //node=arr[i];
		heaped=false;
		while(heaped==false && 2*k<=s)
		{
			j=2*k;
			if(j+1<=s) // two sub nodes are present
			{
				if(strcmp(arr[j+1],arr[j])>0)//if(arr[j+1]>arr[j]) // checking for larger of both
				j=j+1;
			}
			if(strcmp(node,arr[j])<0)	//if(node<arr[j])
			{
				strcpy(arr[k],arr[j]);
			//arr[k]=arr[j];
			k=j;
			}
			else
			heaped=true;
		}
		strcpy(arr[k],node);
		//arr[k]=node;
	}
}
void del_min(char arr[][100] ,long long &s)
{
	swap(arr,1,s);
	s=s-1;
	
	
}
void heap_sort(char arr[][100],long long s)///sort arr[1...s]
{
	long long ctr=1;
	long long  initial=s;
	while(ctr<=initial)
	{
		heapit(arr,s);
		//cout<<arr[1];
		del_min(arr,s);
		heapit(arr,s);
		
		//cout<<arr[ctr];
		ctr++;
		
		
	}
}
int check(char t[])
{
	long long i=0;
	char ch=getchar();
	if(ch==EOF)
	return 0;
	while(t[i]!='\0')
	{
		if(!(t[i]>='A'&&t[i]<='Z'))
		{
		cout<<"enter only upper case characters\n";
		exit(0);
		}
		i++;
		
	}
	return 1;
	
}
int main()
{
//	int arr[]={-1,5,7,1,2,9,11,8,3}; /// indexing from 1 
//int arr[]={-1,2,9,7,6,5,8}; /// indexing from 1 
	/*heapit(arr,1,6);
	for(int i=1;i<=6;i++)
	cout<<arr[i]<<" ";*/
	//cout<<arr[1];
	clock_t s1,e;
	long long s;
	cin>>s;
	//cout<<s;
	checkint(s);
	for(long long i=1;i<=s;i++){
		cin>>arr[i];
		int a=check(arr[i]);
		if(a==0)
		break;
		//cout<<i;
	}
	//cout<<"input done";
	s1=clock();
	heap_sort(arr,s);
	e=clock();
	for(long long i=1;i<=s;i++){
		cout<<arr[i]<<endl;
	
	}
	cout<<(float)(e-s1)/CLOCKS_PER_SEC<<endl;
}
