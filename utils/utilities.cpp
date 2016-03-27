#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

typdef struct memory {
  int amt;
  int multiplier;
} memory;

typedef long long int lli;

char s[7] = {"b", "kB", "K", "MB", "M", "GB", "G"};
//              "TB", "T", "PB", "P", "EB", "E", "ZB",
//              "Z", "YB", "Y"};

lli multiplier[7] = {512, 1000, 1024, 1000*1000, 1024*1024,
                      1000*1000*1000, 1024*1024*1024};

lli mem_parse(char *s) {
  /*Parses memory argument to provide 
   * a number and a multipler*/
   
}
