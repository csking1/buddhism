#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"
#include "read.h"
#include "classifier.h"

// add in removal of stopwords

int main(){
	int range = 152; // size of the training set
	TrainSet* set = get_train_set();
	for (int i = 0; i < range; i++){
		printf("%d\n", set->labels[i]);
	}
	HashTable* table = create_hash_table(range);
	Classifier* clf = classifier_init(set, table);
	walk_through_train(clf, range);
	calculate_probabilities(clf);

	for (int i = 0; i < range; i++){
		float score = get_score(clf, set->sentences[i]);
		printf("%d\n", i);
	}
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