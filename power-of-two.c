#include "stdio.h"
#include "stdlib.h"

int main(int argc, char** argv) 
{
	uint32_t num;

	if (argc > 1) {
		num = atoi(argv[1]);
		printf("Input: %d\n", num);
	} else {
		printf("No input.\n");
		return -1;
	}

	uint8_t ones = 0;
	uint8_t position = 0;	
	for (uint8_t i = 0; i <= 32; i++) {
		if (((num>>i)&1) == 1) {
			ones++;
			position = i;
		}
		if (ones >= 2) {
			printf("Input is not a power of 2\n");	
			return -1;
		}
	}

	printf("The number is 2 to the power of %d\n", position);

	return 0;	
}