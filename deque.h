#include "list.h"
struct Deque;

struct Deque* createDeque();

struct Node* front(struct Deque* deque);
struct Node* back(struct Deque* deque);
struct Node* push_front(struct Deque* deque, int value);
struct Node* push_back(struct Deque* deque, int value);
void pop_front(struct Deque* deque);
void pop_back(struct Deque* deque);

int getSizeDeque(struct Deque* deque);

void clearDeque(struct Deque* deque);

void printDeque(struct Deque* deque);

struct Deque
{
    struct List* list;
};

struct Deque* createDeque()
{
    struct Deque* newDeque = (struct Deque*) malloc(sizeof(struct Deque) * 1);
    if (newDeque == NULL)
        return NULL;
    newDeque->list = createList();
    return newDeque;
}

struct Node* front(struct Deque* deque)
{
    struct Node* node = getElement(deque->list, 0);
    return node;
};

struct Node* back(struct Deque* deque)
{
	struct Node* node = getElement(deque->list, getSize(deque->list) - 1);
    return node;	
}

struct Node* push_front(struct Deque* deque, int value)
{
    struct Node* node = insertFirst(deque->list, value);
    return node;
};

struct Node* push_back(struct Deque* deque, int value)
{
    struct Node* node = insertLast(deque->list, value);
    return node;
};

void pop_back(struct Deque* deque)
{
    deleteLast(deque->list);
};

void pop_front(struct Deque* deque)
{
    deleteFirst(deque->list);
};

int getSizeDeque(struct Deque* deque)
{
    return getSize(deque->list);
}

void clearDeque(struct Deque* deque)
{
    clear(deque->list);
}

void printDeque(struct Deque* deque)
{
    print(deque->list);
}
