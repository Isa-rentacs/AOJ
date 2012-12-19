#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m){
        if((n|m) == 0) break;

        vector<int> h,w;
        map<int,int> mh, mw;
        int sum=0,tmp;
        h.push_back(0);
        for(int i=0;i<n;i++){
            cin >> tmp;
            sum += tmp;
            h.push_back(sum);
        }
        sum = 0;
        w.push_back(0);
        for(int i=0;i<m;i++){
            cin >> tmp;
            sum += tmp;
            w.push_back(sum);
        }

        for(int i=0;i<h.size();i++){
            for(int j=i+1;j<h.size();j++){
                mh[h[j] - h[i]]++;
            }
        }

        for(int i=0;i<w.size();i++){
            for(int j=i+1;j<w.size();j++){
                mw[w[j] - w[i]]++;
            }
        }
        
        map<int,int>::iterator hit = mh.begin(), wit = mw.begin();
        
        int ret = 0;
        while(hit != mh.end() && wit != mw.end()){
            if((*hit).first == (*wit).first){
                ret += (*hit).second * (*wit).second;
                ++hit;
                ++wit;
            }else if((*hit).first < (*wit).first){
                ++hit;
            }else{
                ++wit;
            }
        }
        cout << ret << endl;
    }
}
