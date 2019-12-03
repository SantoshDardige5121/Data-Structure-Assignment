class Node
{
	int data;
	struct Node *left;
	struct Node *right;
public:
	int getdata();
	void setdata(int);
	Node* getleft();
	void setleft(Node*);
	Node* getright();
	void setright(Node*);
};
