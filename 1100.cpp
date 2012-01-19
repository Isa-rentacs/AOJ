#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <complex>

using namespace std;

int main(){
    int n;
    int cnt=1;
    while(cin >> n && n){
        complex<double> p[n];
        double ret = 0;
        for(int i=0;i<n;i++){
            double x;
            double y;
            cin >> x >> y;
            p[i] = complex<double>(x,y); 
        }

        for(int i=0;i<n;i++){
            if(i != n-1){
                ret += 0.5*imag(conj(p[i])*p[i+1]);
            }else{
                ret += 0.5*imag(conj(p[i])*p[0]);
            }
        }
        printf("%d %.1lf\n", cnt++, abs(ret));
    }
}
