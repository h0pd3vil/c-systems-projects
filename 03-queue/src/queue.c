#include <stdlib.h>
#include "03-queue/include/queue.h"

void queue_init(Queue *queue)
{
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}

int queue_clr(Queue *queue)
{
    if(!queue)
        return -1;

    while (queue->size > 0)
    {
        dequeue(queue); 
    }
    return 1;
}

int enqueue(Queue *queue,void *data)
{
    if(!queue)
        return -1;
    Node *tmp;
    tmp = (Node *)malloc(sizeof(Node));
    if (!tmp)
        return -2;
    
    tmp->data = data;
    tmp->link = NULL;

    if (queue->size == 0)
    {
        queue->head = queue->tail = tmp;
    }
    else
    {
        queue->tail->link = tmp;
        queue->tail = tmp;
    }
    queue->size++;
    return 1;
}

void* dequeue(Queue *queue)
{
    if(!queue || queue->size == 0)
        return NULL;
    Node *tmp = queue->head;
    queue->head = tmp->link;
    void *data = tmp->data;
    free(tmp);
    queue->size--;
    if (queue->size == 0)
    {
        queue->tail =NULL;
    }
    
    return data;        
}

void* peek(Queue *queue)
{
    if (!queue || queue->size == 0)
    {
        return NULL;
    }
    return queue->head->data;      
}