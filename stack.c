#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int val;             // 4 bites
    void * prevNode;     // 8 bites
} listNode;

listNode * top = NULL;
int size = 0;

listNode * createNode( int newVal );
void put( int newVal );
int pop();
void freeNode(listNode * top);
void printList(listNode* tmpTop);


void stackInit() {

    top = (listNode *) malloc(sizeof(listNode));
    
    if (top == NULL) {
        printf("out of memory error\n");
		exit(1);
    }
}

void push( int newVal ) {
	
    listNode * newNode = createNode(newVal);
    if( size == 0 ) {
        stackInit();
    }
    top = newNode;
    size++;
}


int pop() {

    int valTmp = top->val;                 // tmp var
    listNode * prevNode = top->prevNode;   // tmp var

    freeNode(top);                         // free memory of current top
    top = prevNode;                        // move top backward
    size--;                                // decrease stack size

    if (top == NULL) {
        printf("Stack is empty, bye bye\n");
		exit(1);
    }

    return valTmp;
}

listNode * createNode( int newVal ) {
    listNode * newNode = (listNode *) malloc (sizeof(listNode));

	if (newNode == NULL) {
		printf("out of memory error\n");
		exit(1);
	}

	newNode->val = newVal;
    if( top != NULL ) {
        newNode->prevNode = top;
    }
    else {
        newNode->prevNode = NULL;
    }

	return newNode;
}


void freeNode(listNode * top) {

	free(top);
	top = NULL;
}

void printList(listNode* tmpTop) {
	while(tmpTop != NULL) {
        printf("%d\n", tmpTop->val);
		tmpTop = tmpTop->prevNode;
	}
    printf("-------------------------------\n");
}

int main() {

    push(4);
    printList(top);

    push(5);
    printList(top);

    push(-2);
    printList(top);

    push(0);
    printList(top);

    pop();
    printList(top);

    push(99);
    printList(top);

    pop();
    printList(top);

    pop();
    printList(top);

    push(33);
    printList(top);

    pop();
    printList(top);

    pop();
    printList(top);

    pop();
    printList(top);

    pop();
    printList(top);

/*
Output:

4
-------------------------------
5
4
-------------------------------
-2
5
4
-------------------------------
0
-2
5
4
-------------------------------
-2
5
4
-------------------------------
99
-2
5
4
-------------------------------
-2
5
4
-------------------------------
5
4
-------------------------------
33
5
4
-------------------------------
5
4
-------------------------------
4
-------------------------------
Stack is empty, bye bye
*/

    return 0;
}

