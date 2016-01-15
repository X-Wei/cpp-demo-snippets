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

int main(){
    int a[] = {1,2,3,4,5};
    vector<int> v(5);
    copy(a, a+5, v.begin());
    print_vec(v);
    vector<int> v2;
    copy(v.begin(), v.end(), back_inserter(v2)); // if v2 needs to increase capacity, need to use back_inserter
    print_vec(v2);
    return 0;
}
