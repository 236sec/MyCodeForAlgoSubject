#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node_t;
typedef node_t bst_t;

int find(bst_t *t, int data) {
  if (t == NULL) {
    return 0;
  }
  if (t->data == data) {
    return 1;
  }
  if (data > t->data) {
    return find(t->right, data);
  }
  if (data < t->data) {
    return find(t->left, data);
  }
}

bst_t *find_tree(bst_t *t, int data) {
  if (t == NULL) {
    return 0;
  }
  if (t->data == data) {
    return t;
  }
  if (data > t->data) {
    return find_tree(t->right, data);
  }
  if (data < t->data) {
    return find_tree(t->left, data);
  }
}

int find_min(bst_t *t) {
  if (t->left == NULL) {
    return t->data;
  }
  return find_min(t->left);
}

int find_max(bst_t *t) {
  if (t->right == NULL) {
    return t->data;
  }
  return find_max(t->right);
}

bst_t *delete(bst_t *t, int data) {
  if(data > t->data){
    if(t->right->data == data){
      
    }
  }
}

bst_t *insert(bst_t *t, int data) {
  if (t == NULL) {
    bst_t *new_node = (bst_t *)malloc(sizeof(bst_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
  }
  if (data > t->data) {
    if (t->right == NULL) {
      bst_t *new_node = (bst_t *)malloc(sizeof(bst_t));
      new_node->data = data;
      new_node->left = NULL;
      new_node->right = NULL;
      t->right = new_node;
    } else {
      insert(t->right, data);
    }
  }
  if (data < t->data) {
    if (t->left == NULL) {
      bst_t *new_node = (bst_t *)malloc(sizeof(bst_t));
      new_node->data = data;
      new_node->left = NULL;
      new_node->right = NULL;
      t->left = new_node;
    } else {
      insert(t->left, data);
    }
  }
  return t;
}

bst_t *delete_tree(bst_t *t,int data){
  if(t==NULL){
    return t;
  }
  if(data == t->data){
    if(t->left == NULL && t->right == NULL){
      free(t);
      return NULL;
    }
    else if(t->left != NULL && t->right != NULL){
      int new_value = find_min(t->right);
      t->data = new_value;
      t->right = delete_tree(t->right,new_value);
      return t;
    }
    else if(t->left != NULL){
      bst_t *tmp = t->left;
      free(t);
      return tmp;
    }
     else if(t->right != NULL){
      bst_t *tmp = t->right;
      free(t);
      return tmp;
    }
  }
  if(data > t->data){
    t->right = delete_tree(t->right,data);
  }
  else if(data < t->data){
    t->left = delete_tree(t->left,data);
  }
  return t;
}

int main(void) {
  bst_t *t = NULL;
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
      t = delete_tree(t, data);
      break;
    case 3:
      scanf("%d", &data);
      printf("%d\n", find(t, data));
      break;
    case 4:
      printf("%d\n", find_min(t));
      break;
    case 5:
      printf("%d\n", find_max(t));
      break;
    }
  }
  return 0;
}


// 13
// 1 50
// 1 8
// 1 61
// 1 1
// 1 35
// 1 87
// 2 50
// 3 50
// 2 8
// 2 61
// 3 8
// 3 87
// 3 61