#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
} *secstart=NULL;

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
void check_plaindrome(struct node *);
void nodefromend(int, struct node *);
struct node *pairwiseswap(struct node *);
struct node *createloop(struct node *, int);
void printreverse(struct node *);
struct node *removeduplicates(struct node *);
struct node*removeduplUnSort(struct node *);
struct node *deletealternate(struct node *);
struct node *splitalternate(struct node *);
struct node *reversegivensize(struct node *, int);

void display(struct node *);
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
    printf("10. swap any two nodes\n");
    printf("11. reverse the list\n");
    printf("12. separate even odd\n");
    printf("13. bubble sort by exchanging links\n");
    printf("14. check if palindrome\n");
    printf("15. nth node from end\n");
    printf("16. pairwise swap\n");
    printf("17. create loop\n");
    printf("18. print reverse\n");
    printf("19. remove adjacent duplicates\n");
    printf("20. remove unsorted duplicates\n");
    printf("21. delete alternate\n");
    printf("22. split alternate\n");
    printf("23. generate second linked list\n");
    printf("24. display second list\n");
    printf("25. reverse list in given sizes\n");
    printf("26. exit\n");
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
        printf("Enter first value: ");
        scanf("%d", &item1);
        printf("Enter second element: ");
        scanf("%d", &item2);
        start = swap(start, item1, item2);
        printf("\n");
        display(start);
        break;
    case 11:
        start = reverse(start);
        printf("\n");
        display(start);
        break;
    case 12:
        start = sep_ev_od(start);
        printf("\n");
        display(start);
        break;
    case 13:
        start = bub_sort_exch_links(start);
        printf("\n");
        display(start);
        break;
    case 14:
        check_plaindrome(start);
        break;
    case 15:
        printf("Enter nth position from end: ");
        scanf("%d", &item);
        nodefromend(item, start);
        break;
    case 16:
        start=pairwiseswap(start);
        printf("\n Done!! \n");
        break;
    case 17:
        printf("Enter position to create loop: ");
        scanf("%d", &item);
        start = createloop(start, item);
        printf("Done\n");
        break;
    case 18:
        printreverse(start);
        break;
    case 19:
        start=removeduplicates(start);
        break;
    case 20:
        start=removeduplUnSort(start);
        break;
    case 21:
        start = deletealternate(start);
        break;
    case 22:
        start = splitalternate(start);
        break;
    case 23:
        secstart = genrandlist(secstart);
        break;
    case 24:
        printf("\n");
        display(secstart);
        break;
    case 25:
        printf("Enter size: ");
        scanf("%d", &item);
        start=reversegivensize(start, item);
        printf("\n");
        display(start);
        break;
    case 26:
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
        ptr=ptr->link;
    }
    return count;
}

struct node* insertatbeg(struct node *start, int item)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->info = item;
    temp->link = start;
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
        temp->link = NULL;
        start = temp;
        return start;
    }
    ptr = start;
    while(ptr->link != NULL)
        ptr=ptr->link;
    temp->link = ptr->link;
    ptr->link = temp;
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
    start = ptr->link;
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
    if(ptr->link==NULL)
    {
        temp = ptr;
        start=NULL;
        free(temp);
        return start;
    }
   while(ptr->link->link != NULL)
    {
        ptr=ptr->link;
    }
    temp = ptr->link;
    ptr->link = NULL;
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
    while(ptr->link != NULL)
    {
        if(ptr->info==item)
        {
            temp = ptr->link;
            ptr->link = temp->link;
            free(temp);
            return start;
        }
        ptr=ptr->link;
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
        start = temp->link;
        free(temp);
        return start;
    }
    while(ptr->link != NULL)
    {
        if(ptr->link->info==item)
        {
            temp = ptr->link;
            ptr->link = temp->link;
            free(temp);
            return start;
        }
        ptr=ptr->link;
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
        ptr=ptr->link;
    }
    printf("\n");
}

//swap start
struct node*swap(struct node *start, int item1, int item2)
{
    struct node *temp1,//points previous node of item1
    *temp2, //points previous node of item2
    *ptr1, *ptr2, //points to item1 and item2 resp
    *temp3;//temp pointer to change item node's link

    ptr2=start;  //searching item2
    temp2=start;
    while(ptr2->info!=item2)
    {
        temp2=ptr2;
        ptr2=ptr2->link;
    }

    if(start->info==item1) //if found at begg
    {
        temp2->link=start;
        temp3=ptr2->link;
        ptr2->link=start->link;
        start->link=temp3;
        start=ptr2;

        return start;
    }

    ptr1=start; //finding item1
    temp1=start;
    while(ptr1->info!=item1)
    {
        temp1=ptr1;
        ptr1=ptr1->link;
    }

    temp1->link=ptr2; //changing previous node's link of items
    temp2->link=ptr1;

    temp3=ptr1->link;
    ptr1->link=ptr2->link;
    ptr2->link=temp3;

    return start;

}

