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
void inittree(Btree &head)
{
    head = new Node;
    head->rchild = NULL;
    head->lchild = NULL;
    head->elem = 0;
    head->lnum = 0;
    head->rnum = 0;
    return;
}
bool addnode(Btree head, int elem)
{
    Btree tmp;
    tmp = head;
    while(tmp->rchild != NULL && tmp->lchild != NULL)
    {
        if(tmp->lnum > tmp->rnum)
        {
            tmp->rnum++;
            tmp = tmp->rchild;
        }
        else
        {
            tmp->lnum++;
            tmp = tmp->lchild;
        }
    }
    Node *child = new Node;
    child->rnum = child->lnum = 0;
    child->lchild = NULL;
    child->rchild = NULL;
    child->elem = elem;
    if(tmp->lchild == NULL)
    tmp->lchild = child,tmp->lnum++;
    else
    tmp->rchild = child,tmp->rnum++;
    return true;
}
void xh(Btree head)
{
    cout<<head->elem<<' ';
    if(head->lchild != NULL)
    xh(head->lchild);
    if(head->rchild != NULL)
    xh(head->rchild);
    return;
}
void droptree(Btree head)
{
    if(head->lchild == NULL && head->rchild == NULL)
    {
        delete(head);
    }
    else
    {
        if(head->lchild != NULL)
        droptree(head->lchild);
        else if(head->rchild != NULL)
        droptree(head->rchild);
        delete(head);
    }
    return;
}
int main()
{  
    Btree head = new Node;
    inittree(head);
    int i,tmp;
    for(i = 0; i < 7; i++)
    {
        cin>>tmp;
        addnode(head,tmp);
    }
    xh(head);
    droptree(head);
    return 0;
}
