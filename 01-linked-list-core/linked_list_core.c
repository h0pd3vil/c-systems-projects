#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;

//function prototypes

void create_node();
void insert_node_at_start();
void insert_node_at_end();
void insert_node_at_pos();
void reverse_list();
void loop_detection();
void dispay_list();
void delete_node();


int main() 
{
    int choice,val,no_of_nodes,position;
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

        scanf("%d ",&choice);

        switch (choice)
        {
        case 1:
            printf("\nenter the no of elements to insert: ");
            scanf("%d",no_of_nodes);
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
            break;

        case 3:
            printf("\nenter the element to insert at end: ");
            scanf("%d",val);
            break;

        case 4:
            printf("\nenter the position: ");
            scanf("%d",&position);
            printf("\nenter the element: ");
            scanf("%d,&val");
            break;
        
        case 5:
            printf("\n reversing list.........");
            reverse_list();
            break;
        
        case 6:
            printf("\n Analyzing.........");
            loop_detection();
            break;

        case 7:
            printf("\n list: ");
            dispay_list();
            break;

        case 8:
            printf("\nenter the value to delete: ");
            scanf("%d",val);
            break;

        case 9:
            printf("\nexec ended");
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