#ifndef _linkedList_h
#define _linkedList_h

typedef struct node {
	int value;
	struct node *next;
	struct node *pre;
} node;


void add(node * p);
void insertAfter(node *p, node *preP);
void displayAll();
node * search(int value);
void displayOne(node * p);
void deleteOne(node *p);
void deleteAll();

#endif