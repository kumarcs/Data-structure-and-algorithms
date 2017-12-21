#include<stdio.h>
#define MAX 10
int top = -1;
int stack[MAX];
void push(char);
char pop();
int match(char a, char b);
main()
{
    char exp[MAX];
    int valid;
    printf("Enter an algebric expression : ");
    gets(exp);
    valid = check(exp);
    if(valid == 1)
        printf("Valid expression\n");
        else
            printf("Invalid expression");
}

int check(char exp[])
{
    int i;
    char temp;
    for(i=0; i<strlen(exp); i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
                     push(exp[i]);
        if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(top == -1)
            {
                printf("righ parentheses are more than left\n");
                return 0;
            }
            else
            {
                temp = pop();
                if(!match(temp, exp[i]))
                {
                    printf("parentheses mismatched are : ");
                    printf("%c and %c\n",temp, exp[i]);
                }
            }
        }
    }
    if(top==-1)
    {
        printf("balanced parentheses\n");
        return;
    }
    else{
        printf("lest parentheses are more than right parentheses\n");
        return 0;
    }
}
int match(char a, char b)
{
    if(a=='{' && b=='}')
        return 1;
    if(a=='(' && b==')')
        return 1;
    if(a=='[' && b==']')
        return 1;
    return 0;
}
void push(char item)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=item;
}
char pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
        return;
    }
    return (stack[top--]);

}
