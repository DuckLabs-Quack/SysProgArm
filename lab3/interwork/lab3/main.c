#include <stdio.h>
#include <stdint.h>
#include "serial.h"

#pragma pack(push)
#pragma pack(1)

typedef struct {
	int32_t x;
	int32_t y;
	void *ptr;
	void (*callback) (void *);
} structure_t;

#pragma pack(pop)

void printInteger(void* vp) {
	int* intp = vp;
	int test = *intp;
	//printf("Integer value = %d", *intp);
}

void printDouble(void* vp) {
	double* dblp = vp;
	double test = *dblp;
	//printf("Integer value = %d", *intp);
}

void process(structure_t *s);

int main(void) {
	serial_init();

	// Your code goes here...
	structure_t test;
	test.x = 3;
	test.y = 5;
	
	double testdbl = 9.55;
	test.ptr = &testdbl;
	
	test.callback = printDouble;
	
	process(&test);
	
	while(1);
}
