#include <stdlib.h>
#include <stdbool.h>
#include "../../04-doubley-ll/include/doubly-ll.h"

ds_status_t dll_init(List *list)
{
    if(!list)
        return DS_ERR_NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return DS_OK;
}

ds_status_t dll_clr(List *list)
{
    if(!list)
        return DS_ERR_NULL;
    Node *q = list->head;
    while (q)
    {
        Node *tmp = q->nex;
        free(q);
        q = tmp;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return DS_OK;
}


ds_status_t dll_push_back(List *list, void *val)
{
    if(!list)
        return DS_ERR_NULL;
    Node *tmp = malloc(sizeof(Node));
    if(!tmp)
        return DS_ERR_OOM;
    tmp->data = val;
    tmp->nex = NULL;

    if (list->head == NULL)
    {
        tmp->pre = NULL;
        list->head = tmp;
        list->tail = tmp;
    }
    else
    {
        tmp->pre = list->tail;
        list->tail->nex = tmp;
        list->tail = tmp;
    }
    list->size++;
    return DS_OK;
}

ds_status_t dll_push_front(List *list, void *val)
{
    if(!list)
        return DS_ERR_NULL;
    Node *tmp = malloc(sizeof(Node));
    if(!tmp)
        return DS_ERR_OOM;
    tmp->data = val;
    tmp->nex = list->head;
    tmp->pre = NULL;
    if(list->head != NULL)
        list->head->pre = tmp;
    else
        list->tail = tmp;
    list->head = tmp;
    
    list->size++;
    return DS_OK;
}

ds_status_t dll_insert_at(List *list, int pos, void *val)
{
    if(!list)
        return DS_ERR_NULL; 

    if(!list || pos < 1 || pos > list->size+1)
        return DS_ERR_BOUNDS;

    //case: pos = end of list
    if(pos == list->size+1)
    {
        ds_status_t code = dll_push_back(list,val);
        return code;
    }

    //case: pos = start of list
    if (pos == 1)
    {
        int code = dll_push_front(list,val);
        return code;
    }

    ///case: at other position
    Node *tmp = malloc(sizeof(Node));
    if(!tmp)
        return DS_ERR_OOM;
    tmp->data = val;
    Node *q = list->head;
    for (int i = 1; i < pos-1; i++)
    {
        q= q->nex;
    }
    tmp->nex = q->nex;      //updating new node nex
    tmp->pre = q;           //updating new node pre
    q->nex = tmp;           //updating pre node nex
    tmp->nex->pre = tmp;    //updating nex node pre part
    list->size++;
    return DS_OK;   
}

ds_status_t dll_delete_at(List *list, int pos)
{
    if(!list)
        return DS_ERR_NULL;

    if(!list->head)
        return DS_ERR_EMPTY;

    if(pos < 1 || pos > list->size)
        return DS_ERR_BOUNDS;    
    
    Node *q = list->head;
    for(int i = 1; i < pos; i++)
    {
        q = q->nex;
    }

    //if current node is head
    if(q->pre == NULL && q->nex == NULL)
    {
        list->head = NULL;
        list->tail = NULL;    
    }
    else if(q->pre == NULL && q->nex != NULL) //check for first node
    {
        q->nex->pre = NULL;
        list->head = q->nex;
    }
    else if(q->pre != NULL && q->nex != NULL) //check for mid node
    {
        q->pre->nex = q->nex;
        q->nex->pre = q->pre;
    }
    else //check for end node
    {
        q->pre->nex = NULL;
        list->tail = q->pre;
    }

    free(q);
    list->size--;
    return DS_OK;

}

ds_status_t dll_reverse(List *list)
{
    if(!list)
        return DS_ERR_NULL;

    if(!list->head)
        return DS_ERR_EMPTY;    
    //doesnt needed
    // if(list->head->nex == NULL)
    //     return 1;


    Node *q = list->head;
    Node *tmp;
    while (q)
    {
        tmp = q->nex;
        q->nex = q->pre;
        q->pre = tmp;
        q = tmp;
    }
    tmp = list->head;
    list->head = list->tail;
    list->tail = tmp;
    return DS_OK;
}

ds_status_t dll_has_cycle(List *list, bool *result)
{
    if(!list || !result)
        return DS_ERR_NULL;
    
    Node *slow,*fast;
    slow = list->head;
    fast = list->head;
    while(fast != NULL && fast->nex != NULL)
    {
        slow = slow->nex;
        fast = fast->nex->nex;
        *result = slow == fast;
        if(*result)
            return DS_OK;
        
    }
    *result = false;
    return DS_OK;
}