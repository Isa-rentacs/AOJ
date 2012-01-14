#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        int ret = 0;
        int last=-1;
        int cnt = 0;
        int stone;
        stack<int> st;
        for(int i=1;i<=n;i++){
            cin >> stone;
            if(i%2 == 0){
                if(last == stone){
                    if(stone == 0){
                        ret++;
                        cnt++;
                    }else{
                        cnt++;
                    }
                }else{
                    if(stone == 0){
                        ret += cnt;
                        if(!st.empty()){
                            cnt += st.top();
                            st.pop();
                        }
                        last = 0;
                        ret++;
                        cnt++;
                    }else{
                        ret -= cnt;
                        if(!st.empty()){
                            cnt += st.top();
                            st.pop();
                        }
                        last = 1;
                        cnt++;
                    }
                }
            }else{
                if(last != stone && last != -1){
                    st.push(cnt);
                    cnt = 0;
                }
                if(stone == 0){
                    cnt++;
                    ret++;
                    last = 0;
                }else{
                    cnt++;
                    last = 1;
                }
            }
        }
        cout << ret << endl;
    }
}
