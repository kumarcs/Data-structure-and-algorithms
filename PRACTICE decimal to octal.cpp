#include<iostream>
#define MAX 50
using namespace std;

int stack[MAX];
void push(int);
int pop();
int top=-1;

int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;
    while(num!=0)
    {
        push(num%8);
        num=num/8;
    }
    cout << "octal conversion is: ";
    while(top!=-1)
    {
        cout << pop();
    }
}

void push(int num)
{
    if(top==MAX)
    {
        cout << "Overflow";
        return;
    }
    stack[++top]=num;
    return;
}

int pop()
{
    if(top==-1)
    {
        cout << "Underflow\n";
        return 0;
    }
    return (stack[top--]);
}
