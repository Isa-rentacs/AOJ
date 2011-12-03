#include <iostream>
#include <sstream>
#include <map>
#include <cstring>
#include <string>
#include <iterator>

using namespace std;

int main(void){
  bool lastmonth[1000];
  bool thismonth[1000];
  map<int,int> times;
  int num, val;
  string str;

  memset(lastmonth, false, sizeof(lastmonth));
  memset(thismonth, false, sizeof(thismonth));
  while(getline(cin, str)){
    if(str.size() == 0) break;
    istringstream iss(str);
    iss >> num;
    iss.ignore();
    iss >> val;
    lastmonth[num] = true;
    times[num]++;
  }

  while(getline(cin,str)){
    if(str.size() == 0) break;
    istringstream iss(str);
    iss >> num;
    iss.ignore();
    iss >> val;
    thismonth[num] = true;
    times[num]++;
  }

  map<int,int>::iterator it = times.begin();
  for(;it!=times.end();++it){
    if(lastmonth[(*it).first] && thismonth[(*it).first]){
      cout << (*it).first << " " << (*it).second << endl;
    }
  }
}
