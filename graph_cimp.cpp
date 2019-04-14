#include <math.h>
#include "graph_cdef.h"


vertex::vertex(int number, int summ_weight){
    //v.first  = number;
    //v.second = summ_weight;

    v = std::make_pair(number, summ_weight);
};

void vertex::add_weight(int weight){
    v.second += weight;
};

vertex& vertex::operator+=(const vertex& rhs){
    add_weight(rhs.v.second);

    return *this;
};

vertex operator+(vertex lhs, const vertex& rhs){
    lhs += rhs;

    return lhs;
};

bool operator<(const vertex& lhs, const vertex& rhs){
    return (lhs.v.second - rhs.v.second) < 0;
};

inline bool operator>(const vertex& lhs, const vertex& rhs){return rhs < lhs;}
inline bool operator<=(const vertex& lhs, const vertex& rhs){return !(lhs > rhs);}
inline bool operator>=(const vertex& lhs, const vertex& rhs){return !(lhs < rhs);}

inline bool operator==(const vertex& lhs, const vertex& rhs){return (lhs <= rhs && lhs >= rhs);}
inline bool operator!=(const vertex& lhs, const vertex& rhs){return !(lhs == rhs);}

edge::edge(pair<vertex, vertex> i_arr_v, pair<int, int> i_info){
    arr_v = std::make_pair(i_arr_v.first, i_arr_v.second);
    info = std::make_pair(i_info.first, i_info.second);
}
edge::edge(vertex v_start, vertex v_end, int number, int weight){
    //arr_v.first  = v_start;
    //arr_v.second = v_end;

    arr_v = std::make_pair(v_start, v_end);

    //info.first  = number;
    //info.second = weight;

    info = std::make_pair(number, weight);

};



//edge::set_edge_number(int number){ info.first = number };

std::ostream& operator<<(std::ostream& os, const vertex& o_vertex){
    return os << o_vertex.v.number << " " << o_vertex.v.second;
};

std::istream& operator>>(std::istream& is, const vertex& i_vertex){
    is >> i_vertex.v.first >> " " >> i_vertex.v.second;

    return is;

};

std::ostream& operator<<(std::ostream& os, const edge& o_edge){
    return os << o_edge.arr_v.first << "\t" << o_edge.arr_v.second << "\t"
              << o_edge.info.number << "\t" << o_edge.info.weight;
};

std::istream& operator>>(std::istream& is, const edge& i_edge){
    is >> i_v_start >> " " >> i_v_end >> "\t" >> i_weight;

    vertex v_start(i_v_start, 0);
    vertex v_end(i_v_end, 0);

    i_edge(v_start, v_end, 0, i_weight);

    return is;
};

/*graph:graph(){

};*/

bool graph::sort_graph(){
    bool flag = false;
    std::copy(old_graph.begin(), old_graph.end(), numeric_graph.begin(), numeric_graph.end());

    std::sort(numeric_graph.begin(), numeric_graph.end());

    std::reverse(numeric_graph.begin(), numeric_graph.end());

    flag = true;

    return flag;

}
