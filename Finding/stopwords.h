#ifndef STOPWORDS_H
#define STOPWORDS_H
#include <stdio.h>
#include <stdlib.h>

typedef struct StopWords {
	char* words[173]; /* actual size of stopwords file*/
} StopWords;

StopWords* get_stopwords();

#endif /* STOPWORDS_H*/