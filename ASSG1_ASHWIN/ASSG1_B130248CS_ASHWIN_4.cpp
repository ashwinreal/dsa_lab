#include<iostream>
#include<string>
using namespace std;
long double area(long double a,long double b)
{
	return a*b;
}
long double peri(long double a,long double b)
{
	return 2*(a+b);
}
long double (*areaptr)(long double a,long double b);
long double (*periptr)(long double a,long double b);
int main()
{
	int flag=0;
	long double a,b;
	int choice;
		cout<<"enter length\n";
		cin>>a;
		cout<<"enter breadth\n";
		cin>>b;
		if(a<=0||b<=0)
		cout<<"invalid inputs\n";
		else{
		
	while(flag==0)
	{
	
		
		cout<<"Menu\n";
		cout<<"  1.Area\n";
		cout<<"  2.Perimeter\n";
		cout<<"  3.Exit\n";
		cout<<"enter the choice\n";
		cin>>choice;
		if(!cin)
		cout<<"enter valid choice\n";
		else
		switch(choice)
		{
			case 1:
				//Area
				areaptr=&area;
				cout<<"Area:\n"<<(*areaptr)(a,b)<<endl;
				break;
			case 2:
				//primeter
				periptr=&peri;
				cout<<"Perimeter:\n"<<(*periptr)(a,b)<<endl;
				break;
			case 3:
				flag=1;
				break;
			default: 
				cout<<"enter valid choice\n";
			
		}
	}
}
	
	
}
