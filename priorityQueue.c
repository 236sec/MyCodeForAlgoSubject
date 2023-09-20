#include <stdio.h>
#include <stdlib.h>
typedef struct heap {
  int *data;
  int last_index;
} heap_t;

heap_t *init_heap(int m){
  int* arr = (int *)malloc(sizeof(int) * m + 1);
  heap_t *h = (heap_t *)malloc(sizeof(heap_t));
  h->data = arr;
  h->last_index = 0;
  h->data[0] = -1;
  return h;
}

void bfs(heap_t *h){
  heap_t *p = h;
  for(int i = 1 ; i <= h->last_index ; i++){
    printf("%d ",h->data[i]);
  }
  printf("\n");
}

void make_insert_heap(heap_t *h,int pos){
  int parent = pos / 2;
  if(parent == 0){
    return ;
  }
  if(h->data[pos] > h->data[parent]){
    // printf("%d <-> %d\n",h->data[pos],h->data[parent]);
    int tmp = h->data[pos];
    h->data[pos] = h->data[parent];
    h->data[parent] = tmp;
    make_insert_heap(h, parent);
  }
  return ;
}

void *insert(heap_t *h,int data){
  h->data[0] = -2;
  h->last_index += 1;
  h->data[h->last_index] = data;
  make_insert_heap(h,h->last_index);
}

int find_max(heap_t *h){
  if(h->data[0] == -1){
    return -1;
  }
  return h->data[1];
}

void make_swap(heap_t *h , int p1 , int p2){
  // make swap between two position
  int tmp = h->data[p1];
  h->data[p1] = h->data[p2];
  h->data[p2] = tmp;
  return;
}

void make_delete_heap(heap_t *h,int pos){
  int child_1 = pos*2 , child_2 = pos*2+1;
  if(child_1 > h->last_index || child_2 > h->last_index){
    // printf("Out of Range %d %d : %d\n",child_1,child_2,h->last_index);
    //handle out of range
    if(child_1 > h->last_index && child_2 > h->last_index){
      return ;
    }
    if(child_1 <= h->last_index && child_2 > h->last_index){
      if(h->data[child_1] > h->data[pos]){
        //check child_1 is can swap
        make_swap(h,pos,child_1);
      }
      return ;
    }
  }
  //check can swap
  if(h->data[pos] < h->data[child_1] || h->data[pos] < h->data[child_2]){
    // check who to swap
    if(h->data[child_1] > h->data[child_2]){
      // printf("Swap %d => %d\n",h->data[pos],h->data[child_1]);
      make_swap(h, pos, child_1);
      make_delete_heap(h,child_1);
    }
    else{
      // printf("Swap %d => %d\n",h->data[pos],h->data[child_2]);
      make_swap(h, pos, child_2);
      make_delete_heap(h,child_2);
    }
  }
  return ;
}

void delete_max(heap_t *h){
  if(h->last_index == 1){
    //reset to beginning
    h->data[0] = -1;
    h->data[1] = 0;
    h->last_index = 0;
    return;
  }
  //swap and -1 last index
  h->data[1] = h->data[h->last_index];
  h->data[h->last_index] = 0;
  h->last_index -= 1;
  //make tree to heap
  make_delete_heap(h,1);
}

int find_pos(heap_t *h , int data){
  for(int i = 1 ; i <= h->last_index ; i++){
    if(h->data[i] == data){
      return i;
    }
  }
}

void update_key(heap_t *h, int old_key, int new_key){
  int pos = find_pos(h,old_key);
  h->data[pos] = new_key;
  make_delete_heap(h, pos);
  make_insert_heap(h, pos);
}

int main(void) {
  heap_t *max_heap = NULL;
  int m, n, i;
  int command, data;
  int old_key, new_key;
  scanf("%d %d", &m, &n);
  max_heap = init_heap(m);
  for (i = 0; i < n; i++) {
    scanf("%d", &command);
    switch (command) {
    case 1:
      scanf("%d", &data);
      insert(max_heap, data);
      break;
    case 2:
      delete_max(max_heap);
      break;
    case 3:
      printf("%d\n", find_max(max_heap));
      break;
    case 4:
      scanf("%d %d", &old_key, &new_key);
      update_key(max_heap, old_key, new_key);
      break;
    case 5:
      bfs(max_heap);
      break;
    }
  }
  return 0;
}

/*
5 11
3

1 11
1 3
1 90
1 43
3

2
2
5

4 3 20
3
*/