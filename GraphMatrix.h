

#include <cassert>

class GraphMatrix
{
public:
    int ** graph_matrix = nullptr;
    int v_quntity = 0;


    GraphMatrix(const std::string filename);
};

GraphMatrix::GraphMatrix(const std::string filename)
{
    FILE * file = nullptr;

    file = fopen(filename.data(), "r");
    assert(file);
    fscanf(file, "%d", &v_quntity);

    graph_matrix = new int * [v_quntity];
    for (int k = 0; k < v_quntity; ++k)
        graph_matrix[k] = new int [v_quntity];

    for (int i = 0; i < v_quntity; i++)
        for (int j = 0; j < v_quntity; j++)
            fscanf(file, "%d", &graph_matrix[i][j]);
}
