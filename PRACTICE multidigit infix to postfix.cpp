#include<math.h>
#include<bits/stdc++.h>
#include<string.h>
#define BLANK ' '
#define TAB '\t'
#define MAX 50
using namespace std;
void push (long int);
long int pop();
void infix_to_postfix();
long int eval_post();
int priority(char);
int isempty();
int top;
int whiteSpace(char);
string infix, postfix;
long int mystack[MAX];
void changeinfix();
main()
{
    long int value;
    top = -1;
    printf("Enter infix : ");
    cin >> infix;
    changeinfix();
    infix_to_postfix();
    cout << postfix << endl;
    value = eval_post();
    cout << value;
}
void infix_to_postfix()
{

    unsigned int i, p =0;
    char next;
    char symbol, prevsymbol='&';
    for(i=0; i<infix.length(); i++)
    {

        symbol = infix[i];
        if(!whiteSpace(symbol))
        {
            switch(symbol)
            {

            case '(':
                push(symbol);
                break;
            case ')':
                while((next = pop())!= '(')
                        postfix += next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while(!isempty() && priority(mystack[top])>=priority(symbol))
                    postfix += pop();
                push(symbol);
                break;
            default:
                postfix += symbol;

            }
        }
    }
    while(!isempty())
        postfix += pop();

}

int priority(char symbol)
{
    switch(symbol)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '%':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}
void push(long int symbol)
{
    if(top>MAX)
    {
        printf("stack overflow\n");
        return;
    }
    mystack[++top]=symbol;
}
long int pop()
{
    if(isempty())
    {
        printf("stack underflow\n");
        exit(1);
    }
    return (mystack[top--]);
}
int isempty()
{
    if(top==-1)
    {
        return 1;
    }
    else
        return 0;
}
int whiteSpace(char symbol)
{
    if(symbol == BLANK || symbol == TAB)
        return 1;
    else
        return 0;
}

long int eval_post()
{
    long int a, b, temp, result;
    unsigned int i;
    for(i=0;i<postfix.length(); i++)
    {
        int n=0;
        if(postfix[i]=='\'')
        {

            i=i+1;
            while(postfix[i]<='9' && postfix[i]>='0')
            {
                n = n*10 + (postfix[i]-'0');
                i=i+1;
            }
            push(n);
        }
        else if(postfix[i]<='9' && postfix[i]>='0')
        {
            push(postfix[i]-'0');   //chech by removing -'0'
        }
        else
        {
            a=pop();
            b=pop();
            switch(postfix[i])
            {
            case '+':
                temp = b+a; break;
            case '-':
                temp = b-a; break;
            case '/':
                temp = b/a; break;
            case '*':
                temp = b*a; break;
            case '%':
                temp = b%a; break;
            case '^':
                temp = pow(b,a);
            }
            push(temp);
        }
    }
    result = pop();
    return result;
}
void changeinfix()
{
    int i, j, len=infix.length(), p=0;
    for(i=0; i<infix.length()-1; i++)
    {
        p=0;
        if(infix[i]<='9' && infix[i]>='0')
        {
            for(j=i+1; j<infix.length(); j++)
            {
                if(infix[j]<='9' && infix[j]>='0')
                {
                    p=1;
                }
                else
                    break;
            }
            if(p==1)
            {
                infix.insert(i, "'");
                infix.insert(j+1, "'");
                i=j+1;
            }
        }
    }
}
