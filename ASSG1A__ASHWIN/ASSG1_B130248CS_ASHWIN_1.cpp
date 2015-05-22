#include<iostream> 
#include<string> 
using namespace std;
string reverse (string str) 
{   string s=""; 
 for(int i=str.length()-1;i>=0;i--) 
 s+=str[i]; 
  return s; 
} 
void call(string str,int pos,int n)
{
int k=pos+1;int ff=0;int ff2=0;int count=0;int j,i;
//cout<<"!!!!!!!"<<pos;
						 	for(i=pos, j=pos;;)
						 	{//cout<<str[str.length()/2]<<"!";
						 	if(i==str.length())
						 	break;
						 	if(j<0)
						 	break;
						 	if(str[i]==str[pos])
						 	{i++;count++;}
						 	else
						 	ff=1;
						 	if(str[j]==str[pos])
						 	{j--;count++;}
						 	else 
						 	ff2=1;
						 	if(ff==1&&ff2==1)
						 	break;
						 	}
						 	//cout<<i<<j;
						 	while(k<i)
						 	{int p=k;
						 	
						 	cout<<str[k]<<endl<<p<<endl;k++;
						 	}
						 	k=pos-1;
						 	while(k>j)
						 	{int p=k;
						 	
						 	cout<<str[k]<<endl<<p<<endl;k--;
						 	}
						 	

}
int ret(string str,int n) 
{   
long start =0;
int ctr=0;
int ctr2=0;
int w=0;
char ch;
int u=1;
int pos=str.length()/2;  ;;;;;;;;;;
long end=str.length()-1;  
while(start < end)  
{    if(str[start]==str[end])
		 { start++; 
		    end--;
		    if(str[0]==str[start])
		    w=w+1;
			} else if(ctr==1)
			{ return 0; 
			  break; 
			  }else if(str[start]!=str[end-1]) 
			     {   return 0;    
				  break;   }
				  else if(str[start]==str[end-1]) 
				    {  
				    
				    
				     ctr++; 
					start++;
					ch=str[end];
					pos=end;
					end=end-2; 
					 }
					   } 
					    if(start>=end)  
						 {//cout<<w<<"!!!"<<ctr<<endl;
						 	/*if(n==0)
						 	pos=str.length()-1-pos;
						 	//cout<<w;
						 	if(w!=str.length()/2&&(w!=str.length()/2 - 1  ))
						 	cout<<ch<<endl<<pos<<endl;
						 	else
						 	if((str.length()/2 )%2==1 &&str[str.length()/2 + 1]==str[0])
						 	cout<<str[str.length()/2 + 1]<<endl<<str.length()/2 <<endl;
						 	else
						 	if(n==0&&w==str.length()/2)
						 	for(int i=0;i<str.length();i++)
						 	cout<<str[0]<<endl<<i<<endl;*/
						 	
						 	if(n==0)
						 	pos=str.length()-1-pos;
						 	
						 	
						 	if(str.length()%2==0)
						 		{
						 		if(w==str.length()/2)
						 			if(n==0)
						 			for(int i=0;i<str.length();i++)
						 			cout<<str[i]<<endl<<i<<endl;
						 			}
						 	else
						 		{
						 		if(w==str.length()/2)
						 		if(n==0)
						 			for(int i=0;i<str.length();i++)
						 			{cout<<str[i]<<endl<<i<<endl;
						 			}
						 			}
						 	if(ctr==0&&w!=str.length()/2&&n==0)
						 	cout<<str[str.length()/2]<<endl<<str.length()/2<<endl;
						 	
						 	if(ctr!=0)
						 	{cout<<ch<<endl<<pos<<endl;
						 	if(pos!=str.length()/2&&n==1)
						 	{call(str,pos,n);
						 	ctr2=1;}
						 	}
						 	//cout<<pos<<"!!";
						 	int flagg=0;
						 	//cout<<ctr<<str.length()<<w<<endl;
						 	if(w!=str.length()/2 && (pos==str.length()/2 ||pos==str.length()/2 - 1))
						 	{int count=0;
						 	int j,i;
						 	int ff=0;
						 	int ff2=0;
						 	//cout<<"###";
						 	for(i=str.length()/2, j=str.length()/2;;)
						 	{//cout<<str[str.length()/2]<<"!";
						 	if(i==str.length())
						 	break;
						 	if(j<0)
						 	break;
						 	if(str[i]==str[str.length()/2])
						 	{i++;count++;}
						 	else
						 	ff=1;
						 	if(str[j]==str[str.length()/2])
						 	{j--;count++;}
						 	else 
						 	ff2=1;
						 	if(ff==1&&ff2==1)
						 	break;
						 	}	
						 	int k;
						 	
						 	
						 	
						 	
						 	if((str[str.length()/2]==str[str.length()/2 - 1])&&n==1)
						 	u=0;
						 
						 	k=str.length()/2 +1;
						 	if(u==1)
						 	{
						 	while(k<i)
						 	{int p=k;
						 	if(n==0)
						 	p=str.length()-1-p;
						 	cout<<str[k]<<endl<<p<<endl;k++;
						 	}
						 	k=str.length()/2 -1;
						 	while(k>j)
						 	{int p=k;
						 	if(n==0)
						 	p=str.length()-1-p;
						 	cout<<str[k]<<endl<<p<<endl;k--;
						 	}
						 	
						 	
						 	
						 	
						 	
						 	
						 	
						 	}
						 	}
						 			
						 		
						 			
						 	
						 	
						 	
						 	
						 	
						 	
						  return 1; 
					}
} 
int check(string a)
{
	long i;
	for( i=0;i!=a.length();i++)
	if(!((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z')))
	break;
	
	if(i==a.length())
	return 1;
	else
	return 0;
}

int main() 
{  

int ctr=0; 
string str,str2; 
cout<<"enter your string\n";
getline(cin,str); 
if(check(str)!=1)
cout<<"invalid input\n";
else
{
str2=reverse(str);   
if(ret(str,1)+ ret(str2,0)) 
; 
else
cout<<"Not Possible\n";   
}
return 0;
		   
} 
