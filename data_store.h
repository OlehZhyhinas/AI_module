#ifndef DATA_STORE_H
#define DATA_STORE_H

#include <vector>

class Data_Store {
	private :
		
		//constants 
		const static char kObstacle        = 'O';
		const static char kEmpty           = 'E';
		const static char kActor           = 'A';
		const static char kCollision       = 'C';
		const static int default_map_cols = 300;
		const static int default_map_rows = 300;
		const static int default_vision_radius = 30;
		const static int default_actor_half_rows = 5;
		const static int default_actor_half_cols = 5;
		
		
		//data stored
		std::vector< std:: vector <char> > vision; //latest vision data
		std::vector< std:: vector <char> > map;  //x by y sized grid of chars, of the most up to date map information
		std::vector< std:: vector <char> > diffs; // a list of diffs in the form of x location, y location, character

		
		std::vector<int> x_history; //x history, including current position
		std::vector<int> y_history; //y history, including current position
		
	
		

		//methods
		void generate_new_diff(std::vector< std:: vector <char> > new_map); // generate a new diff vector, push it to the top of diffs
		

	public:
		void recieveVision(); //recieves the most recent vision data from the server
		void update_map(); //creates a new map from the composition of map and vision, generates new diff, and replaces map with update_map
		void recieve_location(); // recieve current location and update x and y history




}
#endif /*DATA_STORE_H*/