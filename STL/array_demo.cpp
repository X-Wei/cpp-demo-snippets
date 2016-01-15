#include <iostream>
#include <vector>

using namespace std;
#define forloop(i,lo,hi) for(int i = (lo); i <= (hi); i++)
#define rep(i,N) forloop(i,0,(int)N-1)

int main(){
    // 1. get array size
    int a[] = { 3, 1, 4, 1, 5, 9 };
    cout << "size of array a is: " << sizeof a / sizeof a[0] << endl;
    // 2. 2D (dynamic) array construction: 
    /*see http://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
     * dynamic 2D array is basically an array of pointers to arrays*/
    int rowCount=2, colCount=3;
    int** ary = new int*[rowCount];
    for(int i = 0; i < rowCount; ++i)
        ary[i] = new int[colCount];
    return 0;
}
