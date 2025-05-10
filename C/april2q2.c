#include<stdio.h>
#include<stdlib.h>

typedef struct list{
    int data;
    struct list *next;
    struct list *prev;
}list;

list *create(int data)
{
    list *newNode = (list*)calloc(1,sizeof(list));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;

}

void insert(list **head,int data)
{
    list *Node = create(data);
    if(*head==NULL)
    {
        *head=Node;
        return;
    }

    list *current = *head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = Node;
    Node->prev = current;
    Node->next = NULL;
    return;


}

list* merge(list *l1,list*l2)
{
    if(!l1) return l2;
    if(!l2) return l1;

    list *merged=NULL;

    if(l1->data > l2->data)
    {
        merged = l2;
    }
    else{
        merged = l1;
    }

    list *current = merged;
    while(current->next != NULL)
    {
        current = current->next;
    }
    while(l1 && l2)
    {
        if(l1->data > l2->data)
        {
            current->next = l2;
            l2->prev = current;
            l2 = l2->next;
        }
        else
        {
            current->next = l1;
            l1->prev = current;
            l2=l2->next;
        }
        current = current->next;
    }

    if(l2) 
    {
        current->next=l2;
        l2->prev = current;
    }
    if(l1)
    {
        current -> next = l1;
        l1->prev = current;
    }
    while(current->prev!=NULL)
    {
        current = current->prev;
    }

    merged = current;

    return ;

}

void print(list *l)
{
    while(l!=NULL)
    {
        printf("%d ",l->data);
        l = l->next;
    }
}

int main()
{
    list *l1=NULL,*l2=NULL;
    int data;

    while(scanf("%d",&data) && data!=-1)
    {
        insert(&l1,data);
    }
    while(scanf("%d",&data) && data!=-1)
    {   
        insert(&l2,data);
    }

    print(l1);
    print(l2);

    list *l3 = merge(l1,l2);
    print(l3);

    free(l1);
    free(l2);
    free(l3);

    return 0;

}