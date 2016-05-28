#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/* Based on the example http://www.sparknotes.com/cs/searching/hashtables/section3/
  With specialization for reading in grams and calculating frequencies
  And my own rehashing function */

HashTable* create_hash_table(int size){
  HashTable *h;
  if (size < 1){
    return NULL;
  }
  if ((h = malloc(sizeof(h))) == NULL){
    return NULL;
  }
  if ((h->table = malloc(sizeof(h->table) * size)) == NULL){
    return NULL;
  }
  /* initialize the elements of the table */
  for (int i = 0; i < size; i++) {
    h->table[i] = NULL;
  }
  h->size = size;
  return h;
}

unsigned int hash(HashTable *h, char *str){
  unsigned int hashval = 0;
  for(; *str != '\0'; str++){
    // this line is a mystery
   hashval = *str + (hashval << 5) - hashval;
 }
  return hashval % h->size;
}

LinkedList *lookup_string(HashTable *h, char *str){
  LinkedList *list;
  unsigned int hashval = hash(h, str);
  // I don't understand the syntax here
  for (list = h->table[hashval]; list != NULL; list = list -> next){
    if (strcmp(str, list->string) == 0) return list;
  }
  // if there's no match, return NULL
  return NULL;
}

// this might have to take two booleans, whether or not the string is a positive, and whether or not it's a unigram
int add_string(HashTable *h, char *str){
  LinkedList *new;
  LinkedList *current;
  unsigned int hashval = hash(h, str);
  if ((new = malloc(sizeof(new))) == NULL){
    return 1;
  }
  current = lookup_string(h, str);
  if (current != NULL) {
    // string is already in the dictionary, update the values here
    return 2;
  }

  new->string = strdup(str);
  new->next = h->table[hashval];
  h->table[hashval] = new;
  return 0;
}

void free_table(HashTable *h){
  LinkedList *list, *temp;
  if (h == NULL) return;
  for (int i = 0; i < h->size; i++){
    list = h->table[i];
    while(list != NULL){
      temp = list;
      list = list -> next;
      free(temp->string);
      free(temp);
    }
  }
  free(h->table);
  free(h);
}