#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define BLANK ' '
#define TAB '\t'
#define MAX 50

void infix_to_prefix();
void infix_to_postfix();
long int eval_post();
char infix[MAX], postfix[MAX], prefix[MAX];
long int stack[MAX];
int top=-1;
int priority(char);
long int pop();
void push(long int);
void reverseinf();
void reversedpost();

main()
{
    long int value;
    top = -1;
    printf("*");
    printf("Enter infix : ");
    gets(infix);
    printf("*");
    infix_to_prefix();
    printf("*");
    printf("Prefix : %s\n", prefix);
    printf("*");
    infix_to_postfix();
    printf("*");
    value = eval_post();
    printf("*");
    printf("Value of expression : %ld\n", value);

}

void reverseinf()
{
    char arr[MAX];
    int i, j=0;
    for(i=strlen(infix)-1; i>=0; i--)
    {
        arr[j++]=infix[i];
    }
    arr[j]='\0';
    strcpy(infix, arr);
}

void reversedpost()
{
    char arr[MAX];
    int i, j=0;
    for(i=strlen(postfix)-1; i>=0; i--)
    {
        arr[j++]=postfix[i];
    }
    arr[j]='\0';
    strcpy(prefix, arr);
}


void infix_to_prefix()
{
    unsigned int i, p =0;
    char next;
    char symbol;
    reverseinf();
    for(i=0; i<strlen(infix); i++)
    {

        symbol = infix[i];

       if(symbol!=BLANK || symbol!=TAB)
        {
            switch(symbol)
            {

            case ')':
                push(symbol);
                break;
            case '(':
                while((next = pop())!= ')')
                        postfix[p++]=next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while(top!=-1 && priority(stack[top])>=priority(symbol))
                {
                    postfix[p++]=pop();
                }
                push(symbol);
                break;
            default:
                postfix[p++]=symbol;
            }
        }
    }
    while(top!=-1)
    {
        postfix[p++]=pop();
    }
    postfix[p]='\0';
    reversedpost();
}

void infix_to_postfix()
{
    reverseinf();
    int i, p=0;
    char symbol, next;
    for(i=0; i<strlen(infix); i++)
    {
        symbol=infix[i];
        switch(symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while((next=pop())!='(')
                    postfix[p++]=next;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            while(top!=-1 && priority(stack[top])>=priority(symbol))
                postfix[p++]=pop();
            push(symbol);
            break;
        default:
            postfix[p++]=symbol;
        }
    }
    while(top!=-1)
        postfix[p++]=pop();
    postfix[p]='\0';
}
int priority(char symbol)
{
    switch(symbol)
    {
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
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
        printf( "OVERFLOW");
        return;
    }
    stack[++top]=symbol;
}

long int pop()
{
    if(top==-1)
    {
        printf("underflow");
        return;
    }
    return stack[top--];
}

long int eval_post()
{
    long int a, b, temp, result;
    unsigned int i;
    for(i=0; i<strlen(postfix); i++)
    {
        if(postfix[i]<='9' && postfix[i]>='0')
            push(postfix[i]-'0'); //did use '0'
        else
        {
            a=pop();
            b=pop();
            switch(postfix[i])
            {
            case '+':
                temp=b+a; break;
            case '-':
                temp=b-a; break;
            case '*':
                temp=b*a; break;
            case '/':
                temp=b/a; break;
            case '%':
                temp=b%a; break;
            case '^':
                temp=pow(b,a);
            }
            push(temp);
        }
    }
    result = pop();
    return result;
}