//reverse start
struct node *reverse(struct node *start)
{
    struct node *prevnode, *nextnode, *currentnode;
    currentnode = start;
    prevnode = nextnode = NULL;
    while(currentnode!=NULL)
    {
        nextnode = currentnode->link;
        currentnode->link = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    start = prevnode;
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
        ptr=ptr->link;
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
            ptr=temp->link;
            continue;
        }
        temp=ptr;
        ptr=ptr->link;
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
            if(ptr->info>ptr->link->info)
            {
                start = swap(start, ptr->info, ptr->link->info);
                continue;
            }
            ptr=ptr->link;
        }
    }
    return start;
}

//palindrome start
void check_plaindrome(struct node *start)
{
    struct node *ptr;
    ptr=start;
    int len = count_nodes(start);
    int stack[100], top=-1;
    if(ptr==NULL)
    {
        printf("Empty list\n");
        return;
    }
    while(ptr!=NULL)
    {
        stack[++top]=ptr->info;
        ptr = ptr->link;
    }
    ptr=start;
    while(ptr!=NULL)
    {
        if(stack[top--]!=ptr->info)
        {
            printf("Not a palindrome\n");
            return;
        }
        ptr = ptr->link;
    }
    if(ptr==NULL)
    {
        printf("Palindrome\n");
        return;
    }
}

void nodefromend(int n, struct node *start)
{
    int count = count_nodes(start);
    struct node *ptr=start;
    n=count-n;

    if(n==0)
    {
        printf("*\n");
        printf("%d", ptr->info);
        return;
    }

    else if(n>0)
    {
        while(ptr!=NULL && n)
        {
            ptr=ptr->link;
            n--;
        }
        if(ptr!=NULL)
        printf("%d", ptr->info);
        return;
    }
    printf("Not exist!!\n");
    return;

}

struct node *pairwiseswap(struct node *start)
{
    struct node *ptr=start;
    int temp;
    while(ptr && ptr->link)
    {
        temp=ptr->info;
        ptr->info=ptr->link->info;
        ptr->link->info=temp;

        ptr=ptr->link->link;
    }

    return start;
}

struct node*createloop(struct node *start, int n)
{
    struct node *ptr=start, *temp=start;

    if(n==1)
    {
        printf("can't start loop at beg:)");
    }
    n=n-1; //To initialize as base 0
    while(ptr!=NULL && n)
    {
        ptr=ptr->link;
        n--;
    }
    if(ptr==NULL)
    {
        printf("Loop can't created\n");
        return start;
    }
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=ptr;
    return start;
};

void printreverse(struct node *ptr)
{
    if(ptr->link==NULL)
    {
        printf("%d", ptr->info);
        return;
    }
    printreverse(ptr->link);
    printf("%d ", ptr->info);
    return;
}

struct node *removeduplicates(struct node *start)
{
    struct node *_next, *current=start, *temp;
    if(current == NULL)
        return start;
    while(current->link!=NULL)
    {
        if(current->info==current->link->info)
        {
            _next=current->link->link;
            free(current->link);
            current->link=_next;
        }
        else
            current=current->link;
    }
    printf("\n");
    display(start);
    return start;
}

struct node *removeduplUnSort(struct node *start)
{
    struct node *current;
    struct node *iterativeInner, *temp;
    current = start;
    while(current->link != NULL)
    {
        iterativeInner = current;
        while(iterativeInner->link!=NULL)
        {
            if(current->info==iterativeInner->link->info)
            {
                temp=iterativeInner->link;
                iterativeInner->link=iterativeInner->link->link;
                free(temp);
            }
            else
                iterativeInner=iterativeInner->link;
        }
        current=current->link;
    }
    printf("\n");
    display(start);
    return start;
};

struct node*deletealternate(struct node *start)
{
    struct node *prev=start;
    if(prev==NULL)
    {
        return start;
    }
    struct node *next=start->link;
    while( prev!=NULL && next!=NULL)
    {
        prev->link=next->link;
        free(next);
        prev=prev->link;
        if(prev != NULL)
        {
            next = prev->link;
        }
    }
    return start;
};

struct node *splitalternate(struct node *start)
{
    int item;
    struct node *ptr, *tmpstart=NULL;
    ptr=start;
    if(ptr==NULL || ptr->link==NULL)
    {
        return start;
    }
    while(ptr->link!=NULL)
    {
        struct node *tmp;
        item=ptr->link->info;
        tmp=ptr->link;
        ptr->link=ptr->link->link;
        free(tmp);
        tmpstart=insertatend(tmpstart, item);
        if(ptr->link==NULL)
            break;
        ptr=ptr->link;
    }

    printf("original list: ");
    display(start);
    printf("split  list: ");
    display(tmpstart);
    return start;
};

struct node *reversegivensize(struct node *start, int k)
{
    struct node *current = start,
                *prev = NULL,
                *next = NULL;
    int count = 0;
    while(current!=NULL && count<k)
    {
        next = current->link;
        current->link=prev;
        prev=current;
        current=next;
        count++;
    }

    if(next!=NULL)
        start->link=reversegivensize(next, k);

    return prev;
};
