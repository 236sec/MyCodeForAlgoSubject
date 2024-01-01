#include "week9.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef __avl_tree__
typedef struct node {
  int data;
  int height;
  struct node *left;
  struct node *right;
} node_t;
typedef node_t avl_t;
#endif

int find_min(avl_t *t) {
  if (t->left == NULL) {
    return t->data;
  }
  return find_min(t->left);
}

int depth(avl_t *t) {
  if (t == NULL) {
    return -1;
  }
  return t->height;
}

int is_balance(avl_t *t){
  int h_l = depth(t->left);
  int h_r = depth(t->right);
  // printf("\nBalance at %d : %d %d\n",t->data,h_l,h_r);
  if(h_l - h_r > 1 || h_r - h_l > 1){
    return 0;
  }
  return 1;
}

int new_depth(avl_t *t) {
  if (t == NULL) {
    return -1;
  }
  int h_l = -1;
  int h_r = -1;
  if(t->left != NULL){
    h_l = t->left->height;
  }
  if(t->right != NULL){
    h_r = t->right->height;
  }
  if(h_l > h_r){
    return h_l + 1;
  }
  return h_r + 1;
}

avl_t *right_rotation(avl_t *t){
  avl_t *tmp = t->left->right;
  avl_t *new_head = t->left;
  new_head->right = t;
  t->left = tmp;
  t->height = new_depth(t); 
  new_head->height = new_depth(new_head);
  return new_head;
}

avl_t *left_rotation(avl_t *t){
  avl_t *tmp = t->right->left;
  avl_t *new_head = t->right;
  new_head->left = t;
  t->right = tmp;
  t->height = new_depth(t); 
  new_head->height = new_depth(new_head);
  return new_head;
}

avl_t *make_rotation(avl_t *t) {
  int h_l = depth(t->left);
  int h_r = depth(t->right);
  // printf("Make Rotation for %d : %d %d\n",t->data,h_l,h_r);
  if (h_l > h_r) {
    h_l = depth(t->left->left);
    h_r = depth(t->left->right);
    if(h_l > h_r){
      //left left = right rotation
      // printf("left left\n");
      return right_rotation(t);
    }
    // printf("left right\n");
    t->left = left_rotation(t->left);
    t->height = new_depth(t);
    return right_rotation(t);
  }
  if(h_l < h_r){
    h_l = depth(t->right->left);
    h_r = depth(t->right->right);
    if(h_l < h_r){
      //right right = left rotation
      // printf("right right\n");
      return left_rotation(t);
    }
    // printf("right left\n");
    t->right = right_rotation(t->right);
    t->height = new_depth(t);
    return left_rotation(t);
  }
}

avl_t *insert(avl_t *t, int data) {
  if (t == NULL) {
    avl_t *new_node = (avl_t *)malloc(sizeof(avl_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 0;
    return new_node;
  }
  if (data > t->data) {
    t->right = insert(t->right, data);
    t->height = new_depth(t);
  }
  if (data < t->data) {
    t->left = insert(t->left, data);
    t->height = new_depth(t);
  }
  if(!(is_balance(t))){
    // printf("\nFound UnBalance %d\n",t->data);
    return make_rotation(t);
  }
  return t;
}

avl_t *delete(avl_t *t,int data){
  if(data == t->data){
    if(t->left == NULL && t->right == NULL){
      free(t);
      return NULL;
    }
    if(t->left != NULL && t->right != NULL){
      int new_value = find_min(t->right);
      t->data = new_value;
      t->right = delete(t->right,find_min(t->right));
    }
    else if(t->left != NULL){
      avl_t *tmp = t->left;
      free(t);
      return tmp;
    }
    else if(t->right != NULL){
      avl_t *tmp = t->right;
      free(t);
      return tmp;
    }
    
  }
  else if(data > t->data){
    t->right = delete(t->right, data);
  }
  else if(data < t->data){
    t->left = delete(t->left, data);
  }
  t->height = new_depth(t);
  if(!(is_balance(t))){
    // printf("\nFound Unbalance : %d\n",t->data);
    return make_rotation(t);
  }
  t->height = new_depth(t);
  return t;
}

int main(void) {
  avl_t *t = NULL;
  int n, i;
  int command, data;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &command);
    switch (command) {
    case 1:
      scanf("%d", &data);
      t = insert(t, data);
      break;
    case 2:
      scanf("%d", &data);
      t = delete(t, data);
      break;
    case 3:
      print_tree(t);
      break;
    }
  }
  return 0;
}

// 99
// 1 21
// 1 8
// 1 34
// 1 3
// 1 16
// 1 26
// 1 42
// 1 2
// 1 5
// 1 11
// 1 18
// 1 23
// 1 31
// 1 37
// 1 47
// 1 1
// 1 4
// 1 6
// 1 9
// 1 13
// 1 17
// 1 19
// 1 22
// 1 24
// 1 28
// 1 33
// 1 35
// 1 40
// 1 45
// 1 52
// 1 7
// 1 10
// 1 12
// 1 14
// 1 20
// 1 25
// 1 27
// 1 30
// 1 32
// 1 36
// 1 38
// 1 41
// 1 43
// 1 46
// 1 49
// 1 53
// 1 15
// 1 29
// 1 39
// 1 44
// 1 48
// 1 51
// 1 54
// 1 50