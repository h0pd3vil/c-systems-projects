#include <stdlib.h>
#include "../include/linked_list.h"


void ll_init(struct LinkedList *list)
{
    list->head = NULL;
    list->size = 0;

}

void ll_clear(struct LinkedList *list)
{
    struct node *curr,*nex;
    curr = list->head;
    while (curr != NULL)
    {
        nex = curr->next;
        free(curr);
        curr = nex;
    }
    ll_init(list);
    
}

int ll_push_back(struct LinkedList *list, void *val)
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

int ll_push_front(struct LinkedList *list, void *val)
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


int ll_insert_at(struct LinkedList *list, void *val,int pos)
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
    while (curr != NULL)
    {
        nex = curr->next; //nex has adress of next node
        curr->next = prev; //updating current link to previous one 
        prev = curr; //updating previous as current one
        curr = nex; //since current link has been changed so going to a next link using nex
    }
    list->head = prev;
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


//cant be implemented cause we only know about the box what inside it cant be known

// void ll_print(struct LinkedList *list)
// {
//     struct node *q;
//     q=list->head;
//     printf("\n");
//     while (q != NULL)
//     {
//         printf("%d ",q->data);
//         q=q->next;
//     }    
// }

// can't be implemented

// int ll_delete_value(struct LinkedList *list, void *val)
// {
//     if (list->head == NULL)
//         return -1;

//     struct node *q = list->head;
//     struct node *tmp;

//     // Case 1: delete head
//     if (q->data == val)
//     {
//         list->head = q->next;
//         free(q);
//         list->size--;
//         return 0;
//     }

//     // Find node BEFORE the one to delete
//     while (q->next != NULL && q->next->data != val)
//     {
//         q = q->next;
//     }

//     // Value not found
//     if (q->next == NULL)
//         return -1;

//     // Delete the node
//     tmp = q->next;
//     q->next = tmp->next;
//     free(tmp);
//     list->size--;

//     return 0;
// }

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