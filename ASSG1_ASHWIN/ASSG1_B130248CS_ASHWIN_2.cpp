#include<iostream>
#include<string>
using namespace std;
/*
            space not detected!!!!
            no input check

*/
int check(string a)
{
	long i;
	for( i=0;i!=a.length();i++)
	if(!((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z')))
	break;
	
	if(i==a.length())
	return 1;
	else
	return 0;
}
int main()
{
	string s,sub;
	int arr[10000];
	//cin>>s>>sub;
	cout<<"enter string 1\n";
	getline(cin,s);
	cout<<"enter string 2\n";
	getline(cin,sub);
	
	long long pos=0;
	if(check(s)==0||check(sub)==0)
	cout<<"invalid inputs , only aplhabets allowed\n";
	else
	{
	for(long long i=0;i<s.length();i++)
	{
		long long count=0;
		while(count<sub.length())
		{
			if(sub[count]!=s[i+count])
			break;
			count++;
		}
		if(count==sub.length())
		arr[pos++]=i;
		
	
	}
	if(pos==0)
	cout<<"No\n";
	else
	{
		cout<<"YES\n";
		for(long long u=0;u<pos;u++)
		cout<<arr[u]<<endl;
	}
	}
	return 0;
}
