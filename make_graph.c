/**
*   @file make_graph.c
*   @brief This is the part where I made the graph, based on the adjancy matrix.
*
*   @author Stoian Andreea-Maria
*
*   @date 7/06/2018
*/

#include<stdio.h>
#include <assert.h>
#include"make_graph.h"


void set_adj_matrix_value(struct a_graph *graph, int row_index, int column_index, int element_value){
    int position;

    assert(row_index < graph->no_nodes);
    assert(column_index < graph->no_nodes);
    position = row_index * graph->no_nodes + column_index;
    *(graph->adj_matrix + position) = element_value;
}

int get_adj_matrix_value(struct a_graph *graph, int row_index, int column_index) { //returneaza ce a facut set
    int position;

    assert(row_index < graph->no_nodes);
    assert(column_index < graph->no_nodes);
    if (graph->init == 1){
        position = row_index * graph->no_nodes + column_index;
        return *(graph->adj_matrix + position);
    }else{
        printf("Please read the graph first");
        return -1;
    }
}

void init_graph_file(struct a_graph *graph){
    FILE *file_in;
    int iterator_rows;
    int iterator_columns;
    int aux;

    file_in = fopen("graph.txt", "r");
    if (file_in == NULL){
        printf("\n File does not exist.");
        fclose(file_in);
        return;
    }


    fscanf(file_in, "%d", &graph->no_nodes);
    graph->init = 1;
    graph->adj_matrix = calloc(graph->no_nodes * graph->no_nodes, sizeof(int));

    assert((graph->no_nodes * graph->no_nodes) > 0);


    for (iterator_rows = 0; iterator_rows < graph->no_nodes; iterator_rows++ ){
        for (iterator_columns = 0; iterator_columns < graph->no_nodes; iterator_columns++ ){
            fscanf(file_in, "%d ", &aux);
            set_adj_matrix_value(graph, iterator_rows, iterator_columns, aux);

        }
    }

    fclose(file_in);
    printf("=== Reading from file successfull ===\n");
}
