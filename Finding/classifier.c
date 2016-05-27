#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "classifier.h"
#include "hash_tables.h"
#include "read.h"

// set the order of the bigrams by alphabetical

char* get_grams(char* sentences){
	int l = strlen(sentences);
	// printf("%s\n",sentences );

	// links* intermediate;
	// links* resolve;

	for (int i = 0; i < l; i++){
		
		// char letter = sentences[i];
		// printf("%s\n", letter);
		printf("%s\n", &sentences[i]);
	}

	// this will return a linked list
	return "this is a string I swear";
}

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

Classifier* classifier_init(TrainSet* t, HashTable* h){
	Classifier* clf = (Classifier*)malloc(sizeof(Classifier));
	clf->dictionary =  h;
	clf->train = t;

	for (int i = 0; i<h->size; i++){
		// printf("%s\n", clf->quotes[i]);
		// get grams will return a linked list
		// walk through the linked list
		// call add_to_hash_table(g)
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