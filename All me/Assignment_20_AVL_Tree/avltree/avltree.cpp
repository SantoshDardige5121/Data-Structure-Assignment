#include<iostream>
#include"avltree.h"
using namespace std;

avlTree::avlTree()
{
	root=NULL;
}

Node* avlTree::getroot()
{
	return root;
}

int avlTree::height(Node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->getleft());
        int r_height = height (temp->getright());
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
 
int avlTree::diff(Node *temp)
{
    int l_height = height (temp->getleft());
    int r_height = height (temp->getright());
    int b_factor= l_height - r_height;
    return b_factor;
}
 
Node *avlTree::rr_rotation(Node *parent)
{
    Node *temp;
    temp = parent->getright();
    parent->setright(temp->getleft());
    temp->setleft(parent);
    return temp;
}

Node *avlTree::ll_rotation(Node *parent)
{
    Node *temp;
    temp = parent->getleft();
    parent->setleft(temp->getright());
    temp->setright(parent);
    return temp;
}
 
Node *avlTree::lr_rotation(Node *parent)
{
    Node *temp;
    temp = parent->getleft();
    parent->setleft(rr_rotation (temp));
    return ll_rotation (parent);
}
 
Node *avlTree::rl_rotation(Node *parent)
{
    Node *temp;
    temp = parent->getright();
    parent->setright(ll_rotation (temp));
    return rr_rotation (parent);
}
 
Node *avlTree::balance(Node *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->getleft()) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->getright()) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}
 
Node *avlTree::insert(Node *root, int value)
{
    if (root == NULL)
    {
        root = new Node;
        root->setdata(value);
        root->setleft(NULL);
        root->setright(NULL);
        return root;
    }
    else if (value < root->getdata())
    {
        root->setleft(insert(root->getleft(), value));
        root = balance (root);
    }
    else if (value >= root->getdata())
    {
        root->setright(insert(root->getright(), value));
        root = balance (root);
    }
    return root;
}
 
void avlTree::display(Node *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->getright(), level + 1);
        printf("\n");
        if (ptr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->getdata();
        display(ptr->getleft(), level + 1);
    }
}
 
void avlTree::inorder(Node *tree)
{
    if (tree == NULL)
        return;
    inorder (tree->getleft());
    cout<<tree->getdata()<<"  ";
    inorder (tree->getright());
}

void avlTree::preorder(Node *tree)
{
    if (tree == NULL)
        return;
    cout<<tree->getdata()<<"  ";
    preorder (tree->getleft());
    preorder (tree->getright());
 
}
 
void avlTree::postorder(Node *tree)
{
    if (tree == NULL)
        return;
    postorder ( tree ->getleft() );
    postorder ( tree ->getright() );
    cout<<tree->getdata()<<"  ";
}
