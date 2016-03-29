#include <cstdio>
#include <iostream>
#include <string>
#include <getopt.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "utilities.h"

#define no_argument 0
#define required_argument 1

using namespace std;

void print_lines(char *s, lli n) {
  ifstream fin(s, ios::in); string line;
  lli line_count = 0;
  while(getline(fin, line) && line_count < n) {
    cout << line << endl;
    line_count++;
  }
}

void print_chars(char *s, lli n) {
  ifstream fin(s, ios::in); char tmp;
  lli char_count = 0;
  while(!fin.eof() && char_count < n) {
    fin.get(tmp);
    cout << tmp; char_count++;
  }
}

void process(int argc, char **argv, int optind, bool line_print, lli line_print_arg,
             bool char_print, lli char_print_arg, bool quiet_print) {
  for (int i = optind; i < argc; i++) {
    if (!quiet_print) 
      cout << "==> " << argv[i] << " <==" << endl;
    else {}
    if (line_print) {
      print_lines(argv[i], line_print_arg);
    }
    if (char_print) {
      print_chars(argv[i], char_print_arg);
    }
    if (!quiet_print)
      cout << endl;
  }
}

int main(int argc, char **argv) {
  const struct option long_options[] = {
  {"bytes", required_argument, 0, 'c'},
  {"lines", required_argument, 0, 'n'},
  {"quiet", no_argument,       0, 'q'},
  {"verbose", no_argument,     0, 'v'},
  {"help",  no_argument,       0, 'h'},
  {"version", no_argument,     0, 'k'}
  }; 
  int option_index = 0;
  int c;

  // Indicators
  bool line_print = false, char_print = false, quiet_print = false,
       verbose_print = true;
  lli line_print_arg = 0, char_print_arg = 0;
  while((c = getopt_long(argc, argv, "c:n:qvhk", long_options, &option_index)) != -1) {
    switch(c) {
      case 'n': line_print = true;
                line_print_arg = mem_parse(optarg);
                break;
      case 'c': char_print = true;
                char_print_arg = mem_parse(optarg);
                break;
      case 'q': quiet_print = true;
                break;
      case 'v': break;
      case 'k': cout << "head: The version is 1.0.1" << endl;
                break;
      case 'h': cout << "Please see the man page for help" << endl;
                cout << "Flags supported: -c, -n, -q, -v, -k" << endl;
      case '?': break;
      case -1:  break;
    }
  }
  if (!line_print && !char_print) {
    process(argc, argv, optind, true, 10, false, 0, quiet_print);
  }
  else {
    process(argc, argv, optind, line_print, line_print_arg,
            char_print, char_print_arg, quiet_print);
  }
  return 0;
}
