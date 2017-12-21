#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *front = NULL, *rear = NULL;

void insert(int);
int del();
// int isempty();  not used by me
// int isfull();
int peek();
void display();

int main()
{
    int choice, item;
    while(1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display the element at front\n");
        printf("4. Display all the elements of queue\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            insert(item);
            printf("\n");
            break;
        case 2:
            printf("\nItem deleted is: %d\n\n", del());
            break;
        case 3:
            printf("\nItem at the front is %d\n\n", peek());
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

void insert(int item)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(tmp == NULL)
    {
        printf("Queue overflow\n");
        return;
    }
    tmp->info = item;
    tmp->link=NULL;
    if(front == NULL)
        front = tmp;
    else
        rear->link = tmp;
    rear = tmp;
}

int del()
{
    int item;
    struct node *tmp;
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    tmp = front;
    item = front->info;
    front = front->link;
    free(tmp);
    return item;
}

int peek()
{
    if(front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    return front -> info;
}

/*int isempty()
{
    if(front == NULL)
    {
        return 1;
    }
    else
        return 0;
} i Not used, However in book it is used*/

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
   if(front == NULL)
   {
       printf("Queue is empty\n");
       return;
   }
   struct node *tmp;
   tmp = front;
   printf("Queue elements are: \n\n");
   for(;tmp!= NULL; tmp = tmp -> link)
   {
       printf(" %d\n", tmp -> info);

   }
   printf("\n\n");
}


