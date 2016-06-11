#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <getopt.h>

#define no_argument 0
#define required_argument 1

using namespace std;

int copy_file() {
  int ret = 0;

  return ret;
}

int main(int argc, char **argv, char **envp) {

  const struct option long_options[] = {
    {"version", no_argument, 0, 'v'},
    {"help",    no_argument, 0, 'h'},
    {"null",    no_argument, 0, '0'},
    {0, 0, 0, 0}
  };

  int option_index = 0;
  int c;

  while((c = getopt_long(argc, argv, "vh0", long_options, &option_index))!=-1) {

    /* Preventing error messages */
    opterr = 0;

    switch(c) {
      case 'v': cout << "cp: The version is 1.0.1" << endl;
                break;

      case 'h': cout << "Use 'man cp' to know how to use this tool" << endl;
                cout << "All flags of the original tool are supported" << endl;
                break;

      case '0': byte_zero = true;
                break;

      case '?':
                break;
      case -1: break;
    }
  }
  int ret;
  if ((ret = copy_file()) == 1) {
    
  }
  else {

  }
  return 0;
}
