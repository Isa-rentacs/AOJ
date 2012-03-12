#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int s[3], d[2];
    int ret = 1 << 20;
    cin >> s[0] >> s[1] >> s[2] >> d[0] >> d[1];
    for(int i=0;i<3;i++)
        for(int j=0;j<2;j++)
            ret = min(ret, s[i]+d[j]-50);
    cout << ret << endl;
}
