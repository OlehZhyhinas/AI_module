#include "AI.h"


#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>

#define dimensions 40

std::vector< std::vector<char> > field;
std::vector<int> number_of_moves;
std::vector<int> number_of_collisions;
char vision_array[(default_vision_radius*2+1)*(default_vision_radius*2+1)];

void update_vision(int x, int y){
	
	int x_start=x-default_vision_radius;
	int y_start=y-default_vision_radius;
	
	int vision_x=0;
	int vision_y=0;	
	
	for (vision_x=0; vision_x<default_vision_radius*2+1; vision_x++){
		for (vision_y=0; vision_y<default_vision_radius*2+1; vision_y++){
			if (x_start+vision_x >=0 && x_start+vision_x < dimensions 
			&& y_start+vision_y >=0 && y_start+vision_y < dimensions){
				vision_array[vision_x+vision_y*(default_vision_radius*2+1)]=
					field[x_start+vision_x][y_start+vision_y];
			
			} 
			else{
				vision_array[vision_x+vision_y*(default_vision_radius*2+1)]=kObstacle;
			}			


		}
	}
	if (field[x][y]==kObstacle){
		vision_array[(default_vision_radius*2 +1)*(default_vision_radius*2 +1) /2 ]=kCollision;
		number_of_collisions[number_of_collisions.size()-1]++;
	}

	/*for (vision_x=0; vision_x<default_vision_radius*2+1; vision_x++){
		for (vision_y=0; vision_y<default_vision_radius*2+1; vision_y++){
			printf("%c ", vision_array[vision_x+vision_y*(default_vision_radius*2+1)]);			


		}
		printf("\n");
	}*/
}
int main (void){
	srand (time(NULL));
	/*Data_Store d;
	Results r(&d);
	Mod_Master m(&d);
	Evaluation e(&d);
	
	for (int i=0; i<default_map_rows; i++){
		field.push_back(std::vector<char> (default_map_cols, kEmpty));
	}
	
	d.recieve_location(rand()%default_map_rows, rand()%default_map_cols);
	d.recieve_location(rand()%default_map_rows, rand()%default_map_cols);
	d.recieve_destination(rand()%default_map_rows, rand()%default_map_cols);
	d.print_map();
	
	for (int i=0; i<1000; i++){
		update_vision(d.location_values[0], d.location_values[1]);
		d.recieve_vision(vision_array);
		r.calculate_score();
		m.calculate_all_attractivness();
		d.print_location_attractivness();
		e.next_move();
		d.recieve_location(d.next_move[0], d.next_move[1]);
	}
	
	
	
	
	return 0;*/
	

	for (int i=0; i<dimensions; i++){
		field.push_back(std::vector<char> (dimensions, kEmpty));
	}

	for (int x=0; x<dimensions; x++){
		for (int y =0; y<dimensions; y++){
			if (rand()%100>80){
				field[x][y]=kObstacle;
			}
		}
	}

	/*AI a;
	a.initialize_data_store(dimensions,dimensions,0,0,5);
	a.initialize_results();
	a.initialize_mod_master();
	a.initialize_evaluation();
	a.launch_window();
	
	a.set_destination(10, 35);
	a.set_location(5, 5);
	
	usleep(3000000);
	for (int i =0; i>-1; i++){
 		usleep(300000); //sleep for 1 ms
		
		update_vision(a.d->location_values[0], a.d->location_values[1]);
		a.set_vision_data(vision_array);
		a.get_move();
		a.set_location(a.d->next_move[0], a.d->next_move[1]);
		//printf("location x: %d y: %d\n", a.d->location_values[0], a.d->location_values[1]);
		
		
		
		a.show_field();
		a.show_vision();
		

	}*/


	/*for (int i=0; i<10; i++){
		AI a;
		a.initialize_data_store(dimensions,dimensions,0,0,5);
		a.initialize_results();
		a.initialize_mod_master();
		a.initialize_evaluation();
		a.launch_window();
		
		a.set_destination(rand()%(dimensions-5)+2, rand()%(dimensions-5)+2);
		a.set_location(rand()%(dimensions-5)+2, rand()%(dimensions-5)+2);
		printf("running AI # %d\n", i);
		number_of_moves.push_back(0);
		number_of_collisions.push_back(0);
		while (a.d->location_values[0] != a.d->destination_values[0] || a.d->location_values[1] != a.d->destination_values[1]){
			update_vision(a.d->location_values[0], a.d->location_values[1]);
			a.set_vision_data(vision_array);
			a.get_move();
			a.set_location(a.d->next_move[0], a.d->next_move[1]);
			a.show_field();
			a.show_vision();
			number_of_moves[number_of_moves.size()-1]++;	

		}
		printf("it took %d moves\n", number_of_moves[number_of_moves.size()-1]);
		printf("there were %d collisions\n", number_of_collisions[number_of_collisions.size()-1]);
		a.d->print_points_values();
		a.~AI();
		
		
	}*/
	for (int i=0; i<10; i++){
		AI a;
		a.initialize_data_store(dimensions,dimensions,0,0,5);
		a.initialize_results();
		a.initialize_mod_master();
		a.initialize_evaluation();
		a.launch_window();
		a.set_points_values(-1,0,1);
		a.set_destination(rand()%(dimensions-5)+2, rand()%(dimensions-5)+2);
		a.set_location(rand()%(dimensions-5)+2, rand()%(dimensions-5)+2);
		printf("running AI # %d\n", i);
		
		number_of_moves.push_back(0);
		number_of_collisions.push_back(0);
		while (a.d->location_values[0] != a.d->destination_values[0] || a.d->location_values[1] != a.d->destination_values[1]){
			update_vision(a.d->location_values[0], a.d->location_values[1]);
			a.set_vision_data(vision_array);
			a.get_move();
			a.set_location(a.d->next_move[0], a.d->next_move[1]);
			a.show_field();
			a.show_vision();
			number_of_moves[number_of_moves.size()-1]++;	

		}
		printf("it took %d moves\n", number_of_moves[number_of_moves.size()-1]);
		printf("there were %d collisions\n", number_of_collisions[number_of_collisions.size()-1]);
		a.d->print_points_values();
		a.~AI();
		
		
	}
	return 0;
}





