#ifndef DLIST_H
#define DLIST_H

#include "/home/usualguy/c-systems-projects/include/ds_errors.h"

typedef struct Node
{
    void *data;
    struct Node *pre;
    struct Node *nex;
}Node;

typedef struct List
{
    Node *head;
    Node *tail;
    int size;
}List;

ds_status_t dll_init(List *list);
ds_status_t dll_clr(List *list);

ds_status_t dll_push_back(List *list, void *val);
ds_status_t dll_push_front(List *list, void *val);
ds_status_t dll_insert_at(List *list, int pos, void *val);

ds_status_t dll_delete_at(List *list, int pos);

ds_status_t dll_reverse(List *list);
ds_status_t dll_has_cycle(List *list);


#endif