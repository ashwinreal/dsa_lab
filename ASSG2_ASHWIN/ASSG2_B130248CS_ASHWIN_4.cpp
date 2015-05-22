#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int cmp(char s1[],char s2[])
{
	long long i=0;
	while(s1[i]!= '\0'|| s2[i]!='\0')
	{
		if(s1[i]>s2[i])
		return 1;
		else
		if(s1[i]<s2[i])
		return 0;
		else
		{
			i++;
			
		}
		
	}
		if(s1[i]=='\0')
		return 0;
		else
		return 1;
}
void copy(char temp[],char s[] )
{
	long long i=0;
	while(s[i]!='\0')
	{
	temp[i]=s[i];
	i++;
	}
	temp[i]='\0';
}
void check(char t[])
{
	long long i=0;
	while(t[i]!='\0')
	{
		if(!(t[i]>='a'&&t[i]<='z'))
		{
		cout<<"enter only small case characters\n";
		exit(0);
		}
		i++;
		
	}
	
}
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

void select_sort(char s[10000][100],int m)
{
	long long i,j,pos;
	char temp[10000],temp2[10000];
	for(i=0;i<m;i++)
	{
		pos=i;
		copy(temp,s[i]);
	for(j=i+1;j<m;j++)
	{
		if(cmp(s[j],temp)==0)
		{
			pos=j;
			copy(temp,s[j]);
		}
		
	}
	copy(temp2,s[i]);
	copy(s[i],s[pos]);
	copy(s[pos],temp2);
	
	}
}




int main()
{
	clock_t s1,e1;
	//char s1[]="ashwaa;
	//char s2[]="ashwa";
	//cout<<cmp(s1,s2);
	char s[10000][100];
	long long m;
	cin>>m;
	checkint(m);
	for(long long i=0;i<m;i++)
	{
	
	cin>>s[i];
	check(s[i]);

	}
	s1=clock();
	select_sort(s,m);
	e1=clock();
	for(long long  i=0;i<m;i++)
	cout<<s[i]<<endl;
	cout<<(float)(e1-s1)/CLOCKS_PER_SEC<<endl;
	
	
	
	return 0;
}
