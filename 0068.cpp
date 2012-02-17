#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>

using namespace std;

typedef complex<double> P;

bool operator<(const P &a, const P &b){
    return real(a) != real(b) ? real(a) < real (b) : imag(a) < imag(b);
}

bool predication(const P &a, const P &b){
    return real(a) != real(b) ? real(a) < real (b) : imag(a) < imag(b);
}

double cross(const P &a, const P &b){
    return imag(conj(a)*b);
}

double dot(const P &a, const P &b){
    return real(conj(a) * b);
}

int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c) > 0)   return +1;       // counter clockwise
    if (cross(b, c) < 0)   return -1;       // clockwise
    if (dot(b, c) < 0)     return +2;       // c--a--b on line
    if (norm(b) < norm(c)) return -2;       // a--b--c on line
    return 0;                               // b==c || a--c--b on line
}

vector<P> convex_hull(vector<P> ps) {
    int n = ps.size(), k = 0;
    sort(ps.begin(), ps.end(), predication);
    vector<P> ch(2*n);
    for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
        while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
        while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    ch.resize(k-1);
    return ch;
}

int main(){
    int n;
    while(cin >> n && n){
        vector<P> vec;
        vector<P> ch;
        double real,imag;
        for(int i=0;i<n;i++){
            cin >> real;
            cin.ignore();
            cin >> imag;
            vec.push_back(complex<double>(real,imag));
        }
        ch = convex_hull(vec);
        cout << n - ch.size() << endl;
    }
}
