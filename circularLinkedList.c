
/* Program of single linked list*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;

};

struct node *createList(struct node *last);
void display(struct node *last);
struct node *addtoempty(struct node *last, int data);
struct node *addatbeg(struct node *last, int data);
struct node *addatend(struct node *last, int data); //You have to start from here
struct node *addafter(struct node *start, int data, int item);
struct node *addbefore(struct node *start, int data, int item);
struct node *addatpos(struct node *start, int data, int pos);
struct node *del(struct node *start, int data);
struct node *reverse(struct node *start);

main()
{
    struct node *start = NULL;
    int choice, data, item, pos;
    while(1)
    {
        printf("1. Create List\n");
        printf("2. Display\n");
        printf("3. Count\n");
        printf("4. Search\n");
        printf("5. Add at beginning\n");
        printf("6. Add at end\n");
        printf("7. Add after node\n");
        printf("8. Add before node\n");
        printf("9. Add at position\n");
        printf("10. Delete\n");
        printf("11. Reverse\n");
        printf("12. Quit\n\n");
        printf(" Enter your choice: ");
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
                count(start);
                break;
            case 4:
                printf("enter element to be searched: ");
                scanf("%d", &data);
                search(start, data);
                break;
            case 5:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                start = addatbeg(start, data);
                break;
            case 6:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                start = addatend(start, data);
                break;
            case 7:
                printf("Enter the element to be inserted : ");
                scanf("%d", &data);
                printf("Enter the element after which to insert : ");
                scanf("%d", &item);
                start = addafter(start, data, item);
                break;
            case 8:
                printf("Enter the element to be inserted : ");
                scanf("%d", &data);
                printf("Enter the element before which to insert : ");
                scanf("%d", &item);
                start = addbefore(start, data, item);
                break;
            case 9:
                printf("Enter the element to be inserted : ");
                scanf("%d", &data);
                printf("Enter the position at which to insert : ");
                scanf("%d", &pos);
                start = addatpos(start, data, pos);
                break;
            case 10:
                printf("Enter element to be deleted : ");
                scanf("%d", &data);
                start = del(start, data);
                break;
            case 11:
                start = reverse(start);
                break;
            case 12:
                exit(1);
            default:
                printf("wrong choice\n");
        }
    }
}


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
    start = addatbeg(start, data);

    for(i=2; i<=n; i++)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d", &data);
        start = addatend(start, data);
    }
    return start;
}

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
        p = p->link;
        c++;
    }
    printf("\n\n");
}

void count(struct node *start){

    struct node *p;
    p = start;
    int c = 0;
    while(p!=NULL)
    {
        c++;
        p = p->link;
    }
    printf("Number of elements are %d\n", c);

} /*End of Count*/


void search(struct node *start, int item){

    struct node *p;
    p = start;
    int pos = 0;

    while(p != NULL)
    {

        if(p->info == item){
            printf("Item %d found at position %d\n",item, pos);
            return;
        }

        p = p->link;
        pos++;
    }

    printf("Item %d not found in list\n", item);
}/*End of Search*/

struct node *addatbeg(struct node *start, int data)
{
    struct node *tmp;

    tmp = (struct node *)malloc(sizeof(struct node));

    tmp->info = data;
    tmp->link = start;
    start = tmp;
    return start;
}/*end of addatbeg()*/

struct node *addatend(struct node *start, int data){

    struct node *p, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));

    tmp->info = data;

    p = start;
    while(p->link != NULL){
        p = p->link;
    }

    p->link = tmp;
    tmp->link = NULL;
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
                tmp->link = p->link;
                tmp->info = data;
                p->link = tmp;
                return start;
            }

            p = p->link;
    }

    printf("%d id not in the list\n", item);
    return start;
}/*End of addafter()*/

struct node *addbefore(struct node *start, int data, int item)
{
    struct node *p, *tmp;
    if(start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    //If data to be inserted before first node
    if(item == start->info)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;
        tmp->link = start;
        start = tmp;
        return start;
    }

    p = start;
    while(p!=NULL)
    {
            if(p->link->info == item)
            {
                tmp = (struct node *)malloc(sizeof(struct node));
                tmp->link = p->link;
                tmp->info = data;
                p->link = tmp;
                return start;
            }

            p = p->link;
    }

    printf("%d id not in the list\n", item);
    return start;
}/*End of addbefore()*/

struct node *addatpos(struct node *start,int data, int pos)
{
    struct node *tmp, *p;
    int i;
    p = start;
    if(pos == 1)
    {
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->link = start;
        start = tmp;
        return start;
    }

    for(i=1; i<pos-1 && p!= NULL;i++)
        p = p->link;
    if(p == NULL)
        printf("There are less than %d elements \n", pos);
    else{
        tmp->link = p->link;
        p->link = tmp;
        }
    return start;
}/*End of addatpos()*/

struct node *del(struct node *start, int data)
{
    struct node *tmp, *p;

    if (start == NULL)
    {
        printf("list is Empty\n ");
        return start;
    }

    if(start->info == data)
    {
        tmp = start;
        start = start->link;
        free(tmp);
        return start;
    }

    p = start;
    while(p!=NULL)
    {
        if(p->link->info == data)
        {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return start;
        }
        p = p->link;
    }

    printf("Element %d not found\n ", data);
    return start;
}/*End of delete*/

 struct node *reverse(struct node  *start)
 {
     struct node *prev, *next, *ptr;
     prev = NULL;
     ptr = start;
     while(ptr!=NULL)
     {
        next = ptr->link;
         ptr->link = prev;
         prev = ptr;
         ptr = next;

     }
     start = prev;
     return start;

 }/*End of reverse()*/
