#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"
#include "read.h"
#include "classifier.h"

// add in removal of stopwords

// this whole function should take the size of the training set

int main(){
	TrainSet* set = get_train_set();
	HashTable* table = create_hash_table(1); /*this breaks at any size around 200 or larger */

	add_string(table, "a", 0);
	add_string(table, "b", 0);
	add_string(table, "c", 0);
	add_string(table, "d", 0);
	add_string(table, "e", 0);
	add_string(table, "f", 0);
	add_string(table, "g", 0);
	add_string(table, "h", 0);
	add_string(table, "i", 0);
	add_string(table, "j", 0);
	add_string(table, "k", 0);
	add_string(table, "l", 0);
	add_string(table, "m", 0);
	add_string(table, "n", 0);
	add_string(table, "o", 0);
	LinkedList* got = lookup_string(table, "o");
	printf("%s\n", got->string);
	got = lookup_string(table, "a");
	printf("%s\n", got->string);

	Classifier* clf = classifier_init(set, table);

	// calculate_probabilities(clf);

	for (int i = 0; i<16; i++){
		// get a chunk from gutenberg
		// create a classifier
		// create a thread, that takes a gutenchunk and a classifier
		// thread gives you back 10000/16 quotes with the highest score
		// write out the highest scores to the csv
	}
	return 0;
}

	//free(quotes);  // This causes a crash. Try to put it back in later, have to free each quote by index