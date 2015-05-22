#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void swap(int arr[],int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

int partition(int arr[],int start,int end,int pivot,int pivpos)
{
	swap(arr,start,pivpos);
	int i=start+1;
	for(int j=i;j<=end;j++)
	{
		if(arr[j]<pivot)
		{
			swap(arr,j,i);
			i++;
		}
		
	}
	swap(arr,i-1,start);
	return i-1;
	
}
void quicksort(int arr[],int start,int end)
{
	if(start<end)
	{
		int pivot1=start+(rand()%(end-start+1));
		int pivot2=partition(arr,start,end,arr[pivot1],pivot1);
		quicksort(arr,start,pivot2-1);
		quicksort(arr,pivot2+1,end);
    }
	
	
	
}
//find rightmost element such that it is smaller than its next element 
int find_rightmost(int arr[],int size)
{
	int i;
	for(i=size-2;i>=0;i--)
	{
		if(arr[i]<arr[i+1])
		break;
	}
	if(i<0)
	return -1;
	else
	return i;
}
int next_permutation(int prev_perm[],int size)
{
	int first=find_rightmost(prev_perm,size);
	//cout<<prev_perm[first];
	if(first!=-1)
	{
	int k;
	int second;//smallest element greater than first to the right of first
	for( k=first+1;k<size;k++)
	if(prev_perm[k]>prev_perm[first])
	{
	second=k;
	break;
	}
	for(int u=k+1;u<size;u++)
	{
	if(prev_perm[u]>prev_perm[first]&&prev_perm[u]<prev_perm[second])
	second=u;
	
	}
	//cout<<prev_perm[second];
	swap(prev_perm,first,second);
	quicksort(prev_perm,first+1,size-1);
	
	return 1;
	}
	else
	return 0;
    
}
int checkin(int arr[10],int matrix[10][10],int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{   int flag=1;
		int flag2=0;
		for( j=0;j<n;j++)
		{
			if(matrix[i][arr[j]]==1)
			break;
		}
		if(j==n)
		flag=1;
		else
		{
			for(int u=j+1;u<n;u++)
			if(matrix[i][arr[u]]==0)
			{
			flag2=1;
			}
			else
			{
				if(flag2==1)
				{
					flag=0;
					//cout<<"!";
					break;
				}
			}
		}
		if(flag==0)
		break;
	}
	if(i==m)
	{
		cout<<"Yes\n";
		for(int k=0;k<n;k++)
		cout<<arr[k]+1;
		cout<<endl;
		return 1;
	}
	else
	return 0;
	
}
void all_permutations(int prev_perm[],int size,int matrix[10][10],int m,int n)
{
	
	int f=next_permutation(prev_perm,size);
	if(f==1)
	{
		/*for(int i=0;i<size;i++)
		cout<<prev_perm[i];
		cout<<endl;*/
		if( checkin(prev_perm,matrix, m, n)==1)
		;
		else
		all_permutations(prev_perm,size,matrix,m,n);
	}
	else
	cout<<"No\n";
	
	
	
}
int check(int m)
{
	if(m<1||m>10)
	return 0;
	else
	return 1;
}

int main()
{
 	/*int arr[]={1,2,3,4};//must be sorted in non-decreasing order
	for(int i=0;i<4;i++)
	cout<<arr[i];
	cout<<endl;
	all_permutations(arr,4);
	*/
	cout<<"enter m and n\n";
	int m,n;
	int matrix[10][10],arr[10];
	cin>>m>>n;
	if(check(m)!=1||check(n)!=1)
	cout<<"invalid input\n";
	else
	{
		cout<<"enter elements of matrix\n";
		for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{	int temp;
			cin>>temp;
			if(temp!=0||temp!=1)
			{cout<<"invalid input only 0 and 1 is expected\n";
			
			exit(0);}
			cin>>matrix[i][j];
		}
		
		for(int i=0;i<n;i++)
		arr[i]=i;
		
		if( checkin(arr, matrix, m, n)==1)
		;
		else
		all_permutations(arr,n,matrix,m,n);
		
		//int arr[]={3,1,0,4,2};
		//int arr[]={0,1,2,3,4};
		//cout<<checkin(arr,matrix, m,n);
	}
	return 0;
}
