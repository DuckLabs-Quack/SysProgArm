#include <stdio.h>

typedef struct {
	int x;
	int y;
} test_t;

int main(void) {
	
	// Your code goes here
	test_t test;
	test_t *test_p;
	
	test.x = 1;
	test.y = 1;
		
	printf("x = %i y = %i \n", test.x, test.y);
	
	test_p = &test;

	test_p->x = 100;
	test_p->y = -1;
	
	printf("x = %i y = %i \n", test.x, test.y);
}
