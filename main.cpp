#include "data_store.h"
#include "results.h"
#include "stdio.h"



int main (void){

	Data_Store d;
	Results r(&d);
	
	d.recieve_location(20,20);
	d.recieve_destination(10,10);
	char vision_array[]={kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, 
						 kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle,
						 kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle,
						 kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle,
						 kObstacle, kObstacle, kObstacle, kObstacle, kEmpty, kEmpty, kEmpty, kObstacle, kObstacle, kObstacle, kObstacle,
						 kObstacle, kObstacle, kObstacle, kObstacle, kEmpty, kEmpty, kEmpty, kObstacle, kObstacle, kObstacle, kObstacle,
						 kObstacle, kObstacle, kObstacle, kObstacle, kEmpty, kEmpty, kEmpty, kObstacle, kObstacle, kObstacle, kObstacle,
						 kObstacle, kObstacle, kObstacle, kObstacle, kEmpty, kEmpty, kEmpty, kObstacle, kObstacle, kObstacle, kObstacle,
						 kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle,
						 kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle,
						 kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle, kObstacle
						};
	
	d.recieve_vision(vision_array);
	d.recieve_location(19,19);
	d.print_map();
	printf("%lf\n", r.calculate_score());
	
	d.recieve_location(18,18);
	d.print_map();
	printf("%lf\n", r.calculate_score());
	
	d.recieve_location(17,17);
	char vision_array2[] ={kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, 
						 kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty,
						 kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty,
						 kEmpty, kEmpty, kEmpty, kEmpty, kObstacle, kObstacle, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty,
						 kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kObstacle, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty,
						 kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kCollision, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty,
						 kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty,
						 kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty,
						 kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty,
						 kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty,
						 kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty, kEmpty
						};
	//d.print_map();
	d.recieve_vision(vision_array2);
	
	printf("%lf\n", r.calculate_score());
	
	//printf("%lf \n",r.calculate_distance(0,0, 5,5));
	
	
	return 0;
}