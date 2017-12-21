#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *top = NULL;

void push(int);
int pop();
int isempty();
int isfull();
int peek();
void display();

int main()
{
    int choice, item;
    while(1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display the top element\n");
        printf("4. Display all elements\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter the item to be pushed: ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            printf("\nItem popped out is: %d\n\n", pop());
            break;
        case 3:
            printf("\nItem at the top is %d\n\n", peek());
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice\n");

        }

    }
}

void push(int item)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(tmp == NULL)
    {
        printf("Stack overflow\n");
        return;
    }

    tmp->info = item;
    tmp->link=top;
    top = tmp;
}

int pop()
{
    int item;
    struct node *tmp;
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    tmp = top;
    item = top->info;
    top = top -> link;
    free(tmp);
    return item;
}

int peek()
{
    if(top == NULL)
    {
        printf("stack Underflow\n");
        return;
    }

    return top -> info;
}

int isempty()
{
    if(top == NULL)
    {
        return 1;
    }
    else
        return 0;
}

/*int isfull()
{
    if(top==MAX-1)
    {
        return 1;
    }
    else
        return 0;
}*/

void display()
{
   if(isempty())
   {
       printf("Stack is empty\n");
       return;
   }
   struct node *tmp;
   tmp = top;
   printf("stack elements: \n\n");
   for(;tmp!= NULL; tmp = tmp -> link)
   {
       printf(" %d\n", tmp -> info);

   }
   printf("\n");
}

