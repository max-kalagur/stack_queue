#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void * val;         
    void * prevNode; 
} stackNode;

typedef struct {
    stackNode * top;
} stackStruct;


stackStruct * stackInit();
void push( void* newVal, stackStruct * stack );
void* pop(stackStruct * stack);
stackNode * createStackNode( void* newVal, stackStruct * stack );
void freeNode(stackNode * node);


stackStruct * stackInit() {

    stackStruct * stack;

    stack = (stackStruct *) malloc(sizeof(stackStruct));
    if (stack == NULL) {
        printf("out of memory error\n");
        return NULL;
    }
    return stack;
}



void push( void* newVal, stackStruct * stack ) {
	
    stackNode * newNode = createStackNode(newVal, stack);
    if (stack->top == NULL) {
        stack->top = (stackNode *) malloc(sizeof(stackNode));
    
        if (stack->top == NULL) {
            printf("out of memory error\n");
            return;
        }
    }

    stack->top = newNode;
}

void * pop(stackStruct * stack) {

    if(stack->top) {
        void * valTmp = stack->top->val;                    // tmp var
        stackNode * prevNode = stack->top->prevNode;        // tmp var

        freeNode(stack->top);                         // free memory of current top
        stack->top = prevNode;                        // move top backward

        return valTmp;
    }
    else {
        // printf("Stack is empty, bye bye\n");
		return NULL;
    }
    
}

stackNode * createStackNode( void* newVal, stackStruct * stack ) {
    stackNode * newNode = (stackNode *) malloc (sizeof(stackNode));

	if (newNode == NULL) {
		printf("out of memory error\n");
        return NULL;
	}

	newNode->val = newVal;
    newNode->prevNode = stack->top;

	return newNode;
}


void freeNode(stackNode * node) {
	free(node);
	node = NULL;
}


// int main() {

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

//     return 0;
// }

