#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  int data;
  struct node *next;
} node_t;
typedef node_t queue_t;

queue_t *enqueue(queue_t *s, int value) {
  queue_t *node = (queue_t *)malloc(sizeof(queue_t));
  node->data = value;
  node->next = NULL;
  if (s == NULL) {
    return node;
  }
  queue_t *tmp = s;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  tmp->next = node;
  return s;
}

queue_t *dequeue(queue_t *s) {
  if (s == NULL) {
    printf("Queue is empty.\n");
    return NULL;
  }
  queue_t *tmp = s;
  s = tmp->next;
  printf("%d\n", tmp->data);
  free(tmp);
  return s;
}

void empty(queue_t *s) {
  if (s == NULL) {
    printf("Queue is empty.");
  } else {
    printf("Queue is not empty.");
  }
  printf("\n");
}

void show(queue_t *s) {
  if (s == NULL) {
    printf("Queue is empty.");
  } else {
    while (s != NULL) {
      printf("%d ", s->data);
      s = s->next;
    }
  }
  printf("\n");
}

void size(queue_t *s) {
  int i = 0;
  while (s != NULL) {
    i++;
    s = s->next;
  }
  printf("%d\n", i);
}

int main(void) {
  queue_t *q = NULL;
  int n, i, command, value;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &command);
    switch (command) {
    case 1:
      scanf("%d", &value);
      q = enqueue(q, value);
      break;
    case 2:
      q = dequeue(q);
      break;
    case 3:
      show(q);
      break;
    case 4:
      empty(q);
      break;
    case 5:
      size(q);
      break;
    }
  }
  return 0;
}