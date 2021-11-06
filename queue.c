#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int val;
    void * nextNode;
} queueNode;

typedef struct {
    queueNode * head;
    queueNode * tail;
} queueStruct;

queueStruct * queueInit();
void enqueue( int newVal, queueStruct * queue );
int dequeue( queueStruct * queue );
queueNode * createQueueNode( int newVal );
void freeQueueNode(queueNode * node);


queueStruct * queueInit() {

    queueStruct * queue;

    queue = (queueStruct *) malloc(sizeof(queueStruct));
    if (queue == NULL) {
        printf("out of memory error\n");
        return NULL;
    }

    return queue;
}

void enqueue( int newVal, queueStruct * queue ) {
	
    queueNode * newNode = createQueueNode(newVal);

    if( queue->head == NULL ) {
        queue->head = (queueNode *) malloc(sizeof(queueNode));
        if (queue->head == NULL) {
            printf("out of memory error\n");
            return;
        }
        queue->head = newNode;
    }

    if (queue->tail == NULL) {
        queue->tail = (queueNode *) malloc(sizeof(queueNode));
        if (queue->tail == NULL) {
            printf("out of memory error\n");
            return;
        }
    }
    queue->tail->nextNode = newNode;
    queue->tail = newNode;
}


int dequeue( queueStruct * queue ) {

    if( queue->head ) {
        int valTmp = queue->head->val;                 // tmp var
        queueNode * nextNode = queue->head->nextNode;   // tmp var

        printf("%d\n", &queue->head->val);

        freeQueueNode(queue->head);                    // free memory of current head
        queue->head = nextNode;                        // move head toward
        return valTmp;
    }
    else {
        // printf("Queue is empty, bye bye\n");
        return -1;
    }
}

queueNode * createQueueNode( int newVal ) {
    queueNode * newNode = (queueNode *) malloc (sizeof(queueNode));

	if (newNode == NULL) {
		printf("out of memory error\n");
        return NULL;
	}
	newNode->val = newVal;
	newNode->nextNode = NULL;
	return newNode;
}


void freeQueueNode(queueNode * node) {
	free(node);
	node = NULL;
}

// int main() {

/* 
    //Example of use: 

    queueStruct * queue;
    queue = queueInit();

    enqueue(4, queue);      printf("enqueue(4, queue);  // head - %d, tail - %d\n", queue->head->val, queue->tail->val);
    enqueue(5, queue);      printf("enqueue(5, queue);  // head - %d, tail - %d\n", queue->head->val, queue->tail->val);
    enqueue(-2, queue);     printf("enqueue(-2, queue); // head - %d, tail - %d\n", queue->head->val, queue->tail->val);
    enqueue(0, queue);      printf("enqueue(0, queue);  // head - %d, tail - %d\n", queue->head->val, queue->tail->val);
    dequeue(queue);         printf("dequeue(queue);     // head - %d, tail - %d\n", queue->head->val, queue->tail->val);
    enqueue(99, queue);     printf("enqueue(99, queue); // head - %d, tail - %d\n", queue->head->val, queue->tail->val);
    dequeue(queue);         printf("dequeue(queue);     // head - %d, tail - %d\n", queue->head->val, queue->tail->val);
    dequeue(queue);         printf("dequeue(queue);     // head - %d, tail - %d\n", queue->head->val, queue->tail->val);
    enqueue(33, queue);     printf("enqueue(33, queue); // head - %d, tail - %d\n", queue->head->val, queue->tail->val);
    dequeue(queue);         printf("dequeue(queue);     // head - %d, tail - %d\n", queue->head->val, queue->tail->val);
    dequeue(queue);         printf("dequeue(queue);     // head - %d, tail - %d\n", queue->head->val, queue->tail->val);
    dequeue(queue);         
*/
/*
    Output:

    enqueue(4, queue);  // head - 4, tail - 4
    enqueue(5, queue);  // head - 4, tail - 5
    enqueue(-2, queue); // head - 4, tail - -2
    enqueue(0, queue);  // head - 4, tail - 0
    dequeue(queue);     // head - 5, tail - 0
    enqueue(99, queue); // head - 5, tail - 99
    dequeue(queue);     // head - -2, tail - 99
    dequeue(queue);     // head - 0, tail - 99
    enqueue(33, queue); // head - 0, tail - 33
    dequeue(queue);     // head - 99, tail - 33
    dequeue(queue);     // head - 33, tail - 33
    Queue is empty, bye bye
*/

    // return 0;
// }

