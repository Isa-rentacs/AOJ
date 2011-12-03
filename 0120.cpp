#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(void){
  string str;

  while(getline(cin,str)){
    istringstream iss(str);
    vector<int> r;
    int tmp;
    int length;
    double res=0;
    double work;

    iss >> length;

    while(iss >> tmp){
      r.push_back(tmp);
    }
    int sz = r.size();
    double dp[sz][sz]; //dp[i][j] := i+1番目まででj個使ったときの最小値
    int last[sz][sz];

    for(int i=0;i<sz;i++){
      for(int j=0;j<sz;j++){
	if(i == 0){
	  if(j == 0){
	    dp[i][j] = r[j];
	    last[i][j] = r[j];
	  }else{
	    dp[i][j] = min(dp[i][j-1], (double)r[j]);
	    if(dp[i][j] == r[j]){
	      last[i][j] = j;
	    }else{
	      last[i][j] = last[i][j-1];
	    }
	  }
	}else if(i == sz-1){
	  //最後の1個
	}else{
	  work = sqrt((last[i-1][j-1] + r[j]) * (last[i-1][j-1] + r[j]) - abs(last[i-1][j-1] - r[j]) * abs(last[i-1][j-1] - r[j]));
	  dp[i][j] = min(dp[i][j-1], dp[i-1][j-1] + work);
	  if(dp[i][j] == dp[i][j-1]){
	    last[i][j] = last[i][j-1];
	  }else{
	    last[i][j] = r[j];
	  }
	}
      }
    }
  }
}
