#include "queue.h"
#include <stdlib.h>
#include "linkedList.c"
int dequeue()
{
	if (head)
	{
		deleteOne(head);
		return 1;
	}
	else
		return 0;
}

void enqueue(node *p)
{
	add(p);
}
void view()
{
	displayAll();
}
int isEmpty() {
	return head;
}