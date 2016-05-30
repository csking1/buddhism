#ifndef CLASSIFIER_H_
#define CLASSIFIER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"
#include "read.h"

typedef struct Classifier{
	struct TrainSet* train;
	struct HashTable* dictionary;
	float class_prob;
	int all_unigrams;
	int all_bigrams;
	int positive_unigrams;
	int positive_bigrams;
} Classifier;

Classifier* classifier_init(TrainSet* t, HashTable* h);

void get_grams(char* sentence, char* grams[]);

void calculate_probabilities(Classifier* clf);

float get_score(Classifier* clf, char* fragment);

#endif /* CLASSIFIER_H_ */