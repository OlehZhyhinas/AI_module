#include "data_store.h"
#include "stdio.h"

Data_Store::Data_Store(){
	size_x=default_map_cols;
	size_y=default_map_rows;
	
	location_values.push_back(size_x/2);
	location_values.push_back(size_y/2);
	
	x_history.push_back(location_values[0]);
	y_history.push_back(location_values[1]);
	
	destination_values.push_back(size_x/4);
	destination_values.push_back(size_y/4);
	
	x_dest_history.push_back(destination_values[0]);
	y_dest_history.push_back(destination_values[1]);
	
	
	initialize_vision();
	initialize_map();
	initialize_points_values();
	
	
	
	
}

void Data_Store::update_map(){
	int x_start=location_values[0]-default_vision_radius-1;
	int y_start=location_values[1]-default_vision_radius-1;
	
	int x_end=location_values[0]+default_vision_radius;
	int y_end=location_values[1]+default_vision_radius;
	
	int x_offset=0;
	int y_offset=0;
	
	if (x_start<=0){
		x_offset=0-x_start;
		x_start=0;
	}
	if (y_start<=0){
		y_offset=0-y_start;
		y_start=0;
	}
	if (x_end>=size_x){
		x_end=size_x;
	}
	if (y_end>=size_y){
		y_end=size_y;
	}
	

	for (int x=x_start, i=0; x<x_end; x++, i++){
		for (int y=y_start, j=0; y<y_end; y++, j++){

			map[x][y]=vision[i+x_offset][j+y_offset];
		}
	}
	
	map[destination_values[0]][destination_values[1]]=kDestination;
	
	print_map();
	
}

void Data_Store::recieve_vision(){
	
	
	/*for (int x=0; x<default_vision_radius*2+1; x++){
		for (int y=0; y<default_vision_radius*2+1; y++){
			if (x==0 || y == 0 || y == default_vision_radius*2 || x==default_vision_radius*2){
				vision[x][y]=kObstacle;
			}
		}
		
	}*/
	
	
	
	update_map();
}

void Data_Store::recieve_location(int x, int y){
	
	location_values[0]=x;
	location_values[1]=y;
	x_history.push_back(x);
	y_history.push_back(y);
	
}

void Data_Store::recieve_destination(int x, int y){
	
	destination_values[0]=x;
	destination_values[1]=y;
	x_dest_history.push_back(x);
	y_dest_history.push_back(y);
	
}


void Data_Store::initialize_map(){
	int x_max;
	int y_max;
	
	
	
	if (size_x != -1){
		x_max=default_map_cols;
	}
	else{
		x_max=size_x;
	}
	
	if (size_y != -1){
		y_max=default_map_rows;
	}
	else{
		y_max=size_y;
	}
	
	for (int x=0; x<x_max; x++){
		map.push_back(std::vector<char> (y_max, kEmpty));
	}
	map[location_values[0]][location_values[1]]=kSelf;
	
	print_map();
}

void Data_Store::initialize_vision(){
	for (int x=0; x<2*default_vision_radius+1; x++){
		vision.push_back(std::vector<char> (default_vision_radius*2+1, kEmpty));
	}
	
	
}

void Data_Store::initialize_points_values(){
	points_values.push_back(std::vector<double> (number_of_points, 0));
	points_values.push_back(std::vector<double> (number_of_points, 0));
	
	points_values[0][0]=(double)kObstacle;
	points_values[0][1]=(double)kEmpty;
	points_values[0][2]=(double)kActor;
	points_values[0][3]=(double)kCollision;
	points_values[0][4]=(double)kSelf;
	points_values[0][5]=(double)kDestination;
	
	//print_points_values();
	
}

void Data_Store::print_points_values(){
	for (int i=0; i<number_of_points;i++){
		printf("%c    ", (char)points_values[0][i]);
	}
	printf("\n");
	for (int i=0; i<number_of_points;i++){
		printf("%2.2lf ", points_values[1][i]);
	}
	printf("\n");
	printf("\n");
	
}

void Data_Store::print_map(){
	for (int y=0; y<size_y; y++){
		for (int x=0; x<size_x; x++){
			printf("%c ",map[x][y]);
			
		}
		printf("\n");
	}
	printf("\n");
	
}
void Data_Store::print_vision(){
	for (int y=0; y<default_vision_radius*2+1; y++){
		for (int x=0; x<default_vision_radius*2+1; x++){
			printf("%c ", vision[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}


