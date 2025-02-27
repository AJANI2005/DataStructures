#include "Node.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  ifstream infile("Catalog.txt");
  if (!infile.is_open()) {
    cerr << "Error opening file" << endl;
    return 1;
  }
  // Month*Year*Artist(s)*Single*Record-label*Weeks-at-number-one
  string month, artist, title, recordLabel, heading;
  int year, weeks;
  char asterisk;
  // read off the first line
  getline(infile, heading, '\n');
  cout << "The heading line: \n\n" << heading << endl;

  // read in the first record
  getline(infile, month, '*');
  infile >> year;
  infile >> asterisk;
  getline(infile, artist, '*');
  getline(infile, title, '*');
  getline(infile, recordLabel, '*');
  infile >> weeks;

  Node head = Node(month, year, artist, title, recordLabel, weeks);
  cout << head.getRecord() << endl;

  return 0;
}
