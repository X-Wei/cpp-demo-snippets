#include <boost/graph/connected_components.hpp>
#include "udgraph_def.h"

int main(){
    Graph G = udgraph_toy_ex();
    int V = num_vertices(G);
    vector<int> comp(V); // stores index of the vertices’ component
    int ncomp = connected_components(G, &comp[0]);
    cout << ncomp << " connected components in G. " << endl;
    multimap<int, int> mm; // map scc id to vertices
    rep(i, V)
        mm.insert( make_pair(comp[i], i) );
    rep(i, ncomp){
        cout << "component-" << i << " have vertices: " ;
        multimap<int, int>::iterator ibeg, iend;
        for( tie(ibeg,iend) = mm.equal_range(i); ibeg!=iend; ibeg++)
            cout << ibeg->second << ", ";
        cout << endl;
    }
    return 0;
}
