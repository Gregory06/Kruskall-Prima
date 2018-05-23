

class MinimalSpanningTree
{
public:
    LonleyEdge * jorney = nullptr;
    int size = 0;
};

MinimalSpanningTree Kruskala(GraphEdges graph_edges, GraphMatrix graph_matrix)
{
    qsort(graph_edges.edges_list, graph_edges.e_quanity, sizeof(LonleyEdge), graph_edges.EdgeCmp);

    MinimalSpanningTree min_span_tree;
    min_span_tree.jorney = new LonleyEdge [graph_edges.e_quanity];

    DisjointSet v_dsjnt_set(graph_matrix.v_quntity);

    for (int i = 0; i < graph_edges.e_quanity; i++)
    {
        if (v_dsjnt_set.Find(graph_edges.edges_list[i].the_first_point) !=
            v_dsjnt_set.Find(graph_edges.edges_list[i].the_second_point))
        {
            min_span_tree.jorney[min_span_tree.size++] = graph_edges.edges_list[i];
            v_dsjnt_set.Union(v_dsjnt_set.Find(graph_edges.edges_list[i].the_first_point),
                              v_dsjnt_set.Find(graph_edges.edges_list[i].the_second_point));
        }
    }
    return min_span_tree;
}
