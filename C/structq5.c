#include <stdio.h>
#include <stdlib.h>

// Define the node structure 
// for the doubly linked list
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to insert a new node at the beginning of the doubly linked list
void push(struct Node **head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    
    // Since the new node will be the head, its previous pointer is NULL
    new_node->prev = NULL;
    
    // The new node's next pointer is the current head
    new_node->next = (*head_ref);
    
    // Change the previous pointer of the current head node, if it exists
    if ((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }
    
    // Move the head to point to the new node
    *head_ref = new_node;
}

// Function to print the doubly linked list in forward and backward direction
void printList(struct Node *node) {
    struct Node *last;
    
    printf("Forward Traversal:\n");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
        
    }
    printf("\n");
    
    printf("Backward Traversal:\n");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

int main() {
    // Initialize the head of the list as NULL
    struct Node *head = NULL;
    
    // Add nodes to the list
    push(&head,40);
    push(&head,30);
    push(&head,20);
    push(&head,10);
    
    // Print the list in both forward and backward directions
    printList(head);
    
    // Free allocated memory
    struct Node *current = head;
    while (current != NULL) {
        struct Node *next = current->next;
        free(current);
        current = next;
    }
    
    return 0;
}
