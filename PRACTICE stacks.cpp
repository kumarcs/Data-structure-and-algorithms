#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 50
int stack[MAX];
int top=-1;
void insert(int item);
int del();
int main()
{
    int choice, item, i, n;
    while(1)
    {
        cout << "1. generate random stack" << endl
             << "2. insert in stack" << endl
             << "3. delete from stack" << endl
             << "4. more.." << endl;
        cin >> choice;
        switch(choice)
        {
        case 1:
            cout << "Enter number of elements: "; cin >> n;
            for(i=0; i<n; i++)
                insert(rand()%50);
            break;
        case 2:
            cout << "Enter element: ";
            cin >> item;
            insert(item);
            cout << "inserted"<<endl;
            break;
        case 3:
            cout << del() << "deleted!!";
            break;
        //case 3:

        }
    }

}

void insert(int item)
{
    if(top==MAX)
    {
        cout << "Overflow!!" << endl;
        return;
    }
    stack[++top]=item;
    return;
}

int del()
{
    int item;
    if(top==-1)
    {
        cout << "Underflow!" << endl;
        return 0;
    }
    item = stack[top--];
    return (item);
}
