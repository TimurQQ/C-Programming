#include <stdlib.h>
#include <stdio.h>
typedef int elemtype;
typedef struct Node
{
    elemtype elem;
    struct Node *next;
	struct Node *pre;
}node;//alias of Node structure
typedef node* link;
typedef link list;
typedef list* listPointer;
void CreateList(listPointer list )// list is a pointer to a first Node
{
	*list = (link)malloc(sizeof(node));
}
void AddFirst(listPointer list,elemtype elem)
{
    link q=(link)malloc(sizeof(node));
    q->elem=elem;
    q->next=(*list)->next;
    (*list)->next=q;
}
int main()
{
	list L;
	CreateList(&L);
	int num;
	scanf("%d",&num);
	AddFirst(&L,num);
	printf("%d",L->next->elem);
	return 0;
}
