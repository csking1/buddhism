#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"
#include "read.h"
#include "classifier.h"
#include "thread.h"

int main(){
	int range = 7892.0; // size of the training set
	int size = 121555; // relative size of testing files

	TrainSet* train = get_train_set(range);
	HashTable* table = create_hash_table(range);
	Classifier* clf = classifier_init(train, table);
	walk_through_train(clf, range);
	calculate_probabilities(clf);

	for (int i = 0; i<16; i++){
		// char* path = "/home/ec2-user/s3fs-fuse-1.78/gutenberg_text/GutenFiles/file_{}.txt"
		char* path = "Data/file_1.txt";

		Thread *t = initialize_thread(path, clf, size);


	}
	return 0;
}

