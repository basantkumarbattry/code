//this code contain all important code related to tree
// some words have been used like printi -inorder,printl-level order,printp-preorder,printP-post order like that

#include<bits/stdc++.h>
//#include<map>
using namespace std;

struct node{
	int data;node *left,*right,*nextRight;
};
node *root1=new node;
void printi(node *n)
{
	//cout<<"Basant";
	if(n==NULL) return;
	printi(n->left);cout<<n->data<<" ";printi(n->right);
}
void printp(node *n)
{
	if(n==NULL) return;
	cout<<n->data<<" ";printp(n->left);printp(n->right);
}
void printP(node *n)
{
	if(n==NULL) return;
	printP(n->left);printP(n->right);cout<<n->data<<" ";
}
void printl(node *n)
{
	queue<node *> q;node* n1=new node;
	q.push(n);
	while(!q.empty())
	{
		n1=q.front();q.pop();
		cout<<n1->data<<" ";
		if(n1->left) q.push(n1->left);
		if(n1->right) q.push(n1->right);
	}
}

int height(node *n)
{
	if(n==NULL) return 0;
	else
	{
		int l=height(n->left);
		int r=height(n->right);
		return l>r?(l+1):(r+1);
	}
}
void printGivenL(node *n,int l)
{
	node *n1=new node;
	if(n==NULL) return;
	if(l==1) cout<<n->data<<" ";
	printGivenL(n->left,l-1);
	printGivenL(n->right,l-1);
	
}
void printl1(node *n)
{
  int h=height(n);
  if(h==0) return ;
  for(int i=1;i<=h;i++)
  printGivenL(n,i);
}


node *f(int data)
{
	node *n1=new node;
	n1->data=data;n1->left=NULL;n1->right=NULL;return n1;
}
void insert(node *n,int key)
{
	queue<node *> q;q.push(n);node *n1=new node;
	while(!q.empty())
	{
		n1=q.front();q.pop();
		if(!n1->left)
		{
			n1->left=f(key);break;
		}
		else q.push(n1->left);
		if(!n1->right)
		{
			n1->right=f(key);break;
		}
		else q.push(n1->right);
		
	}
}
void printi1(node *n)
{
	node *n1=new node;n1=n;
	stack<node *> s;
	while(s.empty()==false||n1)
	{
		while(n1)
		{
			s.push(n1);n1=n1->left;
		}
		n1=s.top();s.pop();
		cout<<n1->data<<" ";
		n1=n1->right;
	}
	
}
void printp1(node *n)
{
	if(n==NULL) return;
	stack<node *> s;s.push(n);node *n1=new node;
	while(s.empty()==false)
	{
		n1=s.top();s.pop();cout<<n1->data<<" ";
		if(n1->right) s.push(n1->right);
		if(n1->left) s.push(n1->left);
	}
}
void printP1(node *n)
{
	if(n==NULL) return;
	stack<node *> s,s1;s.push(n);node *n1=new node;
	while(s.empty()==false)
	{
		n1=s.top();s1.push(n1);s.pop();
		if(n1->left) s.push(n1->left);
		if(n1->right) s.push(n1->right);
		
		//cout<<n1->data<<" ";
	}
	while(s1.empty()==false)
	{
		n1=s1.top();cout<<n1->data<<" ";s1.pop();
	}
		
}
int size(node *n)
{
	if(n==NULL) return 0;
	else
	return size(n->left)+size(n->right)+1;
}
void printP2(node *n)
{
	node *n1=new node;n1=n;
	unordered_set<node *> s;
	while(n1&&s.find(n1)==s.end())
	{
		if(n1->left&&s.find(n1->left)==s.end())
		n1=n1->left;
		else if(n1->right&&s.find(n1->right)==s.end())
		n1=(n1->right);
		else
		{
			cout<<n1->data<<" ";s.insert(n1);n1=n;
		}
	}
}
void printRight(node *n,int l,int &max)
{
	if(n==NULL) return ;
	if(max<l)
	{
		cout<<n->data<<" ";max=l;
	}
	printRight(n->right,l+1,max);
	printRight(n->left,l+1,max);
}
void printLeft(node *n,int l,int &max)
{
	if(n==NULL) return ;
	if(max<l)
	{
		cout<<n->data<<" ";max=l;
	}
	printLeft(n->left,l+1,max);	
	printLeft(n->right,l+1,max);
}
void printTop(node *n,map<int,node*> &m,int key)
{
	if(n==NULL) return ;
	if(n->left)
	m.insert(make_pair(key-1,n->left));
	printTop(n->left,m,key-1);
	if(n->right)
	m.insert(make_pair(key+1,n->right));
	printTop(n->right,m,key+1);
	
}

