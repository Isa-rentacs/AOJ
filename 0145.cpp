#include <iostream>
#include <algorithm>
#include <cstring>

#define ll long long

using namespace std;

ll memo[101][101];
pair<int,int> cards[100];

ll solve(int left, int right){
    if(memo[left][right] != -1) return memo[left][right];
    
    if(right == left){
        return memo[left][right] = 0;
    }

    ll mini = (ll)1e+20;

    for(int i=left;i<right;++i){
        mini = min(mini, solve(left,i) + solve(i+1,right) + cards[left].first * cards[i].second * cards[i+1].first * cards[right].second);
    }
    
    return memo[left][right] = mini;
}

int main(){
    int n;
    while(cin >> n){
        fill((ll *)memo, (ll *)memo+101*101, -1);
        for(int i=0;i<n;++i){
            cin >> cards[i].first >> cards[i].second;
        }
        cout << solve(0, n-1) << endl;
    }
}
