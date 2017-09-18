#include <stdio.h>

#define MAX_NODE 10
#define TRUE 1
#define FALSE 0

struct Queue {
	char buffer[MAX_NODE];
	int head;
	int end;
};

char queue_pop(struct Queue* queue) {
	int old_head = queue->head;
	queue->head = (queue->head + 1) % MAX_NODE;
	return queue->buffer[old_head];
}

void queue_push(struct Queue* queue, char label) {
	queue->buffer[queue->end] = label;
	queue->end = (queue->end + 1) % MAX_NODE;
}

void print_queue(struct Queue* queue) {
	for (int i = 0; i < MAX_NODE; ++i) {
		printf("%3c", queue->buffer[i]);
	}
	printf("\n");

	for (int i = 0; i < MAX_NODE; ++i) {
		if (i == queue->head)
			printf("%3c", 'H');
		else if (i == queue->end)
			printf("%3c", 'E');
		else 
			printf("%3c", ' ');
	}
	printf("\n");
}

void queue_test(struct Queue* queue) {
	queue_push(queue, 'a');
	queue_push(queue, 'b');
	queue_push(queue, 'c');
	queue_push(queue, 'd');
	queue_push(queue, 'e');
	queue_push(queue, 'f');
	queue_push(queue, 'g');
	queue_push(queue, 'h');
	queue_push(queue, 'i');

	print_queue(queue);

	printf("popped %3c\n", queue_pop(queue));
	print_queue(queue);
	printf("popped %3c\n", queue_pop(queue));
	print_queue(queue);
	printf("popped %3c\n", queue_pop(queue));

}

void new_node(char stack[], int *length, char label) {
	stack[*length] = label;
	++(*length);
}

int find_label_index(char stack[], int length, char label) {
	for (int i = 0; i < length; ++i) {
		if (stack[i] == label) {
			return i;
		}
	}

	return -1;
}

void new_connection(
	char stack[], 
	int connection[MAX_NODE][MAX_NODE], 
	int length, 
	char label_1, 
	char label_2) 
{
	int index_1 = find_label_index(stack, length, label_1);
	int index_2 = find_label_index(stack, length, label_2);

	if (index_1 == -1 || index_2 == -1) {
		printf("- Label does not exist\n");
		return;
	}

	connection[index_1][index_2] = 
		connection[index_2][index_1] = TRUE;
}

void print_stack(char stack[], int length) {
	for (int i = 0; i < length; ++i) 
		printf("%c, ", stack[i]);
	printf("\n");
}

void print_connection(char stack[], int connection[MAX_NODE][MAX_NODE], int length) {
	printf("%3c", ' ');
	for (int i = 0; i < length; ++i)
		printf("%3c", stack[i]);
	printf("\n");

	for (int i = 0; i < length; ++i) {
		printf("%3c", stack[i]);
		for (int r = 0; r < length; ++r) {
			printf("%3c", connection[i][r] == TRUE? '-' : ' ');
		}
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	struct Queue queue = { .buffer = {'\0'}, .head = 0, .end = 0 };
	char stack[MAX_NODE] = {'\0'};
	int connection[MAX_NODE][MAX_NODE] = {FALSE};
	int length = 0;

	//queue_test(&queue);

	new_node(stack, &length, 'a');
	new_node(stack, &length, 'b');
	new_node(stack, &length, 'c');
	new_node(stack, &length, 'd');
	new_node(stack, &length, 'e');
	new_node(stack, &length, 'f');
	new_node(stack, &length, 'g');
	print_stack(stack, length);

a
b
c
d e f
g 

a b c d e f
a b c d e
a b c d g


	new_connection(stack, connection, length, 'a', 'b');
	new_connection(stack, connection, length, 'b', 'c');
	new_connection(stack, connection, length, 'c', 'd');
	new_connection(stack, connection, length, 'c', 'e');
	new_connection(stack, connection, length, 'e', 'f');
	new_connection(stack, connection, length, 'd', 'g');
	print_connection(stack, connection, length);

	return 0;
}