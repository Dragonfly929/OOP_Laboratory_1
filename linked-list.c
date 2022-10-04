#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* Head = NULL;
struct Node* CreateNewNode(int);

void Append(int);
void Prepend(int);
void insert_At_Position(int, int);
void Delete_node_at_position(int);
void Remove(int);

// function to traverse linked list and Print
// all element (Iterative method) */
void Traverse(void);

//  function to traverse linked list and Print
//  all element (Recursive method) */
void print_using_recursion(struct Node* temp);

/* function to Reverse a linked list(Iterative method)*/
void Reverse(void);

/* function to Reverse a linked list(Recursive method)*/
void Reverse_using_recursion(struct Node* p);

void search();

/* Function to bubble sort the given linked list */
void bubbleSort(struct Node *start);

/* Function to swap data of two nodes a and b*/
void swap(struct Node *a, struct Node *b);

void concatenate(struct Node *a, struct Node *b);

void join();

int main(int argc, char* argv[])
{
    int choice, len, position, element;

    do
    {
        printf("\n____________________________Main Menu____________________________\n");
        printf("\n              Choose any option from the list below.\n             ");
        printf("\n.................................................................\n");
        printf("1 : Append  : insert new node to the end of list                :\n");
        printf("2 : Prepend : insert new node to the beginning of list          :\n");
        printf("3 : Insert at position : insert new node to a specific position :\n");
        printf("4 : Delete node from a specific position                        :\n");
        printf("5 : Traverse : Print all the element in list (Iterative method) :\n");
        printf("6 : Traverse : Print all the element in list (Recursive method) :\n");

        printf("7 : Reverse  : Reverse linked list(Iterative method)            :\n");
        printf("8 : Reverse : Reverse linked list(Recursive method)             :\n");
        printf("9 : Search                                                      :\n");
        printf("10 : Sort                                                       :\n");
        printf("11 : Join                                                       :\n");
        printf("0 : Enter 0 to exit (quit)                                      :\n");
        // asking user to enter choice
        printf("\nEnter your choice:                                              :");
        scanf("%d",&choice);
        switch(choice)
        {
            // case 1 insert new node to the end of list
            case 1 :
                printf("Enter element to be inserted at the end  :");
                scanf("%d",&element);
                Append(element); // call Append function
            break;
            // case 2 insert new node to the the beginning of list
            case 2 :
                printf("Enter element to be inserted at the beginning  :");
                scanf("%d",&element);
                Prepend(element);
            break;
            // case 3 insert node at a specific position
            case 3 :
                printf("Enter element to be inserted :");
                scanf("%d",&element);
                printf("Enter the position :");
                scanf("%d",&position);
                insert_At_Position(element, position);
            break;
            // case 4 Delete node from specific position in list
            case 4 :
                printf("Enter the position to be deleted :");
                scanf("%d",&position);
                Delete_node_at_position(position);
            break;
            // case 5 traverse linked list and Print all element(Iterative method)
            case 5 :
                 Traverse();
            break;
            // case 6 traverse linked list and Print all element(Recursive method)
            case 6 :
                print_using_recursion(Head);
            break;
            // case 7 Reverse linked list(Iterative method)
            case 7 :
                Reverse();
            break;
            // case 8 Reverse linked list(Iterative method)
            case 8 :
                Reverse_using_recursion(Head);
            break;

            case 9 :
                search();
            break;

            case 10 :
                printf("\n Linked list after sorting : ");
                bubbleSort(Head);
            break;

            case 11 :
                join();
            break;

            case 0 :  /* case 0 Exit case */
                printf("time to exit thanks\n");
            _Exit(0);

            default : /* default case */
                 printf("Invalid input\n");
        }

    } while(1);

    return 0;

}

struct Node* CreateNewNode(int value)
{
    struct Node* newNode;

    // allocate memory dynamically for node using malloc C function
    newNode = (struct Node*) malloc(sizeof (struct Node));

