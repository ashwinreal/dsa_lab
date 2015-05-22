#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
long long arr[100000000];
void linear(long long arr[],long long i,long long size,long long k,long long flag )
{
	if(i<size)
	{
		if(arr[i]==k)
		{
		cout<<i<<endl;
		linear(arr,i+1,size,k,1);
		}
		else
		linear(arr,i+1,size,k,flag);
	}else
	if(flag==0)
	cout<<"-1\n";
	
	
}
int check(long long n)
{
	char ch=getchar();
	if(ch=='.')
	{
		cout<<"error-floating point not allowed\n";
		return 0;
	}
	else
	if(ch!='\n')
	{
		cout<<"characters and special symbols not allowed\n";
		return 0;
	}else
	return 1;
}
int main()
{
	long long k,n;
	char ch;
	cin>>n;
	int f=check(n);
	if(f==1)
	{
	
	for(long long i=0;i<n;i++)
	{
	cin>>arr[i];
	int ff=check(arr[i]);
	if(ff==0)
	exit(0);
	}
	cin>>k;
	int fff=check(k);
	if(fff==1)
	{
	linear(arr,0,n,k,0);
	}
	}
	return 0;
}
