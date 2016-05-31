#ifndef READ_H_
#define READ_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct TrainSet {
	char* sentences[5];
	int labels[5];
} TrainSet;

TrainSet* get_train_set();

#endif /* READ_H*/
