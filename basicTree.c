#include <stdio.h>
#include <stdlib.h>

typedef struct noded {
  int value;
  struct noded *next_sibling;
  struct noded *first_child;
} noded_t;
typedef noded_t tree_t;

typedef struct node {
  tree_t *tree_node;
  struct node *next;
} node_t;

typedef node_t queue_t;
typedef node_t stack_t;

void show(queue_t *s) {
  if (s == NULL) {
    printf("Queue is empty.");
  } else {
    while (s != NULL) {
      printf("%d ", s->tree_node->value);
      s = s->next;
    }
  }
  printf("\n");
}

queue_t *enqueue(queue_t *s, tree_t *tnode) {
  queue_t *node = (queue_t *)malloc(sizeof(queue_t));
  node->tree_node = tnode;
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
  free(tmp);
  return s;
}

stack_t *push(stack_t *s, tree_t *value) {
  stack_t *node = (stack_t *)malloc(sizeof(stack_t));
  node->tree_node = value;
  node->next = NULL;
  if (s == NULL) {
    return node;
  }
  node->next = s;
  return node;
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

tree_t *search_pos(tree_t *t, int k) {
  if (t == NULL) {
    return NULL;
  }
  if (t->value == k) {
    return t;
  }
  tree_t *k1 = search_pos(t->first_child, k);
  tree_t *k2 = search_pos(t->next_sibling, k);
  if (k1 != NULL) {
    return k1;
  }
  if (k2 != NULL) {
    return k2;
  }
}

int search(tree_t *t, int k) {
  if (t == NULL) {
    return 0;
  }
  if (t->value == k) {
    return 1;
  }
  int k1 = search(t->first_child, k);
  int k2 = search(t->next_sibling, k);
  return k1 || k2;
}

tree_t *attach(tree_t *t, int parent, int child) {
  tree_t *node_child = (tree_t *)malloc(sizeof(tree_t));
  node_child->value = child;
  node_child->next_sibling = NULL;
  node_child->first_child = NULL;
  if (parent == -1) {
    return node_child;
  } else {
    tree_t *pos = search_pos(t, parent);
    if (pos->first_child == NULL) {
      pos->first_child = node_child;
    } else {
      tree_t *run = pos->first_child;
      while (run->next_sibling != NULL) {
        run = run->next_sibling;
      }
      run->next_sibling = node_child;
    }
  }
  return t;
}

int is_leaf(tree_t *t, int k) {
  tree_t *p = search_pos(t, k);
  if (p->first_child == NULL) {
    return 1;
  } else {
    return 0;
  }
}

int is_root(tree_t *t, int k) {
  if (t->value == k) {
    return 1;
  } else {
    return 0;
  }
}

void bfs(tree_t *t) {
  if (t != NULL) {
    tree_t *k = t;
    queue_t *s = NULL;
    s = enqueue(s, k);
    while (s != NULL) {
      tree_t *run = s->tree_node->first_child;
      while (run != NULL) {
        s = enqueue(s, run);
        run = run->next_sibling;
      }
      printf("%d ", s->tree_node->value);
      s = dequeue(s);
    }
  }
  printf("\n");
}

void dfs_rec(tree_t *t) {
  if (t == NULL) {
    return;
  }
  printf("%d ", t->value);
  dfs_rec(t->first_child);
  dfs_rec(t->next_sibling);
  return;
}

void dfs(tree_t *t) {
  dfs_rec(t);
  printf("\n");
  return;
}

int depth_rec(tree_t *t, int k) {
  if (t == NULL) {
    return 0;
  }
  if (t->value == k) {
    // printf("Found!! %d\n",k);
    return 1;
  }
  int k1 = depth_rec(t->first_child, k);
  int k2 = depth_rec(t->next_sibling, k);
  if (k1 != 0) {
    // printf("\nPath to 1 !! %d\n",t->value);
    return 1 + k1;
  }
  if (k2 != 0) {
    // printf("\nPath to 0 !! %d\n",t->value);
    return 0 + k2;
  }
}

int depth(tree_t *t, int k) {
  int res = depth_rec(t,k) - 1;
  return res;
}

stack_t *stack_path(tree_t *t, stack_t *path, int k) {
  if (t == NULL) {
    return NULL;
  }
  if (t->value == k) {
    // printf("Found %d\n",t->value);
    path = push(path, t);
    return path;
  }
  stack_t *path1 = stack_path(t->first_child, path, k);
  stack_t *path2 = stack_path(t->next_sibling, path, k);
  if (path1 != NULL) {
    // printf("Push %d\n",t->value);
    // printf("%d\n",path1->tree_node->value);
    path = push(path1, t);
    return path;
  }
  if (path2 != NULL) {
    // printf("Sibling %d\n",t->value);
    return path2;
  }
  return NULL;
}

void print_path(tree_t *t, int start, int end) {
  tree_t *s = search_pos(t, start);
  stack_t *stack_p = NULL;
  stack_p = stack_path(s->first_child, stack_p, end);
  stack_p = push(stack_p, s);
  while (stack_p != NULL) {
    printf("%d ", stack_p->tree_node->value);
    stack_p = stack_p->next;
  }
  printf("\n");
}

void ancestor(tree_t *t, int end) {
  stack_t *stack_p = NULL;
  stack_p = stack_path(t->first_child, stack_p, end);
  stack_p = push(stack_p, t);
  while (stack_p != NULL) {
    printf("%d ", stack_p->tree_node->value);
    stack_p = stack_p->next;
  }
  printf("\n");
}

tree_t *find_parent(tree_t *t, int k) {
  if (t->first_child != NULL && t->value != k) {
    stack_t *stack_p = NULL;
    stack_p = stack_path(t->first_child, stack_p, k);
    stack_p = push(stack_p, t);
    while (stack_p->next->next != NULL) {
      stack_p = pop(stack_p);
    }
    return stack_p->tree_node;
  }
  return NULL;
}

void siblings(tree_t *t, int k) {
  tree_t *p = find_parent(t, k);
  if (p != NULL) {
    p = p->first_child;
    while (p != NULL) {
      if (p->value != k) {
        printf("%d ", p->value);
      }
      p = p->next_sibling;
    }
  }
  printf("\n");
}

void destroy_tree(tree_t *t) {
  if (t != NULL) {
    destroy_tree(t->first_child);
    destroy_tree(t->next_sibling);
    free(t);
  }
}

tree_t *detach(tree_t *t, int k) {
  if (t->value == k) {
    destroy_tree(t->first_child);
    free(t);
    return NULL;
  }
  tree_t *s = search_pos(t, k);
  tree_t *parent = find_parent(t, k);
  if (parent->first_child->value != k) {
    tree_t *run = parent->first_child;
    tree_t *slow = NULL;
    while (run->value != k) {
      slow = run;
      run = run->next_sibling;
    }
    slow->next_sibling = run->next_sibling;
  } else {
    parent->first_child = parent->first_child->next_sibling;
  }
  destroy_tree(s->first_child);
  free(s);
  return t;
}

int path_length_rec(tree_t *t, int start, int end) {
  tree_t *s = search_pos(t, start);
  stack_t *stack_p = NULL;
  stack_p = stack_path(s->first_child, stack_p, end);
  stack_p = push(stack_p, s);
  int n = -1;
  while (stack_p != NULL) {
    n += 1;
    stack_p = stack_p->next;
  }
  return n;
}

int path_length(tree_t *t, int start, int end) {
  int res = path_length_rec(t, start,end) +1;
  return res;
}

void descendant(tree_t *t, int k) {
  tree_t *s = search_pos(t, k);
  bfs(s);
}

int degree(tree_t *t, int k) {
  tree_t *p = search_pos(t, k);
  int n = 0;
  p = p->first_child;
  while (p != NULL) {
    n += 1;
    p = p->next_sibling;
  }
  return n;
}


void print_tree_rec(tree_t *t, int n) {
  if (t == NULL) {
    return;
  }
  for (int i = 0; i < 4 * n; i++) {
    printf(" ");
  }
  printf("%d\n", t->value);
  print_tree_rec(t->first_child, n + 1);
  print_tree_rec(t->next_sibling, n);
  return;
}

void print_tree(tree_t *t){
  print_tree_rec(t,0);
}

int main(void) {
  tree_t *t = NULL;
  int n, i, command;
  int parent, child, node, start, end;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &command);
    switch (command) {
    case 1:
      scanf("%d %d", &parent, &child);
      t = attach(t, parent, child);
      break;
    case 2:
      scanf("%d", &node);
      t = detach(t, node);
      break;
    case 3:
      scanf("%d", &node);
      printf("%d\n", search(t, node));
      break;
    case 4:
      scanf("%d", &node);
      printf("%d\n", degree(t, node));
      break;
    case 5:
      scanf("%d", &node);
      printf("%d\n", is_root(t, node));
      break;
    case 6:
      scanf("%d", &node);
      printf("%d\n", is_leaf(t, node));
      break;
    case 7:
      scanf("%d", &node);
      siblings(t, node);
      break;
    case 8:
      scanf("%d", &node);
      printf("%d\n", depth(t, node));
      break;
    case 9:
      scanf("%d %d", &start, &end);
      print_path(t, start, end);
      break;
    case 10:
      scanf("%d %d", &start, &end);
      printf("%d\n", path_length(t, start, end));
      break;
    case 11:
      scanf("%d", &node);
      ancestor(t, node);
      break;
    case 12:
      scanf("%d", &node);
      descendant(t, node);
      break;
    case 13:
      bfs(t);
      break;
    case 14:
      dfs(t);
      break;
    case 15:
      print_tree(t);
      break;
    }
  }
  return 0;
}
// 10
// 1 -1 1
// 1 1 2
// 1 1 3
// 1 2 4
// 1 3 5
// 13

// 15
// 1 -1 1
// 1 1 2
// 1 1 3
// 1 2 4
// 1 2 5
// 1 3 6
// 1 3 7
// 1 4 8
// 1 5 9
// 1 5 10
// 1 6 11
// 1 6 12
// 1 6 13
// 1 13 14
// 13

// 23
// 1 -1 1
// 1 1 2
// 1 1 3
// 1 2 4
// 1 2 5
// 1 3 6
// 1 3 7
// 1 4 8
// 1 5 9
// 1 5 10
// 1 6 11
// 1 6 12
// 1 6 13
// 1 13 14
// 8 1
// 8 2
// 8 3
// 8 4
// 8 7
// 8 8
// 8 9
// 8 10
// 8 14
