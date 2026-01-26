/*
PROJECT TODO (Next Steps):

1. Split linked list into header (.h) and source (.c) files
   - Move struct definitions and function prototypes to linked_list.h
   - Move implementations to linked_list.c
   - Keep main() as a client only

2. Make ll_has_cycle() usable
   - Print meaningful output in main() based on return value
   - Optionally add a debug function to intentionally create a loop for testing

3. Add return-value handling in main()
   - Check success/failure for insert/delete operations
   - Print user-friendly messages

4. Add cleanup function
   - Implement ll_clear() to free all nodes before exit

5. Improve README
   - Explain API design
   - Document time complexity of operations
   - Explain design decisions (no globals, size invariant)
*/



/*
PROJECT DONE:
1. Track list size inside LinkedList (no external counters)
2. Remove duplicate node creation logic
3. Refactor to avoid global list head
4. Implement delete-by-value and delete-by-position
5. Improve loop_detection safety checks (Floyd algorithm)
*/




#include <stdio.h>
#include <stdlib.h>


//global struct node
struct node
{
    int data;
    struct node *next;
};


//global struct linked list
struct LinkedList
{
    struct node *head;
    int size;
};



//function prototypes

int ll_push_back(struct LinkedList *list, int val);
int ll_push_front(struct LinkedList *list, int val);
int ll_insert_at(struct LinkedList *list, int val, int pos);
void ll_reverse(struct LinkedList *list);
int ll_has_cycle(struct LinkedList *list);
void ll_print(struct LinkedList *list);
int ll_delete_value(struct LinkedList *list, int val);
int ll_delete_at(struct LinkedList *list, int pos);


int main() 
{
    //local list of type struct LinkedList
    struct LinkedList list = {NULL, 0};


    int choice,val,no_of_nodes,position;
    
    while (1)
    {
        printf("\n1. insert elements");
        printf("\n2. insert node at start");
        printf("\n3. insert node at pos");
        printf("\n4. reverse list");
        printf("\n5. loop detection");
        printf("\n6. display list");
        printf("\n7. delete node");
        printf("\n8. delete at position");
        printf("\n9. quit");
        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1)//removing infi loop problem of scanf for wrong data type
        {
            printf("Invalid input. Enter a number.\n");

            // clear input buffer
            while (getchar() != '\n');
                continue;
        }

        switch (choice)
        {
        case 1:
            printf("\nenter the no of elements to insert: ");
            scanf("%d",&no_of_nodes);
            for (int i = 0; i < no_of_nodes; i++)
            {
                printf("\nenter the value: ");
                scanf("%d",&val);
                ll_push_back(&list,val);
            }
            
            break;
        case 2:
            printf("\nenter the  element to insert at start: ");
            scanf("%d",&val);
            ll_push_front(&list,val);
            break;

        case 3:
            printf("\nenter the position: ");
            scanf("%d",&position);
            printf("\nenter the element: ");
            scanf("%d",&val);
            ll_insert_at(&list,val,position);
            break;
        
        case 4:
            printf("\n");
            ll_print(&list);
            printf("\n reversing list.........");
            ll_reverse(&list);
            ll_print(&list);
            break;
        
        case 5:
            printf("\n Analyzing.........");
            ll_has_cycle(&list);
            break;

        case 6:
            printf("\n list: ");
            ll_print(&list);
            break;

        case 7:
            printf("\nenter the value to delete: ");
            scanf("%d",&val);
            ll_delete_value(&list,val);
            break;

        case 8:
            printf("\nenter the position to delete: ");
            scanf("%d",&position);
            ll_delete_at(&list,position);
            break;

        case 9:
            printf("\nexec ended!");
            exit(0);
            break;


        default:
            break;
        }
    }
        
    return 0;
}


int ll_push_back(struct LinkedList *list, int val)
{
    struct node *tmp, *q;
    tmp = (struct node *)malloc(sizeof(struct node));

    // if malloc is not able to provide memory
    if(tmp == NULL)
        return -1;

    (*tmp).data = val;
    tmp->next = NULL;
    

    //case1: list is empty
    if(list->head == NULL)
    {
        list->head = tmp;
        list->size++;
        return 0;
    }

    //case2: list is not empty
    else
    {
        q = list->head;
        while (q->next != NULL)
        {
            q=q->next;
        }
        q->next = tmp;
        list->size++;
        return 0;
    }
    
}

int ll_push_front(struct LinkedList *list, int val)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(tmp == NULL)
        return -1;
    tmp->data = val;
    tmp->next = list->head;
    list->head = tmp;
    list->size++;
    return 0;
}


int ll_insert_at(struct LinkedList *list, int val,int pos)
{
    if (pos > (list->size)+1 || pos <= 0)
    {
        //printf("\nplease give appropiate size: ");
        return -1;
    }

    //case1: at front
    if (pos == 1)
    {
        ll_push_front(list, val);
        return 0;
    }
    
    //case2: at pos other than front
    struct node *tmp, *q;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(tmp == NULL)
        return -1;
    q=list->head;
    for (int i = 0; i < pos-2; i++)
    {
        q=q->next;
    }
    tmp->next = q->next;
    tmp->data = val;
    q->next = tmp;  
    list->size++;
    return 0; 
}

void ll_reverse(struct LinkedList *list)
{
    if(list->head == NULL)//checking if list is empty
        return;
    struct node  *curr, *prev, *nex;
    prev = NULL; //storing previous address
    curr = list->head; // having current adress
    while (curr->next != NULL)
    {
        nex = curr->next; //nex has adress of next node
        curr->next = prev; //updating current link to previous one 
        prev = curr; //updating previous as current one
        curr = nex; //since current link has been changed so going to a next link using nex
    }
    //at last updating head
    curr->next = prev;
    list->head = curr;
         
}

/// @brief checking if loop is present in list (using floyd algo)
int ll_has_cycle(struct LinkedList *list)
{ 
    if(list->head == NULL)
        return 0;
    struct node *slow, *fast;
    slow = list->head;
    fast = list->head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            //printf("cycle exists");
            return -1;
        }
    }
    //printf("no cycle exits");
    return 0;
}

void ll_print(struct LinkedList *list)
{
    struct node *q;
    q=list->head;
    printf("\n");
    while (q != NULL)
    {
        printf("%d ",q->data);
        q=q->next;
    }    
}

int ll_delete_value(struct LinkedList *list, int val)
{
    if (list->head == NULL)
        return -1;

    struct node *q = list->head;
    struct node *tmp;

    // Case 1: delete head
    if (q->data == val)
    {
        list->head = q->next;
        free(q);
        list->size--;
        return 0;
    }

    // Find node BEFORE the one to delete
    while (q->next != NULL && q->next->data != val)
    {
        q = q->next;
    }

    // Value not found
    if (q->next == NULL)
        return -1;

    // Delete the node
    tmp = q->next;
    q->next = tmp->next;
    free(tmp);
    list->size--;

    return 0;
}

int ll_delete_at(struct LinkedList *list, int pos)
{
    if (list == NULL || list->head == NULL)
        return -1;

    if (pos <= 0 || pos > list->size)
        return -1;

    struct node *tmp;

    // Case 1: delete head
    if (pos == 1)
    {
        tmp = list->head;
        list->head = tmp->next;
        free(tmp);
        list->size--;
        return 0;
    }

    struct node *q = list->head;

    // move to node just before the one to delete
    for(int i = 1; i < pos - 1; i++)
    {
        q = q->next;
    }

    tmp = q->next;
    q->next = tmp->next;
    free(tmp);
    list->size--;

    return 0;
}