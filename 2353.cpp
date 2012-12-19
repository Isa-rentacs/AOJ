#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

ll extgcd(ll a, ll b, ll &x, ll &y){
    ll d=a;
    if(b != 0){
        d = extgcd(b,a%b,y,x);
        y -= (a/b)*x;
    }else{
        x=1;
        y=0;
    }
    return d;
}

ll mod_inverse(ll a,ll m){
    ll x,y;
    extgcd(a,m,x,y);
    return (x%m+m)%m;
}

int main(){
    int n;
    cin >> n;
//    ll m1 = 99989, m2 = 99991;
    ll m1 = 2077753, m2 = 2077769;
    ll t1=0,t2=0;
    int op,y;
    for(int i=0;i<n;i++){
        cin >> op >> y;
        if(op == 1){
            t1 = (t1+y)%m1;
            t2 = (t2+y)%m2;
        }else if(op == 2){
            t1 = (t1-y%m1+m1)%m1;
            t2 = (t2-y%m2+m2)%m2;
        }else if(op == 3){
            t1 = (t1*y)%m1;
            t2 = (t2*y)%m2;
        }else{
            t1 = (t1*mod_inverse(y,m1))%m1;
            t2 = (t2*mod_inverse(y,m2))%m2;
        }
    }
    ll a,b;
    extgcd(m1,m2,a,b);
    ll res = (m1*t2*a+m2*t1*b)%((ll)m1*m2);
    while(res >= (1ll<<31)){
        res -= (ll)m1 * m2;
    }
    cout << res << endl;
}
