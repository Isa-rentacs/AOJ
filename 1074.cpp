#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

bool pred(const pair<int,string> &left, const pair<int,string> &right){
  if(left.first != right.first){
    return left.first < right.first;
  }else{
    return left.second < right.second;
  }
}

int main(void){
  int n;
  while(cin >> n && n){
    bool table[40][40]; 
    vector< pair<int,string> > person(n);
    memset(table, false, sizeof(table));
    int d,tmp;

    for(int i=0;i<n;i++){
      person[i].first = 0;
      cin >> person[i].second >> d;
      for(int j=0;j<d;j++){
	cin >> tmp;
	table[i][tmp] = true;
      }
    }

    int cnt;
    for(int i=0;i<30;i++){
      cnt = 0;
      for(int j=0;j<n;j++){
	if(table[j][i]) cnt++;
      }
      for(int j=0;j<n;j++){
	if(table[j][i]) person[j].first += n - cnt + 1;
      }
    }
    sort(person.begin(), person.end());
    cout << person[0].first << " " <<  person[0].second << endl;
  }
}
