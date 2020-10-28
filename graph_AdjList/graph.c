#include "graph.h"

directed_graph* initialize_dg(const int v){
    directed_graph *g = malloc (sizeof(directed_graph) + sizeof(struct neighbors*) * v);
    g->e = 0;
    g->v = v;

    for(int i = 0; i < v; i++){
        g->adj_list[i] = malloc (sizeof(struct neighbors));
        g->adj_list[i]->size = 0;
        g->adj_list[i]->capacity = Initial_cap;
        g->adj_list[i]->edges = malloc (sizeof(int) * Initial_cap);
    }

    return g;
}

void add_directed_edge(directed_graph* dg, const int src, const int des){
    assert(src >= 0 && src < dg->v);
    assert(des >= 0 && des < dg->v);

    if (dg->adj_list[src]->size == dg->adj_list[src]->capacity){
        dg->adj_list[src]->capacity *= 2;
        dg->adj_list[src]->edges = realloc (dg->adj_list[src]->edges, sizeof(int) * dg->adj_list[src]->capacity);
    }

    dg->adj_list[src]->edges[dg->adj_list[src]->size++] = des;

    dg->e++;
}

void add_undirected_edge(directed_graph* dg, const int src, const int des){
    add_directed_edge(dg, src, des);
    add_directed_edge(dg, des, src);
}

void dgraph_dfs(directed_graph* dg) {
    int visited[dg->v];
    memset(visited, 0, sizeof(visited));

    for (int v = 0; v < dg->v; ++v) {
      dgraph_dfs_reachable(dg, visited, v);
    }
}

static void dgraph_dfs_reachable(directed_graph* dg, int visited[], const int vertex) {
    visited[vertex] = 1;
    printf("\n%d: ", vertex);

    for (int i = 0; i < dg->adj_list[vertex]->size; i++){
        int adj_vertex = dg->adj_list[vertex]->edges[i];

        if (visited[adj_vertex] == 0){
            printf("\t%d -> %d, ", vertex, adj_vertex);
            dgraph_dfs_reachable(dg, visited, adj_vertex);
        }
    }
}
