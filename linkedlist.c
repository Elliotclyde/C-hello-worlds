#include <stdio.h>
#include <stdlib.h>

// defining a brand new type called "node"
struct node {
    // this is the actual payload data which is an integer
   int data;
   // this is how it points to the next node
   // the type it points to is "struct node"
   // We know it's a pointer because of the star
   // the name of the var is "next" 
   struct node *next;
};

// declaring an empty pointer variable which is the head (the most recently set of the linked list)
// This is a global variable which insert will mutate as the list gets filled up 
// Then printlist will use to loop through the list
struct node *head = NULL;

// declaring an empty pointer variable which is the current (we're going to change this when we loop through)
struct node *current = NULL;

//insert link at the first location
void insert(int data) {
   //create a link
   // What are we doing on the right side of this equals sign?
   // We end up with a pointer to our a type of node struct 
   // we get this from the malloc function, which takes a number of bytes
   // we get the right amount of bytes by using the "sizeof" function and putting in our type
   // then this gives us back the pointer (which is actually a number pointing to a memory address) 
   // we're calling the pointer to this memory address link 
   // so really what we're doing here is VERY manually creating the new variable in memory
   struct node *link = (struct node*) malloc(sizeof(struct node));

   // When you have a pointer you use the arrow syntax to get/set the property
   link->data = data;

   // point it to old first node using the arrow syntax
   // This will be a pointer to the old first node
   // If it is the first item declared, this will be null
   link->next = head;

   // Now we're finished initialising both of our properties, 
   // we're ready to make our new structure the head of our list
   // Note  these are both pointers. So we're not copying anything
   // We're just changing a single number to make it point to another place in memory
   head = link;
}

//display the list

void printList() {
    // creating a variable called ptr which is a pointer
    // and assigining the global variable head to it.
    // we're going to mutate this variable to loop through the list
   struct node *ptr = head;

   printf("\n[head] =>");
   //start from the beginning
   while(ptr != NULL) {        
      printf(" %d =>",ptr->data);
      ptr = ptr->next;
   }

   printf(" [null]\n");
}

int main() {
   insert(10);
   insert(20);
   insert(30);
   insert(1);
   insert(40);
   insert(56); 

   printList();
   return 0;
}