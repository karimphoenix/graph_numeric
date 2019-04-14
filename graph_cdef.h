#ifndef GRAPH_CDEF_H_INCLUDED
#define GRAPH_CDEF_H_INCLUDED

//#include <pair>
#include <vector>

using std::pair;
using std::vector;

class vertex{
    pair<int, int> v;

    vertex(int number, int summ_weight);

    void add_weight(int weight);

    vertex& operator+=(const vertex& rhs);

    friend vertex operator+(vertex lhs, const vertex& rhs);

    friend bool operator<(const vertex& l, const vertex& r);

    friend bool operator>(const vertex& lhs, const vertex& rhs);
    friend bool operator<=(const vertex& lhs, const vertex& rhs);
    friend bool operator>=(const vertex& lhs, const vertex& rhs);

    friend bool operator==(const vertex& lhs, const vertex& rhs);
    friend bool operator!=(const vertex& lhs, const vertex& rhs);



};

class edge{
    pair<vertex, vertex> arr_v;
    pair<int, int> info;

    edge(pair<vertex, vertex> arr_v, pair<int, int> info);

    edge(vertex v_start, vertex v_end, int number, int weight);

    void set_edge_number(int i_number){info.first = i_number;};



};

class graph{
    vector<edge> graph;
    vector<edge> copy_graph;

    vector<vertex> old_graph;
    vector<vertex> numeric_graph;

    //graph();

    bool sort_graph();
    void print_edges();
    void print_vertexes();
};


#endif // GRAPH_CDEF_H_INCLUDED
