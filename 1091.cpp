#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
    int a,l,x;

    while(cin >> a >> l >> x){
        double s1,s2,tmp;
        
        tmp = (double)(a + l * 2) / 2;
        s1 = sqrt(tmp*(tmp-a)*(tmp-l)*(tmp-l));
        
        tmp = (double)(l + l + x) / 2;
        s2 = sqrt(tmp*(tmp-l)*(tmp-(double)(l+x)/2)*(tmp-(double)(l+x)/2));

        printf("%.9f\n", s1+s2*2);
    }
}
