#include "stdio.h"
#include "stdlib.h"

struct Node {
	uint32_t num;
	struct Node * next;
};


int main(int argc, char **argv)
{
	uint32_t dataList[] = {1, 21, 33, 46, 56, 66, 79, 81, 99};
	struct Node *nodeHead = NULL;

	uint32_t dataListLength = sizeof(dataList) / sizeof(uint32_t);
	printf("Length of dataList: %d\n", dataListLength);

	if (dataListLength < 2) {
		printf("You need at least two number in dataList\n");
		return -1;
	}

	// Init linked list
	nodeHead = malloc(sizeof(struct Node));
	nodeHead->num = dataList[0];
	nodeHead->next = NULL;


	// Keep adding data
	struct Node *nodePointerTemp = nodeHead;
	for (uint32_t i = 1; i < dataListLength; i++) {
		nodePointerTemp->next = malloc(sizeof(struct Node));
		nodePointerTemp = nodePointerTemp->next;

		nodePointerTemp->num = dataList[i];
		nodePointerTemp->next = NULL;
	}


	// Traverse the linked list
	printf("Traverse the linked list:\n");

	nodePointerTemp = nodeHead;
	while (nodePointerTemp != NULL) {
		printf("%d ", nodePointerTemp->num);
		nodePointerTemp = nodePointerTemp->next;
	}
	printf("\n");


	// Reverse the linked list
	printf("Reverse the linked list:\n");

	struct Node *nodePointerFront;
	struct Node *nodePointerBack;

	nodePointerBack = NULL;
	nodePointerFront = nodeHead;
	while (nodePointerFront != NULL) {
		nodePointerTemp = nodePointerFront->next;
		nodePointerFront->next = nodePointerBack;

		nodePointerBack = nodePointerFront;
		nodePointerFront = nodePointerTemp;
	}
	nodeHead = nodePointerBack;

	nodePointerTemp = nodeHead;
	while (nodePointerTemp != NULL) {
		printf("%u ", nodePointerTemp->num);
		nodePointerTemp = nodePointerTemp->next;
	}
	printf("\n");


	// Binary search
	

	return 0;
}