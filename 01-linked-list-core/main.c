#include<stdio.h>
#include<stdlib.h>
#include"include/linked_list.h"



int main() 
{
    //local list of type struct LinkedList
    //struct LinkedList list = {NULL, 0};

    struct LinkedList list;
    
    ll_init(&list);


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
            ll_clear(&list);
            exit(0);
            break;


        default:
            break;
        }
    }
        
    return 0;
}