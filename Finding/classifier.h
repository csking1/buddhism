#ifndef CLASSIFIER_H_
#define CLASSIFIER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"
#include "read.h"

typedef struct classifier{
	struct train* quotes;
	struct hash_table* dictionary;
	float class_prob;
	int unigrams;
	int bigrams;

} classifier;

classifier* classifier_init(train* quotes, hash_table* dictionary);

char* get_grams(char* sentence);

float get_score(classifier* clf, char* fragment);

void calculate_probabilities(classifier* clf);

float class_probability(classifier* clf);

#endif /* CLASSIFIER_H_ */