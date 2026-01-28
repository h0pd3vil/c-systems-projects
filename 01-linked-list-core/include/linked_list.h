#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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

void ll_init(struct LinkedList *list);
void ll_clear(struct LinkedList *list);

int ll_push_back(struct LinkedList *list, void *val);
int ll_push_front(struct LinkedList *list, void *val);
int ll_insert_at(struct LinkedList *list, void* val, int pos);

//int ll_delete_value(struct LinkedList *list, int val);   will not work now cause cant compare data
int ll_delete_at(struct LinkedList *list, int pos);

void ll_reverse(struct LinkedList *list);
int  ll_has_cycle(struct LinkedList *list);
void ll_print(struct LinkedList *list);

#endif
