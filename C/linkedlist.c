#include<stdio.h>
#include<stdlib.h>

struct Node{
    char city;
    struct Node *next;
};

struct Node* createNode(char* city)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->city,city);
    newNode -> next = NULL;
    return newNode;
}

void append(struct Node** head,char city)
{
    struct Node *newNode = createNode(city);

    if(*head==NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
    
}

void deleteNode()
{

}
int main()
{    

}