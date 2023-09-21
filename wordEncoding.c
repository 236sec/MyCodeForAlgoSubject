#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int feq;
  char *word;
  struct node *left;
  struct node *right;
} node_t;

typedef struct heap {
  node_t **data;
  int last_index;
} heap_t;

typedef struct stack {
  int data;
  struct stack *next;
} stack_t;

stack_t *push(stack_t *s, int data) {
  stack_t *node = (stack_t *)malloc(sizeof(stack_t));
  node->data = data;
  node->next = NULL;
  if (s == NULL) {
    return node;
  }
  node->next = s;
  return node;
}

stack_t *pop(stack_t *s) {
  if(s==NULL){
    return NULL;
  }
  stack_t *tmp = s;
  s = tmp->next;
  free(tmp);
  return s;
}

heap_t *init_heap(int m){
  node_t **arr = (node_t **)malloc(sizeof(node_t *) * m);
  node_t *no = (node_t *)malloc(sizeof(node_t));
  heap_t *h = (heap_t *)malloc(sizeof(heap_t));
  no->left = NULL;
  no->right = NULL;
  no->feq = 0;
  no->word = "";
  h->data = arr;
  h->data[0] = no;
  h->last_index = 0;
  return h;
}

void make_insert_heap(heap_t *h,int pos){
  int parent = pos / 2;
  if(parent == 0){
    return ;
  }
  if(h->data[pos]->feq < h->data[parent]->feq){
    // printf("%d <-> %d\n",h->data[pos],h->data[parent]);
    node_t *tmp = h->data[pos];
    h->data[pos] = h->data[parent];
    h->data[parent] = tmp;
    make_insert_heap(h, parent);
  }
  return ;
}

void *insert(heap_t *h,int feq,char* st){
  node_t *no = (node_t *)malloc(sizeof(node_t));
  no->left = NULL;
  no->right = NULL;
  no->feq = feq;
  no->word = st;
  h->last_index += 1;
  h->data[h->last_index] = no;
  make_insert_heap(h,h->last_index);
}

void make_swap(heap_t *h , int p1 , int p2){
  // make swap between two position
  node_t *tmp = h->data[p1];
  h->data[p1] = h->data[p2];
  h->data[p2] = tmp;
  return;
}

void make_delete_heap(heap_t *h,int pos){
  int child_1 = pos*2 , child_2 = pos*2+1;
  // printf("At : %d Range : %d\n",pos,h->last_index);
  if(child_1 > h->last_index || child_2 > h->last_index){
    // printf("Out of Range %d %d : %d\n",child_1,child_2,h->last_index);
    //handle out of range
    if(child_1 > h->last_index && child_2 > h->last_index){
      return ;
    }
    if(child_1 <= h->last_index && child_2 > h->last_index){
      if(h->data[pos]->feq > h->data[child_1]->feq){
        //check child_1 is can swap
        // printf("Checking %s : %d\n",h->data[child_1]->word,h->data[child_1]->feq);
        make_swap(h,pos,child_1);
      }
      return ;
    }
  }
  //check can swap
  if(h->data[pos]->feq > h->data[child_1]->feq || h->data[pos]->feq > h->data[child_2]->feq ){
    // check who to swap
    // printf("Checking %s : %d  %s : %d\n",h->data[child_1]->word,h->data[child_1]->feq,h->data[child_2]->word,h->data[child_2]->feq);
    if(h->data[child_1]->feq <= h->data[child_2]->feq){
      // printf("Swap %s => %s\n",h->data[pos]->word,h->data[child_1]->word);
      make_swap(h, pos, child_1);
      make_delete_heap(h,child_1);
    }
    else{
      // printf("Swap %s => %s\n",h->data[pos]->word,h->data[child_2]->word);
      make_swap(h, pos, child_2);
      make_delete_heap(h,child_2);
    }
  }
  return ;
}



node_t *delete_min(heap_t *h){
  h->data[h->last_index];
  node_t *tmp = h->data[1];
  h->data[1] = h->data[h->last_index];
  h->last_index-=1;
  // printf("Promote %s\n",h->data[1]->word);
  make_delete_heap(h,1);
  return tmp;
}

// int find_pos(heap_t *h , int data){
//   for(int i = 1 ; i <= h->last_index ; i++){
//     if(h->data[i] == data){
//       return i;
//     }
//   }
// }

// void update_key(heap_t *h, int old_key, int new_key){
//   int pos = find_pos(h,old_key);
//   h->data[pos] = new_key;
//   make_delete_heap(h, pos);
//   make_insert_heap(h, pos);
// }

void print_stack(stack_t *s){
  if(s== NULL){
    return;
  }
  print_stack(s->next);
  printf("%d",s->data);
}

void bfs(heap_t *h){
  heap_t *p = h;
  for(int i = 1 ; i <= h->last_index ; i++){
    printf("%s ",h->data[i]->word);
  }
  printf("\n");
}

void bfs_tree(node_t *t,stack_t *s){
  if(strcmp(t->word,"Tree")){
    printf("%s : ",t->word);
    print_stack(s);
    printf("\n");
  }
  if(t->left != NULL){
    s = push(s,0);
    bfs_tree(t->left,s);
    s = pop(s);
  }
  if(t->right != NULL){
    s = push(s,1);
    bfs_tree(t->right,s);
    s = pop(s);
  }
}

void print_tree(heap_t *h){
  node_t *tr = h->data[1];
  stack_t *s = NULL;
  s = push(s,0);
  bfs_tree(tr->left,s);
  s = pop(s);
  s = push(s,1);
  bfs_tree(tr->right,s);
  s = pop(s);
}

void insert_tree(heap_t *h,node_t *t1,node_t *t2){
  node_t *n_t = (node_t *)malloc(sizeof(node_t));
  n_t->word = "Tree";
  n_t->feq = t1->feq + t2->feq;
  n_t->left = t1;
  n_t->right = t2;
  h->last_index += 1;
  h->data[h->last_index] = n_t;
  make_insert_heap(h,h->last_index);
}

int main(void) {
  heap_t *min_heap = NULL;
  int n, i;
  int command, data;
  int old_key, new_key;
  scanf("%d", &n);
  min_heap = init_heap(n);
  for (i = 0; i < n; i++) {
    char *st = (char *)malloc(sizeof(char) * 16);
    scanf("%s", st);
    scanf("%d", &data);
    insert(min_heap,data,st);
  }
  // bfs(min_heap);
  node_t *t1 = NULL;
  node_t *t2 = NULL;
  while(min_heap->last_index != 1){
    t1 = delete_min(min_heap);
    t2 = delete_min(min_heap);
    insert_tree(min_heap, t1, t2);
    // bfs(min_heap);
  }
  print_tree(min_heap);
  return 0;
}

/*
9
a 1
e 2
g 1
h 2
i 3
m 1
s 5
t 1
_ 3

*/