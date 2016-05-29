#ifndef HASH_TABLES_H_
#define HASH_TABLES_H_

typedef struct LinkedList {
  char *string;
  struct LinkedList *next;
  int positive; /* running count of grams in class positive */
  int zero; /* running count of grams in class zero */
  float gram_probability;
  float probability_gram_is_positive;
} LinkedList;

typedef struct HashTable {
  	float size;
  	LinkedList **table;
  	float grams_count;
}   HashTable;

HashTable* create_hash_table(float size);

LinkedList* lookup_string(HashTable *h, char *str);

HashTable* add_string(HashTable *h, char *str, int class);

void free_table(HashTable *h);

float get_gram_probability(HashTable *h, char* str);

float get_probability_gram_is_positive(HashTable *h, char *str);

#endif /* HASH_TABLES_H_ */