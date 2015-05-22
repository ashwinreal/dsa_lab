#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
long long arr[100000000];
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
		cout<<(int)ch;
		cout<<"characters and special symbols not allowed only integers\n";
		exit(0);
	}
	
}
long long findmin(long long arr[],long long start,long long end)
{
	long long mid=(start+end)/2;
	//cout<<start<<end;
	if(end==-1)
	return 0;
	if(start==end)
	return start;
	else if(arr[mid]<arr[mid+1] && arr[mid]<arr[mid-1])
	return mid;
	else if(arr[mid]<=arr[end])
	findmin(arr,start,mid-1);
	else
	findmin(arr,mid+1,end);
	
}

int binsrch(long long a[],long long high,long long low,long long ele) // sorted in ascending
{
	long long val=0;
	
	 while(high>=low)
	 {
	 	long long mid=(high+low)/2;
	 	if(a[mid]==ele)
	 	{
	 		 cout<<mid<<endl;
	 		 return 1;
	 	}
	 	else if(a[mid]>ele)
	 	high=mid-1;
	 	else
	 	low=mid+1;
	 	
	 	
	 	
	 }	return 0;
	 
	 
}

int main()
{
	long long k,n;
	char ch;
	cin>>n;
	checkint(n);
	clock_t s,e;
	for(long long i=0;i<n;i++)
	{
	
	cin>>arr[i];
	checkint(arr[i]);
	}
	
	cin>>k;
	checkint(k);
	int f3;
	s=clock();
	long long pos=findmin(arr,0,n-1);
	if(arr[pos]==k)
	{
		cout<<pos;
		f3=1;
	}
	int f1=binsrch(arr,pos-1,0,k);
	int f2=binsrch(arr,n-1,pos+1,k);
	if(!(f1+f2+f3))
	cout<<"-1\n";
	e=clock();
	//cout<<(float)(e-s)/CLOCKS_PER_SEC<<endl;
	
	
	
	return 0;
}
