#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define forloop(i,lo,hi) for(int i = (lo); i <= (hi); i++)
#define rep(i,N) forloop(i, 0, (int)N-1)

void print_vec(vector<int>& v){
    rep(i,v.size())
        cout << v.at(i) << " "; // or use v[i]
    cout << endl;
}

int main(){
    // 1. constructor example
    cout << "//1. constructor example\n";
    vector<int> v1; // v1 is initialized as empty vector
    vector<int> v2(5); // v2 is initialized as [0,0,0,0,0]
    print_vec(v2);
    vector<int> v3(5, 3); // v3 is initialized as [3,3,3,3,3]
    print_vec(v3);
    // use `fill` to reset all elements to 30:
    fill(v3.begin(), v3.end(), 30);
    print_vec(v3);
    // initialize a vector from an array
    int a[] = {3,1,5,0,8,9};
    v3 = vector<int>(&a[0], &a[0]+6);
    print_vec(v3);
    cout << endl;
    
    
    // 2. push_back example
    cout << "//2. push_back example\n";
    forloop(i,1,10)
        v1.push_back( i*(i%2 ? 1 : -1) );
    print_vec(v1);
    cout << endl;
    
    // 3. iterator example
    cout << "//3. iterator example\n";
    for(vector<int>::iterator it=v1.begin(); it!=v1.end(); it++)
        cout << *it << " ";
    cout << endl;
    cout << endl;
    
    // 4. simple sort/copy/reverse example
    cout << "// 4. simple sort example" << endl;
    sort(v1.begin(), v1.end()); // simple sort (ascending order)
    print_vec(v1);
    vector<int> v4(10); // MUST decalre size, if not will cause segfault
    copy(v1.begin(), v1.end(), v4.begin());
    print_vec(v4);
    vector<int> v5; // if we donot know the size of v1, use `back_inserter`
    copy(v1.begin(), v1.end(), back_inserter(v5));
    print_vec(v5);
    reverse(v5.begin(), v5.end()); // reverse elements in v5
    print_vec(v4);
    return 0;
}
