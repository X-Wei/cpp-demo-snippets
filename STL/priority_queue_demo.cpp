#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define forloop(i,lo,hi) for(int i = (lo); i <= (hi); i++)
#define rep(i,N) forloop(i,0,(int)N-1)

void print_vec(vector<int>& v){
    rep(i,v.size())
        cout << v.at(i) << " "; // or use v[i]
    cout << endl;
}
void print_pairvec(vector<pair<int, int> >& vp){
    rep(i, 4) 
        cout << vp[i].first << "," << vp[i].second << "; ";
    cout << endl;
}

bool my_cmp(const pair<int, int> &lhs, const pair<int, int> &rhs) {
    return (lhs.first < rhs.first) || (lhs.first==rhs.first && lhs.second < rhs.second);
}

struct MyCmpStruct{
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs){
        return my_cmp(lhs, rhs);
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

class MyFooClass {
    public :
    MyFooClass(int xx, int yy){
        x = xx;
        y = yy;
    }
    bool operator < ( const MyFooClass & other ) const {
        return (x<other.x) || (x==other.x && y<other.y) ;
    }
    public :
        int x,y;
};

int main(){
    // 1. method ONE -- use `make_heap` in <algorithm>
    cout << "// 1. method ONE -- use `make_heap` in <algorithm>" << endl;
    int a[] = { 3, 1, 4, 1, 5, 9 };
    vector<int> v(a,a+6);
    print_vec(v);
    make_heap(v.begin(), v.end()); // build a max heap 
    print_vec(v);
    cout << v.front() << endl;
    pop_heap(v.begin(), v.end()); // attention: this operation only moves largest element to the end
    v.pop_back(); // need to pop_back to really remove the element
    print_vec(v);
    v.push_back(100); // to insert to pq, need to first call push_back then call push_heap
    push_heap(v.begin(), v.end()); // insert the last element (--v.end()) to heap
    print_vec(v);
    cout << endl;
    
    // 2. use self-defined cmp function
    cout << "// 2. use self-defined cmp function" << endl;
    int a1[] = {3,1,5,3}, 
         a2[] = {5,3,2,1};
    vector< pair<int, int> > vp;
    rep(i,4) vp.push_back( make_pair(a1[i], a2[i]) );
    print_pairvec(vp);
    make_heap(vp.begin(), vp.end(), my_cmp);
    print_pairvec(vp);
    cout << endl;
    
    // 3. method TWO: use priority_queue class: `push/pop/top`
    cout << "// 3. method TWO: use priority_queue class: `push/pop/top`" << endl;
    priority_queue<int> pq;
    int arr[] = {1,8,5,6,3,4,0,9,7,2};
    rep(i,9)
        pq.push(arr[i]);
    cout << pq.top() <<endl;
    cout << endl;
    
    // 4. when using priority_queue and want self-define cmp funciton, need to put into a struct
    cout << "// 4. when using priority_queue and want self-define cmp funciton, need to put into a struct" << endl;
    // in this case need to provide the container (vector) in 2nd argument 
    priority_queue<pair<int,int>, vector<pair<int,int> >, MyCmpStruct> ppq;
    vp.clear();
    rep(i,4) vp.push_back( make_pair(a1[i], a2[i]) );
    print_pairvec(vp);
    rep(i,4) ppq.push(vp[i]);
    cout << ppq.top().first << "," << ppq.top().second << endl;
    ppq.pop();
    cout << ppq.top().first << "," << ppq.top().second << endl;
    cout << endl;
    
    // 5. or we can use a self-defined class/struct with `<` operator overloaded
    cout << "// 5. or we can use a self-defined class/struct with `<` operator overloaded" << endl;
    priority_queue<MyFooClass> cpq;
    rep(i,4) cpq.push( MyFooClass(a1[i], a2[i]) );
    cout << cpq.top().x << "," << cpq.top().y << endl;
    cpq.pop();
    cout << cpq.top().x << "," << cpq.top().y << endl;
    priority_queue<MyFooStruct> spq;
    rep(i,4) spq.push( MyFooStruct(a1[i], a2[i]) );
    cout << spq.top().x << "," << spq.top().y << endl;
    spq.pop();
    cout << spq.top().x << "," << spq.top().y << endl;
    cout << endl;
    return 0;
}
