#include <stdio.h>
#include <stdlib.h>
typedef struct cell {
  int data;
  int mem_addr;
} cell_t;
typedef struct hash {
  cell_t *table;
  int cache_size;
} hash_t;
typedef hash_t cache_t;
typedef int memory_t;
memory_t *init_memory(int size) {
  memory_t *memory = (memory_t *)malloc(sizeof(memory_t) * size);
  int i = 0;
  // Randomly assign integers to memory
  for (i = 0; i < size; i++)
    memory[i] = rand();
  return memory;
}

int find_pos(memory_t *mk,int k){
  // for(int i = 0 ; i < mk-> ;)
}

int cache_index(cache_t *c,int mem_addr){
  // printf("Cache : %d Mem_addr : %d\n",c->cache_size,mem_addr);
  return mem_addr % c->cache_size;
}

int findcache(cache_t *c,int mem_addr,int pos){
  if(c->table[pos].mem_addr == 0 && c->table[pos].data == 0){
    return 0;
  }
  if(mem_addr == c->table[pos].mem_addr){
    // printf("Found at %d  :  %d  %d\n",pos,c->table[pos].mem_addr,c->table[pos].data);
    return 1;
  }
  return 2;
}

cache_t *init_cache(int cache_size){
  cache_t *c = (cache_t *)malloc(sizeof(cache_t));
  c->cache_size = cache_size;
  cell_t *arr = (cell_t *)malloc(sizeof(cell_t) * cache_size);
  c->table = arr;
  return c;
}

void get_data(int addr , memory_t *m , cache_t *c){
  int pos = cache_index(c,addr);
  int isfind = findcache(c,addr,pos);
  if(isfind == 1){
    printf("Address %d is loaded\n",addr);
  }else if (isfind == 0){
    c->table[pos].mem_addr = addr;
    c->table[pos].data = m[addr];
    printf("Load from memory\n");
  }
  else if (isfind == 2){
    c->table[pos].mem_addr = addr;
    c->table[pos].data = m[addr];
    printf("Index: %d is used\n",pos);
    printf("Load from memory\n");
  }
  printf("Data: %d\n",m[addr]);
}

int main(void) {
  memory_t *memory = NULL;
  cache_t *cache = NULL;
  int memory_size, cache_size;
  int i, n, addr;
  scanf("%d %d %d", &memory_size, &cache_size, &n);
  memory = init_memory(memory_size);
  cache = init_cache(cache_size);
  for (i = 0; i < n; i++) {
    printf("Load address: ");
    scanf("%d", &addr);
    get_data(addr, memory, cache);
  }
  return 0;
}