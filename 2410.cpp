#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define PB push_back
#define MP make_pair
#define ll long long

inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}

struct Xorshift{
    unsigned int x, y, z, w, t;

    unsigned int rand(){
        t = x ^ (x << 11);
        x = y; y = z; z = w;
        return w = ( (w ^ (w>>19)) ^ (t ^ (t>>8)));
    }

    Xorshift():x(123456789U), y(362436069U), z(521288629U), w(88675123U){}
};
Xorshift rnd;

int main(){
    std::ios::sync_with_stdio(false);

    int n,winAll = -1,out;
    bool flag;
    cin >> n;
    char t[n][n],c;
    for(int i=0;i<n;i++){
        flag = true;
        for(int j=0;j<n;j++){
            cin >> t[i][j];
            if(t[i][j] == 'x') flag = false;
        }
        if(flag) winAll = i+1;
    }
    for(int i=0;i<1000;i++){
        out = winAll > 0?winAll:rnd.rand() % n + 1;
        cout << out << endl;
        cin >> c;
    }
}
