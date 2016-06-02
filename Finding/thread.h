#ifndef THREAD_H
#define THREAD_H
#include <stdio.h>
#include <stdlib.h>
#include "classifier.h"
#include "hash_tables.h"

typedef struct LinkedTest {
	float score;
	char* quote;
} LinkedTest;

typedef struct Thread {
	LinkedTest** table;
	Classifier *clf;
	int size;
} Thread;

Thread* initialize_thread(char* path, Classifier *clf, int size);

void write_quotes(char* path, Thread* t);

#endif /* READ_H*/