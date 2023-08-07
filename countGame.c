#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int count;
    int limit;
    int player_num;
    struct node *next;
} node_t;

node_t *append(node_t *p, int num, int player_i) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->count = 0;
    node->limit = num;
    node->player_num = player_i;
    node->next = NULL;
    
    if (p == NULL) {
        return node;
    } else {
        node_t *tmp = p;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = node;
        return p;
    }
}

node_t *circular(node_t *p) {
    node_t *tmp = p;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = p;
    return tmp;
}

node_t *cut(node_t *prevnode, node_t *curnode) {
    node_t *next_node = curnode->next;
    prevnode->next = next_node;
    return prevnode;
}

int main(void) {
    node_t *startNode = NULL;
    int n, k;
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        startNode = append(startNode, num, i + 1);
    }
    
    node_t *tmp;
    tmp = circular(startNode);
    int i = 1;
    int value = tmp->player_num;
    
    while (startNode->next != startNode) {
        if (i % k == 0) {
            startNode->count++;
        } else {
            int l = i;
            while (l != 0) {
                if (l % 10 == k) {
                    startNode->count++;
                    break;
                } else {
                    l /= 10;
                }
            }
        }
        
        if (startNode->count > startNode->limit) {
            startNode = cut(tmp, startNode);
        }
        
        value = startNode->player_num;
        tmp = startNode;
        startNode = startNode->next;
        i++;
    }
    
    printf("%d", value);
    
    // Clean up: Free allocated memory
    tmp->next = NULL;
    while (startNode != NULL) {
        node_t *temp = startNode;
        startNode = startNode->next;
        free(temp);
    }
    
    return 0;
}
