/*
counts =  {unigram : {0: count, 1:count},
		unigram: {0: count, 1:count},
		unigram: {0: count, 1:count}},
		bigram: {0: count, 1:count},
		bigram: {0: count, 1:count},
		all_unigrams: {0: count, 1: count},
		all_bigrams: {0: count, 1: count},
*/

int get_grams(list){
	// takes a sentence and returns a list of unigrams / bigrams
	// remove punctuation
	// do stemming, cat = cats, sit = sits
}

// create the hashmap
int get_counts_dict(){
	int count = 0;
	// counts = "all_bigrams":{0:count, 1:count}
	// return counts
}

int get_stopwords(){
	// read in from text file
	// add to dictionary
	// return a dictionary
}

int is_not_stopword(gram, stops){
	// hash the gram
	// return 1 if not in stops, 0 otherwise
}

void* add_grams_to_dictionary(counts, grams, stops, labels){
	// for each in grams
		// if is_not_stopword(gram, stops)
			// hash the gram
			// get the label
			// drop into dictionary, into label, increment the count
			// increment count for all_unigrams or all_bigrams
}

int turn_into_probabilities(counts){
	// Walk through counting dictionary and turn it into probabilities dictionary

	/*  probs = { P(1) : number of postive quotes / length(Y),
			P(unigram) :  0 count + 1 count / all_unigrams,
			P(bigram) : 0 count + 1 count / all_bigrams,
			P(unigram|1) : positive count for this unigram / all positive unigrams,
			P(bigram|1) : positive count for this bigram / all positive bigrams}
	*/
}

int train(){
	// stops = get_stopwords()

	// counts = get_counts_dict()

	// for each in sentences:
		// grams = get_grams(each)
		// add_grams_to_dictionary(counts, grams, stops, labels)

	// turn_into_probabilities(counts)

	// return dict
}


int score(dict, quote){
	int score = 0
	//grams = get_grams(quote)
	// for g in grams:
		// numerator = 1 + P(gram|1) * P(1)

		// denominator = 1 + P(gram)

		// score +=  numerator / denominator
	// score = score / length(grams)

}


void* struct classifier(dict){

	// self.dict = dict
	// self.score = score(dict, quote)

};