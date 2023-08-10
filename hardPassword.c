#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000

typedef struct node {
  int data;
  struct node *next;
} node_t;
typedef node_t stack_t;

stack_t *push(stack_t *s, char value) {
  stack_t *node = (stack_t *)malloc(sizeof(stack_t));
  node->data = value;
  node->next = NULL;
  if (s == NULL) {
    return node;
  }
  node->next = s;
  return node;
}

char top(stack_t *s) {
  if (s == NULL) {
    return '0';
  } else {
    return s->data;
  }
}

stack_t *pop(stack_t *s) {
  if (s == NULL) {
    return NULL;
  }
  stack_t *tmp = s;
  s = tmp->next;
  free(tmp);
  return s;
}

int main(void) {
  stack_t *s = NULL;
  char *userInput = NULL;
  int match_value = 0;
  int stage_push = 1;
  userInput = (char *)malloc(sizeof(char) * (MAX_LENGTH + 1));
  fgets(userInput, MAX_LENGTH + 1, stdin);
  int n = strlen(userInput);
  for (int i = 0; i < n; i++) {
    if(stage_push && userInput[i] != 'x'){
      s = push(s,userInput[i]);
    }else if(stage_push && userInput[i] == 'x'){
      stage_push = 0;
    }else if(!(stage_push) && userInput[i] != 'y'){
      char top_char = top(s);
      if(top_char == userInput[i]){
        match_value++;
        s = pop(s);
      }
    }else if(!(stage_push) && userInput[i] == 'y'){
      break;
    }
  }
  if(match_value == (n-2)/2){
    printf("1");
  }else{
    printf("0");
  }
  return 0;
}