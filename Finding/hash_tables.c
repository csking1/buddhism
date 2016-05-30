#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hash_tables.h"

float TOO_FULL_RATIO = 0.50;
float GROWTH_RATIO = 2;

// Skeleton code is from sparknotes, but most is original

HashTable* create_hash_table(float size){
  HashTable *h = malloc(sizeof *h);
  if ((h->table = malloc(sizeof(h->table) * size)) == NULL){
    return NULL;
  }
  for (int i = 0; i < size; i++) {
    h->table[i] = NULL;
  }
  h->size = size;
  h->grams_count = 0.0;
  return h;
}

unsigned int hash(HashTable *h, char *str){
  unsigned int hashval = 0;
  for(; *str != '\0'; str++){
    hashval = *str + (hashval << 5) - hashval;
  }
  return hashval %(int)h->size;
}

LinkedList *lookup_string(HashTable *h, char *str){
  LinkedList *list;
  unsigned int hashval = hash(h, str);
  // does this need to check the begining of the list as well?
  for (list = h->table[hashval]; list != NULL; list = list -> next){
    if (strcmp(str, list->string) == 0) return list;
  }
  return NULL;
}

bool is_too_full(HashTable *h){
  return (h->grams_count / h->size) >= TOO_FULL_RATIO;
}

// make sure this is doing what you think it should be doing, especially the adding to table logic
int transfer_values(HashTable *h, char *new_string, int positive_count, int zero_count){
  LinkedList *new = malloc(sizeof *new);
  unsigned int hashval = hash(h, new_string);
  new->string = new_string;
  new->next = h->table[hashval];
  new->positive = positive_count;
  new->zero = zero_count;
  h->table[hashval] = new;
  return 0;
}

HashTable* rehash(HashTable *h){
  float new_size = h->size * GROWTH_RATIO;
  HashTable* new_table = create_hash_table(new_size);
  new_table->grams_count = h->grams_count;

  // walk through existing hash table and transfer values to new table
  int range = h->size;
  for(int i = 0; i < range; i++){
    if (h->table[i] != NULL){
      char* string = h->table[i]->string;
      transfer_values(new_table, string, h->table[i]->positive, h->table[i]->zero);
    }
  }
  return new_table;
}

bool counting(HashTable *h, LinkedList *current, LinkedList *new, int class){
  /* Returns true if the string is already in the table,
  Increments counting either way */
  if (current != NULL) {
      if (class == 0){
        current->zero ++;
      }
      else {
        current->positive ++;
      }
    return true;
  }
  h->grams_count ++;
  printf("%f\n", h->grams_count);
  if (class == 0){
    new->zero = 1;
    new->positive = 0;
  }
  else {
    new->positive = 1;
    new->positive = 0;
  }
  return false;
}

HashTable* add_to_hash_table(HashTable* h, char* str, LinkedList* new){
  unsigned int hashval = hash(h, str);
  new->next = h->table[hashval];
  h->table[hashval] = new;
  new->string = str;
  if(is_too_full(h) == true){
    HashTable *new = rehash(h);
    return new;
  }
  return h;
}

HashTable* add_string(HashTable *h, char *str, int class){
  LinkedList *new = malloc(sizeof *new);
  LinkedList *current = lookup_string(h, str);
  if(counting(h, current, new, class) == true){
    return h;
  }
  HashTable* rt = add_to_hash_table(h, str, new);
  return rt;
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