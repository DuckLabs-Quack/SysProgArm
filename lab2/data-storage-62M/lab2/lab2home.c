#include <stdio.h>
#include "stack.h"

int main(void) {	
	
	/* Array to hold stack entries */
	int stack[10];
	/* Stack pointer */
	int *stack_p = stack;

	/* Finish this! */
	
	
//	for (int i = 0; i < 100; i++) {
//		push(&stack_p, i);	
//	}
	
	push(&stack_p, 200);
	push(&stack_p, 199);
	push(&stack_p, 198);
	push(&stack_p, 197);
	printf("Popped value: %d\r\n", pop(&stack_p));
	printf("Popped value: %d\r\n", pop(&stack_p));
	printf("Popped value: %d\r\n", pop(&stack_p));
	printf("Popped value: %d\r\n", pop(&stack_p));
}
