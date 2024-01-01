#include <stdio.h>
#include <stdlib.h>
#define MAX_VALUE 50000

struct node {
  int data;
  int weight;
  struct node *next_node;
} typedef node_t;

struct graph {
  int last_index;
  struct node **node_arr;
} typedef graph_t;

struct vertex {
  int data;
  int short_length;
  int previous_vertex;
} typedef vertex_t;

graph_t *create_graph(int n){
  graph_t *gr = (graph_t *)malloc(sizeof(graph_t));
  node_t **node_arr = (node_t **)malloc(sizeof(node_t*)*n);
  gr->last_index = -1;
  gr->node_arr = node_arr;
  return gr;
}

int find_node(int n,graph_t *gr){
  for(int i = 0 ; i < gr->last_index+1 ; i++){
    if(gr->node_arr[i]->data == n){
      return i;
    }
  }
  return -1;
}

int find_pos_vertex(int data,vertex_t **ver,int n){
  for(int i = 0 ; i < n ; i++){
    if(ver[i]->data == data){
      return i;
    }
  }
  return -1;
}

graph_t *create_pair(int u,int v,int w,graph_t *gr){
  int pos_u = find_node(u,gr);
  //check that u is already in node_arr?
  if(pos_u == -1){
    node_t *node_u = (node_t *)malloc(sizeof(node_t));
    node_u->data = u;
    node_u->next_node = NULL;
    node_u->weight = 0;
    gr->last_index++;
    gr->node_arr[gr->last_index] = node_u;
    //update new u position
    pos_u = gr->last_index;
  }
  int pos_v = find_node(v,gr);
  if(pos_v == -1){
    node_t *node_v = (node_t *)malloc(sizeof(node_t));
    node_v->data = v;
    node_v->next_node = NULL;
    node_v->weight = 0;
    gr->last_index++;
    gr->node_arr[gr->last_index] = node_v;
    pos_v = gr->last_index;
  }
  node_t *tmp = gr->node_arr[pos_u]->next_node;
  node_t *chi_node_u = (node_t *)malloc(sizeof(node_t));
  chi_node_u->data = v;
  chi_node_u->next_node = tmp;
  chi_node_u->weight = w;
  gr->node_arr[pos_u]->next_node = chi_node_u;
  tmp = gr->node_arr[pos_v]->next_node;
  node_t *chi_node_v = (node_t *)malloc(sizeof(node_t));
  chi_node_v->data = u;
  chi_node_v->next_node = tmp;
  chi_node_v->weight = w;
  gr->node_arr[pos_v]->next_node = chi_node_v;
  return gr;
}

int is_visited(int node , int *node_visited , int n){
  for(int i = 0 ; i < n ; i++){
    if(node_visited[i] == node){
      return 1;
    }
  }
  return 0;
}

int *add_visited(int *node_visited,int data,int n){
  for(int i = 0 ; i < n ; i++){
    if(node_visited[i] == -1){
      node_visited[i] = data;
      return node_visited;
    }
  }
}

void runner(graph_t *gr,vertex_t **ver,int *node_visited,int pos_now){
  // printf("Im %d\n",ver[pos_now]->data);
  if(is_visited(ver[pos_now]->data,node_visited,gr->last_index+1)){
    return ;
  }
  int pos_gr = find_node(ver[pos_now]->data,gr);
  node_t *tmp = gr->node_arr[pos_gr]->next_node;
  while(tmp != NULL){
    int tmp_pos = find_pos_vertex(tmp->data,ver,gr->last_index+1);
    if(tmp->weight+ver[pos_now]->short_length < ver[tmp_pos]->short_length){
      ver[tmp_pos]->short_length = tmp->weight+ver[pos_now]->short_length;
      ver[tmp_pos]->previous_vertex = ver[pos_now]->data;
      // printf("UPDATE %d with %d\n",ver[tmp_pos]->data,ver[tmp_pos]->short_length);
    }
    tmp = tmp->next_node;
  }
  node_visited = add_visited(node_visited,ver[pos_now]->data,gr->last_index+1);
  int smallest_length = MAX_VALUE;
  int smallest_num = 0;
  for(int i = 0 ; i < gr->last_index+1 ; i++){
    if(ver[i]->short_length <= smallest_length && !is_visited(ver[i]->data,node_visited,gr->last_index+1)){
      smallest_num = ver[i]->data;
      smallest_length = ver[i]->short_length;
    }
  }
  int new_pos = find_pos_vertex(smallest_num,ver,gr->last_index+1);
  runner(gr,ver,node_visited,new_pos);
}

vertex_t **generate_vertex(graph_t *gr){
  int n = gr->last_index+1;
  int max_value = MAX_VALUE;
  vertex_t **ver = (vertex_t **)malloc(sizeof(vertex_t*)*n);
  for(int i = 0 ; i < n ; i++){
    ver[i] = (vertex_t *)malloc(sizeof(vertex_t));
    ver[i]->data = gr->node_arr[i]->data;
    ver[i]->short_length = max_value;
  }
  return ver;
}

void print_ver(vertex_t **ver,int n){
  for(int i = 0 ; i < n ;  i++){
    printf("%d  %d  %d\n",ver[i]->data,ver[i]->short_length,ver[i]->previous_vertex);
  }
}

void print_graph(graph_t *gr){
  node_t *head = NULL;
  for(int i = 0 ; i < gr->last_index+1 ; i++){
    head = gr->node_arr[i];
    printf("%d -> ",head->data);
    head = head->next_node;
    while(head != NULL){
      printf("weight : %d node : %d ",head->weight,head->data);
      head = head->next_node;
    }
    printf("\n");
  }
  printf("\n");
}

int find_shortest_path(int a,int b,graph_t *gr){
  vertex_t **ver = generate_vertex(gr);
  int pos_start = find_pos_vertex(a,ver,gr->last_index+1);
  ver[pos_start]->short_length = 0;
  int *node_visited = (int *)malloc(sizeof(int)*gr->last_index+1);
  for(int i = 0 ; i < gr->last_index+1 ; i++){
    node_visited[i] = -1;
  }
  runner(gr,ver,node_visited,pos_start);
  // print_ver(ver,gr->last_index+1);
  int pos_des = find_pos_vertex(b,ver,gr->last_index+1);
  if(ver[pos_des]->short_length == MAX_VALUE){
    return -1;
  }
  return ver[pos_des]->short_length;
}

int main(void) {
  int n,m,p,u,v,w;
  scanf("%d %d %d", &n,&m,&p);
  graph_t *gr = create_graph(n);
  for(int i = 0 ; i < m ; i++){
    scanf("%d %d %d",&u,&v,&w);
    gr = create_pair(u, v, w, gr);
  }
  // print_graph(gr);
  int a,b;
  for(int i = 0 ; i < p ; i++){
    scanf("%d %d",&a,&b);
    printf("%d\n",find_shortest_path(a,b,gr));
  }
  return 0;
}
