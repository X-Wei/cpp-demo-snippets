#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
#define forloop(i,lo,hi) for(int i = (lo); i <= (hi); i++)
#define rep(i,N) forloop(i,0,(int)N-1)

void print_set(set<int>& s){
    for(set<int>::iterator it=s.begin(); it!=s.end(); it++)
        cout << *it << " ";
    cout << endl;
}

int main(){
    set<int> s;
    // 1. insert into set
    cout << "// 1. insertion" << endl;
    int a[] = {3,1,5,0,8,9,1,1,1,3,3,3};
    int sz = sizeof a / sizeof a[0];
    rep(i, sz) s.insert(a[i]); // insert one by one
    s.insert(a, a+sz); // insert by pointer range (or begin/end for vector)
    cout << s.size() << " elements in set"<<endl;
    cout << endl;
    
    // 2. iterate through set (as set is a BST, the items are ordered)
    cout << "// 2. iterate through set (as set is a BST, the items are ordered)" << endl;
    for(set<int>::iterator it=s.begin(); it!=s.end(); it++)
        cout << *it << " ";
    cout << endl;
    cout << endl;
    
    // 3. test existences by `find` or `count`
    cout << "// 3. test existences by `find` or `count`" << endl;
    cout << (s.find(10)!=s.end()) << " " << (s.find(9)!=s.end()) << endl;
    cout << (s.count(10)==1) << " " << (s.count(9)==1) << endl;
    cout << endl;
    
    // 4. remove element from set (`erase`), either by an iterator or by a value
    cout << "// 4. remove element from set (`erase`), either by an iterator or by a value" << endl;
    s.erase(9);
    cout << "set size after erase(9) = " << s.size() << endl;
    s.erase(100);
    cout << "possible to erase value that is not in set" << endl;
    s.erase(s.begin());
    cout << "new begin after s.erase(s.begin()): " << *s.begin() <<endl;
    s.erase(--s.end()); // must use `--`, otherwise will cause invalid pointer error
    cout << "new end after s.erase(--s.end()): " << *(--s.end()) <<endl;
    cout << endl;
    
    // 5. set union/intersection/difference
    cout << "// 5. set union/intersection/difference" << endl;
    int A[]={1,2,3,4,5}, B[]={4,5,6,7};
    set<int> s1, s2;
    s1.insert(A, A+5);
    s2.insert(B, B+4);
    set<int> s_union, s_intersect, s_diff;
    set_union( s1.begin(), s1.end(), 
                s2.begin(), s2.end(), 
                inserter(s_union, s_union.end()) );
    print_set(s_union);
    set_intersection( s1.begin(), s1.end(), 
                    s2.begin(), s2.end(), 
                    inserter(s_intersect, s_intersect.begin()) );
    print_set(s_intersect);
    set_difference( s1.begin(), s1.end(), 
                    s2.begin(), s2.end(), 
                    inserter(s_diff,s_diff.end()) );
    print_set(s_diff);
    
    return 0;
}
