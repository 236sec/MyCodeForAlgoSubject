#include "week8.h"
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


// Write your code here
// ** Note that the attach() function has
// been implemented already and included
// in the week8.h header
// ...
void print_preorder_rec(tree_t *t){
  if(t==NULL){
    return ;
  }
  printf("%d ",t->data);
  print_preorder_rec(t->left);
  print_preorder_rec(t->right);
}

void print_preorder(tree_t *t){
  printf("%d ",t->data);
  print_preorder_rec(t->left);
  print_preorder_rec(t->right);
  printf("\n");
}

void print_inorder_rec(tree_t *t){
  if(t==NULL){
    return ;
  }
  print_inorder_rec(t->left);
  printf("%d ",t->data);
  print_inorder_rec(t->right);
}

void print_inorder(tree_t *t){
  print_inorder_rec(t->left);
  printf("%d ",t->data);
  print_inorder_rec(t->right);
  printf("\n");
}

void print_postorder_rec(tree_t *t){
  if(t==NULL){
    return ;
  }
  print_postorder_rec(t->left);
  print_postorder_rec(t->right);
  printf("%d ",t->data);
}

void print_postorder(tree_t *t){
  if(t==NULL){
    return ;
  }
  print_postorder_rec(t->left);
  print_postorder_rec(t->right);
  printf("%d ",t->data);
  printf("\n");
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
  print_preorder(t);
  print_postorder(t);
  print_inorder(t);
  return 0;
}