/* Author   :   Ajani Small
 * ID       :   400017967
 * DATE     :   26 February, 2025
 *
 * Purpose:
 *
 * This class represents a song record data structure.
 * In particular, it stores song information including month, year,
 * artist, title, record label, and weeks at #1 position.
 *
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
using namespace std;
class Node {
private:
  // member variables
  string month;
  int year;
  string artist;
  string title;
  string recordLabel;
  int weeksAtNumberOne;
  int priority;
  Node *next;

public:
  Node(string monthName, int yearNum, string artistName, string songTitle,
       string labelName, int weeks);

  // accessor functions
  string getMonth() { return month; }
  int getYear() { return year; }
  string getArtist() { return artist; }
  string getTitle() { return title; }
  string getRecordLabel() { return recordLabel; }
  int getWeeksAtNumberOne() { return weeksAtNumberOne; }
  Node *getNext() { return next; }
  int getPriority() { return priority; }
  string getRecord();

  // mutator functions
  void setMonth(string monthName) { month = monthName; }
  void setYear(int yearNum) { year = yearNum; }
  void setArtist(string artistName) { artist = artistName; }
  void setTitle(string songTitle) { title = songTitle; }
  void setRecordLabel(string labelName) { recordLabel = labelName; }
  void setWeeksAtNumberOne(int weeks) { weeksAtNumberOne = weeks; }
  void setPriority(int p) { priority = p; }
  void setNext(Node *nextNode) { next = nextNode; }
};

// Node Constructor - constructs an object of the Node class
Node::Node(string monthName, int yearNum, string artistName, string songTitle,
           string labelName, int weeks) {
  month = monthName;
  year = yearNum;
  artist = artistName;
  title = songTitle;
  recordLabel = labelName;
  weeksAtNumberOne = weeks;
  next = NULL;
  priority = 0;
}

// This function returns a string representation of the Node class
string Node::getRecord() {
  string out = "";
  out.append(month);
  out.append("\t");
  out.append(to_string(year));
  out.append("\t");
  out.append(artist);
  out.append("\t");
  out.append(title);
  out.append("\t");
  out.append(recordLabel);
  out.append("\t");
  out.append(to_string(weeksAtNumberOne));
  return out;
}

#endif // !NODE_H
