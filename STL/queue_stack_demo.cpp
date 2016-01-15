#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define forloop(i,lo,hi) for(int i = (lo); i <= (hi); i++)
#define rep(i,N) forloop(i,0,(int)N-1)

void print_queue(queue<int>& q){
    queue<int> tmp;
    while(q.empty()==false){
        cout << q.front() << " ";
        tmp.push(q.front());
        q.pop();
    }
    cout << endl;
    q = tmp;
}

void print_vec(vector<int>& v){
    rep(i,v.size())
        cout << v.at(i) << " "; // or use v[i]
    cout << endl;
}

int main(){
    int a[] = {3,1,5,0,8,9,1,1,1,3,3,3};
    int sz = sizeof a / sizeof a[0];
    queue<int> q;
    rep(i,sz) 
        q.push(a[i]);
    print_queue(q);  
    rep(i,sz/2)
        q.pop();
    print_queue(q);  
    cout << endl;
    
    // for stacks, just use a vector `push_back/pop_back`
    vector<int> s(&a[0], &a[0]+sz);
    s.push_back(100);
    print_vec(s);
    cout << s.back() << endl;
    s.pop_back();
    print_vec(s);
    
    return 0;
}
