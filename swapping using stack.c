#include<stdio.h>
#include<stdlib.h>
#define MAX 20
char stack[MAX];
int top = -1;
char pop();
void push(char);
main()
{
    char str[20];
    unsigned int i;
    printf("Enter the string : ");
    gets(str);
    for(i=0;i<strlen(str);i++)
        push(str[i]);
    for(i=0;i<strlen(str);i++)
        str[i]=pop();
    printf("Reversed string is : ");
    puts(str);
    getch();
}
char pop()
{
    if(top==-1)
    {
        printf("Empty stack");
        return;
    }
    return stack[top--];
}
void push(char item)
{
    if(top==MAX-1)
    {
        printf("stack underflow");
        return;
    }
    stack[++top] = item;
}
