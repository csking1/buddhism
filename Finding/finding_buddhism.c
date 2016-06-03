#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"
#include "train.h"
#include "classifier.h"
#include "thread.h"


char* get_path(int i, char* path){
	char index[10];
	sprintf(index, "%d", i);
	char* rt[250];
	strcpy(rt, path);
	strcat(rt, index);
	strcat(rt, ".txt");
	return rt;
}

// char* path = "Data/file_1.txt";

int main(){

	int range = 7892.0; // size of the training set
	int size = 121555; // relative size of testing files

	TrainSet* train = get_train_set(range);
	HashTable* table = create_hash_table(range);
	Classifier* clf = classifier_init(train, table);
	walk_through_train(clf, range);
	calculate_probabilities(clf);

	for (int i = 1; i< 17; i++){
		char* path = get_path(i, "/home/ec2-user/s3fs-fuse-1.78/gutenberg_text/GutenFiles/file_");
		Thread *t = initialize_thread(path, clf, size);
		char* outpath = get_path(i, "Output/file_");
		write_quotes(outpath, t);
	}
return 0;
}

