#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"
#include "read.h"
#include "classifier.h"

// add in removal of stopwords

// this whole function should take the size of the training set

int main(){
	train* quotes = get_train_set();
	hash_table* table = create_hash_table(152);
	classifier* clf = classifier_init(quotes, table);
	calculate_probabilities(clf);

	// turn on the threads
		// each thread takes a copy of the classifier
		// reads in from the randomly-sorted gutenberg files
		// returns the top nodes/10000 quotes

	// write to csv

	return 0;
}

	//free(quotes);  // This causes a crash. Try to put it back in later, have to free each quote by index