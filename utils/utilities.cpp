#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

string toString(int i) {
  stringstream convert; convert << i;
  return convert.str();
}

typedef struct memory {
  int amt;
  int multiplier;
} memory;

typedef long long int lli;

string mult_char[7] = {"b", "kB", "K", "MB", "M", "GB", "G"};
//              "TB", "T", "PB", "P", "EB", "E", "ZB",
//              "Z", "YB", "Y"};

lli mult_int[7] = {512, 1000, 1024, 1000*1000, 1024*1024,
                      1000*1000*1000, 1024*1024*1024};

lli mem_parse(char *s) {
  /* Parses memory argument to provide 
   * a number and a multipler*/
  int i = 0;
  string num_str, mult_str;
  cout << s << endl;
  int num; lli mult;
  while(s[i]!='\0') {
    if (s[i] <= 57 && s[i] >= 48)
      num_str = num_str + s[i];
    else
      mult_str = mult_str + s[i];
    i++;
  }
  num = toString(num_str);
  for (int j = 0; j < mult_str.length(); j++) {
    for (int k = 0; k < 7; k++) {
      /* TODO: Compare the 2 strings here
       * IF equal, get the multipler in int vector
       * and break, set flags.
       * ELSE, return error flag.
       */
    }
  }
}

int main(int argc, char **argv) {
  char *s = "412GB";
  lli j = mem_parse(s);
}
