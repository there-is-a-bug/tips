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
bool init_move(int move[])
{
    for(int i = 0; i < 10; i++)
    {
        move[i] = i;
    }
    return true;
}
int main()
{
    Btree head = new Node;
    head->elem = 1;
    head->lchild = new Node;
    head->lchild->elem = 2;
    d(head,0);
    cout<<head->lchild->elem;
    int move[100];
    init_move(move);
    for(int i = 0; i < 10; i++)
    cout<<move[i];
    return 0;
}