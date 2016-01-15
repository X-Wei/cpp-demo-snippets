#include <boost/graph/depth_first_search.hpp>
#include "digraph_def.h"

class custom_dfs_visitor : public boost::default_dfs_visitor
{
    public:
    template < typename Vertex, typename Graph >
    void discover_vertex(Vertex u, const Graph & g) const{
        cout << u << ", ";
    }
};

int main(){
    Graph G = digraph_toy_ex();
    custom_dfs_visitor vis;
    depth_first_search(G, visitor(vis)); //, vertex(0, G)
    cout << endl;
    return 0;
}
