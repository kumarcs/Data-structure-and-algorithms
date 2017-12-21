#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define MAX 10

int deque_arr[MAX];
int rear = -1;
int front = -1;
void insert_frontEnd(int );
void insert_rearEnd(int );
int del_frontEnd();
int del_rearEnd();
int isempty();
int isfull();
int peek();
void display();

int main()
{
    int choice, item;
    while(1)
    {
        printf("1. Insert at the front end\n");
        printf("2. Insert at the rear end\n");
        printf("3. Delete from front end\n");
        printf("4. Delete from rear end\n");
        printf("5. Display\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            insert_frontEnd(item);
            break;
        case 2:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            insert_rearEnd(item);
            break;
        case 3:
            printf("\nItem deleted is: %d\n\n", del_frontEnd());
            break;
        case 4:
            printf("\nItem deleted is: %d\n\n", del_rearEnd());
            break;
        case 5:
            display();
            break;
        case 6:
            exit(1);
        default:
            printf("Wrong choice\n");

        }

        cout<<"front = "<<front<<" rear = "<<rear<<"\n";
        display();
    }
}

void insert_frontEnd(int item)
{
    if(isfull())
    {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if(front == 0)
        front = MAX-1;
    else front -= 1;
    deque_arr[front] = item;


}

void insert_rearEnd(int item)
{
    if(isfull())
    {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if(rear == MAX-1)
        rear = 0;
    else rear += 1;
    deque_arr[rear] = item;
}

int del_frontEnd()
{
    int item;
    if(isempty())
    {
        printf("Queue is empty\n");
        return;
    }
    item = queue_arr[front];
    if(front = MAX-1)
        front = 0;
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
        front += 1;
    return item;
}

int del_rearEnd()
{
    int item;
    if(isempty())
    {
        printf("Queue is empty\n");
        return;
    }
    item = queue_arr[rear];
    if(rear = 0)
        rear = MAX - 1;
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
        rear -= 1;
    return item;
}

/* int peek()
{
    if(isempty())
    {
        printf("queue Underflow\n");
        return;
    }
    return queue_arr[front];
} */

int isempty()
{
    if(front == -1)
    {
        return 1;
    }
    else
        return 0;
}

int isfull()
{
    if((front = 0 && rear==MAX-1) || (front = rear + 1))
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
   int i;
   printf("Queue elements are: \n\n");
    if(front <= rear)
    {
        i = front;
        while(i <= rear)
            printf(" %d ", deque_arr[i]);
    }
    else
    {
        i = front;
        while(i<=MAX-1)
            printf(" %d ", deque_arr[i]);
        i = 0;
        while(i<=rear)
            printf(" %d ", deque_arr[i]);
    }

   printf("\n");
}

