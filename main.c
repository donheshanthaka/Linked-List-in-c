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


// appending nodes to the end of the list
void append(struct node *head, int data){
    struct node *ptr, *newNode; // creates two pointers of type node
    ptr = head;
    newNode = (struct node*)malloc(sizeof(struct node)); // creates the new node and assigning it's memory location to newNode

    newNode ->data = data; // updating the data field of the new newNode node
    newNode ->link = NULL; // updating the link field

    while(ptr->link != NULL){ // traversing the list until the last node (the condition should be ptr->link, not just ptr)
        ptr = ptr->link; // keep updating the ptr
    }
    ptr->link = newNode; // update the last ptr with created node
};


void insert(struct node **head, int data, int position){
    struct node *ptr = *head; // the ptr pointer will point to the starting node of the list
    struct node *newNode = malloc(sizeof(struct node)); // the new node is created
    newNode->data = data;
    newNode->link = NULL;

    if(position == 1){ // if the position selected is at the beginning of the list(head)
        newNode->link = *head;  // the new node will be pointed to the current head from the main function, that is why "*" head is used for dereferencing
        *head = newNode;    // the head of the main function is now updated with the newly created node pointer's address

    }else{
        position--;
        while(position != 1){
            // ptr is updated by the next node's address in the list until the position becomes 1, which is one node behind the position we desire
            ptr = ptr->link;
            position--;
        }
        newNode->link = ptr->link; // the link of the new node is updated with link of the currently selected node
        ptr->link = newNode; // then the current node's link is updated to point the new node created, therefore the new node is added in between the two nodes
    }
};


// replace the value of the given element.
void replace(struct node *head, int element, int data){ //the head pointer is passed along with the element to be updated with new data
    struct node *temp = head; // temporary pointer is created that points to the head pointer
    int found = 0;
    // loop through the link until temp is moved passed the last node (link of the last node is pointing to NULL)
    // which means the step after the last node will make temp point to NULL, thats when the loop ends
    while(temp != NULL){
        if(temp->data == element){ // checking if the currently selected node's data is equal to the searched element
            temp->data = data; // the data is replaced with new data
            found = 1;
            printf("\nElement (%d) updated successfully with (%d)\n", element, data);
            break;
        }
        temp = temp->link; // temp pointer is updated to the next node
    }
    if(!found){
        printf("\nThe element (%d) was not found in the list\n", element);
    }
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

    // Appending the values to the end of the list
    append(head, 3);
    append(head, 67);

    // the head pointer is passed by value along with data and the position,
    //don't need to update the head since the new node is not being added at the beginning
    insert(&head, 4, 4);

    replace(head, 45, 50); // replace the old element with new data

    print_data(head); // print the entire list to the console

    return 0;
}
