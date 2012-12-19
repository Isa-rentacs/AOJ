#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>

#define ll long long

using namespace std;

int main(){
    ll n,nn,x;
    
    while(cin >> n && n){
        bool minus = n<0, carry = false;
        int res[15], dig[15];
        int tmp,cnt=0;

        memset(res, 0, sizeof(res));
        memset(dig, 0, sizeof(dig));

        if(minus) n *= -1;
        while(n > 0){
            tmp = n%10;
            dig[cnt] = tmp;
            n /= 10;
            cnt++;
        }
        for(int i=0;i<15;i++){
            if(carry){
                if(res[i] >= 1){
                    res[i]--;
                }else{
                    res[i+1]++;
                    res[i] += 9;
                }
                carry = false;
            }
            if(!dig[i]) continue;
            
            if((i%2==0 && !minus) || (i%2 == 1 && minus)){
                res[i] += dig[i];
            }else{
                res[i+1]++;
                res[i] += 10-dig[i];
            }
            if(res[i] >= 10){
                res[i] %= 10;
                carry = true;
            }else{
                carry = false;
            }
        }

        string ret = "";
        for(int i=0;i<15;i++) ret += (char)(res[i] + '0');
        reverse(ret.begin(),ret.end());
        istringstream iss(ret);
        ll ans;
        iss >> ans;
        cout << ans << endl;
    }
}
