#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    // Allocate memory for three nodes
    struct Node *head,*second,*third;
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

  
 if (head == NULL || second == NULL || third == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    // Initialize the first node
    head -> data = 1;
    head -> next = second;
    
    // Initialize the second node
    second -> data = 2;
    second ->next = third;
    
    // Initialize the third node
    third -> data = 3;
    third -> next =NULL;
    
    // Traverse and print the linked list
    struct Node *current = head;
    printf("Linked List: \n");
    while (current != NULL) {
        printf("%d -> ",(current->data));
        current = current-> next;
    }
    printf("\nNULL\n");
    
    // Free allocated memory
    free(head);
    free(second);
    free(third);
    
    return 0;
}
