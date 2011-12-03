#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

int main(void){
  int n,choose,goal,d;

  while(1){
    //for each data set
    cin >> n;
    if(n==0) break;
    cin >> choose;
    cin >> goal;
    cin >> d;

    int num[n+1];
    int state[d+1][n+1]; //state[i][j] := i-th state's j-th vertical line
    bool table[d+1][n];

    //initialize array
    for(int i=1;i<=n;i++){
      num[i] = i;
      state[0][i] = i;
      //cout << state[0][i] << " ";
    }
    //cout << endl;
    
    cin.ignore();

    //swap numbers
    for(int i=1;i<=d;i++){
      string str;
      char tmp;
      getline(cin, str);
      istringstream iss(str);
      int j=1;
      int itmp;

      while(iss >> tmp){
	if(tmp == '1'){
	  table[i][j] = true;
	  swap(num[j], num[j+1]);
	}else{
	  table[i][j] = false;
	}
	j++;
      }
      for(int j=1;j<=n;j++){
	state[i][j] = num[j];
	//cout << state[i+1][j] << " ";
      }
      //cout << endl;
    }

    //cout << "correct line is " << state[d][goal] << endl;
    
    //output result
    if(state[d][choose] == goal){
      cout << 0 << endl;
      goto next;
    }

    for(int i=0;i<d;i++){
      for(int j=1;j<n;j++){
	//cout << state[i][j] << " [" << table[i][j] << "] ";
	if(((state[i][j] == choose && state[i][j+1] == state[d][goal]) ||
	    (state[i][j] == state[d][goal] && state[i][j+1] == choose)) &&
	   table[i+1][j] == false){
	  bool isok = false;
	  if(j == 1){
	    if(table[i+1][2] == false){
	      isok = true;
	    }
	  }else if(j == n-1){
	    if(table[i+1][n-2] == false){
	      isok = true;
	    }
	  }else{
	    if(table[i+1][j-1] == false && table[i+1][j+1] == false){
	      isok = true;
	    }
	  }
	  if(isok){
	    cout << i+1 << " " << j << endl;
	    goto next;
	  }
	}
      }
      //cout << state[i][n];
      //cout << endl;
    }
    cout << 1 << endl;
  next:;
  }
}
