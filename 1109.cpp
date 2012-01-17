#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        int cubic = n*n*n;
        int ret= 1 << 29;
        int ub = 1111,lb=1;
        int maxi = 1111;

        for(int i=1;i<=maxi;i++){
            ub = 1111;
            lb = 1;
            while(ub - lb > 1){
                int mid = (ub + lb) / 2;
                if(i*i*i + mid*mid*mid <= cubic){
                    lb = mid;
                }else{
                    ub = mid;
                }
            }
            maxi = lb;
            ret = min(ret, cubic - i*i*i - lb*lb*lb);
        }
        cout << ret << endl;
    }
}
