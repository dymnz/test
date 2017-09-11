#include <stdio.h>

#define VERBOSE

#define TRUE 1 
#define FALSE 0
#define SWAP(A, B) { \
	int temp = (A); \
	(A) = (B); \
	(B) = temp;}

void quick_sort(int array[], int start_index, int end_index);
int partition(int array[], int start_index, int end_index);
void print_array(int array[], int array_length);

int main(int argc, char const *argv[])
{
	int array[] = {8, 1, 6, 7, 2, 5, 9, 10, 3, 4};
	int array_length = sizeof(array) / sizeof(array[0]);

	printf("Original array:\n");
	print_array(array, array_length);

	printf("quick_sort_pivot:\n");
	quick_sort(array, 0, array_length - 1);
	print_array(array, array_length);

	return 0;
}

void quick_sort(int array[], int start_index, int end_index) {
	#ifdef VERBOSE
	printf("\tSorting:%3d | %3d\n", start_index, end_index);
	#endif

	if (start_index >= end_index) {
		#ifdef VERBOSE
		printf("Returned\n");
		#endif
		return;
	}
	int pivot = partition(array, start_index, end_index);
	printf("Front: ");
	quick_sort(array, start_index, pivot - 1);
	printf("Back: ");
	quick_sort(array, pivot + 1, end_index);

}

int partition(int array[], int start_index, int end_index) {
	int left_index = start_index;
	int right_index = end_index - 1;
	int pivot = array[end_index];

	while (TRUE) {
		while (array[left_index] < pivot) {
			++left_index;
		}	

		while (right_index > 0 && array[right_index] > pivot) {
			--right_index;
		}

		if (left_index >= right_index) {
			break;
		} else {
			SWAP(array[left_index], array[right_index]);
		}
	}

	SWAP(array[left_index], array[end_index]);
	return left_index;
}


void print_array(int array[], int array_length) {
	for (int i = 0; i < array_length; i++) {
		printf("%2d, ", array[i]);
	}
	printf("\n");
}