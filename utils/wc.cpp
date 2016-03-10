#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <getopt.h>
#include <cstdio>
#include <fstream>

#define no_argument 0
#define required_argument 1

using namespace std;

int line_count(char *s) {
  int line_count = 0;
  ifstream fin(s, ios::in); string line;
  while(getline(fin, line)) {
    line_count++;
  }
  return line_count;
}

int char_count(char *s) {
  int char_count = 0;
  ifstream fin(s, ios::in); char tmp;
  fin.get( tmp );
  while(!fin.eof()) {
    fin.get( tmp );
    char_count++;
  }
  return char_count;
}

int stat_count(bool byte_counter, bool char_counter,
    bool line_counter, bool get_max_line,
    bool word_counter, bool read_master_file, char **argv, int optind, int argc) {
  /* For each file, DO */
  for (int i = optind; i < argc; i++) {
    int byte_cnt, char_cnt, line_cnt, max_line, word_cnt, master_file;
    if (byte_counter) {
    }
    if (char_counter) {
      char_cnt = char_count(argv[i]);
    }
    if (line_counter) {
      line_cnt = line_count(argv[i]);
    }
    if (get_max_line) {
    }
    if (word_counter) {
    }
    if (read_master_file) {
    }
    cout << char_cnt << " " << line_cnt << " " << argv[i] << endl;
  }
}

int main(int argc, char **argv) {
  const struct option long_options[] = {
    {"bytes", required_argument, 0, 'c'},
    {"chars", required_argument, 0, 'm'},
    {"lines", required_argument, 0, 'l'},
    {"files0-from", required_argument, 0, 'f'},
    {"max-line-length", required_argument, 0, 'L'},
    {"words", required_argument, 0, 'w'},
    {"version", no_argument, 0, 'v'},
    {"help", no_argument, 0, 'h'}
  }; 

  int option_index = 0;
  bool byte_counter = false, char_counter = false,
       line_counter = false, get_max_line = false,
       word_counter = false, read_master_file = false;

  int c;
  while((c = getopt_long(argc, argv, "cmlfLwvh", long_options, &option_index))!=-1) {
    switch(c) {
      case 'c': byte_counter = true;
                break;
      case 'm': char_counter = true;
                break;
      case 'l': line_counter = true;
                break;
      case 'f': read_master_file = true;
                break;
      case 'L': get_max_line = true;
                break;
      case 'w': word_counter = true;
                break;
      case '?': break;
      case -1: break;
    }
  }
  stat_count(byte_counter, char_count, line_counter, get_max_line, word_counter, read_master_file, argv, optind, argc);


  return 0;
} 
