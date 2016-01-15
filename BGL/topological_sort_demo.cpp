#include<boost/graph/topological_sort.hpp>
#include "digraph_def.h"


int main(){
    Graph G = DAG_toy_ex();
    vector<Vertex> c; // container
    topological_sort(G, back_inserter(c));
    cout << "A topological ordering: ";
    for ( vector<Vertex>::reverse_iterator ii=c.rbegin(); ii!=c.rend(); ++ii)
        cout << (*ii) << " ";
    cout << endl;
}
