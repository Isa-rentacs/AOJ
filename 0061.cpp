#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int main(void){
  int ansnum[31];
  map<int, int> team;
  memset(ansnum, 0, sizeof(ansnum));
  int n,p;

  while(cin >> n){
    cin.ignore();
    cin >> p;
    if(n==0 && p==0) break;
    team[n] = p;
    ansnum[p]++;
  }

  while(cin >> n){
    int ret=0;
    p = team[n];
    for(int i=30;i>p;i--){
      if(ansnum[i] != 0) ret++;
    }
    cout << ret+1 << endl;
  }
}
