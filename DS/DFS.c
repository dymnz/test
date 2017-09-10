#include <stdio.h>
#include <stdlib.h>

//#define VERBOSE

#define MAX_NODE 10
#define CONNECTED 1
#define NOT_CONNECTED 0
#define VISITED 1
#define NOT_VISITED 0

struct DataNode {	
	char label;
};

struct GraphStruct {
	struct DataNode* nodes;
	int** connection;
	int length;
};


int new_connection(struct GraphStruct* graph, char label_1, char label_2) {
	printf("* new connection: %c %c\n", label_1, label_2);
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

	graph->connection[index_1][index_2] 
		= graph->connection[index_2][index_1] 
		= CONNECTED;

	return 0;
}

int new_node(struct GraphStruct* graph, char label) {
	printf("* new node: %c\n", label);
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
	for (int i = 0; i < graph->length+1; ++i) {
		if (graph->connection[i][graph->length] == CONNECTED)
			graph->connection[graph->length][i] = CONNECTED;
		else
			graph->connection[graph->length][i] = NOT_CONNECTED;
	}

	graph->nodes[graph->length] = *((struct DataNode*) malloc(sizeof(struct DataNode)));
	graph->nodes[graph->length].label = label;

	++(graph->length);

	return 0;
}

int find_label_index(struct GraphStruct* graph, char label) {
	for (int i = 0; i < graph->length; ++i) {
		if (graph->nodes[i].label == label) {
			return i;
		}
	}
	return -1;
}


void DFS(struct GraphStruct* graph) {
	char stack[MAX_NODE] = {'\0'};
	int visited[MAX_NODE] = {NOT_VISITED};
	int stack_index = 0;
	char current_node = '\0';
	int current_index = 0;
	int found_next = 0;

	stack[stack_index] = graph->nodes[0].label;
	++stack_index;
	while (1) {		
		found_next = 0;
		current_node = stack[stack_index - 1];
		current_index = find_label_index(graph, current_node);
		printf("Travel to %c\n", current_node);
		visited[current_index] = VISITED;

		int* connectivity_array = graph->connection[current_index];
		for (int i = 0; i < graph->length; ++i) {

			#ifdef VERBOSE
			printf("-connetion: %c to %c: %d\n", current_node, graph->nodes[i].label, connectivity_array[i]);
			#endif

			if (connectivity_array[i] == CONNECTED && visited[i] == NOT_VISITED) {								
				#ifdef VERBOSE		
				printf("-stack %d push %c\n", stack_index, graph->nodes[i].label);
				#endif
				found_next = 1;
				stack[stack_index] = graph->nodes[i].label;		
				++stack_index;
				break;
			}
		}
		if (found_next)
			continue;
		else if (stack_index > 1) {
			printf("-step back: ");
			--stack_index;
		}
		else 
			break;
	}
}


void print_graph(struct GraphStruct* graph) {
	for (int i = 0; i < graph->length; ++i) {
		printf("%c, ", graph->nodes[i].label);
	}
	printf("\n");
}

void print_connection(struct GraphStruct* graph) {
	printf("-------------------\n");
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
			else if (graph->connection[i][r] == NOT_CONNECTED)
				printf("%3c", ' ');
			else 
				printf("%3c", '?');
		}
		printf("\n");
	}
	printf("-------------------\n");
}

int main()
{
	struct GraphStruct graph = {
		.nodes = NULL, 
		.connection = NULL, 
		.length = 0};

	new_node(&graph, 'a');
	new_node(&graph, 'b');
	new_node(&graph, 'c');
	new_node(&graph, 'd');
	new_node(&graph, 'e');
	new_node(&graph, 'f');
	new_node(&graph, 'g');
	print_graph(&graph);

	print_connection(&graph);

	new_connection(&graph, 'a', 'b');
	new_connection(&graph, 'b', 'c');
	new_connection(&graph, 'b', 'e');
	new_connection(&graph, 'c', 'd');
	new_connection(&graph, 'c', 'f');
	new_connection(&graph, 'f', 'g');
	print_connection(&graph);

	DFS(&graph);


	// Test dynamic node adding
	new_node(&graph, 'h');
	new_node(&graph, 'i');

	new_connection(&graph, 'g', 'h');
	new_connection(&graph, 'd', 'i');
	print_connection(&graph);

	DFS(&graph);

	return 0;
}