#include <stdio.h>

int queue[10];
int insert = 0;
int retrieve = 0;
int isFull = 0;

int put(int item) {

	if (!isFull) {
		queue[insert] = item;
		insert = (insert + 1) % 10;

		if (insert == retrieve) {
			isFull = 1;
		}
		return 1;
	}

	return 0;
}

int get(int* item ) {

	if (insert == retrieve && !isFull) {
		return 0;
	} 
	else {
		isFull = 0;
		int value = queue[retrieve];
		retrieve = (retrieve + 1) % 10;
	
		*item = value;
		return 1;
	}
}

int main(void) {

	int value;
	
	put(0);
	put(1);
	put(2);
	put(3);
	put(4);
	put(5);
	put(6);
	put(7);
	put(8);
	put(9);
	
	printf("Status: %d\n", put(11));

	printf("Status: %d\n", get(&value));
	printf("Removed %d from queue\r\n", value);

	printf("Status: %d\n", get(&value));
	printf("Removed %d from queue\r\n", value);

	printf("Status: %d\n", put(11));
}
