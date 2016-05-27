#ifndef HASH_TABLES_H_
#define HASH_TABLES_H_

typedef struct LinkedList {
  char *string;
  struct LinkedList *next;
  int positive; /* running count of grams in class positive */
  int zero; /* running count of grams in class zero */
} LinkedList;

typedef struct HashTable {
  	int size;
  	LinkedList **table;
}   HashTable;

HashTable* create_hash_table(int size);

LinkedList* lookup_string(HashTable *h, char *str);

int add_string(HashTable *h, char *str);

void free_table(HashTable *h);

// function for rehash

/* ---------------------- classifier functions ------------------------------

change add string to add grams, which will also add counts

calculate probabilites, which will walk through and convert counts to probabilities */

#endif /* HASH_TABLES_H_ */