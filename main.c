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


int main()
{
    struct node *head = listInit(45);
    return 0;
}
