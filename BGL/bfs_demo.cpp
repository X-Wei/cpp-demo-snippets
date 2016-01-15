#include <boost/graph/breadth_first_search.hpp>
#include "digraph_def.h"

// write a custom bfs visitor
class custom_bfs_visitor : public boost::default_bfs_visitor
{
    public:
    template < typename Vertex, typename Graph >
    void discover_vertex(Vertex u, const Graph & g) const{
        cout << u << ", ";
    }
};

int main(){
    Graph G = digraph_toy_ex();
    custom_bfs_visitor vis;
    breadth_first_search(G, vertex(0, G), visitor(vis));
    cout << endl;
    return 0;
}
