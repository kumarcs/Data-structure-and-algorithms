#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int queue_arr[MAX];
int rear = -1;
int front = -1;
void insert(int );
int del();
int isempty();
int isfull();
int peek();
void display();

int main()
{
    int choice, item;
    while(1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display the element at the front\n");
        printf("4. Display all elements of queue\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            insert(item);
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
    if(isfull())
    {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    if(rear == MAX - 1)
        rear = 0;

    else rear += 1;
    queue_arr[rear] = item;
    return;

}

int del()
{
    int item;
    if(isempty())
    {
        printf("Queue is empty\n");
        return;
    }
    item = queue_arr[front];
    if(rear==front)
    {
        rear = front = -1;
    }
    else if(front == MAX -1)
        front = 0;
    else front = front + 1;
    return item;
}

int peek()
{
    if(isempty())
    {
        printf("queue Underflow\n");
        return;
    }
    return queue_arr[front];
}

int isempty()
{
    if(front == -1 || front == rear+1)
    {
        return 1;
    }
    else
        return 0;
}

int isfull()
{
    if(rear==MAX-1 && front == 0)
    {
        return 1;
    }
    else
        return 0;
}

void display()
{
   if(isempty())
   {
       printf("Queue is empty\n");
       return;
   }
   int i = front;
   printf("Queue elements are: \n\n");

   if(front <= rear)
   {
       while(i<=rear)
       {
           printf(" %d ",queue_arr[i++]);
       }
   }

   else
   {
       while(i<= MAX-1)
        printf(" %d ", queue_arr[i++]);
       i=0;
       while(i<=rear)
        printf(" %d ", queue_arr[i++]);
   }
   printf("\n");
}



