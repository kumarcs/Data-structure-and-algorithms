#include<stdio.h>
#include<stdlib.h>

struct node
{
    float coef;
    int expo;
    struct node *link;
};
typedef struct node node;
node *create(node *);
node *insert(node *, float coef, int expo);
void display(node *);
void addition(node *, node*);
void multiplication(node *, node *);
node *mult_insert(node *start, float coef, int expo);
int main()
{
    node *poly1, *poly2;
    poly1=NULL; poly2=NULL;
    int terms, expo, coef;
    int choice;
    while(1){
    printf("\n1. create a polynomial 1 \n");
    printf("2. create a polynomial 2 \n");
    printf("3. display a polynomial\n");
    printf("4. add polynomials\n");
    printf("5. multiply polynomials\n");
    printf("6. Exit\n");
    printf("Enter your choice\n");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        poly1=create(poly1);
        display(poly1);
        break;
    case 2:
        poly2=create(poly2);
        display(poly2);
        break;
    case 3:
        printf("polynomial 1: "); display(poly1);
        printf("polynomial 2: "); display(poly2);
        break;
    case 4:
        addition(poly1, poly2);
        break;
    case 5:
        multiplication(poly1, poly2);
        break;
    case 6:
        return 0;
    default:
        printf("Wrong choice\n");
        break;
    }}

}

struct node *create(struct node *start)
{
    int ex, i, n;
    float co;
    printf("enter number of terms : ");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        printf("Enter coefficient for term %d : ", i);
        scanf("%f", &co);
        printf("Enter the exponent for term %d : ", i);
        scanf("%d", &ex);
        start = insert(start, co, ex);
    }
    return start;
}

node *insert(node *start, float coef, int expo)
{
    node *temp, *ptr;
    temp=(node *)malloc(sizeof(node));
    temp->coef=coef;
    temp->expo=expo;
    if(start==NULL || start->expo<expo)
    {
        temp->link=start;
        start=temp;
    }
    else{
        ptr=start;
        while(ptr->link!=NULL && ptr->link->expo >= expo)
        {
            ptr=ptr->link;
        }
        temp->link=ptr->link;
        ptr->link=temp;
        }
        return start;

}

node *mult_insert(node *start, float coef, int expo)
{
    node *temp, *ptr;
    temp = (node *)malloc(sizeof(node));
    if(start == NULL)
    {
        temp->coef=coef;
        temp->expo=expo;
        temp->link=NULL;
        start=temp;
        return start;
    }
    ptr=start;
    while(ptr->link != NULL && ptr->link->expo >= expo)
    {
        if(ptr->link->expo == expo)
        {
            ptr->link->coef=ptr->link->coef+coef;
            return start;
        }
        ptr=ptr->link;
    }
    temp->link=ptr->link;
    temp->coef=coef;
    temp->expo=expo;
    ptr->link=temp;
    return start;
}


void display(node *start)
{
    node *ptr;
    ptr=start;
    if(start==NULL)
    {
        printf("Zero polynomial\n");
        return;
    }
    while(ptr!=NULL)
    {
        printf("(%.2fx^%d)",ptr->coef, ptr->expo);
        ptr=ptr->link;
        if(ptr!=NULL)
            printf(" + ");
        else
            printf("\n");
    }
}

void addition(node *poly1, node *poly2)
{
    node *poly3;
    poly3 = NULL;
    while(poly1!=NULL && poly2!=NULL)
    {
        if(poly1->expo > poly2->expo)
        {
            poly3=insert(poly3,poly1->coef ,poly1->expo);
            poly1=poly1->link;
        }
        else if(poly1->expo < poly2->expo)
        {
            poly3=insert(poly3,poly2->coef ,poly2->expo);
            poly2=poly2->link;
        }
        else if(poly1->expo == poly2->expo)
        {
            poly3=insert(poly3, (poly1->coef)+(poly2->coef) ,poly1->expo);
            poly1=poly1->link;
            poly2=poly2->link;
        }
    }
    while(poly1!=NULL)
    {
        poly3=insert(poly3, poly1->coef, poly1->expo);
        poly1=poly1->link;
    }
    while(poly2!=NULL)
    {
        poly3=insert(poly3, poly2->coef, poly2->expo);
        poly2=poly2->link;
    }
    printf("Added polynomial is: ");
    display(poly3);
}
void multiplication(node *poly1, node *poly2)
{
    node *temp3, *poly2_beg;
    temp3=NULL;
    poly2_beg=poly2;
    if(poly1==0 || poly2==0)
    {
        printf("Multiplied polynomial is zero\n");
        return;
    }
    while(poly1!=NULL)
    {
        poly2=poly2_beg;
        while(poly2!=NULL)
        {
            temp3=mult_insert(temp3, poly1->coef*poly2->coef, poly1->expo+poly2->expo);
            poly2=poly2->link;
        }
        poly1=poly1->link;
    }
    printf("multiplied polynomial is : ");
    display(temp3);
}
