

class GraphVertex
{
public:
    int number = -1;
    int key = -1;
    int origin = -1;

    GraphVertex operator = (GraphVertex a);
};

GraphVertex GraphVertex::operator = (GraphVertex a)
{
    this->key = a.key;
    this->number = a.number;
    this->origin = a.origin;

    return *this;
}

class GraphVertexes
{
public:
    GraphVertex * vertex_list;
    int list_size = -1;
    int avalible = -1;

    GraphVertexes(int list_size);
};


GraphVertexes::GraphVertexes(int v_quantity)
{
    vertex_list = new GraphVertex [v_quantity];
    list_size = avalible = v_quantity;
    for (int i = 0; i < list_size; i++)
    {
        vertex_list[i].number = i;
        vertex_list[i].key = 100500;
    }
}