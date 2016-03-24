#include <cstdio>
#include <iostream>
#include <string>
#include <getopt.h>
#include <cstdlib>
#include <fstream>
#include <sstream>

#define no_argument 0
#define required_argument 1

using namespace std;

void print_lines(char *s, int n) {
  ifstream fin(s, ios::in); string line;
  int line_count = 0;
  while(getline(fin, line) && line_count < n) {
    cout << line << endl;
    line_count++;
  }
}

void process(int argc, char **argv, int optind, bool line_print, int line_print_arg) {
  for (int i = optind; i < argc; i++) {
    cout << "==> " << argv[i] << " <==" << endl;
    if (line_print) {
      print_lines(argv[i], line_print_arg);
    }
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
  bool line_print = false;
  int line_print_arg = 0;
  while((c = getopt_long(argc, argv, "c:n:qvhk", long_options, &option_index)) != -1) {
    switch(c) {
      case 'n': line_print = true;
                line_print_arg = stoi(optarg);
                break;
    }
  }
  if (!line_print) {
    process(argc, argv, optind, line_print, 10);
  }
  else {
    process(argc, argv, optind, line_print, line_print_arg);
  }
  return 0;
}
