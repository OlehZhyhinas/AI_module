#ifndef DATA_STORE_H
#define DATA_STORE_H

#include <vector>

		const static char kObstacle        = 'O';
		const static char kEmpty           = 'E';
		const static char kActor           = 'A';
		const static char kCollision       = 'C';
		const static char kSelf            = 'M';
		const static char kDestination     = 'D';
		const static int number_of_points  = 6;
		const static int default_map_cols = 40;
		const static int default_map_rows = 40;
		const static int default_vision_radius = 5;
		const static int default_actor_half_rows = 1;
		const static int default_actor_half_cols = 1;

class Data_Store {
	public :
		
		//constants 

		
		
		//data stored
		std::vector< std:: vector <char> > vision; //latest vision data
		std::vector< std:: vector <char> > map;  //x by y sized grid of chars, of the most up to date map information
		std::vector< std:: vector <char> > diffs; // a list of diffs in the form of x location, y location, character

		std::vector< std:: vector <double> > points_values;  //the value of each class of points on the map
		
		std::vector<int> location_values; //x and y location
		std::vector<int> x_history; //x history, including current position
		std::vector<int> y_history; //y history, including current position
		
		std::vector<int> destination_values; //x and y of destination
		std::vector<int> x_dest_history; //x destination history
		std::vector<int> y_dest_history; //y destination history
		
		
		
		int size_x;
		int size_y;
		
		

		//methods
		Data_Store();
		void initialize_map();
		void initialize_vision();
		void initialize_points_values();
		
		void generate_new_diff(std::vector< std:: vector <char> > old_map);
		
		
		void recieve_vision(); //recieves the most recent vision data from the server
		void update_map(); //creates a new map from the composition of map and vision, generates new diff, and replaces map with update_map
		void recieve_location(int x, int y); // recieve current location and update x and y history
		void recieve_destination(int x, int y);
		
		
		void print_map();
		void print_vision();
		void print_points_values();
		




};
#endif /*DATA_STORE_H*/