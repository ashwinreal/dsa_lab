#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<ctime>
using namespace std;
double arr[100000000];

void checkint(long long n)
{
	char ch=getchar();
	if(ch!='\n' && ch!=EOF)
	{
		cout<<"characters and special symbols not allowed only integers\n";
		exit(0);
	}
	
}

void swap(double arr[],long long i,long long j)
{
	double temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

long long partition(double arr[],long long start,long long end,double pivot,long long pivpos)
{
	swap(arr,start,pivpos);
	long long i=start+1;
	for(long long j=i;j<=end;j++)
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
void quicksort(double arr[],long long start,long long end)
{
	if(start<end)
	{
		long long pivot1=start+(rand()%(end-start+1));
		long long pivot2=partition(arr,start,end,arr[pivot1],pivot1);
		quicksort(arr,start,pivot2-1);
		quicksort(arr,pivot2+1,end);
    }
	
	
	
}

int main()
{
	long long n;
	clock_t s1,e1;
	//int arr[]={1,1,2,10,7,7,1,3,2,5,8,4,10,11,0};
	cin>>n;
	checkint(n);
	for(long long i=0;i<n;i++)
	{
	cin>>arr[i];
	checkint(arr[i]);
}
cout<<"input over\n";
s1=clock();
	quicksort(arr,0,n-1);
e1=clock();
	//int p=partition(arr,0,6,arr[0],0);
	for(long long i=0;i<n;i++)
	cout<<arr[i]<<endl;
//	cout<<endl<<p;
cout<<(float)(e1-s1)/CLOCKS_PER_SEC<<endl;
	return 0;
}



/*


#include<iostream>
using namespace std;

void swap (long long arr[],long long a ,long long b)
{
	long long temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}
long long partition (long long arr[],long long start,long long end,long long pivot,long long pivotpos)//0 th ele as pivot
{
	swap(arr[start],arr[pivotpos]);
	long long ctr=start;
	for(long long i=start+1;i<=end;i++)
	{
		if(arr[i]  <  arr[start])
		{
			swap(arr,ctr+1,i);
			ctr++;
		}
	}
	swap(arr[start],arr[ctr]);
	return ctr;
}
void quicksort(long long arr[],long long start,long long end)
{
	
	if(start<end)
	{
		long long pivot=partition(arr,start,end,arr[start],start);
		
		quicksort(arr,start,pivot-1);
		
		quicksort(arr,pivot+1,end);
	}	
}


int main()
{
	long long arr[]={5 ,4, 3 ,2 ,7 ,8 ,9 ,0 ,1};
//	int j=partition(arr,0,8,arr[0],0);
//	cout<<j<<endl;
	quicksort(arr,0,8);
	for(int i=0;i<9;i++)
	{
		cout<<arr[i]<<" ";
	}
	
	return 0;
}



*/









