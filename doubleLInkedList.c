
/* Program of double linked list*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int info;
    struct node *next;

};

struct node *createList(struct node *start);
void display(struct node *start);
struct node *addtoempty(struct node *start, int data);
struct node *addatbeg(struct node *start, int data);
struct node *addatend(struct node *start, int data);
struct node *addafter(struct node *start, int data, int item);
struct node *addbefore(struct node *start, int data, int item);
struct node *del(struct node *start, int data);
struct node *reverse(struct node *start);

main()
{
    struct node *start = NULL;
    int choice, data, item;
    while(1)
    {
        printf("1. Create List\n");
        printf("2. Display\n");
        printf("3. Add to Empty List\n");
        printf("4. Add at beginning\n");
        printf("5. Add at End\n");
        printf("6. Add after\n");
        printf("7. Add before\n");
        printf("8. Delete\n");
        printf("9. Reverse\n");
        printf("10. Quit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                start = createList(start);
                break;
            case 2:
                display(start);
                break;
            case 3:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                start = addtoempty(start, data);
                break;
            case 4:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                start = addatbeg(start, data);
                break;
            case 5:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                start = addatend(start, data);
                break;
            case 6:
                printf("Enter the element to be inserted : ");
                scanf("%d", &data);
                printf("Enter the element after which to insert : ");
                scanf("%d", &item);
                start = addafter(start, data, item);
                break;
            case 7:
                printf("Enter the element to be inserted : ");
                scanf("%d", &data);
                printf("Enter the element before which to insert : ");
                scanf("%d", &item);
                start = addbefore(start, data, item);
                break;
            case 8:
                printf("Enter element to be deleted : ");
                scanf("%d", &data);
                start = del(start, data);
                break;
            case 9:
                start = reverse(start);
                break;
            case 10:
                exit(1);
            default:
                printf("wrong choice\n");
        }/*End of switch*/
    }/*End of while*/
}//End of main()


struct node *createList(struct node *start)
{

    int i, n, data;
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    start = NULL;
    if(n==0)
        return start;
    printf("Enter the element to be inserted : ");
    scanf("%d", &data);
    start = addtoempty(start, data);

    for(i=2; i<=n; i++)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d", &data);
        start = addatend(start, data);
    }
    return start;
}//End of create list

void display(struct node *start)
{
    struct node *p;
    if(start == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    printf("List is : \n");
    int c=1;
    p = start;
    for(;p != NULL;)
    {
        printf("%d. %d ",c, p->info);
        p = p->next;
        c++;
    }
    printf("\n");
}

struct node *addtoempty(struct node *start, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    start = tmp;
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = NULL;
    return start;
}//End of addtoempty()

struct node *addatbeg(struct node *start, int data)
{
    struct node *tmp;

    tmp = (struct node *)malloc(sizeof(struct node));

    tmp->info = data;
    tmp->next = start;
    tmp->prev = NULL;
    start->prev = tmp;
    start = tmp;
    return start;
}/*end of addatbeg()*/

struct node *addatend(struct node *start, int data){

    struct node *p, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));

    tmp->info = data;

    p = start;
    while(p->next != NULL){
        p = p->next;
    }

    p->next = tmp;
    tmp->next = NULL;
    tmp->prev = p;
    return start;
}/*End of addatend()*/

struct node *addafter(struct node *start, int data, int item)
{
    struct node *p, *tmp;
    p = start;
    while(p!=NULL)
    {
            if(p->info == item)
            {
                tmp = (struct node *)malloc(sizeof(struct node));
                tmp->next = p->next;
                tmp->info = data;
                if(p->next != NULL)
                    p->next->prev = tmp;
                p->next = tmp;
                return start;
            }

            p = p->next;
    }

    printf("%d id not in the list\n", item);
    return start;
}/*End of addafter()*/      //Completed upto it yet

struct node *addbefore(struct node *start, int data, int item)
{
    struct node *q, *tmp;
    if(start == NULL)
    {
        printf("List is Empty\n");
        return start;
    }
    if(start->info == item)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;
        tmp->prev = NULL;
        tmp->next = start;
        start->prev = tmp;
        start = tmp;
        return start;
    }
    q = start;
    while(q!=NULL)
    {
            if(q->info == item)
            {
                tmp = (struct node *)malloc(sizeof(struct node));
                tmp->prev = q->prev;
                tmp->next = q;
                tmp->info = data;
                q->prev->next = tmp;
                q->prev = tmp;
                return start;
            }

            q = q->next;
    }

    printf("%d id not in the list\n", item);
    return start;
}/*End of addbefore()*/

struct node *del(struct node *start, int data)
{
    struct node *tmp;

    if (start == NULL)
    {
        printf("list is Empty\n ");
        return start;
    }

    if(start->next == NULL)
    {
        if(start->info == data)
        {
            tmp = start;
            start = NULL;
            free(tmp);
            return start;
        }
        else{
            printf("Element %d is not found\n", data);
            return start;
        }
    }

    if(start->info == data)
    {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        free(tmp);
        return start;
    }

    tmp = start->next;
    while(tmp->next!=NULL)
    {
        if(tmp->info == data)
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(tmp);
            return start;
        }
        tmp = tmp->next;
    }
    if(tmp->info == data)
    {
        tmp->prev->next = NULL;
        free(tmp);
        return start;
    }
    printf("Element %d not found\n ", data);
    return start;
}/*End of delete*/

 struct node *reverse(struct node  *start)
 {
     struct node *p1, *p2;
     p1=start;
     p2 = p1->next;
     p1->next = NULL;
     p1->prev = p2;
     while(p2 != NULL)
     {
         p2->prev = p2->next;
         p2->next = p1;
         p1 =p2;
         p2 = p2->prev;
     }
     start = p1;
     printf("List reversed\n");
     return start;

}/*End of reverse()*/
