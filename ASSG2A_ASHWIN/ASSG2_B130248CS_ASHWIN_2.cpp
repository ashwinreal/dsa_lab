#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstdio>
using namespace std;
long long select(long long arr[],long long start,long long end,long long stat);


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


void swap(long long arr[],long long i,long long j)
{
	long long temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
long long partition(long long arr[],long long start,long long end,long long pivot)
{
	long long i=start+1;
	long long ele=arr[pivot];
	swap(arr,pivot,start);
	for(long long j=start+1;j<=end;j++)
	{
		if(arr[j]<ele)
		{
			swap(arr,i,j);
			i++;
		}
	}
	swap(arr,start,i-1);
	return i-1;
}
void isort(long long arr[],long long start,long long end)
{
	for(long long i=start+1;i<=end;i++)
	{
		long long j=i;
		long long key=arr[i];
		while(key<arr[j-1] && j>start)
		{
			arr[j]=arr[j-1];
			j--;
		}
		arr[j]=key;
		
	}
}
/*long long mm(long long arr[],long long start,long long end)
{
	if(start-end<=5)
	{
		isort(arr,start,end);
		return (end-start/2);
	}
	else
	{
		select(arr,start,end,start+(end-start)/2);
	}
}*/
long long select(long long arr[],long long start,long long end,long long stat)
{
	if(start-end<5)
	{
		isort(arr,start,end);
		return start + stat;
	}
	
	long long k=0;
	for(long long i=start;i<=end;i=i+5)
	{
		if(i+4<=end)
		{
		isort(arr,i,i+4);
		swap(arr,k,i+2);//swap the median to start of array
		k++;
		}
		else
		{
		isort(arr,i,end);
		swap(arr,k,(i+end)/2);
		k++;
		}
	} 
	//step 1,2
	//now there are k medians
	long long mom=select(arr,0,k-1,(k-1)/2);
	                                              //partition into unique elements larger than mom and no those not
	long long p=partition(arr,start,end,mom);  
	
	if(p==stat)
	return p;
	else if(stat<p)
	select(arr,start,p-1,stat);
	else
	select(arr,p+1,end,stat-p);

}


int main()
{
	//long long arr[]={3,2,5,0,10,11,100,50,60,70,1,24,44,66,77,99,101,1000,10001,1010,1999,999,16};
	//isort(arr,0,12);
	//for(int i=0;i<=12;i++)
	//cout<<arr[i];
	//for(long long i=0;i<=22;i++)
	//cout<<arr[select(arr,0,22,i)]<<" ";
	
	/*for(int i=0;i<=10;i++)
	cout<<arr[i];*/
	
	long long arr[100000];
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		cin>>arr[i];
		
		int g=check(arr[i]);
		if(g==0)
		exit(0);
	}
	if(n%2==1)
	cout<<arr[select(arr,0,n-1,(n-1)/2)];
	else
	{
		float temp=(float)(arr[select(arr,0,n-1,(n)/2)] + arr[select(arr,0,n-1,(n-1)/2)])/2;
		cout<<temp;
	}	
	
	return 0;
}
