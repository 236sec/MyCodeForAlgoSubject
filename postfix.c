#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  double data;
  struct node *next;
} node_t;
typedef node_t stack_t;

stack_t *push(stack_t *s, double value) {
  stack_t *node = (stack_t *)malloc(sizeof(stack_t));
  node->data = value;
  node->next = NULL;
  if (s == NULL) {
    return node;
  }
  node->next = s;
  return node;
}

double top(stack_t *s) {
  return s->data;
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


int is_sign(char k) {
  if(k == '*' || k == '/' || k=='+' || k=='-'){
    return 1;
  }
  return 0;
}

int main(void) {
  stack_t *s = NULL;
  char *userInput = NULL;
  unsigned long n;
  scanf("%lu", &n);
  int match_value = 0;
  userInput = (char *)malloc(sizeof(char) * (n + 1));
  getchar();
  fgets(userInput, n + 1, stdin);
  for (int i = 0; i < n; i++) {
    if (!(is_sign(userInput[i])) && userInput[i] >= '0' && userInput[i] <= '9'){
      double float_v = userInput[i] - '0';
      s = push(s, float_v);
      // printf("Push %f\n",float_v);
    } else if(is_sign(userInput[i])){
      double top_x = top(s);
      s = pop(s);
      double top_y = top(s);
      s = pop(s);
      double result;
      switch(userInput[i]){
        case '*':
          result = top_x * top_y;
          break;
        case '/':
          result = top_y / top_x;
          break;
        case '+':
          result = top_y + top_x;
          break;
        case '-':
          result = top_y - top_x;
          break;
      }
      s = push(s , result);
    }
  }
  printf("%.2f\n",top(s));
  return 0;
}