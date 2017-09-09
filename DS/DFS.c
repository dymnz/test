#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 5
#define CONNECTED 1
#define NOT_CONNECTED 0

struct DataNode {	
	char label;
};

struct GraphStruct {
	struct DataNode* nodes;
	int** connection;
	int length;
};

int new_connection(struct GraphStruct* graph, char label_1, char label_2) {
	int index_1, index_2;
	index_1 = index_2 = graph->length;

	for (int i = 0; i < graph->length; ++i) {
		if (graph->nodes[i].label == label_1) {
			index_1 = i;
			continue;
		}
		if (graph->nodes[i].label == label_2) {
			index_2 = i;
		}
	}

	if (index_1 == graph->length || index_2 == graph->length) 
		return 1;

	// TODO connect shit

	return 0;
}

int new_node(struct GraphStruct* graph, char label) {
	if (graph->length >= MAX_NODE) { 
		printf("The stack is full");
		return 1;
	}

	graph->nodes = (struct DataNode*) realloc(graph->nodes, 
		sizeof(struct DataNode) * (graph->length+1));

	graph->connection = (int **) realloc(graph->connection, 
		sizeof(int*) * (graph->length+1));
	graph->connection[graph->length] = NULL;

	for (int i = 0; i < graph->length+1; ++i) {
		graph->connection[i] = (int *) realloc(graph->connection[i],
			sizeof(int) * (graph->length+1));
		graph->connection[i][graph->length] = NOT_CONNECTED;
	}

	graph->nodes[graph->length] = *((struct DataNode*) malloc(sizeof(struct DataNode)));
	graph->nodes[graph->length].label = label;

	++(graph->length);

	return 0;
}

void print_graph(struct GraphStruct* graph) {
	for (int i = 0; i < graph->length; ++i) {
		printf("%c, ", graph->nodes[i].label);
	}
	printf("\n");
}

void print_connection(struct GraphStruct* graph) {
	printf("%3c", ' ');
	for (int i = 0; i < graph->length; ++i) {
		printf("%3c", graph->nodes[i].label);
	}
	printf("\n");

	for (int i = 0; i < graph->length; ++i) {
		printf("%3c", graph->nodes[i].label);
		for (int r = 0; r < graph->length; ++r) {
			if (graph->connection[i][r] == CONNECTED)
				printf("%3c", '-');
			else 
				printf("%3c", ' ');
		}
		printf("\n");
	}
}

int main()
{
	struct GraphStruct graph = {
		.nodes = NULL, 
		.connection = NULL, 
		.length = 0};

	new_node(&graph, 'a');
	print_graph(&graph);
	new_node(&graph, 'b');
	print_graph(&graph);
	new_node(&graph, 'c');
	print_graph(&graph);
	print_connection(&graph);


	return 0;
}