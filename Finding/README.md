# Finding Buddhism

## All of these steps are performed by finding_buddhism.c, but they're explained sequentially here by the files that are used.

1. read.c: get the training quotes and labels from Data/training.csv

2. classifier.c: initialize the naieve bayes classifier with the number of quotes, feed the training quotes into the classifier and calculate frequencies

3. partition.c: randomly partition the gutenberg testing set into nodes

4. concurrency.c: feed a copy of the classifier into each of the nodes, along with a partition of the gutenberg testing set

5. classifier.c: score each quote with its predicted probability of being Buddhist

6. out.c: merge the results from each node, print the top 10,000 scored quotes to Output/results.csv