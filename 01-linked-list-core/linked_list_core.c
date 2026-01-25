/*
TODO:
1. Handle deletion of first node in delete_node()
2. Add boundary checks in insert_at_position()
3. Add list size tracking
4. Improve loop_detection NULL checks
*/





#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;

//function prototypes

void create_node(int val);
void insert_at_start(int val);
void insert_at_end(int val);
void insert_at_position(int pos, int val);
void reverse_list();
void loop_detection();
void display_list();
void delete_node(int val);


int main() 
{
    int choice,val,no_of_nodes,position,size;
    while (1)
    {
        printf("\n1. create list");
        printf("\n2. insert node at start");
        printf("\n3. insert node at end");
        printf("\n4. insert node at pos");
        printf("\n5. reverse list");
        printf("\n6. loop detection");
        printf("\n7. display list");
        printf("\n8. delete node");
        printf("\n9. quit");
        printf("\nEnter your choice: ");

        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("\nenter the no of elements to insert: ");
            scanf("%d",&no_of_nodes);
            for (int i = 0; i < no_of_nodes; i++)
            {
                printf("\nenter the value: ");
                scanf("%d",&val);
                create_node(val);
            }
            
            break;
        case 2:
            printf("\nenter the  element to insert at start: ");
            scanf("%d",&val);
            insert_at_start(val);
            break;

        case 3:
            printf("\nenter the element to insert at end: ");
            scanf("%d",&val);
            insert_at_end(val);
            break;

        case 4:
            printf("\nenter the position: ");
            scanf("%d",&position);
            printf("\nenter the element: ");
            scanf("%d",&val);
            insert_at_position(position,val);
            break;
        
        case 5:
            printf("\n");
            display_list();
            printf("\n reversing list.........");
            reverse_list();
            display_list();
            break;
        
        case 6:
            printf("\n Analyzing.........");
            loop_detection();
            break;

        case 7:
            printf("\n list: ");
            display_list();
            break;

        case 8:
            printf("\nenter the value to delete: ");
            scanf("%d",&val);
            delete_node(val);
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


void create_node(int val)
{
    struct node *tmp, *q;
    tmp = (struct node *)malloc(sizeof(struct node));

    (*tmp).data = val;
    tmp->next = NULL;
    
    if(start == NULL)
        start = tmp;
    else
    {
        q = start;
        while (q->next != NULL)
        {
            q=q->next;
        }
        q->next = tmp;
    }
    
}

void insert_at_start(int val)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = val;
    tmp->next = start;
    start = tmp;
    
}

// unecessary doing same work as create node 
void insert_at_end(int val)
{
    if(start == NULL)
    {
        create_node(val);
        return;
    }
    struct node *tmp, *q;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = val;
    tmp->next = NULL;
    q=start;
    while(q->next != NULL)
    {
        q=q->next;
    }
    q->next = tmp; 
       
}

void insert_at_position(int pos, int val)
{
    struct node *tmp, *q;
    tmp = (struct node *)malloc(sizeof(struct node));
    q=start;
    for (int i = 0; i < pos-2; i++)
    {
        q=q->next;
    }
    tmp->next = q->next;
    tmp->data = val;
    q->next = tmp;  
     
}

void reverse_list()
{
    if(start == NULL)//checking if list is empty
        return;
    struct node  *curr, *prev, *nex;
    prev = NULL; //storing previous address
    curr = start; // having current adress
    while (curr->next != NULL)
    {
        nex = curr->next; //nex has adress of next node
        curr->next = prev; //updating current link to previous one 
        prev = curr; //updating previous as current one
        curr = nex; //since current link has been changed so going to a next link using nex
    }
    curr->next = prev;
    start = curr;
         
}

/// @brief checking if loop is present in list (using floyd algo)
void loop_detection()
{ 
    if(start == NULL)
        return;
    struct node *slow, *fast;
    slow = start;
    fast = start;
    while (fast->next != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            printf("cycle exists");
            return;
        }
    }
    printf("no cycle exits");
}

void display_list()
{
    struct node *q;
    q=start;
    printf("\n");
    while (q != NULL)
    {
        printf("%d ",q->data);
        q=q->next;
    }    
}

void delete_node(int val)
{
    if(start == NULL)
        return;
    struct node *tmp, *q;
    q=start;

    //if first element needs to be deleted
    if (q->data == val)
    {
        tmp = start;
        start = q->next;
        free(tmp);
        return;
    }
    
    while (q->next != NULL && q->next->data != val)
    {
        if (q->next == NULL)
        {
            printf("element not found !");
            return;
        }
        
        q=q->next;
    }
    tmp = q->next;
    q->next = q->next->next;
    free(tmp);
}