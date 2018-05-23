

class DisjointSet
{
public:
    int * set = nullptr;
    size_t set_quntity = 0;

    DisjointSet(unsigned int v_num);
    void Union(int first_set_num, int second_set_num);
    int Find(int elem);
};

DisjointSet::DisjointSet(unsigned int v_num)
{
    set_quntity = v_num;
    set = new int [set_quntity];
    for (int i = 0; i < set_quntity; i++)
    {
        set[i] = i;
    }
}

void DisjointSet::Union(int first_set_num, int second_set_num)
{
    int new_set_num = Min(first_set_num, second_set_num);
    int set_num_to_del = Max(first_set_num, second_set_num);

    for (int i = 0; i < set_quntity; i++)
        if (set[i] == set_num_to_del)
            set[i] = new_set_num;
}

int DisjointSet::Find(int elem)
{
    return set[elem];
}