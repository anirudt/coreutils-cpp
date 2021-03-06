#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <getopt.h>

#define no_argument 0
#define required_argument 1

using namespace std;

void process_selective_env(int optind, int argc, 
              char **envp, char **argv, int zero_set) {
  char **env;
  for (int i = optind; i < argc ; i++) {
    string s = argv[i];
    for (env = envp; *env != 0; env++) {
      string env_entry = *env;
      if (env_entry.find(s) != -1) {
        size_t j = env_entry.find("=");
        string value = env_entry.substr(j+1);
        if(zero_set)
          cout << value;
        else
          cout << value << endl;
        break;
      }
    }
  }
}

void process_all_env(char **envp, int zero_set) {
  char **env;
  for (env = envp; *env != 0; env++) {
    char *environ = *env;
    if(zero_set) 
      cout << environ;
    else
      cout << environ << endl;
  }
}


int main(int argc, char **argv, char **envp) {

  const struct option long_options[] = {
    {"version", no_argument, 0, 'v'},
    {"help",    no_argument, 0, 'h'},
    {"null",    no_argument, 0, '0'},
    {0, 0, 0, 0}
  };
  bool byte_zero = false;
  char **env;
  int option_index = 0;
  int c;

  while((c = getopt_long(argc, argv, "vh0", long_options, &option_index))!=-1) {

    /* Preventing error messages */
    opterr = 0;

    switch(c) {
      case 'v': cout << "printenv: The version is 1.0.1" << endl;
                break;

      case 'h': cout << "Use 'man printenv' to know how to use this tool" << endl;
                cout << "All flags of the original tool are supported" << endl;
                break;

      case '0': byte_zero = true;
                break;

      case '?':
                break;
      case -1: break;
    }
  }
  if (byte_zero) {
    if (optind < argc) {
      process_selective_env(optind, argc, envp, argv, 1);
    }
    else if (argc == 2) {
      process_all_env(envp, 1);
    }
  }
  else {
    if (optind < argc) {
      /* Processing any left non-option arguments */
      process_selective_env(optind, argc, envp, argv, 0);
    }
    else if(argc == 1) {
      /* Handling in case of no argument being passed */
      process_all_env(envp, 0);
    }

  }
  return 0;
}
