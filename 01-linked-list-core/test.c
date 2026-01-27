#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/linked_list.h"


int main() 
{
    struct LinkedList list;
    ll_init(&list);
    char a[] = "om purohit";
    char *x = a;
    char *s = strdup("hari");
    ll_push_back(&list,x);
    ll_push_back(&list,s);

    struct node *curr = list.head;
    while (curr != NULL)
    {
        printf("%s ",(char *)curr->data);
        curr = curr->next;
    }
    printf("\n");
    ll_clear(&list);
    
    free(s);
    
   return 0;
}