#include<stdio.h>
#define MAX 10

int stack[MAX];
int top=-1;

void push(int item);
int pop();
void display();
int isempty();
int isfull();
int peek();

int main()
{
    int choice, num, i, item;
    while(1)
    {
        printf("\n1. push item to the list\n");
        printf("2. pop last item\n");
        printf("3. display stack\n");
        printf("4. top element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter number of elements: ");
            scanf("%d", &num);
            if(num <= MAX)
            {
                for(i=0; i<num; i++)
                {
                    printf("Enter item to insert: ");
                    scanf("%d", &item);
                    push(item);
                }
            }
            else
                printf("limit exceeded\n");

            break;
        case 2:
            item = pop();
            printf("\n%d popped out\n", item);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\n%d is top element\n", peek());
            break;
        case 5:
            return;
        default:
            printf("wrong choice\n");
        }
    }

}

void push(int item)
{
    if(isfull())
    {
        printf("stack is full\n");
        return;
    }
    else
    {
        top=top+1;
        stack[top]=item;
        return;
    }
}

int pop()
{
    int item;
    if(isempty())
    {
        printf("stack underflow\n");
        return;
    }
    else
    {
        item=stack[top];
        top--;
        return item;
    }
}

void display()
{
    if(isempty())
    {
        printf("stack is empty\n");
        return;
    }
    int i;
    for(i=top; i>=0; i--)
    {
        printf(" %d", stack[i]);
    }
    printf("\n");
    return;
}

int peek()
{
    if(isempty())
    {
        printf("stack Underflow\n");
        return;
    }
    return stack[top];
}

int isfull()
{
    if(top==MAX)
        return 1;
    else
        return 0;
}

int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
