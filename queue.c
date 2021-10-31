#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int val;             // 4 bites
    void * nextNode;     // 8 bites
} listNode;

listNode * head = NULL;
listNode * tail = NULL;
int size = 0;

listNode * createNode( int newVal );
void enqueue( int newVal );
int dequeue();
void freeNode(listNode * head);
void printList(listNode* tmpHead);


void queueInit() {

    head = (listNode *) malloc(sizeof(listNode));
    tail = (listNode *) malloc(sizeof(listNode));
    
    if (head == NULL || tail == NULL) {
        printf("out of memory error\n");
		exit(1);
    }
}

void enqueue( int newVal ) {
	
    listNode * newNode = createNode(newVal);
    if( size == 0 ) {
        queueInit();
        head = newNode;
    }
    tail->nextNode = newNode;
    tail = newNode;
    size++;
}


int dequeue() {

    int valTmp = head->val;                 // tmp var
    listNode * nextNode = head->nextNode;   // tmp var

    freeNode(head);                         // free memore of current head
    head = nextNode;                        // move head toward
    size--;                                 // decrease queue size

    if (head == NULL) {
        printf("Queue is empty, bye bye\n");
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
	newNode->nextNode = NULL;
	return newNode;
}


void freeNode(listNode * head) {

	free(head);
	head = NULL;
}

void printList(listNode* tmpHead) {
	while(tmpHead != NULL) {
        printf("%d\t", tmpHead->val); 
		tmpHead = tmpHead->nextNode;
	}
    printf("\n\n");
}

int main() {

    enqueue(4);
    printList(head);

    enqueue(5);
    printList(head);

    enqueue(-2);
    printList(head);

    enqueue(0);
    printList(head);

    dequeue();
    printList(head);

    enqueue(99);
    printList(head);

    dequeue();
    printList(head);

    dequeue();
    printList(head);

    enqueue(33);
    printList(head);

    dequeue();
    printList(head);

    dequeue();
    printList(head);

    dequeue();
    printList(head);

/*
Output:

4

4       5

4       5       -2

4       5       -2      0

5       -2      0

5       -2      0       99

-2      0       99

0       99

0       99      33

99      33

33

Queue is empty, bye bye
*/

    return 0;
}