/*void view_map(map<int,node*> &m1)
{
	map<int,node*>::iterator it;
	cout<<"inside map\n";
	for(auto it:m1)
	{
		cout<<(it.second)->data<<" ";
	}
	cout<<"outside map\n";
}*/

void printBottom(node *n, map<int,node*> &m1,int key)
{
	if(n==NULL) return ;
	//map<int,node*>::iterator it;
	//cout<<endl<<n->data<<" ";
	//cout<<"left ";
	if(n->left)
	{
	m1[key-1] = n->left; 
	//cout<<n->left->data<<endl;
    }
	printBottom(n->left,m1,key-1);
	//cout<<"right ";
	if(n->right)
	{
	m1[key+1] = n->right;
	//cout<<n->right->data<<endl;
	}
	printBottom(n->right,m1,key+1);
	//cout<<"map of "<<n->data;
	//view_map(m1);
	return ;
}

bool checkleaf(node *n,int tt,int t)
{
	if(n==NULL&&tt==t)
	return true;
	else if(n==NULL)
	return false;
	return checkleaf(n->left,tt,t+1)&&checkleaf(n->right,tt,t+1);
	
}
//int min=INT_MIN,max=INT_MAX;
bool BST(node *n,int min,int max)
{
	if(n==NULL) return true;
	if(n->data<min||n->data>max) return false;
	return BST(n->left,min,n->data-1)&&BST(n->right,n->data+1,max);
}
void connectLevel(node *n)
{
	queue<node*> q;node *n1=new node;
	q.push(n);q.push(NULL);
	while(q.empty()==NULL)
	{
	n1=q.front();q.pop();
	if(n1!=NULL)
	{
		n1->nextRight=q.front();
		if(n1->left) q.push(n1->left);
		if(n1->right) q.push(n1->right);
	}
	else if(q.empty()==false)
	q.push(NULL);	
	}
}
void diagonalSum(node *n,int d,auto & m)
{ 
	if(n==NULL) return ;
	//m.insert(make_pair(d,n->data));
	m.insert({d,n->data});//cout<<d<<" ";
	diagonalSum(n->left,d+1,m);
	diagonalSum(n->right,d,m);
}
void printDiagonal(auto m)
{
	multimap<int,int>::iterator it;int key=0;
	for(it=m.begin();it!=m.end();it++)
	{
		if(key==it->first) cout<<it->second<<" ";
		else 
		{
			cout<<endl<<it->second<<" ";key=it->first;
		}
	}
}
int maxVerticalSum(node *n)
{
	queue<pair<int,node*>>q;node *n1=new node;
	q.push({0,n});map<int,int>m;int t;
	while(q.empty()==false)
	{
	n1=q.front().second;t=q.front().first;q.pop();	
	m[t]=m[t]+n1->data;
	if(n1->left) q.push({t-1,n1->left});
	if(n1->right) q.push({t+1,n1->right});
	}int max=INT_MIN;
	for(auto x:m)
	if(max<x.second) max=x.second;
	return max;
}
void mirror( node *node1,node **root1) 
{
    
    
    if (node1==NULL) 
	return; 
	*root1=f(node1->data);
	{
	mirror(node1->left,&(*root1)->right);
	mirror(node1->right,&(*root1)->left);
	}
} 
int maxsum(node *root,int &max1,int &maxUp)
{
	if(root==NULL) return 0;
	int l=maxsum(root->left,max1,maxUp);
	int r=maxsum(root->right,max1,maxUp);
	if(l<0&&r<0)
	{
		max1=max(max1,root->data); return root->data;
	}
	if(l>0&&r>0) max1=max(max1,l+r+root->data);
	maxUp=max(l,r)+root->data;
	max1=max(max1,maxUp);
	return maxUp;	
}
int maxleaf(node *root,int k)
{
	if(root==NULL)	return 0;
	int l=maxleaf(root->left,3);
	int r=maxleaf(root->right,3);
	if(k!=0)
	return max(l,r)+root->data;	
	else
	return l+r+root->data;
}
int toSumTree( node *node) 
{ 
	// Base case 
	if(node == NULL) 
	return 0;  
	int old_val = node->data;  
	node->data = toSumTree(node->left) + toSumTree(node->right); 
 
	return old_val+node->data;
}
node* buildTree(int in[], int pre[], int inStrt, 
                       int inEnd, unordered_map<int, int>& mp) 
{ 
    static int preIndex = 0; 
  
    if (inStrt > inEnd) 
        return NULL; 

    int curr = pre[preIndex++]; 
     node* tNode = f(curr); 
   
    if (inStrt == inEnd) 
        return tNode;  
    int inIndex = mp[curr]; 
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1, mp); 
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, mp); 
  
    return tNode; 
} 

