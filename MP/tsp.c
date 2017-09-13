// Compile with -lm flag b/c of math.h: gcc ./tsp.c -o tsp -lm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define VERBOSE
#define DEBUG

#define BOOL int
#define TRUE 1
#define FALSE 0

struct City {
	int index;
	int x;
	int y;
	BOOL visited;
};

struct Edge {
	int index_1;
	int index_2;
	double dist;
};

void swap(struct Edge* v1, struct Edge* v2) {
	struct Edge v_temp = *v1;
	*v1 = *v2;
	*v2 = v_temp;
}

void bubble_sort(struct Edge* edge_list, int length) {
	int i, j, i_temp;
	struct Edge* v_temp;

	for (i = 0; i < length-1; ++i) {
		for (j = 0; j < length-i-1; ++j) {
			if (edge_list[j+1].dist < edge_list[j].dist) {
				swap(&(edge_list[j+1]), &(edge_list[j]));
			}
		}
	}

}


double distance(int x1, int y1, int x2, int y2) {
	return sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
}

double* find_distance(struct City* city_list, int num_city, int center_index) {
	// Remember to free the malloc
	double* dist_list = (double *) malloc(sizeof(double) * num_city);
	int i;
	for (i = 0; i < num_city; ++i) {
		dist_list[i] = distance(
			city_list[center_index].x, 
			city_list[center_index].y,
			city_list[i].x, 
			city_list[i].y);
	}

	return dist_list;
}

double TSP(struct City* city_list, int num_city) {
	int i, j;
	int num_edge = num_city * num_city;
	
	struct Edge* edge_list = (struct Edge*) malloc(sizeof(struct Edge) * num_edge);	
	struct Edge** sel_edge_list = (struct Edge*) malloc(sizeof(struct Edge*));

	int* order_list = (int*) malloc(sizeof(int) * num_city);	
	int* answer_list = (int*) malloc(sizeof(int) * num_city);

	memset(order, 0, sizeof(int) * num_city);

	// Find the vertex of each pair
	double* dist_list;
	for (i = 0; i < num_city; ++i) {
		dist_list = find_distance(city_list, num_city, i);
		for (j = 0; j < num_city; ++j) {
			edge_list[i*num_city+j].index_1 = i; 
			edge_list[i*num_city+j].index_2 = j;
			edge_list[i*num_city+j].dist = dist_list[j];
		}
	}

	// Sort the edge_list
	bubble_sort(edge_list, num_city);

	#ifdef DEBUG
	for (i = 0; i < num_city; ++i)
		for (j = 0; j < num_city; ++j)
			printf("%3d %3d: %3lf\n", 
				edge_list[i*num_city+j].index_1,
				edge_list[i*num_city+j].index_2,
				edge_list[i*num_city+j].dist);
	#endif

	int edge_index;
	int edge_count = 0;
	struct Edge* current_edge = edge_list[0];
	
	for (int i = 0; i < num_edge; ++i){
		sel_edge_list[edge_count] = current_edge;

		if (edge_count[edge_list[i].index_1] <= 2 &&
			edge_count[edge_list[i].index_2] <= 2 &&
			)
	}

	while (edge_count < num_city) {
		
		++edge_count;

		// Check vertex degree

		
		


		// Check edge loop

	}


}


int main(int argc, char const *argv[])
{
	FILE* pInput;
	struct City* city_list;
	struct City temp_city;
	int num_city;
	int i;


  	pInput = fopen (argv[1],"r");	
  	fscanf(pInput, "%d", &num_city);

  	city_list = (struct City*) malloc(sizeof(struct City) * num_city);
  	
  	int index = 0;
  	while(fscanf(pInput, "%d %d %d", 
  		&(temp_city.index), 
  		&(temp_city.x), 
  		&(temp_city.y)) != EOF) 
  	{
  		printf("%3d %3d %3d\n", temp_city.index, temp_city.x, temp_city.y);
  		city_list[index].index = temp_city.index - 1;
  		city_list[index].x = temp_city.x;
  		city_list[index].y = temp_city.y; 		
  		city_list[index].visited = FALSE;

  		if (++index > num_city) 
  			printf("WTF");
  	}

  	double dist = TSP(city_list, num_city);
  	printf("%lf\n", dist);

	return 0;
}
