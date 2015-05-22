#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
long long arr[100000000];
void insertion_sort(long long arr[],long long size,int &count)
{
	
	for(long long i=1;i<size;i++)
	{
		long long key=arr[i];
		long long j=i-1;
		
		while(j>=0 && key<arr[j])
		{
			arr[j+1]=arr[j];
			count ++;
			j--;
		}
		arr[j+1]=key;
		
	}
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
	if(ch!='\n' && ch!=EOF)
	{
		cout<<"characters and special symbols not allowed\n";
		return 0;
	}else
	return 1;
}

int main()
{
	
	//long long arr[]={5 ,4, 3 ,2 ,7 ,8 ,9 ,0 ,1};
	long long k,n;
	char ch;
	cin>>n;
	clock_t s,e;
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
	int count =0;
	s=clock();
	insertion_sort(arr,n,count);
	e=clock();
	for(long long i=0;i<n;i++)
	cout<<arr[i]<<endl;
	cout<<count<<endl;
	cout<<(float)(e-s)/CLOCKS_PER_SEC<<endl;
	/*for(int i=0;i<9;i++)
	{
		cout<<arr[i]<<" ";
	}*/
	return 0;
	}	
}
