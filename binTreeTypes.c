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

typedef struct node2 {
  tree_t *tree;
  struct node2 *next;
} node2_t;
typedef node2_t queue_t;

queue_t *pop(queue_t *s) {
  if (s == NULL) {
    return NULL;
  }
  queue_t *tmp = s;
  s = s->next;
  free(tmp);
  return s;
}

void print_queue(queue_t *s){
  while(s!=NULL){
    printf("%d ",s->tree->data);
    s=s->next;
  }
}

queue_t *enqueue(queue_t *s, tree_t *t) {
  queue_t *new_node = NULL;
  new_node = (queue_t *)malloc(sizeof(queue_t));
  new_node->tree = t;
  new_node->next = NULL;
  if (s == NULL) {
    return new_node;
  }
  queue_t *run = s;
  while (run->next != NULL) {
    run = run->next;
  }
  run->next = new_node;
  return s;
}

int is_full(tree_t *t) {
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

int is_complete(tree_t *t) {
  if (t == NULL || (t->left == NULL && t->right == NULL)) {
    return 1;
  }
  // printf("Checking at %d\n",t->data);
  int d_l = depth(t->left);
  // printf("D_l : %d\n",d_l);
  int d_r = depth(t->right);
  if (d_r > d_l) {
    // printf("D_R > D_L\n");
    return 0;
  }
  if (d_l > d_r) {
    if (d_l - d_r != 1) {
      return 0;
    }
  }
  if (d_l == d_r) {
    int l_full = is_full(t->left);
    if (!l_full) {
      // printf("L_FULL\n");
      return 0;
    }
    // printf("L NOT FULL\n");
  }
  int depth_s = 0;
  queue_t *s = NULL;
  s = enqueue(s, t);
  int count = 1;
  while (depth_s - 1 != d_l) {
    // printf("At Depth %d\n",depth_s);
    if (count != pow(2, depth_s)) {
      // printf("COUNT DOESNT MATCH\n");
      return 0;
    }
    depth_s++;
    if (depth_s - 1 == d_l) {
      // printf("Will Handle\n");
      break;
    }
    // printf("Try Adding Depth %d\n",depth_s);
    count = 0;

    for (int i = 0; i < pow(2, depth_s - 1); i++) {
      if (s->tree->left != NULL) {
        s = enqueue(s, s->tree->left);
        count++;
        // printf("Count : %d\n",count);
      }
      if (s->tree->right != NULL) {
        s = enqueue(s, s->tree->right);
        count++;
        // printf("Count : %d\n",count);
      }
      s = pop(s);
    }
  }
  // print_queue(s);
  // printf("\n");
  int readytoleave = 0;
  while (s != NULL) {
    if (readytoleave) {
      if (s->tree->left != NULL || s->tree->right != NULL) {
        return 0;
      }
    }
    if(s->tree->left != NULL && s->tree->right == NULL){
      readytoleave = 1;
    }
    if(s->tree->left == NULL && s->tree->right == NULL && !readytoleave){
      readytoleave = 1;
    }
    s = pop(s);
  }
  // printf("In the End\n");
  return 1;
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


// 6
// -1 1 0
// 1 2 1
// 1 3 2
// 2 4 1
// 2 5 2
// 3 6 1
// 3 7 2
// 4 8 1
// 4 9 2
// 5 10 2
