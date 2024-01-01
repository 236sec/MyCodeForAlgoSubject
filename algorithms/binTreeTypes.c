#include "week8.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef __bin_tree__
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node_t;
typedef node_t tree_t;
#endif

int is_full(tree_t *t) {
  if(t==NULL){
    return 1;
  }
  if (t->left == NULL && t->right == NULL) {
    return 1;
  }
  if (t->left == NULL || t->right == NULL) {
    return 0;
  }
  return 1 && is_full(t->left) && is_full(t->right);
}

int depth(tree_t *t) {
  if (t == NULL) {
    return -1;
  }
  int d_l = depth(t->left);
  int d_r = depth(t->right);
  if (d_l > d_r) {
    return d_l + 1;
  }
  return d_r + 1;
}

int size_tree(tree_t *t) {
  if (t == NULL) {
    return 1;
  }
  int size_l = size_tree(t->left);
  int size_r = size_tree(t->right);
  if (size_l == 0 || size_r == 0) {
    return 0;
  }
  if (size_r != size_l) {
    return 0;
  }
  return 1 + size_l + size_r;
}

int is_perfect(tree_t *t) {
  if(t==NULL){
    return 1;
  }
  if (t->left == NULL && t->right == NULL) {
    return 1;
  }
  int l_t = size_tree(t->left);
  int r_t = size_tree(t->right);
  if (l_t == 0 || r_t == 0) {
    return 0;
  }
  if (l_t == r_t) {
    int d_l = depth(t->left);
    int d_r = depth(t->right);
    if (d_l != d_r) {
      return 0;
    }
    return 1;
  }
  return 0;
}

int find_dir(tree_t *t, int dir) {
  // 1 left //2 right
  if (t == NULL) {
    return 1;
  }
  if (dir == 1) {
    if (t->right != NULL) {
      return 0;
    }
    return find_dir(t->left, dir);
  }
  if (dir == 2) {
    if (t->left != NULL) {
      return 0;
    }
    return find_dir(t->left, dir);
  }
}

int is_skewed(tree_t *t) {
  if (t->left == NULL && t->right == NULL) {
    return 1;
  }
  if (t->left != NULL && t->right != NULL) {
    return 0;
  }
  if (t->left != NULL) {
    return find_dir(t->left, 1);
  }
  return find_dir(t->right, 2);
}

int is_degenerate(tree_t *t) {
  if (t == NULL) {
    return 1;
  }
  if (t->left == NULL && t->right == NULL) {
    return 1;
  }
  if (t->left != NULL && t->right != NULL) {
    return 0;
  }
  return is_degenerate(t->left) && is_degenerate(t->right);
}

int is_complete(tree_t *t) {
  if (t == NULL) {
    return 1;
  }
  if(is_perfect(t)){
    return 1;
  }
  tree_t *l_tree = t->left;
  tree_t *r_tree = t->right;
  if (depth(l_tree) - 1 == depth(r_tree)) {
    if (is_complete(l_tree) && is_perfect(r_tree)) {
      return 1;
    }
    return 0;
  }
  //depth(l_tree) == depth(r_tree)
  if (depth(l_tree) == depth(r_tree)) {
    if (is_perfect(l_tree) && is_complete(r_tree)) {
      return 1;
    }
    if(t->left != NULL && t->right == NULL){
      return 1;
    }
    return 0;
  }
  return 0;
}

int main(void) {
  tree_t *t = NULL;
  int n, i;
  int parent, child;
  int branch; // 0 root, 1 left, 2 right
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d %d", &parent, &child, &branch);
    t = attach(t, parent, child, branch);
  }
  printf("%d %d %d %d %d\n", is_full(t), is_perfect(t), is_complete(t),
         is_degenerate(t), is_skewed(t));
  return 0;
}
