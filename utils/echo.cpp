#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <getopt.h>
#include <cstdio>

#define no_argument 0
#define required_argument 1

using namespace std;

void enable_escape(int argc, char **argv, int optind) {
  for (int i=optind; i<argc; i++) {
    char *s = argv[i];

    // Starting from first element
    while(*s) {
      char curr;
      if (*s != '\\') {
        cout << *s;
        s++;
        continue;
      }
      switch(*(s+1)) {
        case '\\': curr = '\\';
                  break;
        case 'a': curr = '\a';
                  break;
        case 'b': curr = '\b';
                  break;
        case 'n': curr = '\n';
                  break;
        case 'r': curr = '\r';
                  break;
        case 't': curr = '\t';
                  break;
        case 'v': curr = '\v';
                  break;
        default:  s++;
                  continue;
      }
      cout << curr;
      s+=2;
    }
  }
}

void disable_escape(int argc, char **argv, int optind) {
  for (int i=optind; i<argc; i++) {
    char *s = argv[i];
    cout << s;
  }
}


int main(int argc, char **argv) {
 
  const struct option long_options[] = {
    {"version", no_argument, 0, 'v'},
    {"help",    no_argument, 0, 'h'},
    {0,         required_argument, 0, 'e'},
    {0,         required_argument, 0, 'E'},
    {0,         required_argument, 0, 'n'},
    {0,         0,           0, 0}
  };

  int option_index = 0;

  int c = getopt_long(argc, argv, "vheEn", long_options, &option_index);
  cout << option_index << endl;

  /* Preventing error messages */
  opterr = 0;

  switch(c) {
    case 'v': cout << "echo: The version is 1.0.1" << endl;
              break;

    case 'h': cout << "Refer the man page for more details" << endl;
              break;

    case 'E': /* Disabling escape sequences */
              disable_escape(argc, argv, optind);
              break;

    case 'n': /* Giving output without new line */
              enable_escape(argc, argv, optind);
              break;

    case '?': /* An unknown option is entered */
              break;

    case 'e': /* Enabling escape sequences */
    case -1: /* Only arguments present, no options */
              enable_escape(argc, argv, optind);
              cout << endl;
              break;
  }
  
  return 0;
}
