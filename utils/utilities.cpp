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

char s[17] = {"b", "kB", "K", "MB", "M", "GB", "G",
              "TB", "T", "PB", "P", "EB", "E", "ZB",
              "Z", "YB", "Y"};

lli mem_parse(char *s) {
   
}
