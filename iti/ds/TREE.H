/*
 * File: tree.h
 * -------------
 * This interface exports Binary Search Tree of integers
 * with the basic functions for processing the tree
 */

#ifndef _TREE_H
#define _TREE_H

typedef struct BSTNode {
	int value;
	struct BSTNode * left;
	struct BSTNode * right;
} BSTNode;

typedef BSTNode* Tree;


/*
 * Function: insertNode
 * Usage: insertNode(&tree, item);
 * -------------------------------
 * This function inserts integer value in a tree
 * the tree must be passed by reference (the address of
 * pointer that point to the root)
 */
void insertNode(BSTNode ** node , int value);

/*
 * Function: removeNode
 * Usage: removeNode(tree, item);
 * ------------------------------
 * This function searches for an item and removes it
 * from the tree if it exists
 */
BSTNode *removeNode(BSTNode* t, int value);

/*
 * Function: displayTree
 * Usage: displayTree(tree);
 * -------------------------
 * This function displays the tree in accending order
 */
void displayTree(BSTNode * t);
/*
 * Function: findNode
 * Usage: if (findNode(tree, item)) ....
 * -------------------------------------
 * This function searches for a tree and returns
 * a pointer to it if it exists
 */
BSTNode *findNode(BSTNode *t , int value);
/*
 * Function: displayRoot
 * Usage: dispalyRoot(tree)
 * ------------------------
 * This function displays the value of the root of the given tree
 */
void displayRoot(BSTNode * r);
#endif

