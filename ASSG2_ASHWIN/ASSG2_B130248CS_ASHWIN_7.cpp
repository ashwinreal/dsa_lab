/*#include <iostream>
using namespace std;
void merge(int *,int, int , int );
void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}
void merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}
int main()
{
    int a[20], i;
    cout<<"enter  the elements\n";
    for (i = 0; i < 6; i++)
    {
        cin>>a[i];
    }
    mergesort(a, 0, 5);
    cout<<"sorted array\n";
    for (i = 0; i < 6; i++)
    {
        cout<<a[i];
    }
  

}
*/

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<ctime>
using namespace std;
long long c[100000000];
long long arr[100000000];


void checkint(long long n)
{
	char ch=getchar();
	if(ch=='.')
	{
		cout<<"error-floating point not allowed\n";
		exit(0);
	}
	else
	if(ch!='\n' && ch!=EOF)
	{
		cout<<"characters and special symbols not allowed only integers\n";
		exit(0);
	}
	
}

void merge(long long arr[],long long start,long long end)
{
	
	long long add=start+end;
	long long mid=(add)/2;
	long long i,k;
		i=k=start;
	long long j=mid+1;
	while(i<=mid&&j<=end)
	{
		if(arr[i]<arr[j])
		{
		c[k++]=arr[i];
		i++;
	    }
		else
		{
		
		c[k]=arr[j++];
		k++;
		}
	}
	while(i<=mid){
		c[k++]=arr[i];
		i++;
	}
	while(j<=end)
	{
		c[k]=arr[j++];
		k++;
	}
	for(long long p=start;p<=end;p++)
	arr[p]=c[p];
	;
}
void mergesort(long long arr[],long long start,long long end)
{
	if(start<end)
	{
		long long mid =(start+end)/2;
		mergesort(arr,start,mid);
		mergesort(arr,mid+1,end);
		merge(arr,start,end);
	}
}
int main()
{
	//long long arr[]={5,2,7,9,8,1,2,0,5,3,4,7};
	long long int n;
	clock_t s,e;
	cin>>n;
	checkint(n);
	for(long long i=0;i<n;i++)
	{
		cin>>arr[i];
		checkint(arr[i]);
	}
	s=clock();
	mergesort(arr,0,n-1);
	e=clock();
	/*for(long long i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}*/
	cout<<(float)(e-s)/CLOCKS_PER_SEC<<endl;
}





