#include "data_store.h"
#include "results.h"
#include "mod_master.h"
#include "evaluation.h"
#include "stdio.h"
#include "stdlib.h"

std::vector< std::vector<char> > field;

char vision_array[(default_vision_radius*2+1)*(default_vision_radius*2+1)];

void update_vision(int x, int y){
	for (int i=0; i<(default_vision_radius*2+1)*(default_vision_radius*2+1); i++){
		int vision_x=i%(default_vision_radius*2+1);
		int vision_y=i/(default_vision_radius*2+1);
		
		int field_x = x+vision_x-default_vision_radius;
		int field_y = y+vision_y-default_vision_radius;
		
		if (field_x<0 || field_x>default_map_rows-2 || field_y<0 || field_y>default_map_cols-2){
			vision_array[i]=kObstacle;
		}
		else{
			vision_array[i] = field[field_x][field_y];
		}
		
	}
}
int main (void){

	Data_Store d;
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
	
	
	
	
	return 0;
}





