

class LonleyEdge
{
public:
    int the_first_point = -1;
    int the_second_point = -1;

    int weight = -1;
};

class GraphEdges
{
public:
    LonleyEdge * edges_list = nullptr;
    int e_quanity = 0;

    GraphEdges(GraphMatrix graph_matrix);
    static int EdgeCmp(const void * a, const void * b);
};

GraphEdges::GraphEdges(GraphMatrix graph_matrix)
{
    for (int j = 0; j < graph_matrix.v_quntity; j++)
        for (int k = j; k < graph_matrix.v_quntity; k++)
            if (graph_matrix.graph_matrix[j][k])
                e_quanity++;

    edges_list = new LonleyEdge [e_quanity];

    int cur = 0;
    for (int j = 0; j < graph_matrix.v_quntity; j++)
        for (int k = j; k < graph_matrix.v_quntity; k++)
            if (graph_matrix.graph_matrix[j][k])
            {
                edges_list[cur].weight = graph_matrix.graph_matrix[j][k];
                edges_list[cur].the_first_point = j;
                edges_list[cur++].the_second_point = k;
            }
}

int GraphEdges::EdgeCmp(const void * a, const void * b)
{
    LonleyEdge * x = (LonleyEdge *) a;
    LonleyEdge * y = (LonleyEdge *) b;

    return (x->weight - y->weight);
}