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
    char conso[9] = {'k', 's', 't', 'n', 'h', 'm', 'y', 'r', 'w'};
    string str;
    cin >> str;
    for(int i=0;i<(int)str.size();i++){
        if(i%2 == 0){
            if(str[i] != '1' && str[i] != '0'){
                cout << conso[str[i]-'0'-2];
            }else if(str[i] == '0'){
                if(str[i+1] != 'U'){
                    cout << "w";
                }
            }
        }else{
            if(str[i] == 'T'){
                cout << "a";
            }else if(str[i] == 'L'){
                cout << "i";
            }else if(str[i] == 'U'){
                if(str[i-1] == '0'){
                    cout << "nn";
                }else{
                    cout << "u";
                }
            }else if(str[i] == 'R'){
                cout << "e";
            }else{
                cout << "o";
            }
        }
    }
    cout << endl;
}
