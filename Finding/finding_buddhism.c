#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"
#include "read.h"

int main(){

	train* quotes = get_train_set();
	print_quotes(quotes);
	
	//free(quotes);  // This causes a crash. Try to put it back in later

	// hash_table table = create_hash_table(152);

	// hand off the quotes to the hash table, which calculates the probabilities as well

	// turn on the threads
		// each thread takes a copy of the classifier 
		// reads in from the randomly-sorted gutenberg files
		// returns the top nodes/10000 quotes

	// write to csv
	return 0;
}