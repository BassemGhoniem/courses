#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

node * head = NULL;
node * tail = NULL;
void add(node *p)
{
	if (!head)
	{
		head = tail = p;
	}
	else
	{
		p->pre = tail;
		tail-> next = p;
		tail = p;
	}
}



void insertAfter(node* p, node* preP)
{
	if (!preP)
	{
		printf("sorry you don't creat"
		"this item to insert any thing After\n");
	}
	else if (preP->next)
	{
		p->next = preP->next;
		p->pre = preP;
		preP->next->pre = p;
		preP->next = p;
	}
	else
	{
		p->pre = preP;
		preP->next = p;
		tail = p;
	}
}



void displayAll()
{
	node *p = head;
	if (!p)
	{
		printf("Sorry!, it's empty\n");
	}
	else
	{
		while (p)
		{
			displayOne(p);
			p = p->next;
		}
	}
}

void displayOne(node *p)
{
	if (!p)
		printf("Sorry you didn't create this node yet!\n");
	else
		printf("%d\n", p->value);
}

void deleteOne(node *p) {
	if (!p)
	{
		printf("we don't have this value to delete\n");
	}
	else if (p->next && p->pre)// middle node
	{
		p->pre->next = p->next;
		p->next->pre = p->pre;
		free(p);
		printf("The node deleted.\n");
	}
	else if (p->pre && (!p->next))// tail
	{
		tail = p->pre;
		p->pre->next = NULL;
		free(p);
		printf("The node deleted.\n");
	}
	else if (head == tail)
	{
		free(head);
		head = tail = NULL;
	}
	else                         // head
	{
		head = p->next;
		p->next->pre = NULL;
		free(p);
		printf("The node deleted.\n");
	}

}
void deleteAll()
{
	node *p = head->next;
	if(!head)
	{
		printf("The array already empty\n");
	}
	else
	{
		while(p)
		{
			deleteOne(head);
			head = p;
			p = head->next;
		}
		deleteOne(head);
	}
}

node * search(int x) {
	node* p = head;
	if (!p)
		return NULL;
	else if ( p->value == x)
		return p;
	else
		while (p)
		{
			p = p->next;
			if (p->value == x)	return p;
		}
	return p;
}

