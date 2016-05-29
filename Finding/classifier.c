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
	Classifier *clf = malloc(sizeof *clf);
	clf->dictionary =  h;
	clf->train = t;
	clf->class_prob = class_probability(clf);
	clf->all_unigrams = 0;
	clf->positive_unigrams = 0;

	// Walk through the training set, tokenize each line, add to hash table and increment counts
	for (int i = 0; i < h->size; i++){
		printf("%d\n", i);

		// on the csil machines this gets a segmentation fault
		printf("%s\n", clf->train->sentences[i]);
		
		if (clf->train->sentences[i] != NULL){
			printf("%s\n", "made it here");
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
					HashTable *n = add_string(clf->dictionary, g, class);
					clf->dictionary = n;
					clf->all_unigrams++;
					if (class == 1){
						clf->positive_unigrams++;
					}

				}
			}

		}
	
	printf("%s\n", "got to the end of another sentence ");
	}

	return clf;

}

void calculate_probabilities(Classifier* clf){

	int range = clf->all_unigrams;
	int count = 0;

	for (int i = 0; i < range; i++){

		if (clf->dictionary->table[i] != NULL){
			printf("%s\n", clf->dictionary->table[i]->string);

			count++;
			// P(unigram) :  0 count + 1 count / all_unigrams,
			int sum = clf->dictionary->table[i]->zero;
			sum += clf->dictionary->table[i]->positive;
			float add_one = (float)sum / (float)clf->all_unigrams;
			// printf("%f\n", add_one);

			// // P(unigram|1) : positive count for this unigram / all positive unigrams,
			int positive_count = clf->dictionary->table[i]-> positive;
			float add_two = (float)positive_count / (float)clf->positive_unigrams;

			// // both of these lines create segmentation faults
			clf->dictionary->table[i]->gram_probability = add_one;
			clf->dictionary->table[i]->probability_gram_is_positive = add_two;
		}
	}
	printf("%d\n", count);
}


// takes a single sentence, returns score
float get_score(Classifier* clf, char* fragment){
	int l = strlen(fragment);
	char* grams[l];
	get_grams(fragment, grams);
	int length = 0;
	float score = 0.0;

	for (int i = 0; i < l; i++){
		float num = 1.0;
		float denom = 1.0;
		char* g = grams[i];

		if (g != NULL){
			length++;
			float gp = get_gram_probability(clf->dictionary, g);
			float pp = get_probability_gram_is_positive(clf->dictionary, g);

			// numerator = 1 + prob_gram_positive * class_prob
			num += pp * clf->class_prob;

			// denominator = 1 + gram_prob
			denom += gp;
			score += num / denom;
		}
		return score / length;
	}
	return 0.0;
}