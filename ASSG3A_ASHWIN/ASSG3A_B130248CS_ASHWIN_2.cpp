#include<iostream>
#include<cstdlib>
#define val(x) std::cout<<#x "="<<x<<"\n"
using namespace std;
void check(char arr[])
{
	int open =1;
	int close=0;
	int flag=0;
	int i=0;
	while(arr[i]==' ')
	i++;
	if(arr[i]=='(')
	i++;
	else
	{
	cout<<"invalid input\n";
	exit(0);	
	}
	
	while(arr[i]!='\0')
	{
		if(arr[i]=='-')
	{
		cout<<"only +ve\n";
		exit(0);
				}
		if(open<close )
		{
			cout<<"invalid input\n";
			exit(0);
		}
		if(arr[i]=='(' && flag==1)
		{
			cout<<"invalid input\n";
			exit(0);
			}
			
		if(arr[i]=='(')
		open++;
		if(arr[i]==')')
		close++;
		
		if(open==close)
		flag=1;
		i++;
	}
	if(open!=close)
	{
		cout<<"invalid\n";
		exit(0);
	}
}
struct node
{
int val;
node* child;
node* next;
//node *parent;
};

node *top=NULL;
void showM(node *start){
	//std::cout<<"( ";
	for(node *i = start; i!=NULL; i=i->next){
		std::cout<<i->val;
		if(i->next!=NULL)
		cout<<"->";
		if(i->child!=NULL)
			showM(i->child);
	}
	//std::cout<<") ";
}
node* createnewptr(int vl)
{
node *np=new node;
np->val=vl;
//np->parent=NULL;
np->next=NULL;
np->child=NULL;
return np;
}


int makenumber(char arr[],int &i)
{
int number =0;
while(arr[i]>='0'&&arr[i]<='9')
{
int c=arr[i] - '0';
number=number*10;
number+=c;
//cout<<"!!"<<arr[i];
i++;

}
//val(number);
return number;
}

/*
void create(char arr[],node *&temp,int &i)//initially top and 0
{
if(arr[i]=='\0')
return;

int num;
//cin>>num;
//val(arr);
//val(i);
//val(arr[i]);
while(arr[i]==' ')
	i++;
if(arr[i]==')')
{
//cout<<temp->val<<" ";
temp->next=NULL;

temp->child=NULL;// !!!!!!!!!!!!! go back to main parent parent
//if(temp->parent!=NULL)
//node* temp2=temp;
while(temp->child==NULL)
temp=temp->parent;
cout<<"parent is "<<temp->val<<endl;
i++;
//cout<<i<<endl;
//create(arr,temp,i);
//return;
}

while(arr[i]==' ')
	i++;
if(arr[i]!=')' && arr[i]!='\0')
{
	if(temp==NULL && arr[i]=='(')
	{
		//cout<<"Case 1\n";
		
		i++;
		while(arr[i]==' ')
			i++;
		int num=makenumber(arr,i);
		node* n=createnewptr(num);
		temp=n;
		
		create(arr,temp,i);
	}
	else
	{
	//cout<<"Case 2\n";
	while(arr[i]==' ')
		i++;
	if(arr[i]!='(' && arr[i]!=')' && arr[i]!='\0')//it is a number
	{
		//cout<<"Case 2a\n";
		int num=makenumber(arr,i);
		node *n=createnewptr(num);
		temp->next=n;
		n->parent=temp;
		cout<<temp->val<<endl;
		//cout<<"next :"<<n->val<<endl;
		create(arr,n,i);
		//temp = n;
	}
	else if(arr[i]=='(' &&  arr[i]!=')' && arr[i]!='\0')
	{
		//cout<<"Case 2b\n";
		i++;
		while(arr[i]==' ')
                        i++;
		int num=makenumber(arr,i);
		node* n=createnewptr(num);
		temp->child=n;
		n->parent=temp;
		//cout<<"child :"<<n->val<<endl;
		create(arr,n,i);
		temp = n->parent;
	}
	}
}
create(arr,temp,i);
if(arr[i]==')')
{
;
//i++;
//temp->next=NULL;
}
}*/



/*
void flatten(node *&temp)
{
if(temp->child!=NULL)
{
node *tempc=temp->child;
node *childchild=tempc->child;
node *childnext=tempc->next;

flatten(temp->next);

tempc->next=temp->next;
tempc->child=NULL;
temp->next=tempc;

flatten(tempc);

}
}
*/


/*
node* create(char arr[],node *start,node * now,int &i)
{
	while(arr[i]==' ')
		i++;
		
	if(arr[i]==')' || arr[i]=='\0')
	{
		return start;
	}
	else// can be space , ( ,number
	{
		
		while(arr[i]==' ')
		i++;
		if(start==NULL && arr[i]=='(')
		{
			i++;
			int num=makenumber(arr,i);
			node *st=createnewptr(num);
			start=now=st;
			node *np=create(arr,now,st,i);
			now->next=np;
		}
		else
		 if(arr[i]=='(')
		{
			i++;
			while(arr[i]==' ')
			i++;
			
			int num=makenumber(arr,i);
			node *st=createnewptr(num);
			node *np=create(arr,now,st,i);
			now->child=np;
		}
		else
		{
			while(arr[i]==' ')
			i++;
			
			int num=makenumber(arr,i);
			node *st=createnewptr(num);
			now->next=st;
			node *np=create(arr,start,st,i);
			start->next=np;
		}
	}
}
*/
node *create(char arr[],int &i)
{
	
			node *start,*ch,*now;
	start=ch=now=NULL;
	while(1)
	{
		

		//start=ch=now=NULL;
	while(arr[i]==' ')
		i++;
	if(arr[i]==')' || arr[i]=='\0')
	{i++;return start;}
	else
	{
		if(arr[i]=='(')
		{
			//cout<<"a";
			i++;
			while(arr[i]==' ')
			i++;
		  	ch=create(arr,i);
		  	now->child=ch;
		  	//now=ch;
		}
		else //num
		{
			while(arr[i]==' ')
			i++;
			//cout<<"k";
			int num=makenumber(arr,i);
			node *st=createnewptr(num);
			if(start==NULL)
			start=st;
			else
			now->next=st;
			now=st;
			
		}
	}
	}
}


node* findend()
{
node* temp=top;
while(temp->next!=NULL)
temp=temp->next;
return temp;

}
void flatten()
{
int nochild=0;
while(nochild==0)
{
node *temp=top;
node *end=findend();
while(temp->child==NULL)
{
if(temp->next==NULL)
{
nochild=1;
break;
}
temp=temp->next;
}
if(nochild==0)
{
node *ch=temp->child;
temp->child=NULL;
end->next=ch;
}

}
}
void  show(node *temp)
{
//node* temp=top;
if(temp!=NULL)
{
 cout<<temp->val<<" ";
if(temp->child!=NULL)
{cout<<"( ";
show(temp->child);
cout<<") ";
}

show(temp->next); 
}
}
int main()
{
char s[100];
cin.getline(s,99);
check(s);
int i=0;

top=create(s+1,i);
//showM(top);
cout<<endl;
flatten();
showM(top);
return 0;
}
