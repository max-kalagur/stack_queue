#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void * val;
    void * nextNode;
} queueSNode;

typedef struct {
    queueSNode * head;
    queueSNode * tail;
} queueSStruct;

queueSStruct * queueSInit();
void enqueueS( void * newVal, queueSStruct * queue );
void * dequeueS( queueSStruct * queue );
queueSNode * createqueueSNode( void * newVal );
void freequeueSNode(queueSNode * node);


queueSStruct * queueSInit() {

    queueSStruct * queue;

    queue = (queueSStruct *) malloc(sizeof(queueSStruct));
    if (queue == NULL) {
        printf("out of memory error\n");
        return NULL;
    }

    return queue;
}

void enqueueS( void * newVal, queueSStruct * queue ) {
	
    queueSNode * newNode = createqueueSNode(newVal);

    if( queue->head == NULL ) {
        queue->head = (queueSNode *) malloc(sizeof(queueSNode));
        if (queue->head == NULL) {
            printf("out of memory error\n");
            return;
        }
        queue->head = newNode;
    }

    if (queue->tail == NULL) {
        queue->tail = (queueSNode *) malloc(sizeof(queueSNode));
        if (queue->tail == NULL) {
            printf("out of memory error\n");
            return;
        }
    }
    queue->tail->nextNode = newNode;
    queue->tail = newNode;
}


void * dequeueS( queueSStruct * queue ) {

    if( queue->head ) {
        void * valTmp = queue->head->val;                 // tmp var
        queueSNode * nextNode = queue->head->nextNode;   // tmp var
        freequeueSNode(queue->head);                    // free memory of current head
        queue->head = nextNode;                        // move head toward
        return valTmp;
    }
    else {
        printf("Queue is empty, bye bye\n");
        return NULL;
    }
}

queueSNode * createqueueSNode( void * newVal ) {
    queueSNode * newNode = (queueSNode *) malloc (sizeof(queueSNode));

	if (newNode == NULL) {
		printf("out of memory error\n");
        return NULL;
	}
	newNode->val = newVal;
	newNode->nextNode = NULL;
	return newNode;
}


void freequeueSNode(queueSNode * node) {
	free(node);
	node = NULL;
}
