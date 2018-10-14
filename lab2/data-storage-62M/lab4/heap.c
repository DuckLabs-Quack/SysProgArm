#include "heap.h"

int get_value(heap_t *heap,int index) {
	return heap->store[index];
}

void set_value(heap_t *heap,int index, int value) {
	heap->store[index] = value;	
}

void swap(heap_t *heap,int idx_a, int idx_b) {
	int temp;
	temp = get_value(heap, idx_a);
	
	set_value(heap, idx_a, get_value(heap, idx_b));	
	set_value(heap, idx_b, temp);
}

int get_parent_idx(int currentidx) {
	return (currentidx-1)/2;
}

int get_child_idx(int currentidx) {
	return 2*currentidx+1;
}

int exists(heap_t *heap,int currentidx) {
	return currentidx < heap->length;
}

int has_one_child(heap_t *heap,int currentidx) {
	int childidx = get_child_idx(currentidx);
	return exists(heap, childidx) && !exists(heap, childidx+1);
}

int has_two_children(heap_t *heap,int currentidx) {
	int childidx = get_child_idx(currentidx);
	return exists(heap, childidx+1);
}

static void heap_up(heap_t *heap) {
	// Write me!
	int currentidx = heap->length-1;
	while (1) {
		if (currentidx == 0) {
			break;
		}
		
		int parentidx = get_parent_idx(currentidx);
		int parentvalue = get_value(heap, parentidx);
		int currentvalue = get_value(heap, currentidx);
		
		if (parentvalue <= currentvalue) {
			break;
		}
		
		swap(heap, parentidx, currentidx);
		currentidx = parentidx;
		
	}
}

static void heap_down(heap_t *heap) {
	// Write me!
	int currentidx = 0;

	while(1) {
		int leftchild_idx = get_child_idx(currentidx);
		int rightchild_idx = leftchild_idx + 1;

		if(!exists(heap, leftchild_idx)) {
			break;
		}
		
		if(has_one_child(heap, currentidx)) {
			int child_value = get_value(heap, leftchild_idx);
			int current_value = get_value(heap, currentidx);
			
			if(current_value > child_value) {
				swap(heap, leftchild_idx, currentidx);
				currentidx = leftchild_idx;
			}
			else {
				break;
			}	
		}

		if(has_two_children(heap, currentidx)) {
			
			int left_child_value = get_value(heap, leftchild_idx);
			int right_child_value = get_value(heap, rightchild_idx);
			int current_value = get_value(heap, currentidx);
			int child_value;
			int child_idx;

			if(left_child_value < right_child_value) {
				child_value = left_child_value;
				child_idx = leftchild_idx;
			}
			else {
				child_value = right_child_value;
				child_idx = rightchild_idx;
			}

			if(current_value > child_value) {
				swap(heap, child_idx, currentidx);
				currentidx = child_idx;
			}
			else {
				break;
			}	
		}
	}	
}

void heap_init(heap_t *heap, int *store) {
	heap->store = store;
	heap->length = 0;
}

void heap_insert(heap_t *heap, int value) {
	// The new element is always added to the end of a heap
	heap->store[(heap->length)++] = value;
	heap_up(heap);
}

int heap_extract(heap_t *heap) {
	// The root value is extracted, and the space filled by the value from the end
	// If the heap is empty, this will fail horribly...
	int value = heap->store[0];
	heap->store[0] = heap->store[--(heap->length)];
	heap_down(heap);
	return value;
}

int heap_isEmpty(heap_t *heap) {
	return !(heap->length);
}
