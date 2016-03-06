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
  {"version", no_argument, 0, 0},
  {"help",    no_argument, 0, 0},
  {"null",    no_argument, 0, 0},
  {0, 0, 0, 0}
};
  char **env;

  if (argc > 1) {
    for (int i = 1; i < argc ; i++) {
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

  else {
    /* Handling in case of no argument being passed */
    for (env = envp; *env != 0; env++) {
      char *environ = *env;
      cout << environ << endl;
    }
  }
  return 0;
}
