#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <getopt.h>

#define no_argument 0
#define required_argument 1

using namespace std;

/* TODO 
 *
 * Make a function to 
 * strip double and single
 * quotes.
 *
 */

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

  int c = getopt_long(argc, argv, "vhe:E:n:", long_options, &option_index);
  cout << option_index << endl;

  /* Preventing error messages */
  opterr = 0;

  switch(c) {
    case 'v': cout << "echo: The version is 1.0.1" << endl;
              break;

    case 'h': cout << "Refer the man page for more details" << endl;
              break;

    case 'e': break;

    case 'E': break;

    case 'n': break;

    case '?': break;

    case -1: break;
  }
  
  return 0;
}
