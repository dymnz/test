#include <stdio.h>
#define VERBOSE

void bubble_sort(int array[], int array_length);
void print_array(int array[], int array_length);
int binary_search(int array[], int array_length, int target);

int main() {

	int array[] = {8, 1, 6, 7, 2, 5, 9, 10, 3, 4};
	int array_length = sizeof(array) / sizeof(array[0]);

	printf("Original array:\n");
	print_array(array, array_length);

	// Sort
	printf("Bubble sort:\n");
	bubble_sort(array, array_length);
	print_array(array, array_length);

	// Binary search
	printf("Binary search, finding index of 5:\n");
	int index = binary_search(array, array_length, 5);
	printf("Index of 5 is %d\n", index);

	return 0;
}

int binary_search(int array[], int array_length, int target) {
	int front = 0;
	int back = array_length;
	int index = array_length / 2;

	while (front <= back) {
		#ifdef VERBOSE
			printf("front/index/back: %2d %2d %2d: ", front, index, back);
			print_array(array, array_length);
		#endif	

		if (array[index] == target) {
			return index;
		} else if (array[index] < target) {
			front = index + 1;
		} else {
			back = index - 1;
		}
		
		index = front + (back - front) / 2;
	}
	return -1;
}


void bubble_sort(int array[], int array_length) {
	int temp;
	for (int i = array_length - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (array[j+1] < array[j]) {
				temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;
			}
		}
	}
}

void print_array(int array[], int array_length) {
	for (int i = 0; i < array_length; i++) {
		printf("%2d, ", array[i]);
	}
	printf("\n");
}