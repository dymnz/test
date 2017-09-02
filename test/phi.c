#include "stdio.h"
#include "stdlib.h"

void showArray(uint16_t *);
void showArrayB(uint16_t *, uint16_t);

int main(int argc, char **argv) 
{
	uint16_t a[20]={1,5,9,11,18,21,23,53,200,230,330,331,332,333,400,401,405,430,450,480};

	//showArray(a);
	showArrayB(a, 0);
	return 0;
}

void showArray(uint16_t *a)
{
	uint8_t arrayIndex = 0;
	for (uint16_t i = 1; i <= 500; i++) {
		if ((i < a[arrayIndex]) || (arrayIndex == 20))
			printf("%d ", i);
		while ((arrayIndex < 20) && (a[arrayIndex] <= i))
			arrayIndex++;
	}
}

void showArrayB(uint16_t *a, uint16_t b)
{
	uint8_t arrayIndex = 0;

	for (uint16_t i = b*100; i <= b*100+99; i++) {
		if ((i < a[arrayIndex]) || (arrayIndex == 20))
			printf("%d ", i);
		while ((arrayIndex < 20) && (a[arrayIndex] <= i))
			arrayIndex++;
	}
}
