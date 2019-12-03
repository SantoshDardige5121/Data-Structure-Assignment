#include"node.h"

class avlTree
{
	Node *root;
    public:
	avlTree();
	Node *getroot();
        int height(Node *);
        int diff(Node *);
        Node* rr_rotation(Node *);
        Node* ll_rotation(Node *);
        Node* lr_rotation(Node *);
	Node* rl_rotation(Node *);
        Node* balance(Node *);
        Node* insert(Node *, int );
        void display(Node *, int);
        void inorder(Node *);
        void preorder(Node *);
        void postorder(Node *);
};
