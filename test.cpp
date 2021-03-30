#include <iostream>
using namespace std;
typedef struct Node
{
    
    int elem;
    Node *lchild;
    Node *rchild;
    int lnum;
    int rnum;
}Node, * Btree;
void d(Btree &n,int i)
{
    if(i == 1)
    {
        n = new Node;
        n->elem = 3;
    }
    else
    {
        i++;
        d(n->lchild,i);
    }
}
int main()
{
    Btree head = new Node;
    head->elem = 1;
    head->lchild = new Node;
    head->lchild->elem = 2;
    d(head,0);
    cout<<head->lchild->elem;
    return 0;
}