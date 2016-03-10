#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <getopt.h>
#include <cstdio>
#include <fstream>

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
  {"version", no_argument, 0, 'v'},
  {"help", no_argument, 0, 'h'}
  }; 

  int option_index = 0;

  int c;
  while((c = getopt_long(argc, argv, "cmlfxwvh", long_options, &option_index))!=-1) {
    switch(c) {
      case 'c': for (int i=optind; i<argc; i++) {
                  int char_count = 0;
                  ifstream fin(argv[i], ios::in); char tmp;
                  fin.get( tmp );
                  while(!fin.eof()) {
                    fin.get( tmp );
                    char_count++;
                  }
                  cout << char_count << " " << argv[i] << endl;
                }
                break;
      case 'm': break;
      case 'l': break;
      case 'f': break;
      case 'x': break;
      case 'w': break;
      case '?': break;
      case -1: break;
    }
  }

  return 0;
} 
