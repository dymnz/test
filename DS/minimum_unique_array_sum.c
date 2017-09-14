#include <stdio.h>

#define BOOL
#define TRUE 1
#define FALSE 0

int main(int argc, char const *argv[])
{
	int array[] = {2, 2, 2, 3, 8, 9};
	int array_length = sizeof(array) / sizeof(int);
	
	int sum = array[0];
	for (int i = 1; i < array_length; ++i) {
		if (array[i] < array[i-1])
			array[i] = array[i-1] + 1;
		sum+=array[i];
	}

	printf("%d\n", sum);

	return 0;
}