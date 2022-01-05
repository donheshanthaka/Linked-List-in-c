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


// Remove the first element of the list
void removeFirst(struct node **head){ // the head is passed as a pointer to the pointer head
    if (*head == NULL){
        printf("\nList is already empty!\n");
    }else{
        struct node *temp = *head; // temporary pointer node is created and the pointer head is assigned to that
        *head = temp->link; // the head pointer will be pointed to the next node in the list
        free(temp); // the temp pointer that is pointing the old head node will be freed
        temp = NULL; // it is best practice to make the freed pointers null
    }
};


// the function will delete the last node of the list
void removeLast(struct node *head){
    if(head == NULL){
        printf("\nList is already empty!\n");
    }
    else if(head->link == NULL){ // if there is only one node in the link which is the head node, it will be turned to null
        free(head);
        head = NULL;
    }
    else{
        struct node *temp = head; // temporary pointer node is created and the pointer head is assigned to that
        struct node *temp2 = head; // another temporary pointer node is created and the pointer head is assigned to that

        // The list will loop until temp is at the last node by checking if the link of the current node is null,
        //when it is null that means we are at the last node of the link
        while(temp->link != NULL){
            // temp2 will always stay one step behind of temp cause temp is assigned to temp2 before going into the next node,
            // therefore when temp is at the last node temp2 will be one node before the last node
            temp2 = temp;
            temp = temp->link; // temp pointer will be pointed to the next node in the list
        }
        // when we are at the end of the list, the temp2 pointer which is pointing to the last node of the link will be set to null,
        // that means there no more nodes after temp2
        temp2->link = NULL;
        free(temp); // temp will be freed
        temp = NULL; // and then set to null
    }
};


// Remove the first occurrence of the given element
void removeElement(struct node **head, int element){ //the head is passed as a pointer to the pointer head along with the element to be remove
    struct node *current = *head; // current pointer is created that points to the head pointer
    struct node *previous = *head; // previous pointer is created that points to the head pointer
    struct node *ptr = *head;
    int found = 0;
    while(current != NULL){ // loop through all the elements
        if(current->data == element){ // if the data of the selected node is equal to the given element
            if(current->data == ptr->data){ // if the element found is the head node, it has to be removed in a different way compared to the rest
                struct node *temp = *head; // temporary pointer node is created and the pointer head is assigned to that
                *head = temp->link; // the head pointer will be pointed to the next node in the list
                free(temp); // the temp pointer that is pointing the old head node will be freed
                temp = NULL; // it is best practice to make the freed pointers null
                found = 1;
                printf("\nElement (%d) removed successfully\n", element);
                break;
            }
            //if the selected node is not the head node
            // the next pointer link of the node which is behind the node that we want to delete(previous)
            // will be set to the node in front of the node that we want to delete,
            // which means the node that we want to delete will not be pointed to by any other nodes
            previous->link = current->link;
            free(current); // the current node that we want to delete will be freed
            current = NULL; // then set to null
            printf("\nElement (%d) removed successfully\n", element);
            found = 1;
            break;
        }
        // the previous node will always stay one step behind the current node
        previous = current;
        current = current->link;
    }
    if(!found){
        printf("\nThe element (%d) was not found in the list\n", element);
    }
};


// removeAt function will delete the element at the given position
// the head is passed as a pointer to the pointer head, that is why in order to access the value inside head pointer two ** are used
void removeAt(struct node **head, int position){
    struct node *current = *head;
    struct node *previous = *head;
    int indexStatus = 0; // to check if the list index will go out of range

    if(*head == NULL){
        printf("List is already empty!");
    }
    else if(position == 1){ // if the given position is one(which means head), the head pointer will be pointed to the next node in the link
        *head = current->link; // the head pointer is pointed to the next node in the link
        free(current); // the current pointer will be freed
        current = NULL; // and then set to null
    }
    else{
        while(position != 1){ // the loop will run until the position is equal to 1
            previous = current; // the previous will be set equal to the current pointer
            current = current->link; // and the current pointer will be pointed to the next node in the list
            position--;
            // current->link == NULL means we are already at the last node and the position variable haven't still reached to 1,
            // which means the user entered a value that is higher than the size of the list
            if (current->link == NULL){
                printf("\nError: List index out of range\n");
                indexStatus = 1;
                break;
            }
        }
        if(!indexStatus){ // if the index status did not get turned to one means that the loop ended at the correct position
            // the next pointer link of the node which is behind the node that we want to delete(previous)
            // will be set to the node in front of the node that we want to delete,
            // which means the node that we want to delete will not be pointed to by any other nodes
            previous->link = current->link;
            free(current); // the current node that we want to delete will be freed
            current = NULL; // then set to null
        }
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

    removeFirst(&head); // the head pointer is passed by reference, the head node will be removed

    removeLast(head); // the head pointer is passed by value, don't need to update the head since no changes are made to the head pointer

    removeElement(&head, 555); // remove the first occurrence of the given element

    removeAt(&head, 10); // the head pointer will be sent as a reference, so the function will be able to update the head pointer itself inside the function

    print_data(head); // print the entire list to the console

    return 0;
}