node* buldTreeWrap(int in[], int pre[], int len) 
{ 
    unordered_map<int, int> mp; 
    for (int i = 0; i < len; i++) 
        mp[in[i]] = i; 
  
    return buildTree(in, pre, 0, len - 1, mp); 
} 
int main()
{
	node *n=new node;
	n=f(-9);n->left=f(12);n->right=f(20);
	n->left->left=f(-20);n->left->right=f(-35);
	insert(n,55);insert(n,149);// at first of level order
	//cout<<"in order "<<endl;
	//printi(n);cout<<endl;
	/*printi1(n);cout<<" now pre "<<endl;
	printp(n);cout<<endl;
	printp1(n);cout<<" now post "<<endl;
	printP(n);cout<<endl;
	printP1(n);cout<<endl;
	printP2(n);cout<<" now level "<<endl;
	printl(n);cout<<endl;
	printl1(n);cout<<" now level 2 "<<endl;
	printGivenL(n,2);cout<<" size of tree "<<endl;
	cout<<size(n);cout<<" height of tree"<<endl;
	cout<<height(n);*/
	// print view of tree
	int max=0,key=0;
	map<int ,node*> m;m[0]=n;
	//printRight(n,1,max);cout<<endl;max=0;
	//printLeft(n,1,max);cout<<endl;max=0;
	printTop(n,m,key);
	map<int ,node*>::iterator it;
	//for(auto x:m)
	//for(it=m.begin();it!=m.end();it++)
	//cout<<(x.second)->data<<" ";
	map<int ,node*> m1;
	m1[0]=n;
	//printBottom(n,m1,key);
	//cout<<endl;
	//cout<<"hello basant\n";
//	for(auto it:m1)
	/*for(it=m1.begin();it!=m1.end();it++)
	{
	cout<<(it->second)->data<<" ";
	}*/
 	//view_map(m1);
	//cout<<"hello\n";
	//int tt=height(n);
//	cout<<(checkleaf(n,tt,0)?"Yes at same level":"no")<<endl;
	//BST(n,INT_MIN,INT_MAX)?cout<<"\nBST\n":cout<<"\nNO\n";
	connectLevel(n);multimap<int,int> m2;
	diagonalSum(n,0,m2);
	//printDiagonal(m2);
	//int ttt=maxVerticalSum(n);cout<<ttt<<" ";
	//node *root=new node;
	printi(n);cout<<endl;
	node *root1=new node;
	mirror(n,&root1);//cout<<root->data;
	//root1=n;
	//printi(root1);
	int max1=INT_MIN,maxUp=INT_MIN;
	maxsum(n,max1,maxUp);
	cout<<max1<<endl;
	int tt=maxleaf(n,0);
	cout<<tt<<endl;
	toSumTree(n);
	int in[] = { 12,34,76,43,90,45,60 }; 
    	int pre[] = { 76,34,12,43,60,90,45}; 
    	int len = sizeof(in) / sizeof(in[0]); 
  
    	node *root2 = buldTreeWrap(in, pre, len); 
	printi(root2);
}

