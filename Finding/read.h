#ifndef READ_H_
#define READ_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct TrainSet {
	char* sentences[152];
	int labels[152];
} TrainSet;

TrainSet* get_train_set();

#endif /* READ_H*/