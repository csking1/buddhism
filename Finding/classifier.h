#ifndef CLASSIFIER_H_
#define CLASSIFIER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"
#include "train.h"

typedef struct Classifier{
	struct TrainSet* train;
	struct HashTable* dictionary;
	struct StopWords* stop;
	float class_prob;
	int all_unigrams;
	int all_bigrams;
	int positive_unigrams;
	int positive_bigrams;
} Classifier;

Classifier* classifier_init(TrainSet* t, HashTable* h);

double get_grams(char* sentence, char* grams[]);

void calculate_probabilities(Classifier* clf);

float get_score(Classifier* clf, char* fragment);

void walk_through_train(Classifier *clf, int range);

#endif /* CLASSIFIER_H_ */