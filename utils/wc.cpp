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

string toString(int i) {
  stringstrean convert; convert << i;
  return convert.str();
}

int line_count(char *s) {
  int line_count = 0;
  ifstream fin(s, ios::in); string line;
  while(getline(fin, line)) {
    line_count++;
  }
  return line_count;
}

int max_line_length(char *s) {
  int max_line_length = 0;
  ifstream fin(s, ios::in); string line;
  while(getline(fin, line)) {
    if (line.length() > max_line_length) {
      max_line_length = line.length();
    }
  }
  return max_line_length;
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

int word_count(char *s) {
  int word_count = 1;
  ifstream fin(s, ios::in); char tmp;
  fin.get( tmp );
  while(!fin.eof()) {
    if (tmp == ' ') {
      word_count++;
    }
    fin.get( tmp );
  }
  return word_count;
}

int stat_count(bool byte_counter, bool char_counter,
    bool line_counter, bool get_max_line,
    bool word_counter, bool read_master_file, char **argv, int optind, int argc) {
  /* For each file, DO */
  int tot_byte_cnt = 0, tot_char_cnt = 0,
      tot_line_cnt = 0, glob_max_line = 0,
      tot_word_cnt = 0;
  string glob_str;
  for (int i = optind; i < argc; i++) {
    int byte_cnt = 0, char_cnt = 0, line_cnt = 0, max_line = 0, word_cnt = 0, master_file = 0;
    string str;
    if (line_counter) {
      line_cnt = line_count(argv[i]);
      str += toString(line_cnt);
      str += " ";
      tot_line_cnt += line_cnt;
    }
    if (word_counter) {
      word_cnt = word_count(argv[i]);
      str += toString(word_cnt);
      str += " ";
      tot_word_cnt += word_cnt;
    }
    if (byte_counter) {
    }
    if (char_counter) {
      char_cnt = char_count(argv[i]);
      str += toString(char_cnt);
      str += " ";
      tot_char_cnt += char_cnt;
    }
    if (get_max_line) {
      max_line = max_line_length(argv[i]);
      str += toString(max_line);
      str += " ";

      if (max_line > glob_max_line) {
        glob_max_line = max_line;
      }
    }
    if (read_master_file) {
    }
    if (byte_counter | char_counter | get_max_line | word_counter | read_master_file) {
      cout << str << argv[i] << endl;
    }
  }
  /* Do global printing over here*/
  /* Check for argc > 2, and also for max line len */

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
      case 'w': //word_counter = true;
                cout << "wc: word count not implemented yet" << endl;
                break;
      case 'v': cout << "wc: The version is 1.0.1" << endl;
                break;
      case 'h': cout << "Please see the man page for help" << endl;
                break;
      case '?': break;
      case -1: break;
    }
  }
  if ( !byte_counter && !char_counter && !line_counter && !get_max_line && !word_counter ) {
    stat_count(true, true, true, true, true, true, argv, optind, argc);
  }
  else {
    stat_count(byte_counter, char_counter, line_counter, get_max_line, word_counter, read_master_file, argv, optind, argc);
  }

  return 0;
} 
