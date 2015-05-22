#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;
string s,p;
struct node
{
	char oprtr;
	node *l;
	node *r;
	node *p;
};

node *root=NULL;
int what(char c)
{
	if(c>='a'&& c<='z')
	return 0;
	if(c=='^'||c=='/'||c=='*'||c=='+'||c=='-')
	return 1;
	cout<<"invalid input\n";
	exit(0);
}


void chk(node *root)
{
	if(root!=NULL)
	{
	
		chk(root->l);
		
		if(what(root->oprtr)==1)
		if(root->l==NULL||root->r==NULL)
		{
			cout<<"not postfix\n";
			exit(0);
		}
         
		chk(root->r);
		
	}
}
/*void in(node *root)
{
	if(root!=NULL)
	{
		if(root->l!=NULL&&root->r!=NULL)
		cout<<"(";
		in(root->l);
		

          cout<<root->oprtr;
		in(root->r);
		if(root->l!=NULL&&root->r!=NULL)  
		cout<<")";
	}
}
void pre1(node *root)
{
	if(root!=NULL)
	{
		cout<<root->oprtr;
		pre1(root->l);
		pre1(root->r);
	}
}
void post1(node *root)
{
	if(root!=NULL)
	{
		post1(root->l);
		post1(root->r);
		cout<<root->oprtr;
		
	}
}
*/

void traverseleft(node *stack[],node *root,int &top)
{
	node *temp=root;
	while(temp!=NULL)
	{
		stack[++top]=temp;
		temp=temp->l;	
	}
}

void in(node *root)
{
	node *stack[1000];
	int top=0;
	stack[top]=root;
	while(top!=-1)
	{
	if(stack[top]!=NULL)
	traverseleft(stack,stack[top]->l,top);
	if(stack[top]->p!=NULL)
	if(stack[top]->p->l==stack[top])
	cout<<"(";
	cout<<stack[top]->oprtr<<" ";
	if(stack[top]->p!=NULL)
	if(stack[top]->p->r==stack[top])
	cout<<")";
//	cout<<top;
	top--;
	if(top!=-1)
	if(stack[top]!=NULL)
	{
	
	cout<<stack[top]->oprtr<<" ";
	
	top--;
	if(stack[top+1]!=NULL)
	traverseleft(stack,stack[top+1]->r,top);
	}
	//cout<<stack[top]->oprtr<<top;
	
	}
}
node* make(char c)
{
	node * np =new node;
	np->oprtr=c;
	np->l=NULL;
	np->r=NULL;
	np->p=NULL;
	return np;
}






void makeit(string s,int ctr,node * & curr)
{
	//in(root);
	/*if(curr!=NULL)
	cout<<s[ctr]<<" "<<what(curr->oprtr)<<curr->oprtr<<root->oprtr<<endl;
	else
	cout<<"NULL\n";*/
	if(ctr>=0)
	{
		if(curr==NULL)
		{
			node *np=make(s[ctr]);
			root=np;
			curr=np;
			makeit(s,ctr-1,curr);
		}
		else
		{
			if(what(curr->oprtr)==1)  // only oprtrs hae children
			{
				if(curr->r==NULL)
				{
					node *np=make(s[ctr]);
					np->p=curr;
					curr->r=np;
					//curr=np;
					makeit(s,ctr-1,np);
				}
				else
				if(curr->l==NULL)
				{
					node *np=make(s[ctr]);
					np->p=curr;
					curr->l=np;
					//curr=np;
					makeit(s,ctr-1,np);
				}
				else  
			{
					makeit(s,ctr,curr->p);
			}
				
			}
			else  ///// variableas
			{
					makeit(s,ctr,curr->p);
			}
		}
	}
}

void makexp(string s)
{
	
	int ctr=s.size()-1;
	makeit(s,ctr,root);	
} 
void traverseleft2(node *stack[],node *root,int &top)
{
	node *temp=root;
	while(temp!=NULL)
	{
		stack[++top]=temp;
		cout<<temp->oprtr<<" ";
		temp=temp->l;	
	}
}
void pre1(node *root)
{
	node *stack[1000];
	int top=0;
	stack[top]=root;
	cout<<root->oprtr;
	while(top!=-1)
	{
	if(stack[top]!=NULL)
	traverseleft2(stack,stack[top]->l,top);
	
	//cout<<stack[top]->oprtr<<" ";
	
//	cout<<top;
	top--;
	if(top!=-1)
	if(stack[top]!=NULL)
	{
	
	//cout<<stack[top]->oprtr<<" ";
	
	top--;
	if(stack[top+1]!=NULL)
	traverseleft2(stack,stack[top+1]->r,top);
	}
	//cout<<stack[top]->oprtr<<top;
	
	}
}
void traverseleft3(node *stack[],node *root,int &top,int no[])
{
	node *temp=root;
	while(temp!=NULL)
	{
		stack[++top]=temp;
		no[top]=1;
		//cout<<temp->oprtr<<" ";
		temp=temp->l;	
	}
}
void post1(node *root)
{
	node *stack1[1000],*stack2[1000];
	
	int top1=0;
	int top2=-1;
	stack1[top1]=root;
	
	
	while(top1!=-1)
	{
	
	stack2[++top2]=stack1[top1--];
	if(stack2[top2]->l!=NULL)
	stack1[++top1]=stack2[top2]->l;
	if(stack2[top2]->r!=NULL)
	stack1[++top1]=stack2[top2]->r;
	
	
	
	
	}
	for(int i=top2;i>=0;i--)
	cout<<stack2[i]->oprtr<<" ";
}
int main()
{
	
	cin>>s;
	makexp(s);
	chk(root);
	cout<<"inorder: ";
	in(root);
	cout<<"\n";
	cout<<"preorder: ";
	pre1(root);
	cout<<"\n";
	cout<<"postorder: ";
	post1(root);
	cout<<endl;
	
	return 0;
}
