#include<iostream>
using namespace std;
#include<cstdlib>
#include<fstream>
#include<cstdio>
int check(long long n)
{
	char ch=getchar();
	if(ch=='.')
	{
		cout<<"error-floating point not allowed\n";
		return 0;
	}
	else
	if(ch!='\n' && ch!=EOF && ch!=' ')
	{
		cout<<"characters and special symbols not allowed\n";
		return 0;
	}else
	return 1;
}
void swap(long long arr[],long long a,long long b)
{
	long long temp =arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}
/*void heapit(long long s,long long arr[],long long key[],long long index) //// its min heap not max since 1 is max priority
{
	long long max=index;
	bool heap=true;
	if(key[2*index]<key[index])
	{
	heap=false;
	max=2*index;
	}
	if(2*index+1<=s)
	{
		if(key[max]<key[2*index +1])
		{
		max=2*index + 1;	
		heap=false;
		}
	}
	if(heap==false)
	{
		swap(arr,max,index);
		swap(key,max,index);
		heapit(s,arr,key,max);
	}
}*/
/*void heapit(long long s,long long arr[],long long key[],long long index) // create a min heap.... the parent is greater than children
{
	long long node,kn, i,j,k;
	
	bool heaped;

	for(int i=(s)/2;i>=1;i--)
	{
		k=i;
		node=arr[i];
		kn=key[i];
	    //node=arr[i];
		heaped=false;
		while(heaped==false && 2*k<=s)
		{
			j=2*k;
			if(j+1<=s) // two sub nodes are present
			{
				if(key[j+1]<key[j])
				j=j+1;
			}
			if(node>key[j])	
			{
				key[k]=key[j];
				arr[k]=arr[j];
			//arr[k]=arr[j];
			k=j;
			}
			else
			heaped=true;
		}
		arr[k]=node;
		key[k]=kn;
		//arr[k]=node;
	}
}
*/
void heapit(long long s,long long arr[],long long key[],long long index)
{
	long long m=index;
	if(2*index<=s)
	{
		if(key[m]>key[2*index])
		{
		m=2*index;	
		}
		if(2*index+1<=s)
		{
		
		if(key[m]>key[2*index +1])
		{
		m=2*index + 1;	
		}
		}
		swap(arr,m,index);
		swap(key,m,index);
		if(m!=index)
		heapit(s,arr,key,m);
	}
}
void build(long long arr[],long long key[],long long s)
{
	for(long long i=s/2;i>=1;i--)
	{
		heapit(s,arr,key,i);
	}
}
void inc_pri(long long arr[],long long key[],long long index)//array passed after change
{

	long long parent=index/2;
	if(parent>=1)
	if(key[parent]>key[index])
	{
		swap(arr,parent,index);
		swap(key,parent,index);
		inc_pri(arr,key,parent);
	}
}
void insert(long long arr[],long long key[],long long &n)
{
	long long value,k;
	cin>>value;
	check(value);
	cin>>k;
	if(n>=100000000)
	cout<<"overflow\n";
	else
	{
		n++;
		arr[n]=value;
		key[n]=k;
		inc_pri(arr,key,n);
	//	cout<<arr[1]<<" "<<key[1]<<"\n";//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
}
void remove(long long arr[],long long key[],long long &n)//remove max priority
{
	if(n==0)
	cout<<"Empty\n";
	else{
	cout<<arr[1]<<" "<<"("<<key[1]<<")"<<endl;
	swap(arr,n,1);
	swap(key,n,1);
	n--;
	heapit(n,arr,key,1);
	}
}
void peek(long long arr[],long long key[],long long n)
{
	if(n>=1)
	cout<<arr[1]<<" "<<"("<<key[1]<<")"<<endl;
	else 
	cout<<"Empty\n";
}
int main()
{
	long long arr[100000];
	long long key[100000];
	long long n=0;
	/*cin>>n;
	for(long long i=1;i<=n;i++)
	{
	cin>>arr[i];
	cin>>key[i];
	}
	build(arr,key,n);*/
	int c;
	while(1)
	{
		cin>>c;
		switch(c)
		{
			case 1:
				insert(arr,key,n);
				break;
			case 2:
				remove(arr,key,n);
				//cout<<n;
				break;
			case 3:
				peek(arr,key,n);
				break;
			case 4://// wrong! actually find the indices according to element 
			/*	long long index;
				long long k;
				cin>>index>>k;
				key[index]=k;
				inc_pri(arr,key,index);*/
				long long value,k;
				cin>>value>>k;
				for(long long i=1;i<=n;i++)
				{
					if(arr[i]==value)
					{
						key[i]=k;
						inc_pri(arr,key,i);
					}
				}
				break;
			case 0:
				exit(0);
				break;
			default:
				for(int i=1;i<=n;i++)
				cout<<arr[i]<<" "<<key[i]<<endl;
				cout<<"invalid choice\n";
		}
	}
	//cout<<arr[1];
	return 0;
}

