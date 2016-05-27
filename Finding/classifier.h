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
	int unigrams;
	int bigrams;

} Classifier;

Classifier* classifier_init(TrainSet* t, HashTable* h);

char* get_grams(char* sentence);

float get_score(Classifier* clf, char* fragment);

void calculate_probabilities(Classifier* clf);

float class_probability(Classifier* clf);

#endif /* CLASSIFIER_H_ */