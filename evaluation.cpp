#include "evaluation.h"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"


Evaluation::Evaluation(Data_Store* d_pointer){
	d=d_pointer;
	best_target.push_back(0);
	best_target.push_back(0);
	shortest_path_next.push_back(0);
	shortest_path_next.push_back(0);
}



void Evaluation::next_move(){
	double max= -1000000000;
	double min=  1000000000;
	
	double range=0;
	int selection;
	
	std::vector<double> probabilities (4,0);
	
	
	for (int x=0; x<d->size_x; x++){
		for (int y=0; y<d->size_y; y++){
			if (d->location_attractivness[x][y]>=max && d->location_attractivness[x][y]!=0){//most attractive location
				max=d->location_attractivness[x][y];
				best_target[0]=x;
				best_target[1]=y;
			}
			if (d->location_attractivness[x][y]<=min && d->location_attractivness[x][y]!=0){//least attractive location
				min=d->location_attractivness[x][y];

			}
		}
	}
	
	range=max-min;
	
	shortest_path();
	direction=UP;
	
	
	if (d->location_values[0]>0){
		probabilities[LEFT]=range+d->location_attractivness[d->location_values[0]-1][d->location_values[1]];
	}
	if (d->location_values[0]<d->size_x-1){
		probabilities[RIGHT]=range+d->location_attractivness[d->location_values[0]+1][d->location_values[1]];
	}
	if (d->location_values[1]>0){
		probabilities[UP]=range+d->location_attractivness[d->location_values[0]][d->location_values[1]-1];
	}
	if (d->location_values[1]<d->size_y-1){
		probabilities[DOWN]=range+d->location_attractivness[d->location_values[0]][d->location_values[1]+1];
	}
	

	probabilities[direction]=range+max;
	
	range=probabilities[0]+probabilities[1]+probabilities[2]+probabilities[3];
	
	selection = rand() % (int)range;
	
	
	if (selection<probabilities[UP]){
		direction=UP;
		d->next_move[0]=d->location_values[0];
		d->next_move[1]=d->location_values[1]-1;
	}
	else if(selection<probabilities[UP]+probabilities[RIGHT]){
		direction=RIGHT;
		d->next_move[0]=d->location_values[0]+1;
		d->next_move[1]=d->location_values[1];
	}
	else if(selection<probabilities[UP]+probabilities[RIGHT]+probabilities[DOWN]){
		direction=DOWN;
		d->next_move[0]=d->location_values[0];
		d->next_move[1]=d->location_values[1]+1;
	}
	else {
		direction=LEFT;
		d->next_move[0]=d->location_values[0]-1;
		d->next_move[1]=d->location_values[1];
	}
	printf("next_move x: %d, y: %d\n", d->next_move[0], d->next_move[1]);
	
}

void Evaluation::shortest_path(){
	std::vector< std::vector <double>  > map_copy;
	for (int i=0; i<d->size_x; i++){
		map_copy.push_back(std::vector<double> (d->size_y,0));
	}
	
	for (int x=0; x<d->size_x; x++){
		for (int y=0; y<d->size_y; y++){
			if (d->location_attractivness[x][y]>=0){
				map_copy[x][y]=0;
			}
			else{
				map_copy[x][y]=-1;
			}
		}
	}
	
	map_copy[best_target[0]][best_target[1]]=1;
	map_copy[d->location_values[0]][d->location_values[1]]=0;
	
	
	
	while (map_copy[d->location_values[0]][d->location_values[1]]==0){
		for (int x=1; x<d->size_x-1; x++){
			for (int y=1; y<d->size_y-1; y++){
				if (map_copy[x][y]>0){
					if (map_copy[x-1][y]>map_copy[x][y]+1 || map_copy[x-1][y] == 0){
						map_copy[x-1][y]=map_copy[x][y]+1;
					}
					if (map_copy[x+1][y]>map_copy[x][y]+1 || map_copy[x+1][y] == 0){
						map_copy[x+1][y]=map_copy[x][y]+1;
					}
					if (map_copy[x][y-1]>map_copy[x][y]+1 || map_copy[x][y-1] == 0){
						map_copy[x][y-1]=map_copy[x][y]+1;
					}
					if (map_copy[x][y+1]>map_copy[x][y]+1 || map_copy[x][y+1] == 0){
						map_copy[x][y+1]=map_copy[x][y]+1;
					}
					
					
				}
			}	
		}	
	}
	
	int min=100000;
	if (d->location_values[0]>0){
		if (map_copy[d->location_values[0]-1][d->location_values[1]] < min && map_copy[d->location_values[0]+1][d->location_values[1]] > 0){
			min = map_copy[d->location_values[0]-1][d->location_values[1]];
			shortest_path_next[0]=d->location_values[0]-1;
			shortest_path_next[1]=d->location_values[1];
			direction=LEFT;
		}
	}
	
	if (d->location_values[0]<d->size_x-1){
		if (map_copy[d->location_values[0]+1][d->location_values[1]]<min && map_copy[d->location_values[0]+1][d->location_values[1]] > 0){
			min = map_copy[d->location_values[0]+1][d->location_values[1]];
			shortest_path_next[0]=d->location_values[0]+1;
			shortest_path_next[1]=d->location_values[1];
			direction=RIGHT;
		}
	}
	
	
	if (d->location_values[1]>0){
		if (map_copy[d->location_values[0]][d->location_values[1]-1]<min && map_copy[d->location_values[0]][d->location_values[1]-1] > 0){
			min = map_copy[d->location_values[0]][d->location_values[1]-1];
			shortest_path_next[0]=d->location_values[0];
			shortest_path_next[1]=d->location_values[1]-1;
			direction=DOWN;
		}
	}
	
	
	if (d->location_values[1]<d->size_y-1){
		if (map_copy[d->location_values[0]][d->location_values[1]+1]<min && map_copy[d->location_values[0]][d->location_values[1]+1] > 0){
			min = map_copy[d->location_values[0]][d->location_values[1]+1];
			shortest_path_next[0]=d->location_values[0];
			shortest_path_next[1]=d->location_values[1]+1;
			direction=UP;
		}
	}
	printf("direction: %d\n", direction);
}

