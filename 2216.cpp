#include <iostream>

using namespace std;

int main(){
    int a,b;
    while(cin >> a >> b){
        if(a+b == 0) break;
        int change = b - a;

        int x,y,z;
        z = change / 1000;
        change -= z * 1000;
        y = change / 500;
        change -= y * 500;
        x = change / 100;

        cout << x << " " << y << " " << z << endl;
    }
}
