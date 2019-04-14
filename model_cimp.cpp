#include <fstream>
#include "model.h"

model::do_sort(){
    return g.graph_sort();
}

model::fill_graph(){
    string file_name = "input.txt";

    ifstream line(file_name);

    int i = 1;
    edge i_edge;
    flag = false;
    while(line >> i_edge){
        i_edge.set_edge_number(i);
        g.graph.push_back(i_edge);
    }
    flag = true;

    return flag;
}

model::print_graph(){
    string file_name = "output.txt";

    ofstream line(file_name);

    for(auto v:g.copy_graph)
        line << v;

}
