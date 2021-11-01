#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int val;         
    void * prevNode; 
} listNode;

typedef struct {
    listNode * top;
} stackStruct;


stackStruct * stackInit();
void put( int newVal, stackStruct * stack );
int pop(stackStruct * stack);
listNode * createStackNode( int newVal, stackStruct * stack );
void freeNode(listNode * node);


stackStruct * stackInit() {

    stackStruct * stack;

    stack = (stackStruct *) malloc(sizeof(stackStruct));
    if (stack == NULL) {
        printf("out of memory error\n");
        return NULL;
    }

    return stack;
}

void push( int newVal, stackStruct * stack ) {
	
    listNode * newNode = createStackNode(newVal, stack);
    if (stack->top == NULL) {
        stack->top = (listNode *) malloc(sizeof(listNode));
        if (stack->top == NULL) {
            printf("out of memory error\n");
        }
    }
    stack->top = newNode;
}


int pop(stackStruct * stack) {

    int valTmp = stack->top->val;                 // tmp var
    listNode * prevNode = stack->top->prevNode;   // tmp var

    freeNode(stack->top);                         // free memory of current top
    stack->top = prevNode;                        // move top backward

    if (stack->top == NULL) {
        printf("Stack is empty, bye bye\n");
		return -1;
    }

    return valTmp;
}

listNode * createStackNode( int newVal, stackStruct * stack ) {
    listNode * newNode = (listNode *) malloc (sizeof(listNode));

	if (newNode == NULL) {
		printf("out of memory error\n");
        return NULL;
	}

	newNode->val = newVal;
    newNode->prevNode = stack->top;

	return newNode;
}


void freeNode(listNode * node) {
	free(node);
	node = NULL;
}


int main() {

/*
    //Example of use:
    stackStruct * stack;
    stack = stackInit();

    push(4, stack);         printf("push(4, stack);     // top - %d\n", stack->top->val);
    push(5, stack);         printf("push(5, stack);     // top - %d\n", stack->top->val);
    push(-2, stack);        printf("push(-2, stack);    // top - %d\n", stack->top->val);
    push(0, stack);         printf("push(0, stack);     // top - %d\n", stack->top->val);
    pop(stack);             printf("pop(stack);         // top - %d\n", stack->top->val);
    push(99, stack);        printf("push(99, stack);    // top - %d\n", stack->top->val);
    pop(stack);             printf("pop(stack);         // top - %d\n", stack->top->val);
    pop(stack);             printf("pop(stack);         // top - %d\n", stack->top->val);
    push(33, stack);        printf("push(33, stack);    // top - %d\n", stack->top->val);
    pop(stack);             printf("pop(stack);         // top - %d\n", stack->top->val);
    pop(stack);             printf("pop(stack);         // top - %d\n", stack->top->val);
    pop(stack);             
*/
/*
    Output:

    push(4, stack);     // top - 4
    push(5, stack);     // top - 5
    push(-2, stack);    // top - -2
    push(0, stack);     // top - 0
    pop(stack);         // top - -2
    push(99, stack);    // top - 99
    pop(stack);         // top - -2
    pop(stack);         // top - 5
    push(33, stack);    // top - 33
    pop(stack);         // top - 5
    pop(stack);         // top - 4
    Stack is empty, bye bye
*/

    return 0;
}

