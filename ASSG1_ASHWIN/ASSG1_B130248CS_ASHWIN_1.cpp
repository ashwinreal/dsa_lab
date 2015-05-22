#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

/*
		trailing zeroes not supported
		no input check
*/
void print0(long long n)
	{
	if(n==0)
	;
	else
	{
	cout<<0;
	print0(n-1);
    }
	}
long long power(long long b,long long p)
{
	long long ans=1;
	
	for(long long i=0;i<p;i++)
	ans*=b;
	return ans;
}
long long calc0(long long n)
	{
		if(n%10!=0||n==0)
		return 0;
		else
		return 1+calc0(n/10);
	}
long long reverse(long long n)
{
	if(n/10==0)
	return n;
	else
	{
		
		long long dig=(log(n)/log(10));
		return ((n%10)*(power(10,dig)))  +  reverse(n/10) ;
	}
	
}

int main()
{    long long n,z;
	z=0;
	cout<<"enter the value of the number\n";
	cin>>n;
/*	while(n%10==0)
	{
		z++;
		n/=10;
	}*/
	/*for(long i=0;i<z;i++)
	cout<<0;*/
	if(n<0)
	cout<<"enter positive numbers only!\n";
	else
	if(!cin)
	cout<<"enter valid input\n";
	else
	{
	char c=getchar();
	if(c!='\n')
	cout<<"invalid input\n";
	else{
    	z=calc0(n);
	print0(z);
	cout<<reverse(n)<<endl;}
	}
	return 0;
}
