#include <climits>
#include <iostream>
#include <vector>
#include <boost/graph/adjacency_list.hpp>
#include <boost/tuple/tuple.hpp> // tuples::ignore

using namespace std;
using namespace boost;

typedef adjacency_list<vecS, vecS, undirectedS,
                        no_property,
                        property<edge_weight_t, int> > Graph;
typedef graph_traits<Graph>::edge_descriptor Edge; // Edge type
typedef graph_traits<Graph>::edge_iterator EdgeIt; // Iterator
typedef property_map<Graph, edge_weight_t>::type WeightMap; // Map edge -> weight.

#define forloop(i,lo,hi) for(int i = (lo); i <= (hi); i++)
#define rep(i,N) forloop(i,0,(int)N-1)


int main(){
    // we build an example of undirected graph G (V=5, E=6)
    Graph G(5);
    WeightMap wm = get(edge_weight, G); // associate wm with G --> so that G is edge-weighted
    int us[] = {0,2,1,1,3,2};
    int vs[] = {1,0,2,3,2,4};
    int cs[] = {1,2,5,1,2,3};
    rep(i,6){
        Edge e;
        tie(e, tuples::ignore) = add_edge(us[i], vs[i], G); 
        wm[e] = cs[i];
    }
    cout << "Graph with V=" << num_vertices(G) <<", E=" << num_edges(G) << endl;
    
    // iterate through all edges in G:
    EdgeIt ebeg, eend;// `edges(G)` returns a tuple of edge iterators(beg, end) for G 
    for (tie(ebeg, eend) = edges(G); ebeg != eend; ++ebeg) {
        int u = source(*ebeg, G), v = target(*ebeg, G); // use `source/target` to get edge ending points
        cout << u << "-" << v << ", weight="<< wm[*ebeg] << endl;
    } 
    return 0;
}
