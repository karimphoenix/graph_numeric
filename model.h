#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include "graph_cdef.h"

class model{
    graph g;

    bool fill_graph();
    bool print_graph();

    bool do_sort();
};

#endif // MODEL_H_INCLUDED
