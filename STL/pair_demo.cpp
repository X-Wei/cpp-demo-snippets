#include <iostream>
#include <vector>

using namespace std;
#define forloop(i,lo,hi) for(int i = (lo); i <= (hi); i++)
#define rep(i,N) forloop(i,0,(int)N-1)

int main(){
    // 1. constructor example
    cout << "// 1. constructor example" << endl;
    pair<string, int> p1("pair1", 1);
    pair<string, int> p2 = make_pair("pair2", 2);
    cout << p1.first << " " << p1.second << endl;
    cout << p2.first << " " << p2.second << endl;
    cout << endl;
    
    // 2. nested pair example
    cout << "// 2. nested pair example" << endl;
    pair<string, pair<int, double> > p3 = make_pair("pair3", make_pair(3,3.33));
    cout << p3.first << " " << p3.second.first << " " << p3.second.second << endl;
    return 0;
}
