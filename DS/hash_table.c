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
void print_table(struct DataNode**);

int main() {

	struct DataNode* hash_table[SPACE] = {NULL};
	struct DataNode* data_node = 
		(struct DataNode *) malloc(sizeof(struct DataNode));
	// NULL means empty

	data_node->data = 1;
	data_node->key = 1;
	data_node->next = NULL;
	insert(hash_table, data_node);

	data_node->data = 11;
	data_node->key = 11;
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

	data_node->data = 3*SPACE + 111;
	data_node->key = 3*SPACE + 111;
	data_node->next = NULL;
	insert(hash_table, data_node);

	print_table(hash_table);

	data_node->data = SPACE + 111;
	data_node->key = SPACE + 111;
	data_node->next = NULL;
	delete(hash_table, data_node);

	print_table(hash_table);

	return 0; 
}

int hash(int key) {
	return key % SPACE;
}

void insert(struct DataNode* hash_table[SPACE], struct DataNode* data_node) {
	int index = hash(data_node->key);

	if (hash_table[index] == NULL) {
		printf("Inserting into blankspot: %d\n", index);
		hash_table[index] = 
			(struct DataNode *) malloc(sizeof(struct DataNode));
		memcpy(hash_table[index], data_node, sizeof(struct DataNode));
	} else {
		printf("Collision at %d\n", index);
		struct DataNode* temp_node = 
			(struct DataNode *) malloc(sizeof(struct DataNode));
		memcpy(temp_node, data_node, sizeof(struct DataNode));

		struct DataNode* node_ptr = hash_table[index];
		while (node_ptr->next != NULL) {
			node_ptr = node_ptr->next;
		}

		node_ptr->next = temp_node;		
	}
}

void delete(struct DataNode* hash_table[SPACE], struct DataNode* data_node) {
	int found = 0;
	int index = hash(data_node->key);
	int counter = 0;

	// triple ref ptr
	// http://www.eprg.org/computerphile/tripref.c
	struct DataNode** node_ptr = &(hash_table[index]); 

	printf("Deleting %4d %4d\n", data_node->key, data_node->data);
	while ( *node_ptr!=NULL) {
		if ((*node_ptr)->key != data_node->key &&
			(*node_ptr)->data != data_node->data) {
			printf("Found at index:%d node:%d\n", index, counter);
			found = 1;
			break;
		}

		node_ptr = &((*node_ptr)->next); 
		++counter;
	}

	if (found) {
		struct DataNode* temp_ptr = *node_ptr;
		// int a = 10;
		// int *p = &a;
		// int **tp = &p;
		// p is the address of a
		// tp is the address of p
		// *tp is the content of p, the address of a
		// node_ptr is the address of an DataNode*
		// *node_ptr is the address of an DataNode

		// The next line changes the address of the current node to the next node, 
		// effectively removing the current node.
		*node_ptr = (*node_ptr)->next;		
		free(temp_ptr);
	}
}

void print_table(struct DataNode* hash_table[SPACE]) {

	struct DataNode* node_ptr;
	int counter = 0;
	for (int i = 0; i < SPACE; ++i) {
		if (hash_table[i] == NULL) 
			continue;

		node_ptr = hash_table[i];
		counter = 0;

		printf("==========\n");
		printf("Space: %4d\n", i);
		do {
			printf("Node %4d: %4d %4d\n", 
				counter, node_ptr->key, node_ptr->data);

			++counter;
			node_ptr = node_ptr->next;
		} while (node_ptr != NULL);
	}
}
