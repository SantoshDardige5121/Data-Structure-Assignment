/*1. Insert Binary search tree using linked list and implement following functions
Insert a node
Display ( Inorder, postorder, preorder ) using recursion
Display ( Inorder, postorder, preorder ) without using recursion.
( Create your own stack and make use of that )
Delete a terminal node
Delete a non terminal node
Search a node */

#include<iostream>
#include<bits/stdc++.h> 

using namespace std;

struct node
{
	node *left;
	int data;
	node *right; 
};

class BinarySearchTree
{
	node *root;
	public:
			BinarySearchTree();
			void insert(int);
			void remove(int);
			void inorder(node*);
			void preorder(node*);
			void postorder(node*);
			void display();
			void search(int);
	
};
BinarySearchTree::BinarySearchTree()
{
		root=NULL;
}

void BinarySearchTree::search(int r)
{
	node *parent=root;
	node *temp=root;
	node *trav=root;
	int dt;
	while(temp!=NULL)
	{
		if(temp->data==r)
		{
		//	parent=temp;
			dt=temp->data;
			break;
			
		}
		
		else if(temp->data>r)
		{
			parent=temp;
			temp=temp->left;
		}
		else if(temp->data<r)
		{
			parent=temp;
			temp=temp->right;
		}
		
	}
	if(dt==r)
	{
		cout<<"Element is present"<<endl;
	}
	else
	{
		cout<<"Element is not present"<<endl;
	}
	
}
void BinarySearchTree::insert(int d)
{
	node *head= new node;
	head->data=d;
	head->left=NULL;
	head->right=NULL;
	if(root==NULL)
	{
		root=head;
	}
	else
	{
		node *temp=root;
		while(true)
		{
			if(head->data>temp->data)
			{
				if(temp->right==NULL)
				{
					temp->right=head;
					break;
				}
			
				else
				{
					temp=temp->right;
				}
				
			}
			else if(head->data<temp->data)
			{
				if(temp->left==NULL)
				{
					temp->left=head;
					break;
				}
			
				else
				{
					temp=temp->left;
				}
			}
		}
		
		
	}
	//inorderStack(head);
	
}
void BinarySearchTree::remove(int r)
{
	node *parent=root;
	node *temp=root;
	node *trav=root;
	int dt;
	while(temp!=NULL)
	{
		if(temp->data==r)
		{
		//	parent=temp;
			dt=temp->data;
			break;
			
		}
		
		else if(temp->data>r)
		{
			parent=temp;
			temp=temp->left;
		}
		else if(temp->data<r)
		{
			parent=temp;
			temp=temp->right;
		}
		
	}
	
		
		if(temp->left!=NULL && temp->right!=NULL)
		{
			trav=temp->right;
			parent=temp;
			while(trav->left!=NULL)
			{
				parent=trav;
				trav=trav->left;	
			}
			temp->data=trav->data;
			temp=trav;	
		}
		if(temp->left!=NULL && temp->right==NULL)
		{
			if(parent->left==temp)
			{
				parent->left=temp->left;
				delete temp;
			}
			else if(parent->right==temp)
			{
				parent->right=temp->left;
				delete temp;
			}
		}
		else if(temp->left==NULL && temp->right!=NULL)
		{		
			if(parent->left==temp)
			{
				parent->left=temp->right;
				delete temp;
			}
			else if(parent->right==temp)
			{
				parent->right=temp->right;
				delete temp;
			}
		
		}
		else if(temp->left==NULL && temp->right==NULL)
		{		
			if(temp==parent->left)
			{
				parent->left=NULL;
			}
			else if(temp==parent->right)
			{
				parent->right=NULL;
			}
			delete temp;
			
		}
	
}
void BinarySearchTree::inorder(node *r)
{
		if (r==NULL) return;
		inorder(r->left);
		cout<<r->data<<endl;
		inorder(r->right);

	
}
void BinarySearchTree::preorder(node *r)
{
		if (r==NULL) return;
		cout<<r->data<<endl;
		preorder(r->left);
		preorder(r->right);

}

void BinarySearchTree::postorder(node *root)
{
		if (root==NULL) return;
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<endl;

}
void BinarySearchTree::display()
{
	int c;
	cout<<"Choose option:"<<endl;
	cout<<"1.Inorder"<<endl;
	cout<<"2.Preorder"<<endl;
	cout<<"3.Postorder"<<endl;
	cin>>c;
	
	if(c==1)
	{
		inorder(root);	
	}
	else if(c==2)
	{
		preorder(root);
	}
	else if(c==3)
	{
		postorder(root);
	}
	
	
}
int main()
{
	BinarySearchTree bst;
	int n,ch,o;
	while(1)
	{
		cout<<"Choose option:"<<endl;
		cout<<"1.Insert a node"<<endl;
		cout<<"2.Remove"<<endl;
		cout<<"3.Display"<<endl;
		cout<<"4.Search"<<endl;
		cout<<"5.Inorder without recursion"<<endl;
		cout<<"0.exit"<<endl;
		cin>>ch;
		
		switch(ch)
		{
			case 1:
					cout<<"Enter a node"<<endl;
					cin>>n;
					bst.insert(n);
					break;
			case 2:
					cout<<"Enter a node"<<endl;
					cin>>n;
					bst.remove(n);
					break;
			case 3:
					bst.display();
				//	bst.postorder();
					break;
			case 4:
					cout<<"Enter a node"<<endl;
					cin>>n;
					bst.search(n);
					break;
			case 5:
					cout<<"Enter node"<<endl;
					cin>>n;
					bst.insert(n);
					break;
			case 0:
					exit(0);		
					
					
			
		}
		
		
	}
	
	return 0;
} 
