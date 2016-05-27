#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "classifier.h"
#include "hash_tables.h"
#include "read.h"

float class_probability(Classifier* clf){
	float count = 0;
	int l = clf->dictionary->size;
	for (int i = 0; i<l; i++){
		int l = clf->train->labels[i];
		if (l != 1){
			count = count + 1.0;
		}
	}
	return count/l;
}

void get_grams(char* sentences, char* grams[]){
	int count = 0;
	char* words = strtok(sentences, " ");
	while (words != NULL){
		grams[count] = words;
		words = strtok(NULL, " ");
		count ++;
	}
}

Classifier* classifier_init(TrainSet* t, HashTable* h){
	Classifier* clf = (Classifier*)malloc(sizeof(Classifier));
	clf->dictionary =  h;
	clf->train = t;
	for (int i = 0; i<h->size; i++){
		int l = strlen(clf->train->sentences[i]);
		char* grams[l]; /* always greater than number of grams*/
		get_grams(clf->train->sentences[i], grams);
		// call add_to_hash_table(g) for each element in the linked list
	}
	return clf;
}

void calculate_probabilities(Classifier* clf){
	/* walk through the hash map and calculate probabilities
  			{gram: gram_prob, prob_gram_positive}

			P(unigram) :  0 count + 1 count / all_unigrams,
			P(bigram) : 0 count + 1 count / all_bigrams,
			P(unigram|1) : positive count for this unigram / all positive unigrams,
			P(bigram|1) : positive count for this bigram / all positive bigrams}
	*/
	return;
}

float get_score(Classifier* clf, char* fragment){
	//char* grams = get_grams(fragment);

	// for g in grams:
		// numerator = 1 + prob_gram_positive * class_prob

		// denominator = 1 + gram_prob

		// score +=  numerator / denominator
	// score = score / length(grams)

	return 0.0;
}