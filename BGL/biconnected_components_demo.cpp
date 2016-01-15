#include <boost/graph/biconnected_components.hpp>
#include "udgraph_def.h"

namespace boost
{
  struct edge_component_t{
    enum { num = 555 };
    typedef edge_property_tag kind;
  } edge_component;
}

int main(){
    Graph G = udgraph_toy_ex();
    // biconnected component is a partition of *edges*, so we need a property_map (for edges) to store the component id for each edge
    WeightMap wm = get(edge_weight, G); 
    /* we just use the WeightMap (which is just a property_map for edges) to store the components
    * else we can use the edge_component_t as above... ( need to redefine the `Graph` type, see: http://www.boost.org/doc/libs/1_59_0/libs/graph/example/biconnected_components.cpp )
    */
    int ncomp = biconnected_components(G, wm); 
    cout << ncomp << " biconnected components" << endl;
    EdgeIt ei, ei_end;
    for (tie(ei, ei_end) = edges(G); ei != ei_end; ++ei)
    cout << source(*ei, G) << "-" << target(*ei, G)
              << ", belongs to biconnected-component-" << wm[*ei] << endl;
    cout << endl;
    
    // get articulation points
    vector<Vertex> art_pts;
    articulation_points(G, back_inserter(art_pts));
    cout << art_pts.size() << " articulation points, they are: " << endl;
    for(vector<Vertex>::iterator it=art_pts.begin(); it!=art_pts.end(); it++)
        cout << *it << ", ";
    cout << endl;
}
