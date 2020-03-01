#include "list.h"
struct Queue;

struct Queue* createQueue();

struct Node* front(struct Queue* queue);
struct Node* push(struct Queue* queue, int value);
void pop(struct Queue* queue);

int getSizeQueue(struct Queue* queue);

void clearQueue(struct Queue* queue);

void printQueue(struct Queue* queue);

struct Queue
{
    struct List* list;
};

struct Queue* createQueue()
{
    struct Queue* newQueue = (struct Queue*) malloc(sizeof(struct Queue) * 1);
    if (newQueue == NULL)
        return NULL;
    newQueue->list = createList();
    return newQueue;
}

struct Node* front(struct Queue* queue)
{
    struct Node* node = getElement(queue->list, getSize(queue->list) - 1);
    return node;
};

struct Node* push(struct Queue* queue, int value)
{
    struct Node* node = insertFirst(queue->list, value);
    return node;
};

void pop(struct Queue* queue)
{
    deleteLast(queue->list);
};

int getSizeQueue(struct Queue* queue)
{
    return getSize(queue->list);
}

void clearQueue(struct Queue* queue)
{
    clear(queue->list);
}

void printQueue(struct Queue* queue)
{
    print(queue->list);
}
