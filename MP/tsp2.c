// Compile with -lm flag b/c of math.h: gcc ./tsp.c -o tsp -lm
#include <stdio.h>
#include <stdlib.h>
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

struct Vertex {
	int index_1;
	int index_2;
	double dist;
};

void swap(struct Vertex* v1, struct Vertex* v2) {
	struct Vertex* v_temp = v1;
	v1 = v2;
	v2 = v_temp;
}

void bubble_sort(struct Vertex* vertex_list[], int length) {
	int i, j, i_temp;
	struct Vertex* v_temp;

	for (i = 0; i < length-1; ++i) {
		for (j = 0; j < length-i-1; ++j) {
			if (vertex_list[j+1].dist < vertex_list[j].dist) {
				swap(&(vertex_list[j+1]), &(vertex_list[j]));
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
			current_city[center_index].x, 
			current_city[center_index].y,
			city_list[i].x, 
			city_list[i].y);
	}

	return dist_list;
}

double TSP(struct City* city_list, int num_city) {
	int i, j;
	struct Vertex* vertex_list = (struct Vertex*) 
		malloc(sizeof(struct Vertex) * num_city * num_city);
	double* dist_list;

	// Find the vertex of each pair
	for (i = 0; i < num_city; ++i) {
		dist_list = find_distance(city_list, num_city, i);
		for (j = 0; j < num_city; ++j) {
			vertex_list[i*num_city+j].index_1 = i; 
			vertex_list[i*num_city+j].index_2 = j;
			vertex_list[i*num_city+j].dist = dist_list[j];
		}
	}

	// Sort the vertex_list
	bubble_sort(vertex_list, num_city);

	for (i = 0; i < num_city; ++i)
		for (j = 0; j < num_city; ++j)
			printf("%3d %3d: %3lf", vertex_list)
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
  		city_list[index].index = temp_city.index;
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
