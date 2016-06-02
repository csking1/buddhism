#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"
#include "read.h"
#include "classifier.h"

int main(){
	int range = 7892.0; // size of the training set
	TrainSet* train = get_train_set(range);

	HashTable* table = create_hash_table(range);
	Classifier* clf = classifier_init(train, table);
	walk_through_train(clf, range);
	calculate_probabilities(clf);

	for (int i = 0; i<16; i++){
		char* path = "/home/ec2-user/s3fs-fuse-1.78/gutenberg_text/GutenFiles/file_{}.txt"
		
		// make a list of text files, walk through it
			// create a thread, that takes a gutenchunk and a classifier
			// uses locks to access the classifier 
			// thread gives you back quotes with the highest scores
			// join the threads and write out to csv
	}
	return 0;
}

	//free(quotes);  // This causes a crash. Try to put it back in later, have to free each quote by index


	//  code for testing on the train set, works fine
	// for (int i = 0; i < range; i++){
	// 	if (test->sentences[i] != NULL){
	// 		float score = get_score(clf, test->sentences[i]);
	// 		printf("%f\n", score);
	// 	}
	// }