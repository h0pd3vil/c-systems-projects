#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "/home/usualguy/c-systems-projects/include/ds_errors.h"

/* ========= DATA STRUCTURES ========= */

struct node
{
    void *data;
    struct node *next;
};

struct LinkedList
{
    struct node *head;
    int size;
};

/* ========= API FUNCTIONS ========= */

ds_status_t ll_init(struct LinkedList *list);
ds_status_t ll_clear(struct LinkedList *list);

ds_status_t ll_push_back(struct LinkedList *list, void *val);
ds_status_t ll_push_front(struct LinkedList *list, void *val);
ds_status_t ll_insert_at(struct LinkedList *list, void* val, int pos);

//int ll_delete_value(struct LinkedList *list, int val);   will not work now cause cant compare data
ds_status_t ll_delete_at(struct LinkedList *list, int pos);

ds_status_t ll_reverse(struct LinkedList *list);
ds_status_t  ll_has_cycle(struct LinkedList *list);
//void ll_print(struct LinkedList *list);

#endif
