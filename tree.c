#include <stdio.h>
#include <stdlib.h>
#include "queue.c"  // queue int
#include "queueS.c" // queue struct
#include "stack.c"  // stack struct

/*
	BST = Binary Search Tree -> left and right BST 
	if new->key < ROOT->key ====> left BST
	else 					====> right BST
*/

typedef struct treeNode {
	struct treeNode * left;
	int key;
	struct treeNode * right;
} tree;

tree* addNode(tree*, int);
tree * createTreeNode(int);
void freeTree(tree**);

void levelorder(tree*);
void preorder(tree*); 	// P->L->R
void inorder(tree*); 	// L->P->R
void postorder(tree*); 	// L->R->P

int main(int argc, char const *argv[]) {
	tree * root = NULL;
	root = addNode(root, 42);
	root = addNode(root, 11);
	root = addNode(root, 64);
	root = addNode(root, 7);
	root = addNode(root, 15);
	root = addNode(root, 55);
	root = addNode(root, 99);
	root = addNode(root, 3);
	root = addNode(root, 100);
	printf("======= LEVELORDER ========\n");
	levelorder(root); 	// 
	printf("\n=========================\n");
	printf("======= PREORDER ========\n");
	preorder(root); 	// P->L->R
	printf("\n=========================\n");
	printf("======= INORDER =========\n");
	inorder(root); 	// L->P->R
	printf("\n=========================\n");
	printf("======= POSTORDER =======\n");
	postorder(root); 	// L->R->P
	printf("\n=========================\n");
	
	freeTree(&root);
	
	printf("======= PREORDER ========\n");
	preorder(root); 	// P->L->R
	printf("=========================\n");
	printf("======= INORDER =========\n");
	inorder(root); 	// L->P->R
	printf("=========================\n");
	printf("======= POSTORDER =======\n");
	postorder(root); 	// L->R->P
	printf("=========================\n");
	return 0;

/* Tree we have:
                    42  
        11                      64
    7       15              55      99
3                                       100

Terminal Output: 

======= LEVELORDER ========
42      11      64      7       15      55      99      3       100
=========================
======= PREORDER ========
42      11      7       3       15      64      55      99      100
=========================
======= INORDER =========
3       7       11      15      42      55      64      99      100
=========================
======= POSTORDER =======
3       7       15      11      55      100     99      64      42
=========================
======= PREORDER ========
=========================
======= INORDER =========
=========================
======= POSTORDER =======
=========================
    
*/
}

tree* addNode(tree* root, int key) {
	if (root == NULL) {
		root = createTreeNode(key);
	} else {
		if (key < root->key) {
			root->left = addNode(root->left, key);
		} else {
			root->right = addNode(root->right, key);
		}
	}
	return root;
}

tree * createTreeNode(int key) {
	tree * newTreeNode = (tree*) malloc (sizeof(tree));
	if (newTreeNode == NULL) {
		printf("out of memory :(\n");
		exit(1);
	}
	newTreeNode->key = key;
	newTreeNode->left = NULL;
	newTreeNode->right = NULL;
	return newTreeNode;
}

void levelorder(tree* root) { // 42 11 64 7 15 55 99 3 100

    if (root != NULL) {
		
        queueSStruct * queue = queueSInit();
        tree* node;

        enqueueS(root, queue);

        while ( node = dequeueS(queue) ) {
        
            if(node->left)  enqueueS(node->left, queue);
            if(node->right) enqueueS(node->right, queue);

            printf("%d\t", node->key);

        }

	}

}

void preorder(tree* root) { // 42 11 7 3 15 64 55 99 100

    if (root != NULL) {
		
        stackStruct * stack = stackInit();
        tree* node;

        push(root, stack);

        while ( node = pop(stack) ) {

            if(node->right) push(node->right, stack);
            if(node->left)  push(node->left, stack);

            printf("%d\t", node->key);
        }
	}

}

void inorder(tree* root) { // 3 7 11 15 42 55 64 99 100

    if (root != NULL) {

        stackStruct * stack = stackInit();
		tree* stackTop;
        tree* currNode = root;

        while ( currNode || !isEmptyStack(stack) ){

			if( currNode ) {
				push(currNode, stack);
				currNode = currNode->left;
			}
			else {
				currNode = pop(stack);
				printf("%d\t", currNode->key);
				currNode = currNode->right;
			}
		}
	}
}

void postorder(tree* root) {    // 3 7 15 11 55 100 99 64 42

    if (root != NULL) {
		
        stackStruct * stack = stackInit();
        tree* currNode = root;
        tree* prevNode;

		while ( currNode || !isEmptyStack(stack) ){

			if( currNode ) {
				push(currNode, stack);
				currNode = currNode->left;
			}
			else {

				currNode = stack->top->val;

				if( !currNode->right || currNode->right == prevNode ) {
					printf("%d\t", currNode->key);
					prevNode = pop(stack);
					currNode = NULL;
				}
				else {
					currNode = currNode->right;
				}
			}
		}
	}
}

void freeTree(tree** root) {
	if (*root != NULL) {
		freeTree(&((*root)->left));
		freeTree(&((*root)->right));
		free(*root);
		*root = NULL;
	}
}
