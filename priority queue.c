#include <stdio.h>
#include <stdlib.h>

struct node
{
    int priority;
    int info;
    struct node *link;
} *front = NULL;

void insert(int item, int item_priority);
int del();
void display();
int isempty();

int main()
{
    int choice, item, item_priority;
    while(1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Input the item to be added in the queue: ");
            scanf("%d", &item);
            printf("Enter its priority: ");
            scanf("%d", &item_priority);
            insert(item, item_priority);
            break;
        case 2:
            printf("Deleted item is %d\n", del());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
    }
}
void insert(int item, int item_priority)
{
    struct node *tmp, *p;
    tmp = (struct node*)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("Memory not available\n");
        return;
    }
    tmp->info = item;
    tmp->priority = item_priority;
    if(isempty() || item_priority < front->priority)
    {
        tmp->link = front;
        front = tmp;
    }
    else
    {
        p = front;
        while(p->link!=NULL && p->link->priority<=item_priority)
            p = p->link;
        tmp->link=p->link;
        p->link=tmp;
    }
}
int del()
{
    struct node *tmp;
    int item;
    if(isempty())
    {
        printf("Queue Underflow\n");
        return 0;
    }
    else
    {

        tmp = front;
        front = front->link;
        item = tmp->info;
        free(tmp);
    }
    return item;
}
int isempty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}
void display()
{
    struct node *ptr;
    ptr = front;
    if(isempty())
        printf("Queue is empty\n");
    else
    {
        printf("Queue is :\n");
        printf("priority     item\n");
        while(ptr!=NULL)
        {
            printf("%5d          %5d\n",ptr->priority,ptr->info);
            ptr = ptr->link;
        }
    }
}
