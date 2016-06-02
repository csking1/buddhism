#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "classifier.h"
#include "hash_tables.h"
#include "train.h"

float class_probability(Classifier* clf){
	float count = 0;
	int l = clf->dictionary->size;
	for (int i = 0; i<l; i++){
		int l = clf->train->labels[i];
		if (l != 1){count = count + 1.0;}
	}
	return count/l;
}

double get_grams(char* sentences, char* grams[]){
	// Is given an empty char* grams, populates it with words from the sentence
	int count = 0;
	char* words = strtok(sentences, " ");
	while (words != NULL){
		grams[count] = words;
		words = strtok(NULL, " ");
		count ++;
	}
	return count;
}

void add_grams(Classifier* clf, char* grams[], char* quote, int l, int class){
	double r = get_grams(quote, grams);
	for (int i = 0; i < l; i++){
		if (grams[i] != NULL){
			HashTable *n = add_string(clf->dictionary, grams[i], class);
			clf->dictionary = n;
			clf->all_unigrams++;
			if (class == 1){clf->positive_unigrams++;}
			
		}
	}
}

void walk_through_train(Classifier* clf, int range){
	for (int i = 0; i < range; i++){
		char* quote = clf->train->sentences[i];
		if (quote != NULL){
			int length = strlen(quote);
			int class = clf->train->labels[i];
			char* grams[length]; /* always greater than the actual number of grams*/
			for (int i = 0; i < length; i++){
				grams[i] = NULL;
			}
			add_grams(clf, grams, quote, length, class);
		}
	}
}

Classifier* classifier_init(TrainSet* t, HashTable* h){
	Classifier *clf = malloc(sizeof *clf);
	clf->dictionary = h;
	clf->train = t;
	clf->class_prob = class_probability(clf);
	clf->all_unigrams = 0;
	clf->positive_unigrams = 0;
	return clf;
}

void calculate_probabilities(Classifier* clf){
	int range = clf->dictionary->size;
	int count = 0;
	for (int i = 0; i < range; i++){
		if (clf->dictionary->table[i] != NULL){
			count ++;
			// P(unigram) :  0 count + 1 count / all_unigrams,
			int sum = clf->dictionary->table[i]->zero;
			sum += clf->dictionary->table[i]->positive;
			float add_one = (float)sum / (float)clf->all_unigrams;
			clf->dictionary->table[i]->gram_probability = add_one;
			// // P(unigram|1) : positive count for this unigram / all positive unigrams,
			int positive_count = clf->dictionary->table[i]-> positive;
			float add_two = (float)positive_count / (float)clf->positive_unigrams;
			clf->dictionary->table[i]->probability_gram_is_positive = add_two;
		}
	}
	printf("%s\n", "Number of grams is ");
	printf("%f\n", clf->dictionary->grams_count);
	printf("%s\n", "Number of grams calculated probabilities for");
	printf("%d\n", count);
	printf("%s\n", "Size of dictionary is");
	printf("%d\n", clf->all_unigrams);
}

float get_score(Classifier* clf, char* fragment){
	int l = strlen(fragment);
	char* grams[l];
	for (int i = 0; i < l; i++){
		 grams[i] = NULL;
	}
	double set = get_grams(fragment, grams);
	int length = 0;
	float score = 0.0;

	// for every gram, get a score
	for (int i = 0; i < l; i++){
		char* g = grams[i];

		if (g != NULL){
			float num = 1.0;
			// double denom = log(set);
			float denom = set;
			length++;

			float gp = get_gram_probability(clf->dictionary, g);
			float pp = get_probability_gram_is_positive(clf->dictionary, g);

			// numerator = 1 + prob_gram_positive * class_prob
			float p = clf->class_prob;
			num += (pp * p);

			// denominator = length of the input string + gram_prob
			denom += gp;
			
			score += num / denom;
		}	
	}

return score / length;
}