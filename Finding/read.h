#ifndef READ_H_
#define READ_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct trainset {
	char* sentences[152]; /* 152 is the size of the training set*/
	int labels[152];
} train;

train* get_train_set();

void* print_quotes(train* quotes);

#endif /* READ_H*/