    if(newNode == NULL) /* error handling */
      printf("error in allocating memory\n");

    /* adding information to node */
    newNode -> data = value;
    newNode -> next = NULL;
    newNode -> prev = NULL;

     return   newNode;  // return newly created node to place where it been be called

}

void Append(int value)
{
    struct Node *newNode, *temp;

    newNode = CreateNewNode(value);

    if (Head == NULL){
        // insert as the first node in list
        Prepend(value);
    } else {

         temp = Head;     // temp is now point to head node

         while(temp -> next != NULL){
             temp = temp -> next; // move temp to next node
         }
        newNode -> prev = temp;   // right side connection first
        temp -> next = newNode;   // left side connection second
        printf("%d : is been inserted at end of list\n",value);
    }

}

void Prepend(int value)
{
    struct Node *newNode;
    newNode = CreateNewNode(value);
    if(Head == NULL){
        Head = newNode;
        printf("%d : is been inserted as first node in list\n",value);
    }  else {

        newNode -> next = Head;
        Head -> prev = newNode;
        Head = newNode;

        printf("%d : is been inserted at the Beginning of list\n",value);
    }
}

void insert_At_Position(int value, int position)
{
    int i, len;       // local variable declaration
    struct Node *newNode, *temp; // local variables of type struct node declaration */
    i = 1;            // initialize counter i to one
    temp = Head;     // temp is now point to head node
    len = length();   // call length() to get length of list

    newNode = CreateNewNode(value);
    if((Head == NULL && position == 1) || (Head != NULL && position == 1)){
        Prepend(value);
    }
    else if(position > len || position < 1) // invalid position case
    {
        printf("invalid location!!!\n");
        return; // we are done
    } else {
        while(i < position - 1){
            temp = temp -> next; // move temp to next node
            i++; // increment counter i by one
        }
        newNode -> next = temp -> next;  // right side connection first
        temp -> next -> prev = newNode;     // right side connection first
        newNode -> prev = temp;          // left side connection second
        temp -> next = newNode;           // left side connection second
        printf("%d : is been inserted at %d position \n",value, position);
    }
}

void insert_After_Position(int value, int position)
{
    int i, len;                  // local variable declaration
    struct Node *newNode, *temp; // local variables of type struct node declaration */

    // create the node
    newNode = CreateNewNode(value); // call function to create new nod (now node is ready to add)
    temp = Head;     // temp is now point to head node
    len = length();   // call length() to get length of list
    i = 1;            // initialize counter i to one

    if(Head == NULL){
        printf("Doubly linked list is Empty!!!\n");
        return; // we are done
    }
    else if(position  > len || position < 1){
        printf("invalid location!!!\n");
        return; // we are done
    } else if(position == len){
        // insert at the end of list
        Append(value); // call Append  function for help
        return;
    }

    while(i < position){
        temp = temp -> next;   // move temp to next node
        i++;                   // increment counter i by one
    }

    newNode -> next = temp -> next;  // right side connection first
    temp -> next -> prev = newNode;   // right side connection first
    newNode -> prev = temp;          //  left side connection second
    temp -> next = newNode;           // left side connection second
    printf("%d : is been inserted at %d position \n",value, position + 1); // inform user the element is been inserted

}

void insert_Before_Position(int value, int position)
{
    int i, len;                  // local variable declaration
    struct Node *newNode, *temp; // local variables of type struct node declaration */

    // create the node
    newNode = CreateNewNode(value); // call function to create new nod (now node is ready to add)
    temp = Head;     // temp is now point to head node
    len = length();   // call length() to get length of list
    i = 1;            // initialize counter i to one

    if(Head == NULL) /* linked is empty Case */
    {
        printf("Doubly linked list is Empty!!!\n");
        return; // we are done
    } else if(position > len || position < 2){
        printf("invalid location!!!\n");
        return; // we are done
    } else if(position == 2){
        // insert at beginning in list in first position
        Prepend(value);  // call Insert_At_Begining
        return; // we are done
    }
    while(i < position - 2)
    {
        temp = temp -> next;   // move temp to next node
        i++;                   // increment counter i by one
    }

    /** link changes */

    newNode -> next = temp -> next;  // right side connection first
    temp -> next -> prev = newNode;   // right side connection first
    newNode -> prev = temp;          //  left side connection second
    temp -> next = newNode;           // left side connection second
    printf("%d : is been inserted at %d position \n",value, position - 1); // inform user the element is been inserted
}

