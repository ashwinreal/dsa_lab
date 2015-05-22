#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<fstream>
using namespace std;
void checkint(long long n)
{
	char ch=getchar();
	if(ch=='.')
	{
		cout<<"error-floating point not allowed\n";
		exit(0);
	}
	else
	if(ch!='\n')
	{
		cout<<"characters and special symbols not allowed only integers\n";
		exit(0);
	}
	
}

void check(string t)
{
	long long i=0;
	while(i!=t.length())
	{
		if(!(t[i]>='0'&&t[i]<='9') && !(t[i]>='A'&&t[i]<='F'))
		{
		cout<<"enter only 0-9 and A-F\n";
		exit(0);
		}
		i++;
		
	}
	
}
int runcase(char i)
{
	
	if(i-'0'>=0 && i-'0'<=9)
	return i-'0';
	else
	return i-'A'+ 10;
}
void radix(string arr[100000],long n)
{
	int p=1;
	
	while(p<=8)
	{
		vector<string> v1[16];
		for(long i=0;i<n;i++)
		{
			long r;
			long len=arr[i].size();
			if(len-p>=0)
			r=runcase(arr[i][len-p]);
			else
			 r=0;
			//cout<<r;
			v1[r].push_back(arr[i]);
		}
		long k=0;
		for(long i=0;i<16;i++)
		for(long j=0;j<v1[i].size();j++)
		{
			//if(p==7)
			//cout<<v1[i][j];
			arr[k++]=v1[i][j];
		}
		p++;
	}
}


int main()
{
	
	string arr[100000];
	long temp,n;
	cin>>n;
	checkint(n);
	clock_t s1,e1;
	for(long i=0;i<n;i++)
	{
		
		cin>>arr[i];
		check(arr[i]);
	}
	s1=clock();
	radix(arr,n);
	e1=clock();
	for(long i=0;i<n;i++)
	{
		
		cout<<arr[i]<<endl;
	}
	cout<<(float)(e1-s1)/CLOCKS_PER_SEC<<endl;
	/*vector<int> v1,v2;
	for(int i=0;i<5;i++)
	{
		int temp;
		cin>>temp;
		v1.push_back(temp);
	}
	for(int i=0;i<4;i++)
	{
		int temp;
		cin>>temp;
		v2.push_back(temp);
	}
	for(int i=0;i<5;i++)
	{
		int temp;
		cout<<v1[i]<<" ";
		
		//v1.push_back(temp);
	}
	cout<<endl;
	for(int i=0;i<4;i++)
	{
		int temp;
		cout<<v2[i]<<" ";
		
		//v1.push_back(temp);
	}
	cout<<endl;
	v1=v2;
	
	for(int i=0;i<5;i++)
	{
		int temp;
		cout<<v1[i]<<" ";
		
		//v1.push_back(temp);
	}
	cout<<endl;
	for(int i=0;i<4;i++)
	{
		int temp;
		cout<<v2[i]<<" ";
		
		//v1.push_back(temp);
	}
	string s1,s2;
	cin>>s1;
	cin>>s2;
	s1=s2;
	cout<<s1;*/
	
	return 0;
}
