#ifndef QUEUE_H
#define QUEUE_H


typedef struct Node
{
    void *data;
    struct Node *link;
}Node;

typedef struct Queue
{
    struct Node *head;
    int size;
}Queue;

/*prototypes*/

void queue_init(Queue *queue);
void queue_clr(Queue *queue);

int enqueue(Queue *queue, void *data);
void* dequeue(Queue *queue);
void* peek(Queue *queue);


#endif



