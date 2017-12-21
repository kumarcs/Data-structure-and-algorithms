#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *genrandlist(struct node *);
int count_nodes(struct node *start);
struct node *insertatbeg(struct node*, int);
struct node *insertatend(struct node*, int);
struct node *delfirst(struct node*);
struct node *dellast(struct node*);
struct node *delafter(struct node*, int);
struct node *delat(struct node*, int);
struct node *swap(struct node*, int ,int);
struct node *reverse(struct node*);
struct node *sep_ev_od(struct node*);
struct node *bub_sort_exch_links(struct node *);
void display(struct node *);
void reversedisplay(struct node *);
int main()
{
    struct node *start=NULL;
    int choice, item, n, item1, item2, count;
    while(1){
    printf("\n");
    printf("1. generate random list\n");
    printf("2. count no of nodes\n");
    printf("3. insert at beginning\n");
    printf("4. insert at end\n");
    printf("5. delete first node\n");
    printf("6. delete last node\n");
    printf("7. delete after a node\n");
    printf("8. delete a node\n");
    printf("9. display the list\n");
    printf("10. reverse display\n");
    printf("11. swap any two nodes\n");
    printf("12. reverse the list\n");
    printf("13. separate even odd\n");
    printf("14. bubble sort by exchanging links\n");
    printf("15. exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        start = genrandlist(start);
        printf("\n");
        display(start);
        break;
    case 2:

        count = count_nodes(start);
        printf("No of nodes are: %d", count);
        break;
    case 3:
        printf("Enter data to be inserted: ");
        scanf("%d", &item);
        start = insertatbeg(start, item);
        printf("\n");
        display(start);
        break;
    case 4:
        printf("Enter data to be inserted: ");
        scanf("%d", &item);
        start = insertatend(start, item);
        printf("\n");
        display(start);
        break;
    case 5:
        start = delfirst(start);
        printf("\n");
        display(start);
        break;
    case 6:
        start = dellast(start);
        printf("\n");
        display(start);
        break;
    case 7:
        printf("Enter element after which want to delete: ");
        scanf("%d", &item);
        start = delafter(start, item);
        printf("\n");
        display(start);
        break;
    case 8:
        printf("enter element which want to delete: ");
        scanf("%d", &item);
        start = delat(start, item);
        printf("\n");
        display(start);
        break;
    case 9:
        display(start);
        break;
    case 10:
        reversedisplay(start);
        break;
    case 11:
        printf("Enter first value: ");
        scanf("%d", &item1);
        printf("Enter second element: ");
        scanf("%d", &item2);
        start = swap(start, item1, item2);
        printf("\n");
        display(start);
        break;
    case 12:
        start = reverse(start);
        printf("\n");
        display(start);
        break;
    case 13:
        start = sep_ev_od(start);
        printf("\n");
        display(start);
        break;
    case 14:
        start = bub_sort_exch_links(start);
        printf("\n");
        display(start);
        break;
    case 15:
        exit(0);
        break;
    default :
        printf("Wrong choice!!\n");
        break;
    }

    }//end of while
}
//random list generation start
struct node *genrandlist(struct node *start)
{
    int n, i;
    printf("Enter no of nodes: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        start = insertatend(start, rand()%50);
    }
    return start;
}//random list generation end

//count nodes start
int count_nodes(struct node *start)
{
    struct node *ptr;
    ptr=start;
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    return count;
}

struct node* insertatbeg(struct node *start, int item)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->info = item;
    temp->next = start;
    temp->prev = NULL;
    start->prev=temp;
    start = temp;
    return start;
}
struct node *insertatend(struct node *start, int item)
{
    struct node *temp, *ptr;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL)
    {
         printf("overflow");
         return start;
    }
    temp->info = item;
    if(start==NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        start = temp;
        return start;
    }
    ptr = start;
    while(ptr->next != NULL)
        ptr=ptr->next;
    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next = temp;
    return start;
}

struct node *delfirst(struct node *start)
{
    if(start == NULL)
    {
        printf("Underflow\n");
        return start;
    }
    struct node *ptr=start;
    start = start->next;
    free(ptr);
    return start;
}
struct node *dellast(struct node *start)
{
    if(start == NULL)
    {
        printf("Underflow\n");
        return start;
    }
    struct node *ptr=start, *temp;
   while(ptr->next != NULL)
    {
        ptr=ptr->next;
    }
    temp = ptr->prev->next;
    ptr=ptr->prev;
    ptr->next = NULL;
    free(temp);
    return start;
}

