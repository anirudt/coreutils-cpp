#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <getopt.h>
#include <cstdio>

#define no_argument 0
#define required_argument 1

using namespace std;

int main(int argc, char **argv) {
  const struct option long_options[] = {
  {"bytes", required_argument, 0, 'c'},
  {"chars", required_argument, 0, 'm'},
  {"lines", required_argument, 0, 'l'},
  {"files0-from", required_argument, 0, 'f'},
  {"max-line-length", required_argument, 0, 'x'},
  {"words", required_argument, 0, 'w'},
  {"version"}
  }; 

  int optind = 0;

  while((c = getopt_long())!=-1) {
    case 'c': break;

    case 'm': break;

    case 'l': break;

    case 'f': break;

    case 'x': break;

    case 'w': break;

    case '?': break;

    case -1: break;
  }

  return 0;
} 
