#include "data_store.h"
#include "results.h"
#include "mod_master.h"
#include "evaluation.h"
#include "stdio.h"



int main (void){

	Data_Store d;
	Results r(&d);
	Mod_Master m(&d);
	Evaluation e(&d);
	
	
	
	
	return 0;
}