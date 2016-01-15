#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define forloop(i,lo,hi) for(int i = (lo); i <= (hi); i++)
#define rep(i,N) forloop(i,0,(int)N-1)

void print_map(map<string,int>& m){
    for(map<string,int>::iterator it=m.begin(); it!=m.end(); it++)
        cout << it->first << ":" << it->second << ", ";
    cout << endl;
}

int main(){
    map<string,int> m;
    // 1. insert into 
    cout << "// 1. insertion" << endl;
    /* map<K,V>::key_type is K
     * map<K,V>::mapped_type is V
     * map<K,V>::value_type is pair<K,V>
     * */
    // by `insert` function (use `make_pair`)
    string wds[] = {"aa", "bb", "cc"};
    int cnts[] = {30, 40, 50};
    rep(i, 3)
        m.insert( make_pair(wds[i], cnts[i]) );
    // or insert by index
    m["dd"] = 60;
    print_map(m);
    
    // 2. update: by [] or by `insert_or_assign`
    cout << "// 2. update: by [] or by `insert_or_assign`" << endl;
    m["aa"] = 3;
    m.insert( make_pair("dd", 6) ); // if key is already in map --> will NOT update the value!!
    print_map(m);
    // m.insert_or_assign( "dd", 6 ); // need to use `insert_or_assign` (only in C++17)
    cout << endl;
    
    // 3. iteration
    cout << "// 3. iteration" << endl;
    for(map<string,int>::iterator it=m.begin(); it!=m.end(); it++)
        cout << it->first << ":" << it->second << ", ";
    cout << endl << endl;
    
    // 4. test existences/get value by `find` or `count`
    cout << "// 4. test existences by `find` or `count`" << endl;
    cout << (m.count("dd")==1) << " " << (m.count("ee")==1) << endl;
    cout << (m.find("dd")!=m.end()) << " " << (m.find("ee")!=m.end()) << endl;
    map<string,int>::iterator it = m.find("dd");
    cout << it->second << endl;
    cout << endl;
    
    // 4. remove element from map (`erase`), either by an iterator or by a value
    cout << "// 4. remove element from set (`erase`), either by an iterator or by a value" << endl;
    m.erase("bb");
    cout << "after calling m.erase(\"bb\"): ";
    print_map(m);
    m.erase("zz"); // possible to erase value that is not in map
    cout << "possible to erase value that is not in map: ";
    print_map(m);
    m.erase(m.begin());
    cout << "after calling m.erase(m.begin()): ";
    print_map(m);
    m.erase(--m.end()); // must use `--`, otherwise will cause invalid pointer error
    cout << "after calling m.erase(--m.end()): ";
    print_map(m);
    cout << endl;
        
    return 0;
}
