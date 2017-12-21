#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
using namespace std;
struct node
{
    int roll_no;
    char name[20];
    int marks;
    node *link;
};

node *insertatbeg(node *, int , char *, int);
node *insertatend(node *, int , char *, int);
node *insertafter(node *, int , int , char *, int);
node *deletenode(node *, int );
void displayheader(node *);
void display(node *);
int main()
{
    int choice, roll_no, marks, noderoll;
    char name[20];
    node *last=new node;
    last->roll_no=0;
    last->marks=0;
    last->link=NULL;
    while(1)
    {
        printf("1. insert at beginning\n");
        printf("2. insert at end\n");
        printf("3. insert after a given node\n");
        printf("4. delete a specific node\n");
        printf("5. display the list\n");
        printf("6. display header info\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            cout << "Enter roll_no: ";
            cin >> roll_no;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter marks: ";
            cin >> marks;
            last = insertatbeg(last, roll_no, name, marks);
            break;
        case 2:
            cout << "Enter roll_no: ";
            cin >> roll_no;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter marks: ";
            cin >> marks;
            last = insertatend(last, roll_no, name, marks);
            break;
        case 3:
            cout << "Enter roll no after which to insert: ";
            cin >> noderoll;
            cout << "Enter roll_no: ";
            cin >> roll_no;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter marks: ";
            cin >> marks;
            last = insertafter(last, noderoll, roll_no, name, marks);
            break;
        case 4:
            cout << "Enter roll no to delete: ";
            cin >> noderoll;
            last = deletenode(last, noderoll);
            break;
        case 5:
            display(last);
            break;
        case 6:
            displayheader(last);
            break;
        default:
            cout << "wrong choice\n";
            break;
        }
    }
}

node *insertatbeg(node *last, int roll_no, char name[], int marks)
{
    node *temp;
    temp = new node;
    temp->roll_no=roll_no;
    strcpy(temp->name,name);
    temp->marks=marks;
    if(marks > last->marks)
    {
        last->marks=marks;
        last->roll_no=roll_no;
    }
    if(last->link==NULL)
    {
        last->link=temp;
        temp->link=temp;
        return last;
    }
    temp->link=last->link->link;
    last->link->link=temp;
    return last;
}

node *insertatend(node *last, int roll_no, char name[], int marks)
{
    node *temp;
    temp = new node;
    temp->roll_no=roll_no;
    strcpy(temp->name, name);
    temp->marks=marks;
    if(marks>last->marks)
    {
        last->marks=marks;
        last->roll_no=roll_no;
    }
    temp->link=last->link->link;
    last->link->link=temp;
    last->link=temp;
    return last;
}

node *insertafter(node *last, int noderoll, int roll_no, char *name, int marks)
{
    node *ptr, *temp;
    temp = new node;
    if(last->link->roll_no==noderoll)
    {
        last = insertatend(last, roll_no, name, marks);
        return last;
    }
    ptr=last->link->link;
    do
    {
        if(ptr->roll_no=noderoll)
        {
            temp->roll_no=roll_no;
            strcpy(temp->name,name);
            temp->marks=marks;
            temp->link=ptr->link;
            ptr->link=temp;
            return last;
        }
        ptr=ptr->link;
    }while(ptr!=last->link->link);
    cout << "roll_no not present in the list";
    return last;
}

void display(node * last)
{
    if(last->link==NULL)
    {
        cout << "List is empty\n";
        return;
    }
    node *ptr;
    ptr=last->link->link;
    do
    {
        cout <<"roll no: " << ptr->roll_no << "\n"
             <<"name: " << ptr->name << "\n"
             <<"marks: " << ptr->marks << "\n\n";
        ptr=ptr->link;
    }while(ptr!=last->link->link);
    printf("\n");
}

node *deletenode(node *last, int noderoll)
{
    node *ptr, *temp;
    if(last->link==NULL)
    {
        cout << "empty list";
        return last;
    }
    if(last->link->link==last->link && last->link->roll_no==noderoll)
    {
        temp=last->link;
        last->link=NULL;
        free(temp);
        return last;
    }
    ptr=last->link;
    if(ptr->link->roll_no==noderoll)
    {
        temp=ptr->link;
        ptr->link=temp->link;
        free(temp);
        return last;
    }
    ptr=last->link->link;
    while(ptr->link!=last->link)
    {
        if(ptr->link->roll_no==noderoll)
        {
            temp=ptr->link;
            ptr->link=temp->link;
            free(temp);
            return last;
        }
        ptr=ptr->link;
    }
    if(last->link->roll_no==noderoll)
    {
        temp=last->link;
        ptr->link=temp->link;
        last->link=ptr;
        free(temp);
        return last;
    }
    cout << "element not found\n";
    return last;
}

void displayheader(node *last)
{
    if(last->link==NULL)
    {
        cout << "list is empty\n";
        return;
    }
    printf("\n");
    cout << "max marks: " << last->marks << " of roll no: " << last->roll_no << "\n\n";
    return;
}
