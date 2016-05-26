#include <stdlib.h>
#include <stdio.h>
#include "classifier.h"
#include "hash_tables.h"
#include "read.h"

char* get_grams(char* sentences){
	return "this isn't the actual answer";
}

float class_probability(classifier* clf){
	// P(1) : number of postive quotes / length(Y)
	return 0.0;
}

classifier* classifier_init(train* quotes, hash_table* hash_table){
	classifier* clf = (classifier*)malloc(sizeof(classifier));
	clf-> class_prob = class_probability(clf);


	/* 152 is the size of the training set*/
	for (int i = 0; i<152; i++){
		//int l = quotes->labels[i];
		//char* grams = get_grams(quotes->sentences[i]);
		// walk through grams, add to hash table
		// increment unigrams and bigrams
	}

	return clf;
}

void calculate_probabilities(classifier* clf){
	/* walk through the hash map and calculate probabilities
  			{gram: gram_prob, prob_gram_positive}

			P(unigram) :  0 count + 1 count / all_unigrams,
			P(bigram) : 0 count + 1 count / all_bigrams,
			P(unigram|1) : positive count for this unigram / all positive unigrams,
			P(bigram|1) : positive count for this bigram / all positive bigrams}
	*/
	return;
}

float get_score(classifier* clf, char* fragment){
	//char* grams = get_grams(fragment);

	// for g in grams:
		// numerator = 1 + prob_gram_positive * class_prob

		// denominator = 1 + gram_prob

		// score +=  numerator / denominator
	// score = score / length(grams)

	return 0.0;
}

