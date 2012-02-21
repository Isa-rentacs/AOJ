#include <iostream>
#include <complex>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef complex<double> P;
typedef vector<P> polygon;

double cross(const P &a, const P &b){
    return imag(conj(a)*b);
}

double dot(const P &a, const P &b){
    return real(conj(a) * b);
}

#define curr(G, i) G[i]
#define next(G, i) G[(i+1)%G.size()]
enum { OUT, ON, IN };

int contains(const polygon& G, const P& p) {
    bool in = false;
    for (int i = 0; i < G.size(); ++i) {
        P a = curr(G,i) - p, b = next(G,i) - p;
        if (imag(a) > imag(b)) swap(a, b);
        if (imag(a) <= 0 && 0 < imag(b))
            if (cross(a, b) < 0) in = !in;
        if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;
    }
    return in ? IN : OUT;
}

int main(){
    int n;
    int xp1, yp1, xp2, yp2, xp3, yp3, xa, ya, xb, yb;
    cin >> n;

    for(int i=0;i<n;i++){
        polygon triangle;
        cin >> xp1 >> yp1 >> xp2 >> yp2 >> xp3 >> yp3 >> xa >> ya >> xb >> yb;
        triangle.push_back(P(xp1,yp1));
        triangle.push_back(P(xp2,yp2));
        triangle.push_back(P(xp3,yp3));
        int a,b;
        a = contains(triangle, P(xa,ya));
        b = contains(triangle, P(xb,yb));
        if(a+b == 2 && a*b == 0){
            cout << "OK" << endl;
        }else{
            cout << "NG" << endl;
        }
    }
}
