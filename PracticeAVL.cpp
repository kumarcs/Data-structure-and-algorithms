#include<iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
struct node
{
    node *lchild;
    node *rchild;
    int info;
    int balance;
};
struct node *rotateleft(node *root)
{
    node *temp;
    temp=root->lchild;
    root->lchild=temp->rchild;
    temp->rchild=root;
    return temp;
};
struct node *rotateright(node *root)
{
    node *temp;
    temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    return temp;
};
node *insert(node *ptr, int data)
{
    static int taller;
    if(ptr==NULL)
    {
        ptr=new node;
        ptr->info=data
        ptr->child=NULL;
        ptr->rchild=NULL;
        ptr->balance=0;
        taller=TRUE;
    }
    else if(key<ptr->info)
    {
        ptr->lchild=insert(ptr->lchild, key);
        if(taller==TRUE)
        {
            ptr=insert_left_check(ptr, &taller);
        }
    }
    else if(key>ptr->info)
    {
        ptr->rchild=inser(ptr->rchild, key);
        if(taller==TRUE)
        {
            ptr=insert_right_check(ptr, &taller);
        }
    }
    else
    {
        cout << "duplicate key" << endl;
        taller = FALSE;
    }
    return ptr;
}
int main()
{

}
