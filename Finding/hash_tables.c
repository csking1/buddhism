#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/* http://www.sparknotes.com/cs/searching/hashtables/section3/page/2/ */

HashTable* create_hash_table(int size){
  HashTable *h;
  if (size < 1){
    return NULL;
  }

  // sparknotes has sizeof(hash_value_t), but I don't know what that refers to

  if ((h = malloc(sizeof(h))) == NULL){
    return NULL;
  }
  if ((h-> table = malloc(sizeof(links *) * size)) == NULL){
    return NULL;
  }

  /* initialize the elements of the table */
  for (int i = 0; i < size; i++) h -> table[i] = NULL;

  /* set the table's size */
  h -> size = size;

  return h;
}

unsigned int hash(HashTable *h, char *str){
  unsigned int hashval = 0;
  for(; *str != '\0'; str++){
   hashval = *str + (hashval << 5) - hashval;
 }
  return hashval % h->size;
}

links *lookup_string(HashTable *h, char *str){
  links *list;
  unsigned int hashval = hash(h, str);

  // this for loop syntax looks fishy, and gets errors as well
  for (list = h->table[hashval]; list != NULL; list = list -> next){
    if (strcmp(str, list->string) == 0) return list;
  }

  // if there's no match, return NULL
  return NULL;
}

int add_string(HashTable *h, char *str){
  links *new;
  links *current;
  unsigned int hashval = hash(h, str);

  if ((new = malloc(sizeof(new))) == NULL){
    return 1;
  }

  current = lookup_string(h, str);
  if (current != NULL) {
    // string is already in the dictionary, update the values here
    // increment postive or negative 
    return 2;
  }

  new->string = strdup(str);
  new->next = h->table[hashval];
  h->table[hashval] = new;
  return 0;
}

void free_table(HashTable *h){
  links *list, *temp;

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