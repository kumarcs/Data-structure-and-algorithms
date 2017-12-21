#include<iostream>
#include<cstring>
using namespace std;
#define MAX 20

char exp[MAX];
void push(char );
char pop();
char stack[MAX];
int top=-1;

int main()
{
    cout << "Enter expression: ";
    cin >> exp;
    int i;
    char symbol, temp;
    for(i=0; i<strlen(exp); i++)
    {
        symbol=exp[i];
        switch(symbol)
        {
        case '(':
        case '{':
        case '[':
            push(symbol);
            break;
        case ')':
            if(top==-1)
            {
                cout << "right parenthesis are more than left\n";
                return 0;
            }
            else
            {
                temp=pop();
                if(!(temp=='(' && symbol==')'))
                {
                    cout << "mismatched parenthesis are: " << temp << " and " << symbol;
                    return 0;
                }
            }
                break;
        case '}':
            if(top==-1)
            {
                cout << "right parenthesis are more than left\n";
                return 0;
            }
            else
            {
                temp=pop();
                if(!(temp=='{' && symbol=='}'))
                {
                    cout << "mismatched parenthesis are: " << temp << " and " << symbol;
                    return 0;
                }
            }
                break;
        case ']':
            if(top==-1)
            {
                cout << "right parenthesis are more than left\n";
                return 0;
            }
            else
            {
                temp=pop();
                if(!(temp== '[' && symbol==']'))
                {
                    cout << "mismatched parenthesis are: " << temp << " and " << symbol;
                    return 0;
                }
            }
        }
    }

    if(top==-1)
    {
        cout << "parenthesis are balanced \n";
        return 1;
    }
    else
    {
        cout << "left parenthesis are greater than right parenthesis\n";
        return 0;
    }
}

void push(char item)
{
    if(top==MAX)
    {
        cout << "Overflow\n";
        return;
    }
    top=top+1;
    stack[top]=item;
}

char pop()
{
    if(top==-1)
    {
        cout << "Underflow\n";
        return 1;
    }
    return (stack[top--]);
}
