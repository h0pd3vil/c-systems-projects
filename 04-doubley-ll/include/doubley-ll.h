#ifndef DLIST_H
#define DLIST_H

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

int dll_init(List *list);
int dll_clr(List *list);

int dll_push_back(List *list, void *val);
int dll_push_front(List *list, void *val);
int dll_insert_at(List *list, int pos, void *val);

int dll_delete_at(List *list, int pos);

int dll_reverse(List *list);
int dll_has_cycle(List *list);


#endif