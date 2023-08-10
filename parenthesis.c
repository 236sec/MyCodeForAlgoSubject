#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void empty(stack_t *s) {
  if (s != NULL) {
    printf("Stack is not empty.");
  } else {
    printf("Stack is empty.");
  }
  printf("\n");
}

int match(char l, char r) {
  if (l == '(' && r == ')') {
    return 1;
  } else if (l == '{' && r == '}') {
    return 1;
  } else if (l == '[' && r == ']') {
    return 1;
  }
  return 0;
}

void show(stack_t *s) {
  if (s == NULL) {
    printf("Stack is empty.");
  } else {
    while (s != NULL) {
      printf("%c ", s->data);
      s = s->next;
    }
  }
  printf("\n");
}

int main(void) {
  stack_t *s = NULL;
  char *userInput = NULL;
  int n, i, command, value;
  scanf("%d", &n);
  int match_value = 0;
  userInput = (char *)malloc(sizeof(char) * (n + 1));
  getchar();
  fgets(userInput, n + 1, stdin);
  for (i = 0; i < n; i++) {
    // printf("Checking %c\n", userInput[i]);
    if (userInput[i] == '(' || userInput[i] == '[' || userInput[i] == '{') {
      s = push(s, userInput[i]);
      // printf("Push %c\n",userInput[i]);
    } else {
      char top_char = top(s);
      // printf("Top Char is %c\n",userInput[i]);
      if (top_char == '0') {
        break;
      }
      if (match(top_char, userInput[i])) {
        //printf("Match!!\n");
        s = pop(s);
        match_value++;
      } else {
        // printf("Dont Match!!\n");
        break;
      }
    }
  }
  if(match_value == n/2 && n%2!=1){
    printf("1");
  }else{
    printf("0");
  }
  return 0;
}