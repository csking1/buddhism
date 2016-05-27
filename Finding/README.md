# Finding Buddhism

All of these steps are performed by finding_buddhism.c, but they're explained sequentially here by the files that are used.

1. read.c: Get the training quotes and labels from Data/training.txt. This results in a 2-D array of quotes and a 1-D array of integers that correspond to the quotes.

2. classifier.c: Initialize the naieve bayes classifier with the number of quotes, feed the training quotes into the classifier and calculate frequencies

3. partition.c: Randomly partition the gutenberg testing set into nodes

4. Feed a copy of the classifier into each of the threads, along with a partition of the gutenberg testing set

5. classifier.c: Score each quote with its predicted probability of being Buddhist

6. Merge the results from each node, print the top 10,000 scored quotes to Output/results.csv