void Delete_from_Beginning()
{
    struct Node* temp;  // local variable of type struct node declaration */
    temp = Head;       // temp is now point to head node

    if(Head == NULL) /* linked is empty Case */
    {
        printf("Doubly linked list is Empty!!!\n");
        return; // we are done
    } else if(temp -> next == NULL && temp -> prev == NULL){
        printf("node --> %d is Will be Deleted\n",temp -> data); // inform user the job is about to done
        Head = NULL; // assign head to NULL
        free(temp);  // now Delete temp using free() C function
    } else {
        printf("node --> %d is Will be Deleted\n",temp -> data); // inform user the job is about to done
        Head = Head -> next;  // right side connection first
        Head -> prev = NULL;  // left side connection second
        temp -> next = NULL;  // assign temp -> next to NULL(this not have to)
        free(temp);          // now Delete temp using free() C function
    }
}

void Delete_from_End()
{
    struct Node *temp; // local variables of type struct node declaration */
    temp  = Head;      // temp is now point to head node

    if (Head == NULL) /*linked is empty Case*/
    {
        printf("Doubly linked list is Empty!!!\n");
        return; // we are done
    } else if(temp -> next == NULL && temp -> prev == NULL)
        Delete_from_Beginning(); // call Delete_from_Beginning() for help
        else {
                while(temp -> next != NULL){
            temp = temp -> next;    // move temp to next node
        }
        printf("node --> %d is Will be Deleted\n",temp -> data);
        temp -> prev -> next =  NULL;  // right side connection first
        temp -> prev = NULL;  // assign temp -> prev to NULL(this not have to)
        free(temp);           // now Delete temp using free() C function
    }
}

void Delete_node_at_position(int position)
{
    int i, len;          // local variable declaration
    struct Node *temp;   // local variables of type struct node declaration */
    temp  = Head;      // temp is now point to head node
    len = length();    // call length() to get length of list
    i = 1;            // initialize counter i to one

    if (Head == NULL){
        printf("Doubly linked list is Empty!!!\n");
        return; // we are done
    }
    else if(position > len || position < 1){
        printf("invalid position!!!\n");
        return; // we are done
    } else if(position == 1) {
        Delete_from_Beginning(); // call Delete_from_Beginning() function for help
        return; // we are done
    } else if (position == len){
        Delete_from_End();
        return;
        }
    while(i < position){
        temp = temp -> next;   // move temp to next node
        i++;                   // increment counter i by one
    }
    printf("node --> %d is Will be Deleted\n",temp -> data);
    temp -> prev -> next = temp -> next;  // right side connection first
    temp -> next -> prev = temp -> prev;  // left side connection first
    temp -> next = NULL;  // assign temp -> next to NULL(this not have to)
    temp -> prev = NULL;  // assign temp -> prev to NULL(this not have to)
    free(temp);          // now Delete temp using free() C function

}

void Reverse()
{
    struct  Node *current, *Previous, *nextNode;

    Previous = NULL;  // for Previous node(only to keep address of last node)
    current = Head;   // for current node
    nextNode = NULL;  // for next node

    if(Head == NULL) /* linked is empty Case */
    {
        printf("Doubly linked list is Empty!!!\n");
        return; // we are done
    }
    while(current != NULL)
    {
        nextNode = current -> next;    // move nextNode point to next node
        current -> next = current -> prev; //swap between current -> next and current -> prev
        current -> prev = nextNode;        ////swap between current -> next and current -> prev
        Previous = current;      // I use Previous only to get address of last node and assgin to head pointer
        current = nextNode;   // move current to next until you reach null which is end of list
    }

    Head = Previous;  // Reverse (head pointer) to point to last node

    printf("Doubly linked list is been Reversed\n");

}

