#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 5


struct DataNode {	
	char label;
};

struct GraphStruct {
	struct DataNode* nodes;
	int length;
};

int new_node(struct GraphStruct* graph, char label) {
	if (graph->length >= MAX_NODE) { 
		printf("The stack is full");
		return 1;
	}

	graph->nodes = (struct DataNode*) realloc(graph->nodes, 
		sizeof(struct DataNode) * (graph->length+1));

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

int main()
{
	struct GraphStruct graph = {.nodes = NULL, .length = 0};

	new_node(&graph, 'a');
	print_graph(&graph);
	new_node(&graph, 'b');
	print_graph(&graph);
	new_node(&graph, 'c');
	print_graph(&graph);


	return 0;
}