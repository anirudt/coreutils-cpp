#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv, char **envp) {
  
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
