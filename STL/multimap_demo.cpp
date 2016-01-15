#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
//~ #include <tuple>

using namespace std;
#define forloop(i,lo,hi) for(int i = (lo); i <= (hi); i++)
#define rep(i,N) forloop(i,0,(int)N-1)

void print_mmap(multimap<string,int>& m){
    for(multimap<string,int>::iterator it=m.begin(); it!=m.end(); it++)
        cout << it->first << ":" << it->second << ", ";
    cout << endl;
}

int main(){
    multimap<string,int> mm;
    // 1. insert into 
    cout << "// 1. insertion" << endl;
    // by `insert` function (use `make_pair`)
    string wds[] = {"aa", "bb", "cc"};
    int cnts[] = {30, 40, 50};
    rep(i, 3)
        mm.insert( make_pair(wds[i], cnts[i]) );
    // insert a key that is already in mm
    mm.insert( make_pair("aa", 60) ); // can no longer use the index operator []
    mm.insert( make_pair("aa", 3) );
    print_mmap(mm);
    cout << endl;
    
    // 2. test existences/get value by `find` or `count`
    cout << "// 2. test existences by `find` or `count`" << endl;
    cout << (mm.count("aa")>=1) << " " << (mm.count("ee")>=1) << endl;
    cout << (mm.find("aa")!=mm.end()) << " " << (mm.find("ee")!=mm.end()) << endl;
    
    // using `find`, will only return any of the pairs with the given key
    cout << "// using `find`, will only return any of the pairs with the given key" << endl;
    multimap<string,int>::iterator it = mm.find("aa");
    cout << it->second << endl;
    
    // to get all values associated with a key, use `equal_range` (which is equal to use `lower/upper_bound`)
    cout << "// to get all values associated with a key, use `equal_range` (which is equal to use `lower/upper_bound`)" << endl;
    cout << "all values correspongding to key='aa': " << endl;
    multimap<string,int>::iterator ibeg, iend;
    //~ tie(ibeg, iend) = mm.equal_range("aa");
    ibeg = mm.lower_bound("aa");
    iend = mm.upper_bound("aa");
    for(; ibeg!=iend; ibeg++)
        cout << ibeg->second << ", ";
    cout << endl;
    cout << endl;
    
    // 3. erasing a key will erase all pairs with that key
    cout << "// 3. erasing a key will erase all pairs with that key" << endl;
    mm.erase("aa");
    print_mmap(mm);        
    return 0;
}
