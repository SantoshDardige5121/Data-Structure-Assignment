#include"node.h"

int Node::getdata()
{
	return data;
}

void Node::setdata(int d)
{
	data=d;
}

Node* Node::getleft()
{
	return left;
}

void Node::setleft(Node *l)
{
	left=l;
}

Node* Node::getright()
{
	return right;
}

void Node::setright(Node* r)
{
	right=r;
}
