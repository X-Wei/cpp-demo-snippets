#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/graph/prim_minimum_spanning_tree.hpp>
#include "udgraph_def.h"

int main(){
    Graph G = udgraph_toy_ex();
    WeightMap wm = get(edge_weight, G); 
    // 1. Kruskal algo
    cout << "// 1. Kruskal algo" << endl;
    vector<Edge> mst; // edge vector to store mst: a list of V-1 edges
    kruskal_minimum_spanning_tree(G, back_inserter(mst));
    int mst_weight = 0;
    for (vector<Edge>::iterator ebeg = mst.begin(); ebeg != mst.end(); ++ebeg) { // iterate through mst edges
        int u = source(*ebeg, G), v = target(*ebeg, G);
        int c = wm[*ebeg];
        cout << u<<'-'<<v<<", weight="<<c<<endl;
        mst_weight += c;
    }
    cout << "MST total weight is: " << mst_weight << endl;
    cout << endl;
    
    // 2. Prim algo
    cout << "// 2. Prim algo" << endl;
    int V = num_vertices(G);
    vector<int> pred(V); // predecessor vector
    prim_minimum_spanning_tree(G, &pred[0]);
    rep(j, V){
        Edge e; 
        bool success;
        tie(e, success) = edge(j, pred[j], G);
        if(success){// because the mst root do not have pred...
            int u = source(e, G), v = target(e, G);
            int c = wm[e];
            cout << u<<'-'<<v<<", weight="<<c<<endl;
        }
    }

    return 0;
}
