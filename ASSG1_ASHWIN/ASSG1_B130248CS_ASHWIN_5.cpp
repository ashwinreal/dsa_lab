#include<iostream>
using namespace std;

int sumrows(long m[20][20],long n)
{
	long r=0;
	long sr=0;
	for(long i=0;i<n;i++)
	{r=0;
	for(long j=0;j<n;j++)
	r+=m[i][j];
	if(i==0)
	sr=r;
	if(r!=sr)
	return 0;
	}
	return 1;

}
int sumclmns(long m[20][20],long n)
{
	long r=0;
	long sc=0;
	for(long i=0;i<n;i++)
	{r=0;
	for(long j=0;j<n;j++)
	r+=m[j][i];
	if(i==0)
	sc=r;
	if(r!=sc)
	return 0;
	}
	return 1;

}
int sumdia(long m[20][20],long n)
{
	long r1=0;
	long r2=0;
	
	for(long i=0;i<n;i++)
	for(long j=0;j<n;j++)
	{
	if(i==j)
	r1+=m[i][j] ;
	if(i+j==n-1)
	r2+=m[i][j];
	}
	if(r1!=r2)
	return 0;
	
	return 1;

}
int main(){
	long n;
	int flag=0;
	cout<<"enter value for n\n";
	cin>>n;
	
	long m[20][20];
	long arr[10001];
	long sum=0;
	if(n<=0)
	cout<<"n should be a number and greater than 0\n";
	else
	{
	cout<<"enter the elements\n";
	for(long i=1;i<=n*n;i++)
	arr[i]=0;
	
	for(long i=0;i<n;i++)
	for(long j=0;j<n;j++)
	{
		cin>>m[i][j];
		sum+=m[i][j];
		if(flag==0)
		if(m[i][j]<1||m[i][j]>n*n)
		flag=1;
		else
		{
			if(arr[m[i][j]]>0)
			flag=1;
			else
			arr[m[i][j]]++;
		}
		
	}
	if(flag==1)
	cout<<"No\n";
	else
	{
		if(sumrows(m,n)==1&&sumclmns(m,n)==1&&sumdia(m,n)==1)
		cout<<"Yes\n";
		else
		cout<<"No\n";	
	//	cout<<sum<<sumrows(m,n)<<sumclmns(m,n)<<sumdia(m,n);
	
	}
		
		
}
	
}
