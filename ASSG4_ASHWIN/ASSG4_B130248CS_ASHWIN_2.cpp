#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct node
{
	int val;
	node* l;
	node *r;
	node *p;
};
node *root=NULL;

node* make(int v)
{
	node *np=new node;
	np->val=v;
	np->r=NULL;
	np->l=NULL;
	np->p=NULL;
	return np;
}
void insert(node *&root,node *np)//pass copy of root
{
	node *add=NULL;
	node* temp=root;
	int f;
	if(root==NULL)
	{
		root=np;
		return;

	}

	while(root!=NULL)
	{
		if(np->val>root->val)
			{
				f=0;
				add=root;
				root=root->r;
			
			}
		else
			{
				f=1;
				add=root;
				root=root->l;
			}
	}
	if(f==0)
	{
		np->p=add;
		add->r=np;
		root=temp;

	}
	else
	{
		np->p=add;
		add->l=np;
		root=temp;
	}
	
}
node *search(node *root,int v)
{
	node *temp=root;
	if(root==NULL)
	{
		cout<<"not found\n";
		return NULL;
	}
	while(root!=NULL)
	{
		if(v==root->val)
		{
			
			node *t=root;
			root=temp;
			return t;
		}
		else
		if(v>root->val)
			{
				
			
				root=root->r;
			
			}
		else
			{
				
			
				root=root->l;
			}
	}
	root=temp;
	cout<<"not found\n";
	return NULL;
}
node *min(node *root)
{
	if(root==NULL)
	{
		cout<<"NIL\n";
		return NULL;
	}
	while(root->l!=NULL)
	{
		root=root->l;
	}
	
	return root;
}
node *max(node *root)
{
	if(root==NULL)
	{
		cout<<"NIL\n";
		return NULL;
	}
	while(root->r!=NULL)
	{
		root=root->r;
	}
	
	return root;
}
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->l);
		cout<<root->val<<" ";
		inorder(root->r);
	}
}
void preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<root->val<<" ";
		preorder(root->l);
		preorder(root->r);
	}
}
void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->l);
		postorder(root->r);
		cout<<root->val<<" ";
	}
}
node* pred(node *root, node *x)
{
	/*if(root==NULL)
	{
		cout<<"not found\n";
		return NULL;
	}*/
	node *parent;
	/*if(root->p==NULL)
	{
		cout<<"No predecessor\n";
		return NULL;
	}*/
	

	//cout<<"@"<<x->val<<endl;
	if(x->l!=NULL)
	{
	//	cout<<"l present\n";
		return max(x->l);
	}


	parent=x->p;
	if(parent==NULL)
	{
		return NULL;
	}

	while(parent->r!=x)
	{

		x=parent;
		parent=parent->p;
		if(parent==NULL)
			break;
	}
	if(parent==NULL)
	{
		//cout<<"!";
		//cout<<"No predecessor\n";
		return NULL;
	}
	return parent;
}
void del(node *&root,node *x)
{
	//inorder(root);
	if(x->l==NULL && x->r==NULL)
	{
		//cout<<"leaf\n";
		node *parent=x->p;
		if(parent==NULL)
		{
			delete x;
			root=NULL;
			return;
		}

		if(parent->l==x)
		{
			parent->l=NULL;
			delete x;
		}
		else
		{
			parent->r=NULL;
			delete x;
		}
	}
	else
	if(x->l!=NULL && x->r==NULL)
	{
		//cout<<"only l\n";
		
		node *parent=x->p;
		if(parent==NULL)
		{
			root=x->l;
			root->p=NULL;
			delete x;
		}
		else
		{
			
		if(parent->l==x)
		{
			parent->l=x->l;
			parent->l->p=parent;
			delete x;
		}
		else
		{
			parent->r=x->l;
			parent->r->p=parent;
			delete x;
		}
		}

	}
	else
	if(x->r!=NULL && x->l==NULL)
	{
		//cout<<"only r\n";

		node *parent=x->p;

		if(parent==NULL)
		{
			root=x->r;
			root->p=NULL;
			delete x;
		}
		else
		{
		
		if(parent->l==x)
		{
			parent->l=x->r;
			parent->l->p=parent;
			delete x;
		}
		else
		{
			parent->r=x->r;
			parent->r->p=parent;
			delete x;
		}}
	}
	else
	{
		//cout<<"both \n";
		//cout<<"cccc";

		node *m=max(x->l);
		x->val=m->val;
		del(root,m);

	}

}
node* succ(node *root, node *x)
{
	/*if(root==NULL)
	{
		cout<<"not found\n";
		return NULL;
	}*/
	node *parent;
	/*if(root->p==NULL)
	{
		cout<<"No predecessor\n";
		return NULL;
	}*/
	

	//cout<<"@"<<x->val<<endl;
	if(x->r!=NULL)
	{
	//	cout<<"l present\n";
		return min(x->r);
	}


	parent=x->p;
if(parent==NULL)
	return NULL;

	while(parent->l!=x)
	{

		x=parent;
		parent=parent->p;
		if(parent==NULL)
			break;
	}
	if(parent==NULL)
	{
		//cout<<"!";
		//cout<<"No predecessor\n";
		return NULL;
	}
	return parent;
}
void check(int v)
{
	char ch=getchar();
	if(ch=='\n'||ch==' ')
	return;
	if(ch=='.')
	cout<<"no floating point\n";
	else
	cout<<"no alphabets and spcl chars\n";
	exit(0);
}
int main()
{
	int c;
	while(1)
	{
		cin>>c;
		check(c);
		switch(c)
		{
			case 0:
			{
				exit(0);
			}
			case 1:
			{
				int v;
				cin>>v;
				check(v);
				if(v<0)
				{
					cout<<"invalid <0\n";
				}
				else
				{
					
					node *np=make(v);
					insert(root,np);
				}
				break;
			}
			case 2:
			{
				int v;
				cin>>v;
				check(v);
				if(v<0)
				cout<<"invalid <0 \n";
				else
				{
				
				node * n=search(root,v);
				if(n==NULL)
					;//cout<<"not found\n";
				else
					cout<<"found\n";
				break;}
			}
			case 3:
			{

				node *m=min(root);
				if(m!=NULL)
				{
					cout<<m->val<<endl;
				}
				
				break;
			}
			case 4:
			{
				node *m=max(root);
				if(m!=NULL)
				{
					cout<<m->val<<endl;
				}
				break;
			}
			case 5:
			{
				int v;
				cin>>v;
				if(v<0)
				{
					cout<<"invalid <0\n";
				}
				else
				{
					node *s=search(root,v);
					if(s!=NULL)
					{
					node *p=pred(root,s);
					if(p!=NULL)
					{
						cout<<p->val;
					}
					else
					{
						cout<<"NIL\n";
					}}
					
				}
				break;
			}
			case 6:
			{
				int v;
				cin>>v;
				if(v<0)
				{
					cout<<"invalid\n";
				}
				else
				{
					node *s=search(root,v);
					if(s!=NULL)
					{
					node *p=succ(root,s);
					if(p!=NULL)
					{
						cout<<p->val;
					}
					else
					{
						cout<<"NIL\n";
					}
					}
					
				}
				break;
			}
			case 7:
			{
				int v;
				cin>>v;
				if(v<0)
				{
					cout<<"invalid\n";
				}
				else
				{
					node *s=search(root,v);
					if(s==NULL)
						cout<<"NIL\n";
					else
					{
						del(root,s);
					}
				}

				break;
			}
			case 8:
			{
				if(root==NULL)
					cout<<"empty\n";
				else
				inorder(root);
				break;
			}
			case 9:
			{
				if(root==NULL)
					cout<<"empty\n";
				else
				preorder(root);
				break;
			}
			case 10:
			{
				if(root==NULL)
					cout<<"empty\n";
				else
				postorder(root);
				break;
			}


			default: cout<<"enter valid choice\n";
		}
	}

	return 0;
}
