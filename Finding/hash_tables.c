#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/* http://www.sparknotes.com/cs/searching/hashtables/section3/page/2/ */

hash_table *create_hash_table(int size){
  hash_table *new;
  if (size < 1){
    return NULL;
  }

  // sparknotes has sizeof(hash_value_t), but I don't know what that refers to

  if ((new = malloc(sizeof(new))) == NULL){
    return NULL;
  }
  if ((new-> table = malloc(sizeof(links *) * size)) == NULL){
    return NULL;
  }

  /* initialize the elements of the table */
  for (int i = 0; i < size; i++) new -> table[i] = NULL;

  /* set the table's size */
  new -> size = size;

  return new;
}

unsigned int hash(hash_table *hashtable, char *str){
  unsigned int hashval = 0;
  for(; *str != '\0'; str++){
   hashval = *str + (hashval << 5) - hashval;
 }
  return hashval % hashtable -> size;
}

links *lookup_string(hash_table *hashtable, char *str){
  links *list;
  unsigned int hashval = hash(hashtable, str);

  // this for loop syntax looks fishy, and gets errors as well
  for (list = hashtable -> table[hashval]; list != NULL; list = list -> next){
    if (strcmp(str, list->string) == 0) return list;
  }

  // if there's no match, return NULL
  return NULL;
}

int add_string(hash_table *hashtable, char *str){
  links *new;
  links *current;
  unsigned int hashval = hash(hashtable, str);

  if ((new = malloc(sizeof(new))) == NULL){
    return 1;
  }

  current = lookup_string(hashtable, str);
  if (current != NULL) {
    // string is already in the dictionary, update the values here
    return 2;
  }

  new -> string = strdup(str);
  new -> next = hashtable -> table[hashval];
  hashtable -> table[hashval] = new;
  return 0;
}

void free_table(hash_table *hashtable){
  links *list, *temp;

  if (hashtable == NULL) return;

  for (int i = 0; i < hashtable -> size; i++){
    list = hashtable -> table[i];
    while(list != NULL){
      temp = list;
      list = list -> next;
      free(temp->string);
      free(temp);
    }
  }

  free(hashtable->table);
  free(hashtable);
}