#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fib[1002];

int main(){
    fib[0] = 1;
    fib[1] = 2;

    for(int i=2;i<1002;i++){
        fib[i] = (fib[i-1] + fib[i-2]) % 1001;
    }

    int v,d;

    while(cin >> v >> d){
        if((v|d) == 0) break;
        vector<int> vec;
        int res = 1;
        for(int i=1;i<=v;i++){
            vec.push_back(fib[i]);
        }
        sort(vec.begin(), vec.end());

        for(int i=1;i<vec.size();i++){
            if(vec[i] - vec[i-1] >= d){
                res++;
            }
        }
        cout << res << endl;
    }
}
