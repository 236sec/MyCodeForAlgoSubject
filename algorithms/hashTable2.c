#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef char *item_t;

typedef struct hash {
  item_t *table;
  int size;
  int hash_key;
} hash_t;

hash_t *init_hashtable(int m, int hash_key) {
  item_t *arr = (item_t *)malloc(sizeof(item_t) * m);
  hash_t *h = (hash_t *)malloc(sizeof(hash_t));
  h->size = m;
  h->hash_key = hash_key;
  h->table = arr;
  for (int i = 0; i < m; i++) {
    h->table[i] = NULL;
  }

  return h;
}

unsigned int hash_function(hash_t *h, char *text, int n) {
  if (n == 0) {
    return text[n];
  }
  return h->hash_key * hash_function(h, text, n - 1) + text[n];
}

int shift_num(int i) {
  int value = (i + i * i) / 2;
  return value;
}

unsigned int hash(hash_t *h, char *text) {
  int size = strlen(text) - 1;
  // printf("Hash Function : %d\n",hash_function(h,text,size));
  return hash_function(h, text, size) % h->size;
}

void insert(hash_t *h, char *text) {
  unsigned int pos_start = hash(h, text);
  unsigned int pos = pos_start;
  int i = 0;
  while (h->table[pos] != NULL) {
    pos = pos_start + shift_num(i);
    i++;
  }
  item_t node = (item_t)malloc(strlen(text)+1);
  strcpy(node, text);
  h->table[pos] = node;
  // printf("Insert %s at %d\n",node,pos);
}

int inHash(hash_t *h, int pos_start, char *text) {
  int pos = pos_start;
  int i = 0;
  while (h->table[pos] != NULL) {
    // printf("%s == %s\n",h->table[pos],text);
    if (!strcmp(h->table[pos], text)) {
      return pos;
    }
    // if(i > h->size){
    //   return -1;
    // }
    i++;
    pos = pos_start + shift_num(i);
    if(pos == pos_start){
      return -1;
    }
  }
  return -1;
}

int search(hash_t *h, char *text) {
  unsigned int pos = hash(h, text);
  return inHash(h, pos, text);
}

int main(void) {
  hash_t *hashtable = NULL;
  char *text = NULL;
  int m, n, i, hash_key;
  int command;
  scanf("%d %d %d", &m, &n, &hash_key);
  hashtable = init_hashtable(m, hash_key);
  text = (char *)malloc(sizeof(char) * TEXTSIZE);
  for (i = 0; i < n; i++) {
    scanf("%d %s", &command, text);
    switch (command) {
    case 1:
      insert(hashtable, text);
      break;
    case 2:
      printf("%d\n", search(hashtable, text));
      break;
    }
  }
  return 0;
}