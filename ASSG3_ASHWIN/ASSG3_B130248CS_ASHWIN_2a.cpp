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
		//return 0;
		exit(0);
	}
	else
	if(ch!='\n' && ch!=EOF && ch!=' ')
	{
		cout<<"characters and special symbols not allowed\n";
		//return 0;
		exit(0);
	}else
	return 1;
}
void enq(long long q[],long long &head,long long &tail,long long ele)//head point to first input
{
		if(tail + 1>= limit)
		{
			cout<<"overflow!!\n";
		}
		else
		{
			
		if(head==-1)
		{
			head++;
		}
				
		if(tail>=max)
		cout<<"overflow\n";
		else{
		tail++;
		q[tail]=ele;
		
		}
		}
}
long long dq(long long q[],long long &head,long long &tail)
{
	if(head==-1)
	{
	
	return -1;
	}
	if(head==tail)
	{
		long long temp =head;
		head=tail=-1;
		return q[temp];
		
	}
	else
	{
	long long temp =head; 
	long long sh=q[temp];//
	
	head++;
	//
	for(int i=0;i<tail;i++)
	q[i]=q[i+1];
	
	head--;
	tail--;
	//
//	return q[temp];//
 return sh; 
	}
	
	
}
long long peek(long long q[],long long head)
{
	if(head==-1)
	return -1;
	else
	{
	return q[head];
	}
}
void show(long long q[],long long head,long long tail)
{
	if(head==-1)
	cout<<"no element present\n";
	else
	{
		for(long long i=head;i<=tail;i++)
		cout<<q[i]<<" ";
		cout<<endl;
	}
}

int main()
{
	long long q[max];
	long long head,tail;
	head=tail=-1;
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
				enq(q,head,tail,ele);
				break;
			}
			case 2 :
			{
				long long cp=dq(q,head,tail);
				if(cp==-1)
				cout<<"EMPTY\n";
				else
				cout<<cp<<endl;
				break;
			}
			case 3 :
				{
				long long co=peek(q,head);
				if(co==-1)
				cout<<"EMPTY\n";
				else
				cout<<co<<endl;
				break;
				}
			case 4 :
				{
				show(q,head,tail);
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
