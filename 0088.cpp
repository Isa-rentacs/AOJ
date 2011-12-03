#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void){
  string str, ret;

  while(getline(cin, str)){
    ret = "";
    for(int i=0;i<str.size();i++){
      if(str[i] == ' '){
	ret += "101";
      }else if(str[i] == '\''){ //'
	ret += "000000";
      }else if(str[i] == ','){
	ret += "000011";
      }else if(str[i] == '_'){
	ret += "10010001";
      }else if(str[i] == '.'){
	ret += "010001";
      }else if(str[i] == '?'){
	ret += "000001";
      }else if(str[i] == 'A'){
	ret += "100101";
      }else if(str[i] == 'B'){
	ret += "10011010";
      }else if(str[i] == 'C'){
	ret += "0101";
      }else if(str[i] == 'D'){
	ret += "0001";
      }else if(str[i] == 'E'){
	ret += "110";
      }else if(str[i] == 'F'){
	ret += "01001";
      }else if(str[i] == 'G'){
	ret += "10011011";
      }else if(str[i] == 'H'){
	ret += "010000";
      }else if(str[i] == 'I'){
	ret += "0111";
      }else if(str[i] == 'J'){
	ret += "10011000";
      }else if(str[i] == 'K'){
	ret += "0110";
      }else if(str[i] == 'L'){
	ret += "00100";
      }else if(str[i] == 'M'){
	ret += "10011001";
      }else if(str[i] == 'N'){
	ret += "10011110";
      }else if(str[i] == 'O'){
	ret += "00101";
      }else if(str[i] == 'P'){
	ret += "111";
      }else if(str[i] == 'Q'){
	ret += "10011111";
      }else if(str[i] == 'R'){
	ret += "1000";
      }else if(str[i] == 'S'){
	ret += "00110";
      }else if(str[i] == 'T'){
	ret += "00111";
      }else if(str[i] == 'U'){
	ret += "10011100";
      }else if(str[i] == 'V'){
	ret += "10011101";
      }else if(str[i] == 'W'){
	ret += "000010";
      }else if(str[i] == 'X'){
	ret += "10010010";
      }else if(str[i] == 'Y'){
	ret += "10010011";
      }else if(str[i] == 'Z'){
	ret += "10010000";
      }
    }

    string patt="";
    for(int i=0;i<ret.size() || !patt.empty();i++){
      if(i<ret.size()){
	patt += ret[i];
      }else{
	patt += '0';
      }
      if(i%5 == 4){
	if(patt == "00000"){
	  cout << "A";
	}else if(patt == "00001"){
	  cout << "B";
	}else if(patt == "00010"){
	  cout << "C";
	}else if(patt == "00011"){
	  cout << "D";
	}else if(patt == "00100"){
	  cout << "E";
	}else if(patt == "00101"){
	  cout << "F";
	}else if(patt == "00110"){
	  cout << "G";
	}else if(patt == "00111"){
	  cout << "H";
	}else if(patt == "01000"){
	  cout << "I";
	}else if(patt == "01001"){
	  cout << "J";
	}else if(patt == "01010"){
	  cout << "K";
	}else if(patt == "01011"){
	  cout << "L";
	}else if(patt == "01100"){
	  cout << "M";
	}else if(patt == "01101"){
	  cout << "N";
	}else if(patt == "01110"){
	  cout << "O";
	}else if(patt == "01111"){
	  cout << "P";
	}else if(patt == "10000"){
	  cout << "Q";
	}else if(patt == "10001"){
	  cout << "R";
	}else if(patt == "10010"){
	  cout << "S";
	}else if(patt == "10011"){
	  cout << "T";
	}else if(patt == "10100"){
	  cout << "U";
	}else if(patt == "10101"){
	  cout << "V";
	}else if(patt == "10110"){
	  cout << "W";
	}else if(patt == "10111"){
	  cout << "X";
	}else if(patt == "11000"){
	  cout << "Y";
	}else if(patt == "11001"){
	  cout << "Z";
	}else if(patt == "11010"){
	  cout << " ";
	}else if(patt == "11011"){
	  cout << ".";
	}else if(patt == "11100"){
	  cout << ",";
	}else if(patt == "11101"){
	  cout << "_";
	}else if(patt == "11110"){
	  cout << "'";
	}else if(patt == "11111"){
	  cout << "?";
	}
	patt.clear();
      }
    }
    cout << endl;
  }
}
