#include <stdio.h>
#include <stdlib.h>
#include "../include/doubley-ll.h"

/* ===============================
   PRINT FUNCTIONS
================================ */

void print_forward(List *list)
{
    Node *cur = list->head;
    printf("Forward: ");
    while (cur)
    {
        printf("%ld ", (long)cur->data);
        cur = cur->nex;
    }
    printf("\n");
}

void print_backward(List *list)
{
    Node *cur = list->tail;
    printf("Backward: ");
    while (cur)
    {
        printf("%ld ", (long)cur->data);
        cur = cur->pre;
    }
    printf("\n");
}

/* ===============================
   MENU
================================ */

void menu()
{
    printf("\n====== DOUBLY LINKED LIST MENU ======\n");
    printf("1. Push Back\n");
    printf("2. Push Front\n");
    printf("3. Insert At Position\n");
    printf("4. Delete At Position\n");
    printf("5. Reverse List\n");
    printf("6. Clear List\n");
    printf("7. Print Forward\n");
    printf("8. Print Backward\n");
    printf("9. Check Cycle\n");
    printf("10. Show Size\n");
    printf("0. Exit\n");
    printf("Choose: ");
}

/* ===============================
   MAIN
================================ */

int main()
{
    List list;
    dll_init(&list);

    int choice;
    long value;
    int pos;

    while (1)
    {
        menu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%ld", &value);
                dll_push_back(&list, (void*)value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%ld", &value);
                dll_push_front(&list, (void*)value);
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%ld", &value);
                if (dll_insert_at(&list, pos, (void*)value) != 1)
                    printf("Invalid position!\n");
                break;

            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                if (dll_delete_at(&list, pos) != 1)
                    printf("Invalid position!\n");
                break;

            case 5:
                dll_reverse(&list);
                printf("List reversed.\n");
                break;

            case 6:
                dll_clr(&list);
                printf("List cleared.\n");
                break;

            case 7:
                print_forward(&list);
                break;

            case 8:
                print_backward(&list);
                break;

            case 9:
                if (dll_has_cycle(&list))
                    printf("Cycle detected!\n");
                else
                    printf("No cycle.\n");
                break;

            case 10:
                printf("Size: %d\n", list.size);
                break;

            case 0:
                dll_clr(&list);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}