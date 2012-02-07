#include <iostream>
#include <algorithm>

using namespace std;

class BIT{
public:
    int *p;
    int num;
    BIT(int arg){
        p = new int[arg+1];
        for(int i=0;i<arg+1;i++) p[i] = 0;
        num = arg;
    }
    
    //return sum of p[1] ... p[arg]
    int sum(int arg){
        int ret=0;
        while(arg > 0){
            ret += p[arg];
            arg -= arg & -arg;
        }
        return ret;
    }

    //add value to index-th node
    void add(int index, int value){
        while(index <= num){
            p[index] += value;
            index += index & -index;
        }
    }
};

int main(){
    int n, m, tmp;
    int mod = 100000;
    int ret = 0;

    cin >> n >> m;
    BIT bit(n);
    for(int i=1;i<n;i++){
        cin >> tmp;
        bit.add(i,tmp%mod);
    }
    int pos = 0;
    for(int i=0;i<m;i++){
        cin >> tmp;
        ret += abs(bit.sum(pos) - bit.sum(pos+tmp)) % mod;
        ret %= mod;
        pos += tmp;
//        cout << "ret = " << ret << endl;
//        cout << "pos = " << pos << endl;
    }
    cout << ret << endl;
}
