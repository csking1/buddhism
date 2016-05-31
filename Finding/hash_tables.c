#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hash_tables.h"

float TOO_FULL_RATIO = 0.50;
float GROWTH_RATIO = 2;

// The skeleton from sparknotes turned out to be buggy and not very useful, so most of this code is original.
// Lesson: don't trust sparknotes. Sometimes what you find online is barely useful. 8 hours later.
// I think I'm not capturing some of the functionality of linked lists

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
  for (int i = hashval; i < h->size; i++){
    list = h->table[i];
    if (list != NULL){
      if (strcmp(str, list->string) == 0){
        return list;
      }
    }
  }

  for (int i = 0; i < hashval; i++){
    list = h->table[i];
    if (list != NULL){
      if (strcmp(str, list->string) == 0){
        return list;
      }
    }
  }

  return NULL;
}

bool is_too_full(HashTable *h){
  return (h->grams_count / h->size) >= TOO_FULL_RATIO;
}

void add_to_table(HashTable *h, char* str, LinkedList* new){
  unsigned int hashval = hash(h, str);

  // walk through the table and check for the first free spot, start at hash val and go to the top
  for (int i = hashval; i<h->size; i++){
    if (h->table[i] == NULL){
        new->next = h->table[i];
        h->table[i] = new;
        new->string = str;
        return;
    }
  }
  // start at the bottom of the table, check for the first free spot up to hash val, then return
  for (int i = 0; i < hashval; i++){
    if (h->table[i] == NULL){
        new->next = h->table[i];
        h->table[i] = new;
        new->string = str;
        return;
    }
  }
}

HashTable* rehash(HashTable *h){
  float new_size = h->size * GROWTH_RATIO;
  HashTable* new_table = create_hash_table(new_size);
  new_table->grams_count = h->grams_count;
  printf("%s\n", "grams count is");
  printf("%f\n", h->grams_count);

  int count = 0;
  // walk through old hash table and transfer values to new table
  for(int i = 0; i < h->size; i++){
    if (h->table[i] != NULL){
      count++;
      LinkedList *new = malloc(sizeof *new);
      new->positive = h->table[i]->positive;
      new->zero = h->table[i]->zero;
      printf("%s\n", h->table[i]->string);
      add_to_table(h, h->table[i]->string, new);
    }
  }
  printf("%s\n", "actually transferred this many: ");
  printf("%d\n", count);
  return new_table;
}

bool counting(HashTable *h, LinkedList *current, LinkedList *new, int class){
  /* Returns true if the string is already in the table, increments counting either way */
  if (current != NULL) {
      if (class == 0){
        current->zero ++;
      }
      else {
        current->positive ++;
      }
    return true;
  }
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

HashTable* add_string(HashTable *h, char *str, int class){
  LinkedList *new = malloc(sizeof *new);
  LinkedList *current = lookup_string(h, str);
  if(counting(h, current, new, class) == true){
    return h;
  }
  h->grams_count ++;
  add_to_table(h, str, new);
  if(is_too_full(h) == true){
    HashTable *t = rehash(h);
    return t;
  }
  return h;
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