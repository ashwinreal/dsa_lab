#include<fstream>
#include<iostream>
#include<cstdio>
/*
	
	input check
	name of file
	a,b,c,d
	space enter
	
*/
using namespace std;
struct stud
{
	char name[30];
	char roll[30];
	char branch[30];
	float marks[5];
	float total;
}s1,s2;
float calctot(float arr[5])
{
	float tot=0;
	for(int i=0;i<5;i++)
	tot=tot + arr[i];
	return tot;
}
void append(char *a)
{
	ofstream f;
	f.open(a,ios::app);
	if(!f)
	cout<<"file not present!\n";
	else
	{
	
	cout<<"enter name,roll number,branch and marks of 5 subjects \n";
	//cin.ignore();
	//cin.getline(s1.name,30);
	cin>>s1.name;
	//cin.getline(s1.name,30);
	///cout<<"enter roll of student\n";
	//cin.ignore();
	cin>>s1.roll;
	//cout<<"enter branch of student\n";
	//cin.ignore();
	//getline(cin,s1.branch);
	cin>>s1.branch;
	//cout<<"enter marks of student\n";
	int ff=0;
	for(int i=0;i<5;i++)
	{
	cin>>s1.marks[i];
	if(!cin)
	ff=1;
	}
	if(ff==1)
	cout<<"invalid input\n";
	else
	{
	s1.total=calctot(s1.marks);
	
	f.write((char*)&s1,sizeof(s2));
	}
	cout<<endl;
	f.close();}
}
void count(char *a)
{
	ifstream f;
	f.open(a,ios::in);
	long long count =0;
	float tot=0.0;
	if(!f)
	cout<<"file not present\n";
	else
	{
	
	while(f.read((char*)&s2,sizeof(s2)))
	{
		
		
		count++;
		tot=tot+s2.total;
		
	}
	cout<<"the total no of records: ";
	cout<<count<<endl;
	if(count==0)
	cout<<"no record present\n";
	{
	cout<<"average total marks: ";
	float o=tot/count;
	cout<<o;
	}
	f.close();
	cout<<endl;
}
}
void display(char *a)
{
	ifstream f;
	f.open(a,ios::in);
	if(!f)
	cout<<"file not present\n";
	else
	{
	
	while(f.read((char*)&s2,sizeof(s2)))
	{
		
		
		cout<<s2.name<<"  ";
		
		cout<<s2.roll<<"  ";
		
		cout<<s2.branch<<"	";
		
		for(int i=0;i<5;i++)
		cout<<s2.marks[i]<<" ";
		cout<<endl;
		
	}
	f.close();
	cout<<endl;
}
}
int main(int args,char *argv[])
{
	int flag=0;
	if(args!=2)
	cout<<"invalid number of command line arguments:enter one and only one filename\n";
	else
	while(flag==0)
	{
		cout<<"Menu:\n";
		cout<<"a.Append record\n";
		cout<<"b.display all\n";	
		cout<<"c.count the no of records and display the average total marks\n";
		cout<<"d.exit\n\n";
		
		char c;
		cin>>c;
		
		switch(c)
		{
			case 'a':
				append(argv[1]);
				break;
			case 'b':
				display(argv[1]);
				break;
			case 'c':
				count(argv[1]);
				break;
			case 'd':
				flag=1;
				break;
			default:
				cout<<"enter valid menu number\n";
				
		}
	}
		
}
