#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERBOSE

void print_array(int array[], int);
int* merge_sort(int array[], int);
int* merge(int array_1[], int array_2[], int, int);

int main() {

	int array[] = {8, 1, 6, 7, 2, 5, 9, 10, 3, 4};
	int array_length = sizeof(array) / sizeof(array[0]);

	printf("Original array:\n");
	print_array(array, array_length);

	// Sort
	int* sorted_array = merge_sort(array, array_length);
	printf("Sorted:\n");
	print_array(sorted_array, array_length);

	return 0;
}


int* merge_sort(int array[], int array_length) {
	#ifdef VERBOSE
		printf("merge sort: ");
		print_array(array, array_length);
	#endif

	if (array_length == 1) {
		#ifdef VERBOSE
		printf("--Length reached\n");
		#endif 
		return array;
	}
	int front_length = array_length / 2;
	int back_length = array_length - front_length;

	int* front_array = (int *) malloc(sizeof(int) * front_length);
	int* back_array = (int *) malloc(sizeof(int) * back_length);

	memcpy(front_array, array, sizeof(int)*front_length );
	memcpy(back_array, array+front_length, sizeof(int)*back_length );

	#ifdef VERBOSE
	printf("Front split: ");
	#endif 
	front_array = merge_sort(front_array, front_length);
	#ifdef VERBOSE
	printf("Back split: ");
	#endif 
	back_array = merge_sort(back_array, back_length);

	return merge(front_array, back_array, front_length, back_length);
}

int* merge(int array_1[], int array_2[], int length_1, int length_2) {
	int* merged_array = (int *) malloc(sizeof(int) * (length_1+length_2));
	int index_1, index_2, merged_index;
	merged_index = index_1 = index_2 = 0;

	while (index_1 < length_1 && index_2 < length_2) {
		if (array_1[index_1] < array_2[index_2]) {
			merged_array[merged_index] = array_1[index_1];
			++index_1;
		} else {
			merged_array[merged_index] = array_2[index_2];
			++index_2;
		}
		++merged_index;
	}

	if (index_1 < length_1) {
		memcpy(merged_array+merged_index, 
			array_1+index_1, 
			sizeof(int) * (length_1-index_1+1));
	}

	if (index_2 < length_2) {
		memcpy(merged_array+merged_index, 
			array_2+index_2, 
			sizeof(int) * (length_2-index_2+1));
	}

	free(array_1); 
	free(array_2);

	return merged_array;
}

void print_array(int array[], int array_length) {
	for (int i = 0; i < array_length; i++) {
		printf("%2d, ", array[i]);
	}
	printf("\n");
}