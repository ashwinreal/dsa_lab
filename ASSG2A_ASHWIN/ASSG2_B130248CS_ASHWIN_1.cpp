#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;
long long arrp[10000000];

void merge8(char fn[64][7])// total n files ie 64 files
{
	char filename[8][8]; //for 8 new files
	for(int i=0;i<8;i++)
	{
		int q=i%10;
		int w=(i/10)%10;
		int y=i/100;
		filename[i][0]='0'+q;
		filename[i][1]='0'+w;
		filename[i][2]='0'+y;
		filename[i][3]='.';
		filename[i][4]='t';
		filename[i][5]='x';
		filename[i][6]='t';
		filename[i][7]='\0';
	//	cout<<filename[i];
		
	}
	fstream fina[8];//for 8 new merged files
	int s=0-8;
	int e=7-8;
	for(int t=0;t<8;t++)
	{ 
		cout<<"merging "<<t<<endl;
	fina[t].open(filename[t],ios::out);
	s+=8;
	e+=8;
	fstream f[8];// open 8 out of 64 sorted files 
	for(int a=0;a<=7;a++)
	{
			f[a].open(fn[a+s],ios::in);
	}
	bool ff[8]={false};
	int ctrf=0;
	long long  minarr[8],mpos,mine;
	for(int u=0;u<8;u++)
	{
		f[u]>>minarr[u];
	}
	while(ctrf!=8)
	{
		mine=minarr[0];
		mpos=0;
		for(int u=0;u<8;u++)
		{
			if(mine>minarr[u])
			{
				mpos=u;
				mine=minarr[u];
			}
		}
		fina[t]<<mine;
		fina[t]<<'\n';
		if(f[mpos].eof())
		{minarr[mpos]=10000000000;
		if(ff[mpos]==false)
		{ff[mpos]=true;
		ctrf++;
		//cout<<ctrf;
		}
		}
		else
		{
			f[mpos]>>minarr[mpos];
		}
	}
	
	
	
	for(int a=0;a<=7;a++)
	{
			f[a].close();
	}
}
}
void merge4(char fn[8][8])// total n files ie 8 files
{
	char filename[2][9]; //for 2 new files
	for(int i=0;i<2;i++)
	{
		int q=i%10;
		int w=(i/10)%10;
		int y=(i/100)%10;
		int p=i/1000;
		filename[i][0]='0'+q;
		filename[i][1]='0'+w;
		filename[i][2]='0'+y;
		filename[i][3]='0'+p;
		filename[i][4]='.';
		filename[i][5]='t';
		filename[i][6]='x';
		filename[i][7]='t';
		filename[i][8]='\0';
	//	cout<<filename[i];
		
	}
	fstream fina[2];//for 2 new merged files
	int s=0-4;
	int e=3-4;
	for(int t=0;t<2;t++)
	{ 
	cout<<"merging "<<t<<endl;
	fina[t].open(filename[t],ios::out);
	s+=4;
	e+=4;
	fstream f[4];// open 4 out of 64 sorted files 
	for(int a=0;a<=3;a++)
	{
			f[a].open(fn[a+s],ios::in);
	}
	bool ff[4]={false};
	int ctrf=0;
	long long  minarr[4],mpos,mine;
	for(int u=0;u<4;u++)
	{
		f[u]>>minarr[u];
	}
	while(ctrf!=4)
	{
		mine=minarr[0];
		mpos=0;
		for(int u=0;u<4;u++)
		{
			if(mine>minarr[u])
			{
				mpos=u;
				mine=minarr[u];
			}
		}
		fina[t]<<mine;
		fina[t]<<'\n';
		if(f[mpos].eof())
		{minarr[mpos]=10000000000;
		if(ff[mpos]==false)
		{ff[mpos]=true;
		ctrf++;
		//cout<<ctrf;
		}
		}
		else
		{
			f[mpos]>>minarr[mpos];
		}
	}
	
	
	
	for(int a=0;a<4;a++)
	{
			f[a].close();
	}
}
}

void merge2(char fn[2][9])// total n files ie 2 files
{
	char filename[1][10]; //for 1 new files
	for(int i=0;i<1;i++)
	{
		int q=i%10;
		int w=(i/10)%10;
		int y=(i/100)%10;
		int p=(i/1000)%10;
		int o=i/10000;
		filename[i][0]='0'+q;
		filename[i][1]='0'+w;
		filename[i][2]='0'+y;
		filename[i][3]='0'+p;
		filename[i][4]='0'+o;
		filename[i][5]='.';
		filename[i][6]='t';
		filename[i][7]='x';
		filename[i][8]='t';
		filename[i][9]='\0';
	//	cout<<filename[i];
		
	}
	fstream fina[1];//for 1 new merged files
	int s=0-2;
	int e=1-2;
	for(int t=0;t<1;t++)
	{ 
	cout<<"merging "<<t<<endl;
	fina[t].open(filename[t],ios::out);
	s+=2;
	e+=2;
	fstream f[2];// open 1 out of 2 sorted files 
	for(int a=0;a<=1;a++)
	{
			f[a].open(fn[a+s],ios::in);
	}
	bool ff[2]={false};
	int ctrf=0;
	long long  minarr[2],mpos,mine;
	for(int u=0;u<2;u++)
	{
		f[u]>>minarr[u];
	}
	while(ctrf!=2)
	{
		mine=minarr[0];
		mpos=0;
		for(int u=0;u<2;u++)
		{
			if(mine>minarr[u])
			{
				mpos=u;
				mine=minarr[u];
			}
		}
		fina[t]<<mine;
		fina[t]<<'\n';
		if(f[mpos].eof())
		{minarr[mpos]=10000000;
		if(ff[mpos]==false)
		{ff[mpos]=true;
		ctrf++;
		//cout<<ctrf<<" "<<mpos;
		}
		}
		else
		{
			f[mpos]>>minarr[mpos];
		}
	}
	
	
	
	for(int a=0;a<2;a++)
	{
			f[a].close();
	}
}
}


