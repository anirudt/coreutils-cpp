#include <stdlib.h>
#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char **argv, char **envp) {
  char **env;
  for (env = envp; *env != 0; env++) {
    char *environ = *env;
    cout << environ << endl;
  }

  return 0;
}
