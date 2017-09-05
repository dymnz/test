#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SPACE 1000

struct DataNode {
	int key;
	int data;
	struct DataNode* next;
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
	data_node->next = NULL;
	insert(hash_table, data_node);

	data_node->data = SPACE + 111;
	data_node->key = SPACE + 111;
	data_node->next = NULL;
	insert(hash_table, data_node);

	data_node->data = 2*SPACE + 111;
	data_node->key = 2*SPACE + 111;
	data_node->next = NULL;
	insert(hash_table, data_node);


	return 0; 
}

int hash(int key) {
	return key % SPACE;
}

void insert(struct DataNode* hash_table[SPACE], struct DataNode* data_node) {
	int index = hash(data_node->key);

	
}

void delete(struct DataNode* hash_table[SPACE], struct DataNode* data_node) {

}

void print_list(struct DataNode* hash_table[SPACE]) {

}
