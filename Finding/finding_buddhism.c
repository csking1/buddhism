#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"
#include "read.h"
#include "classifier.h"


float GROWTH_RATIO = 5;

// add in removal of stopwords

// this whole function should take the size of the training set

int main(){
	TrainSet* set = get_train_set();
	HashTable* table = create_hash_table(152); /*this breaks at any size around 200 or larger */
	add_string(table, "adding this string", 0);
	// lookup_string(table, "adding this string");
	// printf("%d\n", table->new_grams_count);

	Classifier* clf = classifier_init(set, table);

	// walks through the hash table and calculate probabilities
	calculate_probabilities(clf);

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