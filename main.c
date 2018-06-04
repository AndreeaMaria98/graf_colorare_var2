#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "make_graph.h"
#include "print_adj_matrix.h"
#include "backtracking.h"

/**
*   @file main.c
*   @brief I solved this problem with the backtracking method.
*
*   @author Stoian Andreea-Maria
*
*   @date 7/06/2018
*/

int main()
{
    int colors_number;
    int *colors;
    struct a_graph *graph = calloc(1,sizeof(struct a_graph));

    ///Here I call the construction function of the graph.
    init_graph_file(graph);

    print_adj_matrix(graph);

    ///I used a vector for the given colors
    int *colored_vector = calloc(graph->no_nodes,sizeof(int));

    backtracking(colored_vector, 0, graph);

    return 0;
}
