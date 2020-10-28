#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#ifndef PROJECT_GRAPH_ADJ_LIST_H
#define PROJECT_GRAPH_ADJ_LIST_H

const int Initial_cap = 8;

typedef struct{
    int v;
    int e;
    struct neighbors {
        int size;
        int capacity;
        int* edges;        // vector of all edges to the vertex;
    } *adj_list[];          // vector to hold all vertices

} directed_graph;

directed_graph* initialize_dg(const int v);

void add_directed_edge(directed_graph* dg, const int src, const int des);

void add_undirected_edge(directed_graph* dg, const int src, const int des);

void dgraph_dfs(directed_graph* dg);

static void dgraph_dfs_reachable(directed_graph* dg, int visited[], const int vertex);

#endif
