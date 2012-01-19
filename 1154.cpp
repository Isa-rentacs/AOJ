#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    while(cin >> n && n != 1){
        int cand=0;
        bool isok;
        vector<int> fact;
        cout << n << ":";
        for(cand=0;cand <= n;cand += 7){
            if(cand != 0){
                if((n % (cand + 1) == 0 && n / (cand + 1) % 7 == 1) || 
                   (n % (cand + 1) == 0 && n / (cand + 1) % 7 == 6)){
                    isok = true;
                    for(int i=0;i<fact.size();i++){
                        if((n / (cand + 1)) % fact[i] == 0 && 
                           (((n / (cand + 1)) / fact[i]) % 7 == 1 ||
                            ((n / (cand + 1)) / fact[i]) % 7 == 6)){
                            isok = false;
                        }
                    }
                    if(isok){
                        cout << " " << cand+1;
                        fact.push_back(cand+1);
                    }
                }
            }
            if((n % (cand + 6) == 0 && n / (cand + 6) % 7 == 1)||
                     (n % (cand + 6) == 0 && n / (cand + 6) % 7 == 6)){
                isok = true;
                for(int i=0;i<fact.size();i++){
                    if((n / (cand + 6)) % fact[i] == 0 && 
                       (((n / (cand + 6)) / fact[i]) % 7 == 1 ||
                        ((n / (cand + 6)) / fact[i]) % 7 == 6)){
                        isok = false;
                    }
                }
                if(isok){
                    cout << " " << cand+6;
                    fact.push_back(cand+6);
                }                
            }
        }
        cout << endl;
    }
}
