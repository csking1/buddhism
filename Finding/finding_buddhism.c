// read in list of quotes and vector of labels from read.c. This function takes the size of the training set.

// initialize classifier with N: create the hash table. This function takes the total number of unigrams and bigrams to calculate the starting size of the hash table.

// hand off list of quotes and vector to classifier for training

// get gutenberg splits from partition.c

// feed splits and copies of classifier into nodes with concurrency.c

// score each quote in the node with classifier.c

// merge results and print top 10,000 quotes to Output/results.csv