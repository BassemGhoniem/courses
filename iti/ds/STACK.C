#include "stack.h"
#include <stdlib.h>
#include "linkedList.c"
int pop()
{
	if (tail)
	{
		deleteOne(tail);
		return 1;
	}
	else
		return 0;
}

void push(node *p)
{
	add(p);
}
void view()
{
	displayAll();
}
