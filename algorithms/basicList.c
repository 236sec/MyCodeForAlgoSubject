#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

int show( node_t *p ) {
  while (p != NULL) {
    printf( "%d " , p->data );
    p = p->next;
  }
  printf("\n");
  return 1;
}

void get( node_t *p , int num) {
  for(int i = 0 ; i < num+1 ; i++){
    if(i == num ){
      printf("%d",p->data);
    }
    p = p->next;
  }
}

node_t *append( node_t *p , int num){
  node_t *node = (node_t *)malloc(sizeof(node_t));
  node->data = num;
  node->next = NULL;
  if(p==NULL){
    return node;
  }
  else{
    node_t *tmp = p;
    while (tmp->next != NULL) {
      tmp = tmp->next;
    }
    tmp->next = node;
    return p;
  }
}

node_t *reverse( node_t *p ){
  if(p==NULL){
    return NULL;
  }
  else{
    node_t *tmp,*prev,*next_node;
    prev = NULL;
    tmp = p;
    while (tmp != NULL) {
      next_node = tmp->next;
      tmp->next = prev;
      prev = tmp;
      tmp = next_node;
    }
    p=prev;
    return p;
  }
}

node_t *cut( node_t *p , int num_s , int num_e ){
  if(p==NULL){
    return NULL;
  }
  else{
    node_t *node_start,*tmp;
    for(int i = 0 ; i < num_s+1 ; i++){
      node_start = p;
      p=p->next;
    }
    tmp = node_start;
    int round = num_e - num_s;
    for(int i = 0 ; i < round ; i++){
      tmp=tmp->next;
    }
    tmp->next = NULL;
    return node_start;
  }
}

int main(void) {
  node_t *startNode;
  int n,i,num;
  int num_s,num_e;
  char command;
  startNode = NULL;
  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf(" %c", &command);
    switch (command) {
      case 'A':
        scanf("%d",&num);
        startNode = append(startNode,num);
        break;
      case 'G':
        scanf("%d",&num);
        get(startNode,num);
        break;
      case 'S':
        show(startNode);
        break;
      case 'R':
        startNode = reverse(startNode);
        break;
      case 'C':
        scanf("%d %d",&num_s,&num_e);
        startNode = cut(startNode,num_s,num_e);
        break;
      default:
        break;
    }
  }
  return 0;
}