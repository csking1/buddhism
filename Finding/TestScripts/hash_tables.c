/* From the sparknotes http://www.sparknotes.com/cs/searching/hashtables/section3/page/2/ */

typedef struct _list_t_ {
  char *string;
  struct _list_t_ *next;
} list_t;

typedef struct _hash_table_t_ {
  int size;   /* size of the table */
  list_t **table; /*the table elements */
} hash_table_t;

hash_table_t *create_hash_table(int size){
  hash_table_t *new_table;
  if (size<1){
    return NULL;
  }
  if ((new_table = malloc(sizeof(hash_value_t))) == NULL){
    return NULL;
  }
  if ((new_table -> table = malloc(sizeof(list_t *) * size)) == NULL){
    return NULL;
  }

  /* initialize the elements of the table */
  for (int i = 0; i < size; i++) new_table -> table[i] = NULL;


  /* set the table's size */
  new_table -> size = size;

  return new_table;
}


hash_table_t *my_hash_table;
int size_of_table = 12;
my_hash_table = create_hash_table(size_of_table);

unsigned int hash(hash_table_t *hashtable, char *str){
  unsigned int hashval;
  hashval = 0;

  for(; *str != '\0'; str++) hashval = *str + (hashval << 5) - hashval;

  return hashval % hashtable -> size;
}

list_t *lookup_string(hash_table_t *hashtable, char *str){
  list_t *list;
  unsigned int hashval = hash(hashtable, str);
  for (list = hashtable->table[hashval]; list != NULL; list = list->next{
    if (strcmp(str, list->str) == 0) return list;
  }
  return NULL;
}

int add_string(hash_table_t *hashtable, char *str){
  list_t *new_list;
  list_t *current_list;
  unsigned int hashval = hash(hashtable, str);

  if ((new_list = malloc(sizeof(new_list))) == NULL){
    return 1;
  }

  current_list = lookup_string(hashtable, str);
  if (current_list != NULL) {
    return 2;
  }
  new_list -> str = strdup(str);
  new_list -> next = hashtable -> table[hashval];
  hashtable -> table[hashval] = new_list;
  return 0;
}

void free_table(hash_table_t *hashtable){
  int i;
  list_t *list, *temp;

  if (hashtable == NULL) return;

  for (i=0; i<hashtable-> size; i++){
    list = hashtable -> table[i];
    while(list != NULL){
      temp = list;
      list = list -> next;
      free(temp->str);
      free(temp);
    }
  }

  free(hashtable->table);
  free(hashtable);
}