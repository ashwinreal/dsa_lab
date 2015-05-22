#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
/*
			no input check
*/
long long len(char temp[100])
{
	long long ret =0;
	for(ret=0;temp[ret]!='\0';ret++);
	return ret;
}
int check(char a[100])
{
	long i;
	for( i=0;a[i]!='\0';i++)
	if(!((a[i]>='A'&&a[i]<='Z')||(a[i]>='0'&&a[i]<='9')))
	break;
	if(a[i]=='\0')
	return 1;
	else
	return 0;
}
int main()
{
	int ff=0;
	union iid
	{
		long long int adhaar;
		char voter[7];
	};
	struct s{
		string name;
		int age;
		union iid id;
	}s1;
	
	cout<<"enter name\n";
	//cin>>s1.name;
	getline(cin,s1.name);
	cout<<"enter age\n";
	cin>>s1.age;
	

	if(s1.age<0)
	cout<<"invalid age\n";
	else
	if(s1.age<18)
	{
		cout<<"enter adhaar no\n";
		cin>>s1.id.adhaar;
		if(!cin)
		cout<<"enter valid adhaar no\n";
		else
		if(s1.age<0||s1.id.adhaar<0)
		cout<<"invalid input\n";
		else
		{
		               char c=getchar();
			if(c!='\n')
		cout<<"invalid adhaar\n";
		ff=1;
		}
		if(ff==0)
		cout<<s1.name<<","<<s1.age<<","<<s1.id.adhaar<<endl;
	}else
	{
		char temp[100];
		cout<<"enter voter-id\n";
		cin>>temp;
		if(len(temp)!=7 || check(temp)!=1)
		cout<<"invalid voter id\n";
		else
		{
		strcpy(s1.id.voter,temp);
		cout<<s1.name<<","<<s1.age<<","<<s1.id.voter;
		}
	}
	
	
	
	
}