struct node *delafter(struct node *start,int item)
{
    if(start == NULL)
    {
        printf("Underflow\n");
        return start;
    }
    struct node *ptr=start, *temp;
    while(ptr->next != NULL)
    {
        if(ptr->info==item)
        {
            temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
            return start;
        }
        ptr=ptr->next;
    }
    if(ptr->info == item)
    {
        printf("No item ahead\n");
        return start;
    }
    printf("item does not exist\n");
    return start;
}

struct node *delat(struct node *start,int item)
{
    if(start == NULL)
    {
        printf("Underflow\n");
        return start;
    }
    struct node *ptr=start, *temp;
    if(start->info == item)
    {
        temp = start;
        start = temp->next;
        free(temp);
        return start;
    }
    while(ptr->next != NULL)
    {
        if(ptr->next->info==item)
        {
            temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
            return start;
        }
        ptr=ptr->next;
    }

    printf("item does not exist\n");
}

void display(struct node *start)
{
    if(start==NULL)
    {
        printf("Empty list\n");
        return;
    }
    struct node *ptr;
    ptr = start;
    while(ptr!=NULL)
    {
        printf("%d ", ptr->info);
        ptr=ptr->next;
    }
    printf("\n");
}

void reversedisplay(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    while(ptr!=start)
    {
        printf("%d ", ptr->info);
        ptr=ptr->prev;
    }
    printf("%d\n", ptr->info);
    return;
}

//swap start
struct node*swap(struct node *start, int item1, int item2)
{
    struct node *temp1,//points previous node of item1
    *temp2, //no need of it here to points previous node of item2
    *ptr1, *ptr2, //no need of it here to points to item1 and item2 resp
    *temp3;//temp pointer to change item node's link

    ptr2=start;  //searching item2
    while(ptr2->info!=item2)
    {
        ptr2=ptr2->next;
    }

    if(start->info==item1) //if found at begg
    {
        temp2->next=start;
        temp3=ptr2->next;
        ptr2->next=start->next;
        start->next=temp3;
        start=ptr2;

        return start;
    }

    ptr1=start; //finding item1
    temp1=start;
    while(ptr1->info!=item1)
    {
        temp1=ptr1;
        ptr1=ptr1->next;
    }

    ptr1->prev->next=ptr2; //changing previous node's link of items
    ptr2->prev->next=ptr1;

    temp3=ptr1->next;
    ptr1->next=ptr2->next;
    ptr2->next=temp3;

    return start;

}

//reverse start
struct node *reverse(struct node *start)
{
    struct node *prevnode, *currentnode;
    prevnode = start;
    currentnode=prevnode->next;
    prevnode->next=NULL;
    prevnode->prev=currentnode;
    while(currentnode!=NULL)
    {
        currentnode->prev=currentnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=currentnode->prev;
    }
    start = prevnode;
    printf("List reversed\n");
    return start;
}//reverse end

//separateEven odd start
struct node *sep_ev_od(struct node *start)
{
    struct node *ptr, *temp=start;
    ptr = start;
    int count=0, value;
    while(ptr!=0)
    {
        count++;
        ptr=ptr->next;
    }
    printf("%d ", count);
    ptr=start;
    while(count--)
    {
        printf("*");
        value = ptr->info;
        if(value%2 == 0)
        {
            start = delat(start, value);
            start = insertatend(start, value);
            ptr=temp->next;
            continue;
        }
        temp=ptr;
        ptr=ptr->next;
    }
    return start;
} //separateEvenOdd end

//bubble sort start
struct node *bub_sort_exch_links(struct node *start)
{
    struct node *ptr;
    int count, i, j;
    count = count_nodes(start);
    for(i=0; i<count-1; i++)
    {
        ptr=start;
        for(j=0; j<count-1-i; j++)
        {
            if(ptr->info>ptr->next->info)
            {
                start = swap(start, ptr->info, ptr->next->info);
                continue;
            }
            ptr=ptr->next;
        }
    }
    return start;
}



