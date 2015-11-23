#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
/*
 * Function: findMin
 * -----------------
 * This functioon returns pointer to the node that has the min
 * value in the tree
 */
BSTNode *findMin(BSTNode *node)
{
	if(node == NULL)
		return NULL;
	if(node->left)
		return findMin(node->left);
	else
		return node;
}

/*
 * Function: removeNode
 * --------------------
 * This function removes the node that has the passed value
 * 
 * 
 * if the node has two children
 *		the function palce the next greater node in the tree
 *		in its place and then removes it
 * if the node has one or zero children
 *		the function simply removes the node and place its
 *		child in its place
 */
BSTNode *removeNode(BSTNode* t, int value)
{
	BSTNode *tmp;
	if (t == NULL)
		printf("Element Not found\n");
	else if (t->value > value)
		t->left = removeNode(t->left, value);
	else if (t->value < value)
		t->right = removeNode(t->right, value);
	else
	{
		if (t->right && t->left)
		{
			tmp = findMin(t->right);
			t->value = tmp->value;
			t->right = removeNode(t->right, tmp->value);
		}
		else
		{
			tmp = t;
			if (t->left == NULL)
				t = t->right;
			else if(t->right == NULL);
				t = t->left;
			free(tmp);
		}
	}
	return t;
}

/*
 * Function: createNode
 * --------------------
 * This function returns reference to new node
 * with the passed values
 */
BSTNode * createNode(int value)
{
	BSTNode* node = (BSTNode*) malloc(sizeof(BSTNode));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

/*
 * Function: findNode
 * ------------------
 * This function returns a pointer to the node that
 * contains the passed value if it exists
 */
BSTNode *findNode(BSTNode *t, int value)
{
	if (t == NULL) return NULL;
	if (value == t->value) return t;
	if (value < t->value)
		return findNode(t->left, value);
	else
		return findNode(t->right, value);
}

/*
 * Function: insertNode
 * --------------------
 * This function inserts the passed value in the given tree
 * the tree must be passed by reference to the function 
 */
void insertNode(BSTNode ** t , int value)
{
	if (*t == NULL)
		*t = createNode(value);
	else
		if (value != (*t)->value)
		{
			if (value < (*t)->value)
				insertNode(&((*t)->left), value);
			else
				insertNode(&((*t)->right), value);
		}
}


void displayTree(BSTNode* r)
{
	if(r != NULL)
	{
		displayTree(r->left);
		printf("%d\n", r->value);
		displayTree(r->right);
	}
}

void displayRoot(BSTNode * r)
{
	if (r)
		printf("The root is %d\n", r->value);
	else
		printf("The tree is empty!\n");
}