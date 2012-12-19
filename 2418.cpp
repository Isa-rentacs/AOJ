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

int main(){
    std::ios::sync_with_stdio(false);
    int n,t,h,l;
    int val = 0, turn = 0 , change;
    cin >> n >> t >> h >> l;
    int ten[n], hand[n];
    for(int i=0;i<n;i++){
        cin >> ten[i] >> hand[i];
    }

    while(1){
        if(ten[turn] == 0 && hand[turn] == 0) break;

        if(ten[turn] > 0){
            val += 10;
            t++;
            ten[turn]--;
            if(t > l) break;
        }else{
            val += 100;
            h++;
            hand[turn]--;
        }
        change = 0;
        if(val >= 90){
            val -= 90;
            change = val;
            val = 0;
        }
        if(change > t * 10) break;
        ten[turn] += change / 10;
        t -= change / 10;
        turn = (turn + 1) % n;
    }
    cout << turn+1 << endl;

}
