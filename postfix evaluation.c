#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define BLANK ' '
#define TAB '\t'
#define MAX 50
void push (long int);
long int pop();
void infix_to_postfix();
long int eval_post();
int priority(char);
int isempty();
int top;
int whiteSpace(char);
char infix[MAX], postfix[MAX];
long int stack[MAX];

main()
{
    long int value;
    top = -1;
    printf("Enter infix : ");
    gets(infix);
    infix_to_postfix();
    printf("Postfix : %s\n", postfix);
    value = eval_post();
    printf("Value of expression : %ld\n", value);
}
void infix_to_postfix()
{

    unsigned int i, p =0;
    char next;
    char symbol, prevsymbol='&';
    for(i=0; i<strlen(infix); i++)
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
                        postfix[p++]=next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while(!isempty() && priority(stack[top])>=priority(symbol))
                    postfix[p++] = pop();
                push(symbol);
                break;
            default:
                postfix[p++] = symbol;

            }
        }
    }
    while(!isempty())
        postfix[p++] = pop();
    postfix[p] = '\0';

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
    stack[++top]=symbol;
}
long int pop()
{
    if(isempty())
    {
        printf("stack underflow\n");
        exit(1);
    }
    return (stack[top--]);
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
    for(i=0;i<strlen(postfix); i++)
    {
        if(postfix[i]<='9' && postfix[i]>='0')
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
