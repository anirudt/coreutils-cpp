#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <getopt.h>

#define no_argument 0
#define required_argument 1

using namespace std;


int main(int argc, char **argv, char **envp) {
  
  const struct option long_options[] = {
    {"version", no_argument, 0, 'v'},
    {"help",    no_argument, 0, 'h'},
    {"null",    no_argument, 0, '0'},
    {0, 0, 0, 0}
  };
  char **env;
  int option_index = 0;

  int c = getopt_long(argc, argv, "vh0", long_options, &option_index);

  /* Preventing error messages */
  opterr = 0;

  switch(c) {
    case 'v': cout << "printenv: The version is 1.0.1" << endl;
              break;

    case 'h': cout << "Use 'man printenv' to know how to use this tool" << endl;
              break;

    case '0': /* TODO */
              cout << "Ending each line with byte 0, rather than newline" << endl;
              break;

    case '?': break;
  }

  if (optind < argc) {
    /* Processing any left non-option arguments */
    for (int i = optind; i < argc ; i++) {
      string s = argv[i];
      for (env = envp; *env != 0; env++) {
        string env_entry = *env;
        if (env_entry.find(s) != -1) {
          cout << env_entry << endl;
          break;
        }
      }
    }
  }
  else if(argc == 1) {
    /* Handling in case of no argument being passed */
    for (env = envp; *env != 0; env++) {
      char *environ = *env;
      cout << environ << endl;
    }
  }
  return 0;
}
