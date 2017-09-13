#include <stdio.h>
#include <stdlib.h>

struct City {
	int index;
	int x;
	int y;
};


int main(int argc, char const *argv[])
{
	FILE* pInput;
	City* city_list;
	City temp_city;
	int num_city;


  	pInput = fopen (argv[1],"r");	
  	fscanf(pFile, "%d", &num_city);

  	city_list = (struct City*) malloc(sizeof(struct City) * num_city);
  	
  	int index = 0;
  	while(scanf("%d %d %d", 
  		&(temp_city.index), 
  		&(temp_city.x), 
  		&(temp_city.y)) == 1) 
  	{
  		city_list[index].index = temp_city.index;
  		city_list[index].x = temp_city.x;
  		city_list[index].y = temp_city.y; 		

  		if (++index > num_city) 
  			printf("WTF");
  	}

  	for (int i = 0; i < num_city; ++i) {
  		printf("%d %d %d\n", city_list[index].index, city_list[index].x, city_list[index].y);
  	}


	return 0;
}
