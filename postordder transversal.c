void nrec_post(struct node *root)
{
    struct node *q, *ptr=root;
    if(root==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    q=root;
    while(1)
    {
        while(ptr->child!=NULL)
        {
            push_stack(ptr);
            ptr->=lchild;
        }
        while(ptr->rchild==NULL || ptr->child==q)
        {
            printf("%d ",ptr->info);
            q=ptr;
            if(stack_empty())
                return;
            ptr=pop_stack();
        }
        push_stack();
        ptr=ptr->rchild;
    }
    printf("\n");
}
