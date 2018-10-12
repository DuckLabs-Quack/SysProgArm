#include "stack.h"

void push(int **sp, int value) {
	/* Finish this! */
	*((*sp)++) = value;
	
	
}

int pop(int **sp) {
	/* Finish this! */
	return *(--(*sp));
}
