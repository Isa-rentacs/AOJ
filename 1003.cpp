#include <iostream>
#include <string>

using namespace std;

int num[9] = {5,3,3,3,3,3,4,3,4};
char one[5] = {'\'', ',', '.', '!', '?'};
char lower[8] = {'a', 'd', 'g', 'j', 'm', 'p', 't', 'w'};
char upper[8] = {'A', 'D', 'G', 'J', 'M', 'P', 'T', 'W'};
int main(){
    string str;
    while(cin >> str){
        char tmp=-1;
        int cnt = 0;
        for(int i=0;i<str.size()+1;i++){
            if(i != str.size() && (tmp == -1 || tmp == str[i])){
                tmp = str[i];
                cnt++;
            }else{
                int div,index;
                if(tmp != '0'){
                    div = (cnt-1)/num[tmp-'1'];
                    index = (cnt-1)%num[tmp-'1'];
                }
                if(tmp == '1'){
                    cout << one[index];
                }else if('2' <= tmp && tmp <= '9'){
                    if(div % 2){
                        cout << (char)(upper[tmp - '2'] + index);
                    }else{
                        cout << (char)(lower[tmp - '2'] + index);
                    }
                }else{
                    for(int j=0;j<cnt-1;j++){
                        cout << " ";
                    }
                }
                tmp = str[i];
                cnt = 1;
            }
        }
        cout << endl;
    }
} 
