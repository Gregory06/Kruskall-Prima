

GraphVertex ExtractMin(GraphVertexes * vertexes);

MinimalSpanningTree Prima(GraphMatrix graph_matrix, int vertex_to_begin = 0)
{
    GraphVertexes vertexes(graph_matrix.v_quntity);
    vertexes.vertex_list[vertex_to_begin].key = 0;
    vertexes.vertex_list[vertex_to_begin].origin = 0;

    MinimalSpanningTree min_span_tree;
    min_span_tree.jorney = new LonleyEdge [100];

    GraphVertex new_vert;
    while(vertexes.avalible != 0)
    {
        new_vert = ExtractMin(&vertexes);
        min_span_tree.jorney[min_span_tree.size].the_first_point = new_vert.number;
        min_span_tree.jorney[min_span_tree.size++].the_second_point = new_vert.origin;

        for (int i = 0; i < graph_matrix.v_quntity; i++)
        {
            if (graph_matrix.graph_matrix[new_vert.number][i])
                if ((new_vert.key != -2) &&
                    (graph_matrix.graph_matrix[new_vert.number][i] < vertexes.vertex_list[i].key))
                {
                    vertexes.vertex_list[i].origin = new_vert.number;
                    vertexes.vertex_list[i].key = graph_matrix.graph_matrix[new_vert.number][i];
                }
        }
    }
    return min_span_tree;
}

GraphVertex ExtractMin(GraphVertexes * vertexes)
{
    GraphVertex vertex_to_return = * new GraphVertex;
    int num_to_ret = -1;
    vertex_to_return.key = 100500;
    for (int i = 0; i < vertexes->list_size; i++)
        if ((vertexes->vertex_list[i].key < vertex_to_return.key) &&
            (vertexes->vertex_list[i].key != -2))
        {
            vertex_to_return = vertexes->vertex_list[i];
            num_to_ret = i;
        }

    vertexes->vertex_list[num_to_ret].key = -2;
    vertexes->avalible--;

    return vertex_to_return;
}