void Reverse_using_recursion(struct Node* curentNode)
{
    if (Head == NULL)  /* linked is empty Case*/
    {
        printf("Doubly linked list is Empty!!!\n");
        return; // we are done
    }

    struct  Node *nextNode;
    nextNode = curentNode -> next;

    curentNode -> next = curentNode -> prev;
    curentNode -> prev = nextNode;

    if (curentNode -> prev == NULL){
        printf("Doubly linked list is have only one Node\n");
        return;
    } else if(nextNode -> next == NULL){
        nextNode -> next = nextNode -> prev; // swap between lastNode -> next and lastNode -> prev
        nextNode ->prev = NULL;              // swap between lastNode -> next and lastNode -> prev
        Head = nextNode;                     // Reverse (head pointer) to point to last node
        printf("Doubly linked list is been Reversed\n"); // inform user the work is done
        return;  // we are done
    }
    // else cases
    Reverse_using_recursion(curentNode -> prev); //Recursive call to move to next node  first


}

int length()
{
    int count = 0;     // local counter variable declaration and initializations to zero
    struct Node* temp; // local variable of type struct node declaration */
    temp = Head;      // temp is now point to head node

    /* while not yet reach NULL count the number of nodes in list */
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}

void Traverse()
{
    struct Node* temp; // local variable of type struct node declaration */
    temp = Head;      // temp is now point to head node

    if(Head == NULL){
        printf("Doubly linked list is Empty!!!\n");
        return; // we are done
    }
     while(temp != NULL){
         printf("%d --> ", temp -> data);  // print the value
         temp = temp -> next;              // move temp to next node
     }
     printf("\n");
}

void print_using_recursion(struct Node* temp)
{
    if(temp == NULL){
        printf("\n");
         return;
    }

    // else cases
    printf("%d --> ", temp -> data);
    print_using_recursion(temp -> next);
}

void search()
{
    struct Node *ptr;
    int item,i=0,flag;
    ptr = Head;
    if(ptr == NULL){
        printf("\nEmpty List!!\n");
    } else {
        printf("\nEnter element to search:\n");
        scanf("%d",&item);
        while (ptr!=NULL){
            if(ptr->data == item){
                printf("\nElement found at location %d ",i+1);
                flag=0;
                break;
            } else {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        if(flag==1){
            printf("\nElement not found.\n");
        }
    }
}

// /* Bubble sort the given linked list */
void bubbleSort(struct Node *Head)
{
    int swapped, i;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    /* Checking for empty list */
    if (Head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = Head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

/* function to swap data of two nodes a and b*/
void swap(struct Node *a, struct Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void concatenate(struct Node *a,struct Node *b)
{
    if( a != NULL && b!= NULL ){
        if (a->next == NULL)
            a->next = b;
        else
            concatenate(a->next,b);
    } else {
        printf("Either a or b is NULL\n");
    }
}

void join()
{
    struct Node *prev,*a, *b, *p;
    int n,i;
    printf ("number of elements in a:");
    scanf("%d",&n);
    a=NULL;
    for(i=0;i<n;i++)
    {
        p=malloc(sizeof(struct Node));
        scanf("%d",&p->data);
        p->next=NULL;
        if(a==NULL)
            a=p;
        else
            prev->next=p;
        prev=p;
    }
    printf ("number of elements in b:");
    scanf("%d",&n);
    b=NULL;
    for(i=0;i<n;i++)
    {
        p=malloc(sizeof(struct Node));
        scanf("%d",&p->data);
        p->next=NULL;
        if(b==NULL)
            b=p;
        else
            prev->next=p;
        prev=p;
    }
    concatenate(a,b);
    print_using_recursion(a);
    return 0;
}
