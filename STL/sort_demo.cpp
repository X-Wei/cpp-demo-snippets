#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define forloop(i,lo,hi) for(int i = (lo); i <= (hi); i++)
#define rep(i,N) forloop(i,0,(int)N-1)

void print_vec(vector<int>& v){
    rep(i,v.size())
        cout << v.at(i) << " "; // or use v[i]
    cout << endl;
}

bool my_cmp(const pair<int, int> &lhs, const pair<int, int> &rhs) {
    return (lhs.first < rhs.first) || (lhs.first==rhs.first && lhs.second < rhs.second);
}

class MyFooClass {
    public :
    int x,y;
    MyFooClass(int xx, int yy){
        x = xx;
        y = yy;
    }
    bool operator < ( const MyFooClass & other ) const {
        return (x<other.x) || (x==other.x && y<other.y) ;
    }
};

struct MyFooStruct {
    int x,y;
    MyFooStruct(int xx, int yy){
        x = xx;
        y = yy;
    }
    bool operator < ( const MyFooStruct & other ) const {
        return (x<other.x) || (x==other.x && y<other.y) ;
    }
};

int main(){
    // 1. basic sort (ascending order)
    cout << "// 1. basic sort" << endl;
    int a[] = {3,1,5,0,8,9};
    vector<int> v(&a[0], &a[0]+6);
    print_vec(v);
    sort(a, a+6);
    rep(i, 6) cout << a[i] << ",";
    cout << endl;
    sort(v.begin(), v.end());
    print_vec(v);
    // if want descending order, use reverse:
    reverse(v.begin(), v.end());
    print_vec(v);
    cout << endl;
    
    // 2. write a self-defined compare function
    cout << "// 2. sort using a self-defined function" << endl;
    // ex. sort pairs by their first element, if first equal, then compare by second --> in `my_cmp function`
    int a1[] = {3,1,5,3}, 
         a2[] = {5,3,2,1};
    vector< pair<int, int> > vp;
    rep(i,4) vp.push_back( make_pair(a1[i], a2[i]) );
    rep(i, 4) cout << vp[i].first << "," << vp[i].second << "; ";
    cout << endl;
    sort(vp.begin(), vp.end(), my_cmp); // put the function name as 3rd argument
    rep(i, 4) cout << vp[i].first << "," << vp[i].second << "; ";
    cout << endl;
    cout << endl;
    
    // 3. define a struct with the `<` operator overloaded
    cout << "// 3. define a struct with the `<` operator overloaded" << endl;
    vector<MyFooStruct> vs;
    rep(i,4) vs.push_back( MyFooStruct(a1[i], a2[i]) );
    rep(i, 4) cout << vs[i].x << "," << vs[i].y << "; ";
    cout << endl;
    sort(vs.begin(), vs.end());
    rep(i, 4) cout << vs[i].x << "," << vs[i].y << "; ";
    cout << endl;
    cout << endl;
    
    // 4. define a class with the < operator overloaded
    cout << "// 4. define a class with the `<` operator overloaded" << endl;
    vector<MyFooClass> vc;
    rep(i,4) vc.push_back( MyFooClass(a1[i], a2[i]) );
    rep(i, 4) cout << vc[i].x << "," << vc[i].y << "; ";
    cout << endl;
    sort(vc.begin(), vc.end());
    rep(i, 4) cout << vc[i].x << "," << vc[i].y << "; ";
    cout << endl;
    cout << endl;
    
    return 0;
}