void swap(long long arr[],long long i,long long j)
{
	long long temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

long long partition(long long arr[],long long start,long long end,long long pivot,long long pivpos)
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
void quicksort(long long arr[],long long start,long long end)
{
	if(start<end)
	{
		long long pivot1=start+(rand()%(end-start+1));
		long long pivot2=partition(arr,start,end,arr[pivot1],pivot1);
		quicksort(arr,start,pivot2-1);
		quicksort(arr,pivot2+1,end);
    }
	
	
	
}

void sortfile(char fname[10])
{
	fstream f;
	f.open(fname,ios::in);
	
	long long i=0;
	while(!f.eof())
	{
		f>>arrp[i++];
	}
	quicksort(arrp,0,i-1);
	f.close();
	
	f.open(fname,ios::out);
	//cout<<i;
	int k=0;
	while(k<i)
	{
		f<<arrp[k++];
		f<<'\n';
	}
	f.close();
	
}
void generate()
{
	fstream f;
	f.open("bigfile.txt",ios::out);
	while(1)
	{
	long long end=f.tellp();
	if(end>=1024*1024*256)
	{
		break;
	}
	long long r=rand()%10000;
	f<<r;
	f<<'\n';
	}
	f.close();
}

void create64()
{
	cout<<"start\n";
	char filename[64][7];
	for(int i=0;i<64;i++)
	{
		int q=i/10;
		int w=i%10;
		filename[i][0]='0'+ q;
		filename[i][1]='0'+ w;
		filename[i][2]='.';
		filename[i][3]='t';
		filename[i][4]='x';
		filename[i][5]='t';
		filename[i][6]='\0';
		//cout<<filename[i];
		
	}
	fstream f[64];
	fstream fb;
	fb.open("bigfile.txt",ios::in);
	if(!fb)
	cout<<"error bigfile";
	else
	for(int i=0;i<64;i++)
	{
		
		if(fb.eof())
		break;
		
		long long end=0;
		f[i].open(filename[i],ios::out);
		if(!f[i])
		cout<<"error";
		else{
		cout<<"creating file "<<i<<endl;
		while(end<1024*1024*4 && !(fb.eof()))
		{
			
			long long r;
			fb>>r;
			f[i]<<r;
			f[i]<<'\n';
			end=f[i].tellp();
		}
		f[i].close();
		sortfile(filename[i]);
		}
	}
	fb.close();
	
	
}
int main()
{
	//generate();
	create64();
		char filename[64][7];
	for(int i=0;i<64;i++)
	{
		int q=i/10;
		int w=i%10;
		filename[i][0]='0'+ q;
		filename[i][1]='0'+ w;
		filename[i][2]='.';
		filename[i][3]='t';
		filename[i][4]='x';
		filename[i][5]='t';
		filename[i][6]='\0';
		//cout<<filename[i];
		
	}
	merge8(filename);
	char filename2[8][8];
	for(int i=0;i<8;i++)
	{
		int q=i%10;
		int w=(i/10)%10;
		int y=i/100;
		filename2[i][0]='0'+q;
		filename2[i][1]='0'+w;
		filename2[i][2]='0'+y;
		filename2[i][3]='.';
		filename2[i][4]='t';
		filename2[i][5]='x';
		filename2[i][6]='t';
		filename2[i][7]='\0';
	//	cout<<filename[i];
		
	}
	merge4(filename2);
	
	char filename3[2][9]; 
	for(int i=0;i<=1;i++)
	{
		int q=i%10;
		int w=(i/10)%10;
		int y=(i/100)%10;
		int p=(i/1000)%10;
		
		filename3[i][0]='0'+q;
		filename3[i][1]='0'+w;
		filename3[i][2]='0'+y;
		filename3[i][3]='0'+p;
		
		filename3[i][4]='.';
		filename3[i][5]='t';
		filename3[i][6]='x';
		filename3[i][7]='t';
		filename3[i][8]='\0';
	//	cout<<filename[i];
		
	}
	merge2(filename3);
	return 0;
}
