#ifndef READ_H_
#define READ_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct TrainSet {
	char* sentences[152]; /* 152 is the size of the training set*/
	int labels[152];
} TrainSet;

TrainSet* get_train_set();

void* print_quotes(TrainSet* t);

#endif /* READ_H*/