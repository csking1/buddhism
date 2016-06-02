#ifndef THREAD_H
#define THREAD_H
#include <stdio.h>
#include <stdlib.h>
#include "classifier.h"
#include "hash_tables.h"

typedef struct Thread {
	LinkedList* sentences;
	Classifier *clf;
} Thread;

Thread* initialize_thread(char* path, Classifier *clf);

#endif /* READ_H*/