#include "graph.c"
#include "graph.h"

int main(){
    directed_graph* dg = initialize_dg(6);

    add_directed_edge(dg, 1, 2);
    add_directed_edge(dg, 2, 3);
    add_directed_edge(dg, 2, 4);
    add_directed_edge(dg, 3, 5);
    add_directed_edge(dg, 4, 3);

    dgraph_dfs(dg);

    return 0;
}
