#include <stdlib.h>
#include "03-queue/include/queue.h"

ds_status_t queue_init(Queue *queue)
{
    if(!queue)
        return DS_ERR_NULL;

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return DS_OK;
}

ds_status_t enqueue(Queue *queue,void *data)
{
    if(!queue)
        return DS_ERR_NULL;
    Node *tmp;
    tmp = (Node *)malloc(sizeof(Node));
    if (!tmp)
        return DS_ERR_OOM;
    
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
    return DS_OK;
}

ds_status_t dequeue(Queue *queue, void **out_data)
{
    if(!queue)
        return DS_ERR_NULL;

    if(!queue->head)
        return DS_ERR_EMPTY;    
    
    Node *tmp = queue->head;
    queue->head = tmp->link;
    *out_data = tmp->data;
    free(tmp);
    queue->size--;
    if (queue->size == 0)
    {
        queue->tail =NULL;
    }
    
    return DS_OK;        
}

int queue_clr(Queue *queue)
{
    if(!queue)
        return DS_ERR_NULL;

    while (queue->head)
    {
        void *data;
        ds_status_t status = dequeue(queue,&data);
        if(status != DS_OK)
            return status;
    }
    return DS_OK;
}

ds_status_t peek(const Queue *queue, void **out_data)
{
    if(!queue)
        return DS_ERR_NULL;

    if (!queue->head)
    {
        return DS_ERR_EMPTY;
    }
    *out_data = queue->head->data;
    return DS_OK;      
}