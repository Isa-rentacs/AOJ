#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool debug = false;;

int main(void){
  string str;
  string conv="";

  while(getline(cin,str)){
    conv.clear();
    for(int i=0;i<str.size();i++){
      switch(str[i]){
      case ' ':
	conv += "11010";
	break;
      case '\'':
	conv += "11110";
	break;
      case ',':
	conv += "11100";
	break;
      case '-':
	conv += "11101";
	break;
      case '.':
	conv += "11011";
	break;
      case '?':
	conv += "11111";
	break;
      case 'A':
	conv += "00000";
	break;
      case 'B':
	conv += "00001";
	break;
      case 'C':
	conv += "00010";
	break;
      case 'D':
	conv += "00011";
	break;
      case 'E':
	conv += "00100";
	break;
      case 'F':
	conv += "00101";
	break;
      case 'G':
	conv += "00110";
	break;
      case 'H':
	conv += "00111";
	break;
      case 'I':
	conv += "01000";
	break;
      case 'J':
	conv += "01001";
	break;
      case 'K':
	conv += "01010";
	break;
      case 'L':
	conv += "01011";
	break;
      case 'M':
	conv += "01100";
	break;
      case 'N':
	conv += "01101";
	break;
      case 'O':
	conv += "01110";
	break;
      case 'P':
	conv += "01111";
	break;
      case 'Q':
	conv += "10000";
	break;
      case 'R':
	conv += "10001";
	break;
      case 'S':
	conv += "10010";
	break;
      case 'T':
	conv += "10011";
	break;
      case 'U':
	conv += "10100";
	break;
      case 'V':
	conv += "10101";
	break;
      case 'W':
	conv += "10110";
	break;
      case 'X':
	conv += "10111";
	break;
      case 'Y':
	conv += "11000";
	break;
      case 'Z':
	conv += "11001";
	break;
      }
    }
    if(debug) cout << conv << endl;

    str.clear();
    for(int i=0;i<conv.size();i++){
      str += conv[i];
      if(str == "101"){
	cout << " ";
	str.clear();
      }else if(str == "000000"){
	cout << "'";
	str.clear();
      }else if(str == "000011"){
	cout << ",";
	str.clear();
      }else if(str == "10010001"){
	cout << "-";
	str.clear();
      }else if(str == "010001"){
	cout << ".";
	str.clear();
      }else if(str == "000001"){
	cout << "?";
	str.clear();
      }else if(str == "100101"){
	cout << "A";
	str.clear();
      }else if(str == "10011010"){
	cout << "B";
	str.clear();
      }else if(str == "0101"){
	cout << "C";
	str.clear();
      }else if(str == "0001"){
	cout << "D";
	str.clear();
      }else if(str == "110"){
	cout << "E";
	str.clear();
      }else if(str == "01001"){
	cout << "F";
	str.clear();
      }else if(str == "10011011"){
	cout << "G";
	str.clear();
      }else if(str == "010000"){
	cout << "H";
	str.clear();
      }else if(str == "0111"){
	cout << "I";
	str.clear();
      }else if(str == "10011000"){
	cout << "J";
	str.clear();
      }else if(str == "0110"){
	cout << "K";
	str.clear();
      }else if(str == "00100"){
	cout << "L";
	str.clear();
      }else if(str == "10011001"){
	cout << "M";
	str.clear();
      }else if(str == "10011110"){
	cout << "N";
	str.clear();
      }else if(str == "00101"){
	cout << "O";
	str.clear();
      }else if(str == "111"){
	cout << "P";
	str.clear();
      }else if(str == "10011111"){
	cout << "Q";
	str.clear();
      }else if(str == "1000"){
	cout << "R";
	str.clear();
      }else if(str == "00110"){
	cout << "S";
	str.clear();
      }else if(str == "00111"){
	cout << "T";
	str.clear();
      }else if(str == "10011100"){
	cout << "U";
	str.clear();
      }else if(str == "10011101"){
	cout << "V";
	str.clear();
      }else if(str == "000010"){
	cout << "W";
	str.clear();
      }else if(str == "10010010"){
	cout << "X";
	str.clear();
      }else if(str == "10010011"){
	cout << "Y";
	str.clear();
      }else if(str == "10010000"){
	cout << "Z";
	str.clear();
      }
    }
    cout << endl;
    str.clear();
  }
}
