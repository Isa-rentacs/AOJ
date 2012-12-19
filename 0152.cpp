#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

class student{
public:
    student(int a, int b){
        id = a;
        score = b;
    }
    int id;
    int score;

    bool operator < (const student arg) const{
        if(score == arg.score){
            return id < arg.id;
        }else{
            return score > arg.score;
        }
    }
};

int main(void){
    int n;

    while(cin >> n && n){
        vector<student> v;
        int id,tmp;
        string str;
        cin.ignore();
        for(int i=0;i<n;i++){
            getline(cin,str);
            istringstream iss(str);
            vector<int> score;
            iss >> id;
            while(iss >> tmp){
                score.push_back(tmp);
            }
            
            int sum=0;
            int fcount=0;
            int mul[score.size()];
            memset(mul, 0, sizeof(mul));
            for(int j=0;j<score.size();j++){
                if(score[j] == 10){ //strike
                    if(j+1 < score.size()) mul[j+1]++;
                    if(j+2 < score.size()) mul[j+2]++;
                    sum += 10;
                    sum += mul[j] * score[j];
                }else if(j+1 < score.size()){
                    if(j+1 < score.size() && score[j] + score[j+1] == 10){ //spare?
                        if(j+2 < score.size()) mul[j+2]++;
                    }
                    sum += score[j]+score[j+1];
                    sum += score[j]*mul[j] + score[j+1] * mul[j+1];
                    j++;
                }else{
                    sum += score[j] * (mul[j] + 1);
                }
            }
            v.push_back(student(id,sum));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout << v[i].id << " " << v[i].score << endl;
        }
    }
}
