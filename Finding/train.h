#ifndef TRAIN_H_
#define TRAIN_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct TrainSet {
	char* sentences[7892];
	int labels[7892];
} TrainSet;

TrainSet* get_train_set(float range);

#endif /* TRAIN_H*/
