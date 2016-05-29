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
	clf->class_prob = class_probability(clf);
	clf->all_unigrams = 0;
	clf->positive_unigrams = 0;

	// Walk through the training set, tokenize each line, add to hash table and increment counts
	for (int i = 0; i < h->size; i++){
		int l = strlen(clf->train->sentences[i]);
		int class = clf->train->labels[i];
		char* grams[l]; /* always greater than the actual number of grams*/
		for (int i = 0; i < l; i++){
			grams[i] = NULL;
			/* this for loop seems really inefficient */
		}
		get_grams(clf->train->sentences[i], grams);
		for (int i = 0; i < l; i++){
			char* g = grams[i];
			if(g != NULL){
				// add_to_hash_table(clf->dictionary, g, class) for each element in the linked list
				clf->all_unigrams++;
				if (class == 1){
					clf->positive_unigrams++;
				}
			}
		}
	}
	return clf;
}

void calculate_probabilities(Classifier* clf){
	int range = clf->dictionary->size;
	for (int i = 0; i < range; i++){

		// get probability of grams
		int sum = clf->dictionary->table[i]->zero;
		sum += clf->dictionary->table[i]->positive;
		float add_one = sum / clf->all_unigrams;

		// get probability grams are positive
		int positive_count = clf->dictionary->table[i]-> positive;
		float add_two = positive_count / clf->positive_unigrams;


		// both of these lines create segmentation faults
		// clf->dictionary->table[i]->gram_probability = add_one;
		// clf->dictionary->table[i]->probability_gram_is_positive = add_two;
	}
	/* walk through the hash map and calculate probabilities
  			{gram: gram_prob, prob_gram_positive}
			P(unigram) :  0 count + 1 count / all_unigrams,
			P(bigram) : 0 count + 1 count / all_bigrams,
			P(unigram|1) : positive count for this unigram / all positive unigrams,
			P(bigram|1) : positive count for this bigram / all positive bigrams}
	*/
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