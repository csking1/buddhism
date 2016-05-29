#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hash_tables.h"

float TOO_FULL_RATIO = 0.50;
float GROWTH_RATIO = 5;

// Skeleton from http://www.sparknotes.com/cs/searching/hashtables/section3/, but most is original

HashTable* create_hash_table(int size){
  HashTable *h = malloc(sizeof *h);
  if (size < 1){
    return NULL;
  }
  // if ((h = malloc(sizeof h*)) == NULL){
  //   return NULL;
  // }
  if ((h->table = malloc(sizeof(h->table) * size)) == NULL){
    return NULL;
  }
  /* initialize the elements of the table */
  for (int i = 0; i < size; i++) {
    h->table[i] = NULL;
  }
  h->size = size;
  h->grams_count = 0;
  return h;
}

unsigned int hash(HashTable *h, char *str){
  unsigned int hashval = 0;
  for(; *str != '\0'; str++){
   hashval = *str + (hashval << 5) - hashval;
 }
  return hashval % h->size;
}

LinkedList *lookup_string(HashTable *h, char *str){
  LinkedList *list;
  unsigned int hashval = hash(h, str);
  for (list = h->table[hashval]; list != NULL; list = list -> next){
    if (strcmp(str, list->string) == 0) return list;
  }
  // if there's no match, return NULL
  return NULL;
}

bool is_too_full(HashTable *h){
  return (h->grams_count / h->size) >= TOO_FULL_RATIO;
}

int transfer_values(HashTable *h, char *new_string, int positive_count, int zero_count){
  LinkedList *new = malloc(sizeof *new);
  // if ((new = malloc(sizeof new*)) == NULL){
  //   return 1;
  // }
  unsigned int hashval = hash(h, new_string);
  new->string = new_string;
  new->next = h->table[hashval];
  new->positive = positive_count;
  new->zero = zero_count;
  h->table[hashval] = new;
  h->grams_count ++;
  return 0;
}

HashTable* rehash(HashTable *h){
  int new_size = h->size * GROWTH_RATIO;
  HashTable* new_table = create_hash_table(new_size);
  for(int i = 0; i<h->size; i++){
    char* string = h->table[i]->string;
    transfer_values(new_table, string, h->table[i]->positive, h->table[i]->zero);
  }
  return new_table;
}

int add_string(HashTable *h, char *str, int class){
  LinkedList *new = malloc(sizeof *new);
  LinkedList *current;
  unsigned int hashval = hash(h, str);
  current = lookup_string(h, str);
  if (current != NULL) {
      if (class == 0){
        new->zero ++;
      }
      else {
        new->positive ++;
      }
    return 2;
  }
  new->string = strdup(str);

  if (class == 0){
    new->zero = 1;
    new->positive = 0;
  }
  else {
    new->positive = 1;
    new->positive = 0;
  }
  new->next = h->table[hashval];
  h->table[hashval] = new;
  h->grams_count ++;
  bool go = is_too_full(h);
  if(go == true){
    h = rehash(h);
  }
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

float get_gram_probability(HashTable *h, char* str){
  LinkedList *rt = lookup_string(h, str);
  if (rt == NULL){
    return 0.0;
  }
  return rt->gram_probability;
}

float get_probability_gram_is_positive(HashTable *h, char *str){
    LinkedList *rt = lookup_string(h, str);
    if (rt == NULL){
      return 0.0;
    }
    return rt->probability_gram_is_positive;
}