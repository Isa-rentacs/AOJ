#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        int mini = 1 << 29;
        int maxi = -1;
        int sum = 0;
        int tmp;
        for(int i=0;i<n;i++){
            cin >> tmp;
            mini = min(mini, tmp);
            maxi = max(maxi, tmp);
            sum += tmp;
        }
        cout << (sum - mini - maxi) / (n - 2) << endl;
    }
}
