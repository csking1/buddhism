#ifndef HASH_TABLES_H_
#define HASH_TABLES_H_

typedef struct linked {
  char *string;
  struct linked *next;
} links;

typedef struct hash_map {
  int size;   /* size of the table */
  links **table; /*the table elements */
} hash_table;

hash_table *create_hash_table(int size);

links *lookup_string(hash_table *hashtable, char *str);

int add_string(hash_table *hashtable, char *str);

void free_table(hash_table *hashtable);


// function for rehash


/* ---------------------- classifier functions ------------------------------

change add string to add grams, which will also add counts

calculate probabilites, which will walk through and convert counts to probabilities */

#endif /* HASH_TABLES_H_ */