#include <climits>
#include <iostream>
#include <vector>
#include <boost/graph/adjacency_list.hpp>
#include <boost/tuple/tuple.hpp>
using namespace std;
using namespace boost;

typedef adjacency_list<vecS, vecS, undirectedS, // undirected graph
                        no_property,
                        property<edge_weight_t, int> > Graph;
typedef graph_traits<Graph>::edge_descriptor Edge; // Edge type
typedef graph_traits<Graph>::edge_iterator EdgeIt; // Iterator
typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef property_map<Graph, edge_weight_t>::type WeightMap; // Map edge -> weight.

#define forloop(i,lo,hi) for(int i = (lo); i <= (hi); i++)
#define rep(i,N) forloop(i,0,(int)N-1)

Graph udgraph_toy_ex(){// return a toy example of undirected weighted graph (V=5, E=6)
    Graph G(5); 
    WeightMap wm = get(edge_weight, G); // associate wm with G --> G is edge-weighted
    int us[] = {0,2,1,1,3,2};
    int vs[] = {1,0,2,3,2,4};
    int cs[] = {1,2,5,1,2,3};
    rep(i,6){
        Edge e;
        tie(e, tuples::ignore) = add_edge(us[i], vs[i], G); 
        wm[e] = cs[i];
    }
    return G;
}

