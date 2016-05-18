////////////////
// Initialize //
////////////////

// given N quotes, create vector Y of length N filled with NULLs

// build stopwords dictionary for not interesting unigrams: he, she, if, it, the, a, where

// how many 1s should be in the training set? should match Gutenberg ... loosely estimate probability of a quote being formally tagged "Buddhist"

// create counts dictionary

// create probabilities dictionary





///////////
// Train //
///////////

// walk through each quote: break into unigrams and bigrams

// for each gram that's not a stopword, hash and add to counts

// all_unigrams and all_bigrams counts in total, not discrete. If it sees the same gram, it will count it again.

/*
counts =  {unigram : {0: count, 1:count},
		unigram: {0: count, 1:count},
		unigram: {0: count, 1:count}},
		bigram: {0: count, 1:count},
		bigram: {0: count, 1:count},
		all_unigrams: {0: count, 1: count},
		all_bigrams: {0: count, 1: count},
/*

// Walk through counting dictionary and calculate probabilities

/*  probs = { P(1) : number of postive quotes / length(Y),
			P(unigram) :  0 count + 1 count / all_unigrams,
			P(bigram) : 0 count + 1 count / all_bigrams,
			P(unigram|1) : positive count for this unigram / all positive unigrams,
			P(bigram|1) : positive count for this bigram / all positive bigrams}
/*


//////////
// Test //
//////////


// break up the quote into grams and bigrams

// given a gram, calculate a score

// numerator = 1 + P(gram|1) * P(1)

// denominator = 1 + P(gram)

// score =  numerator / denominator

// sum the scores and divide by the number of grams

// return the quote and the score
