#include <boost/graph/dijkstra_shortest_paths.hpp>
#include "digraph_def.h"

int main(){
    Graph G = digraph_toy_ex();
    //~ WeightMap wm = get(edge_weight, G); 
    int V = num_vertices(G);
    vector<int> dist(V), pred(V);
    dijkstra_shortest_paths(
            G, 0, // dijkstra with source=0
            predecessor_map( make_iterator_property_map(pred.begin(), get(vertex_index, G)) ).
                    distance_map( make_iterator_property_map(dist.begin(),get(vertex_index, G)) )
        );
    rep(i,V)
        cout << "0-" << i << ", dist = " << dist[i] << endl;
    return 0;
}
