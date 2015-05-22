#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstdio>
using namespace std;
#define max 100
int limit;
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
void push(long long stack[],long long &top,long long ele)
{
	if(top + 1 >= limit)
	cout<<"overflow\n";
	else
	stack[++top]=ele;	
}
long long pop(long long stack[],long long &top)
{
	if(top==-1)
	return -1;
	else
	{
	long long temp =top; 
	top--;
	return stack[temp];
	}
}
long long peek(long long stack[],long long top)
{
	if(top==-1)
	return -1;
	else
	{
	return stack[top];
	}
}
void show(long long stack[],long long top)
{
	if(top==0)
	cout<<"no element present\n";
	else
	{
		for(long long i=top;i>=0;i--)
		cout<<stack[i]<<" ";
		cout<<endl;
	}
}

int main()
{
	long long stack[max];
	long long top=-1;
	long long ele;
	cin>>limit;
	check(limit);
	while(1)
	{
		int c;
		cin>>c;
		switch(c)
		{
			case 1 :
				{
				
				cin>>ele;
				check(ele);
				push(stack,top,ele);
				break;
			}
			case 2 :
			{
				long long cp=pop(stack,top);
				if(cp==-1)
				cout<<"EMPTY\n";
				else
				cout<<cp<<endl;
				break;
			}
			case 3 :
				{
				long long co=peek(stack,top);
				if(co==-1)
				cout<<"EMPTY\n";
				else
				cout<<co<<endl;
				break;
				}
			case 4 :
				{
				show(stack,top);
				break;
				}
			case 0 :
				{
				exit(0);
				break;
				}
			default:
				cout<<"invalid choice\n";
		}
		
	}
	return 0;
}
