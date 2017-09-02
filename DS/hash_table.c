#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SPACE 1000

struct DataNode {
	int key;
	int data;
};

int hash(int key);
void insert(struct DataNode**, struct DataNode *);
void delete(struct DataNode**, struct DataNode *);
void print_list(struct DataNode**);

int main() {

	struct DataNode* hash_table[SPACE] = {NULL};
	struct DataNode* data_node = 
		(struct DataNode *) malloc(sizeof(struct DataNode));
	// NULL means empty

	data_node->data = 111;
	data_node->key = 111;
	insert(hash_table, data_node);

	data_node->data = SPACE + 111;
	data_node->key = SPACE + 111;
	insert(hash_table, data_node);

	data_node->data = 2*SPACE + 111;
	data_node->key = 2*SPACE + 111;
	insert(hash_table, data_node);


	return 0; 
}

int hash(int key) {
	return key % SPACE;
}

void insert(struct DataNode* hash_table[SPACE], struct DataNode* data_node) {
	int index = hash(data_node->key);


	// If node is empty, create node and copy data
	if (hash_table[index] == NULL)	{
		hash_table[index] = 
			(struct DataNode *) malloc(sizeof(struct DataNode));
		hash_table[index]->data = data_node->data;
		hash_table[index]->key = data_node->key;		

		printf("Inserted at index (%d)\t | \t", index);
		printf("Data: %4d Key: %4d\n", hash_table[index]->data, hash_table[index]->key);
	} else {
		printf("Collision!\n");

		// Expand the array and append the data
		//int length = sizeof(hash_table[index]) / sizeof(struct DataNode);
		

		hash_table[index] = 
			(struct DataNode *)
				realloc(hash_table[index], sizeof(struct DataNode) * (length + 1));
		(hash_table[index] + length)->data = data_node->data;
		(hash_table[index] + length)->key = data_node->key;
			printf("Inserted at index (%d/%d)\t  | \t", index, length);
		printf("Data: %4d Key: %4d\n", 
			(hash_table[index] + length)->data, 
			(hash_table[index] + length)->key);
	}

}

void delete(struct DataNode* hash_table[SPACE], struct DataNode* data_node) {

}

void print_list(struct DataNode* hash_table[SPACE]) {

}
