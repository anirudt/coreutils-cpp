#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <getopt.h>

#define no_argument 0
#define required_argument 1

using namespace std;


int main(int argc, char **argv) {
 
  const struct option long_options[] = {
    {"version", no_argument, 0, 0},
    {"help",    no_argument, 0, 0},
    {0,         no_argument, 0, 'e'},
    {0,         no_argument, 0, 'E'},
    {0.         no_argument, 0, 'n'},
    {0,         0,           0, 0}
  };

  int option_index = 0;

  int c = getopt_long(argc, argv, "", long_options, &option_index);

  /* Preventing error messages */
  opterr = 0;
  return 0;
}
