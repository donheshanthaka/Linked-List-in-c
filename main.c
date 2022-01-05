#include <stdio.h>
#include <stdlib.h>

/*
Created by:  donheshanthaka
Git Hub link: https://github.com/donheshanthaka
*/

struct node{
    int data;
    struct node *link;
};


// Initialize the list by creating the first node
struct node *listInit(int data){
    //creates a new node by returning a pointer of type node from space allocated in the heap and assign it to pointer head
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head -> data = data; // the data field of the node is updated
    head -> link = NULL;
    return head;
};


/*
// adding nodes at the beginning of the list
// the function receives two arguments, pointer to a pointer with "**" head,
// that means the a head pointer that points to the already available head pointer in the main function and the data as data
*/
void add(struct node **head, int data){
    struct node *newNode = malloc(sizeof(struct node)); // a new node being created and assigned to the newNode pointer
    newNode->data = data;  // updating the value
    newNode->link = NULL;
    newNode->link = *head;  // the new node will be pointed to the current head from the main function, that is why "*" head is used for dereferencing
    *head = newNode;    // the head of the main function is now updated with the newly created node pointer's address
};

// Display the entire list on to the console
void print_data(struct node *head){
    printf("\n");
    if (head == NULL){
        printf("\nLinked list is empty\n");
    }
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
};

int main()
{
    struct node *head = listInit(45);

    // the head will be sent as a reference, so the function will be able to update the head pointer itself inside the function
    add(&head, 111);
    add(&head, 0);

    print_data(head); // print the entire list to the console

    return 0;
}
