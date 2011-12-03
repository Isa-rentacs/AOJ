#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long

int main(){
    ll q1;
    
    while(cin >> q1 && q1){
        ll badget, pi, pn, lim;
        ll reti, retn;
        cin >> badget >> pi >> pn >> lim;
        
        if(pi*q1 <= badget){
            reti = q1;
            retn = 0;
        }else{
            retn = ceil((double)(pi*q1 - badget) / (pi - pn));
            reti = q1 - retn;
        }

        badget -= pi * reti + pn * retn;

        if(reti > lim){
            badget += pi * (reti - lim);
            reti = lim;
        }else{
            if(badget > 0){
                reti += min(lim - reti, badget / pi);
                badget -= min(lim - reti, badget / pi) * pi;
            }
        }

        if(badget > 0){
            retn += badget / pn;
            badget = badget - (badget / pn) * pn;
        }
        if(badget < 0 || retn+reti < q1 || retn < 0 || reti <= 0){
            cout << "NA" << endl;
        }else{
            cout << reti << " " << retn << endl;
        }
    }
}
