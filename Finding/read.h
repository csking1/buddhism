#ifndef READ_H_
#define READ_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct TrainSet {
	char* sentences[50];
	int labels[50];
} TrainSet;

TrainSet* get_train_set();

#endif /* READ_H*/