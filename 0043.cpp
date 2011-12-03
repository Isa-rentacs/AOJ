#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;

int main(void){
  vector<int> hand;
  set<int> ans;
  deque<vector<int> > Q;
  char tmp;

  for(int i=0;i<10;i++){
    hand.push_back(0);
  }

  while(cin >> tmp){
    bool nothing = true;
    //in each case
    hand[tmp - '0']++;
    for(int i=0;i<12;i++){
      cin >> tmp;
      hand[tmp - '0']++;
    }

    for(int i=1;i<=9;i++){
      vector<int> tmp, work;
      int kind = 0;
      int sum = 0;
      if(hand[i] < 4){
	hand[i]++;
      }else{
	continue;
      }
      Q.clear();
      Q.push_back(hand);
      hand[i]--;
      while(!Q.empty()){
	tmp = Q.front(); Q.pop_front();

	/* ended or not*/
	kind = 0;
	sum = 0;
	for(int j=1;j<=9;j++){
	  sum += tmp[j];
	  if(tmp[j] != 0) kind++;
	}
	if(sum == 2 && kind == 1){
	  ans.insert(i);
	  break;
	}


	for(int j=1;j<=9;j++){
	  if(tmp[j] >= 3){// can be used as a head
	    tmp[j] -= 3;
	    if(find(Q.begin(), Q.end(), tmp) == Q.end()){
	      Q.push_back(tmp);
	    }
	    tmp[j] += 3;
	  }
	}
	
	for(int j=1;j<=7;j++){
	  if(tmp[j] >= 1 && tmp[j+1] >= 1 && tmp[j+2] >= 1){
	    tmp[j]--; tmp[j+1]--; tmp[j+2]--;
	    if(find(Q.begin(), Q.end(), tmp) == Q.end()){
	      Q.push_back(tmp);
	    }
	    tmp[j]++; tmp[j+1]++; tmp[j+2]++;
	  }
	}
      }
    }
    set<int>::iterator it = ans.begin();
    if(ans.size() == 0){
      cout << 0 << endl;
    }else{
      for(int i=0;i<ans.size()-1;++it){
	cout << *it << " ";
	i++;
      }
      cout << *it << endl;
    }
    hand.clear();
    for(int i=0;i<10;i++){
      hand.push_back(0);
    }
    ans.clear();
  }  
}
