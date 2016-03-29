#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include "utilities.h"
using namespace std;

typedef long long int lli;

string mult_char[7] = {"b", "kB", "K", "MB", "M", "GB", "G"};
//              "TB", "T", "PB", "P", "EB", "E", "ZB",
//              "Z", "YB", "Y"};

lli mult_int[7] = {512, 1000, 1024, 1000*1000, 1024*1024,
                      1000*1000*1000, 1024*1024*1024};

lli mem_parse(string s) {
  /* Parses memory argument to provide 
   * a number and a multipler*/
  int i = 0;
  string num_str="", mult_str="";
  cout << s << endl;
  int num; lli mult;
  int flag = 0;
  while(s[i]!='\0') {
    if (s[i] <= 57 && s[i] >= 48)
      num_str = num_str + s[i];
    else
      mult_str = mult_str + s[i];
    i++;
  }
  num = stoi(num_str.c_str());
  for (int j = 0; j < mult_str.length() && flag == 0; j++) {
    for (int k = 0; k < 7; k++) {
      if (!mult_str.compare(mult_char[k])) {
        mult = mult_int[k];
        flag = 1;
        break;
      }
    }
  }
  lli mem = num*mult;
  return mem;
}
