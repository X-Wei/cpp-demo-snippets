#include <boost/graph/strong_components.hpp>
#include "digraph_def.h"

int main(){
    Graph G = digraph_toy_ex();
    int V = num_vertices(G);
    vector<int> scc(V); // `scc` stores index of the vertices’ strong component (ie. one PARTITION of all vertices)
    int nscc = strong_components(G,
                make_iterator_property_map(scc.begin(),get(vertex_index, G)) ); // nscc = nb of scc in G
    cout << nscc << " strong components in digraph G. " << endl;
    multimap<int, int> mm; // map scc id to vertices
    rep(i, V)
        mm.insert( make_pair(scc[i], i) );
    rep(i, nscc){
        cout << "SCC-" << i << " have vertices: " ;
        multimap<int, int>::iterator ibeg, iend;
        for( tie(ibeg,iend) = mm.equal_range(i); ibeg!=iend; ibeg++)
            cout << ibeg->second << ", ";
        cout << endl;
    }
    return 0;
}
