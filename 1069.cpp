#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long

ll gcd(ll a ,ll b){
    return b==0?a:gcd(b,a%b);
}

int main(void){
    int n;
    ll evens[251];
    ll odds[251*250/2];
    while(cin >> n && n){
        //ll evens[n];
        //ll odds[n*(n-1)/2];
        ll g,tmp;
        ll oindex=0, eindex=0;
        for(int i=0;i<n*(n+1)/2;i++){
            cin >> tmp;
            tmp%2?odds[oindex++] = tmp:evens[eindex++] = tmp;
        }
        sort(evens, evens+n);
        sort(odds, odds + n * (n-1)/2);
        tmp = gcd(evens[0], odds[0]);
        g = (ll)sqrt(evens[0] / tmp * (evens[1] / (odds[0] / tmp)));
        cout << g << endl;
        for(int i=0;i<n-1;i++){
            cout << (ll)round((double)evens[i]/g) << " ";
        }
        cout << (ll)round((double)evens[n-1]/g) << endl;
    }
}
