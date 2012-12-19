#include <iostream>

using namespace std;

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
    int n,k;

    cin >> n >> k;
    int card[k][n];
    for(int i=0;i<k;i++){
        for(int j=0;j<n/2;j++){
            cin >> card[i][j];
        }
    }
    int res[n];
    for(;;){
        for(int i=0;i<n;i++){
            res[i] = rnd.rand()%2;
        }
        int tmp = 0;
        for(int i=0;i<k;i++){
            tmp = 0;
            for(int j=0;j<n/2;j++){
                tmp += res[card[i][j]-1];
            }
            if(!(n <= 8*tmp && 8*tmp <= 3*n)){
                goto nxt;
            }
        }
        break;
      nxt:;
    }
    for(int i=0;i<n;i++){
        cout << res[i];
    }
    cout << endl;
}
