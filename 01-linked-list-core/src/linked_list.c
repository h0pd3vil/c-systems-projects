#include <stdlib.h>
#include "linked_list.h"


ds_status_t ll_init(struct LinkedList *list)
{
    if(!list)
        return DS_ERR_NULL;
    list->head = NULL;
    list->size = 0;
    return DS_OK;
}

ds_status_t ll_clear(struct LinkedList *list)
{
    if(!list)
        return DS_ERR_NULL;
    struct node *curr,*nex;
    curr = list->head;
    while (curr != NULL)
    {
        nex = curr->next;
        free(curr);
        curr = nex;
    }
    ll_init(list);
    return DS_OK;   
}

ds_status_t ll_push_back(struct LinkedList *list, void *val)
{
    if(!list)
        return DS_ERR_NULL;

    struct node *tmp, *q;
    tmp = (struct node *)malloc(sizeof(struct node));

    // if malloc is not able to provide memory
    if(tmp == NULL)
        return DS_ERR_OOM;

    (*tmp).data = val;
    tmp->next = NULL;
    

    //case1: list is empty
    if(list->head == NULL)
    {
        list->head = tmp;
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
    }

    list->size++;
    return DS_OK;    
}

ds_status_t ll_push_front(struct LinkedList *list, void *val)
{
    if(!list)
        return DS_ERR_NULL;

    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(tmp == NULL)
        return DS_ERR_OOM;

    tmp->data = val;
    tmp->next = list->head;
    list->head = tmp;
    list->size++;
    return DS_OK;
}


ds_status_t ll_insert_at(struct LinkedList *list, void *val,int pos)
{
    if(!list)
        return DS_ERR_NULL;

    if (pos > (list->size)+1 || pos <= 0)
    {
        //printf("\nplease give appropiate size: ");
        return DS_ERR_BOUNDS;
    }

    //case1: at front
    if (pos == 1)
    {
        ds_status_t code = ll_push_front(list, val);
        return code;
    }
    
    //case2: at pos other than front
    struct node *tmp, *q;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(tmp == NULL)
        return DS_ERR_OOM;

    q=list->head;
    for (int i = 0; i < pos-2; i++)
    {
        q=q->next;
    }
    tmp->next = q->next;
    tmp->data = val;
    q->next = tmp;  
    list->size++;
    return DS_OK; 
}

ds_status_t ll_reverse(struct LinkedList *list)
{
    if(!list)
        return DS_ERR_NULL;

    if(list->head == NULL)//checking if list is empty
        return DS_ERR_EMPTY;

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
    return DS_OK;
}

/// @brief checking if loop is present in list (using floyd algo)
ds_status_t ll_has_cycle(struct LinkedList *list)
{ 
    if(!list)
        return DS_ERR_NULL;

    if(!list->head)
        return DS_ERR_EMPTY;

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
            return DS_ERR_STATE;
        }
    }
    //printf("no cycle exits");
    return DS_OK;
}


ds_status_t ll_delete_at(struct LinkedList *list, int pos)
{
    if (list == NULL)
        return DS_ERR_NULL;

    if(!list->head)
        return DS_ERR_EMPTY;

    if (pos <= 0 || pos > list->size)
        return DS_ERR_BOUNDS;

    struct node *tmp;

    // Case 1: delete head
    if (pos == 1)
    {
        tmp = list->head;
        list->head = tmp->next;
        free(tmp);
        list->size--;
        return DS_OK;
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

    return DS_OK;
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
