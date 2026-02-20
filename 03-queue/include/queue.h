#ifndef QUEUE_H
#define QUEUE_H

#include "/home/usualguy/c-systems-projects/include/ds_errors.h"

typedef struct Node
{
    void *data;
    struct Node *link;
}Node;

typedef struct Queue
{
    Node *head;
    Node *tail;
    int size;
}Queue;

/*prototypes*/

ds_status_t queue_init(Queue *queue);
ds_status_t queue_clr(Queue *queue);

ds_status_t enqueue(Queue *queue, void *data);
ds_status_t dequeue(Queue *queue, void **out_data);
ds_status_t peek(Queue *queue, void **out_data);



#endif



