

#include <string>
#include <iostream>
#include <cstddef>
#include "OtherFunctions.h"
#include "Set.h"
#include "GraphMatrix.h"
#include "GraphEdges.h"
#include "Kruskala.h"
#include "GraphVertex.h"
#include "Prima.h"

std::string filename = "/Users/MyMac/CLionProjects/TopProgramming/Kruskala/input_graph.txt"; // ##### ACHTUNG change it on your ordinator!!!


int main() {

    GraphMatrix graph_matrix(filename);

    for (int i = 0; i < graph_matrix.v_quntity; i++)
    {
        for (int j = 0; j < graph_matrix.v_quntity; j++)
            printf("%d   ", graph_matrix.graph_matrix[i][j]);
        printf("\n");
    }

    GraphEdges graph_edges(graph_matrix);

    std::cout << "\n";
    //----------------------------------------------------------\begin{Kruskala}
    std::cout << "By Kruskala";
    MinimalSpanningTree answer = Kruskala(graph_edges, graph_matrix);
    for (int l = 0; l < answer.size; l++)
        printf("(%d, %d)\n", answer.jorney[l].the_first_point+1, answer.jorney[l].the_second_point+1);
    //----------------------------------------------------------\end{Kruskala}
    std::cout << "\n";
    //----------------------------------------------------------\begin{Prima}
    answer = Prima(graph_matrix);
    std::cout << "By Prima";
    for (int l = 1; l < answer.size; l++)
        printf("(%d, %d)\n", answer.jorney[l].the_first_point+1, answer.jorney[l].the_second_point+1);
    //----------------------------------------------------------\end{Prima}

    return 0;
}