// Name: Ajani Small
// ID: 400017967
// Date: 2/26/2025
// Description: Deque class for a node (Node.h)

#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
class Deque {
private:
  Node *head;
  Node *tail;
  int count;

public:
  Deque();
  void insertLast(Node node);
  void insertFirst(Node node);
  string removeLast();
  string removeFirst();
  bool isEmpty() { return count == 0; }
  int size() { return count; }
  string toString();
};
Deque::Deque() {
  head = tail = NULL;
  count = 0;
}
void Deque::insertFirst(Node node) {
  // case 1 : empty queue
  Node *newNode = new Node(node);
  if (isEmpty()) {
    head = tail = newNode;
  } else {
    // add to head
    newNode->setNext(head);
    head = newNode;
  }
  count += 1; // update count
}
void Deque::insertLast(Node node) {
  // case 1 : empty queue
  Node *newNode = new Node(node);
  if (isEmpty()) {
    head = tail = newNode;
  } else {
    // add to tail
    tail->setNext(newNode);
    tail = newNode;
  }
  count += 1; // update count
}

string Deque::removeFirst() {
  if (isEmpty()) {
    // case 1 : empty queue
    return "Error: Attempt to removeFirst from empty queue";
  } else if (head == tail) {
    // case 2 : one node in queue
    string record = head->getRecord();
    delete head;
    head = tail = NULL;
    count -= 1; // update count
    return record;
  } else {
    // case 3 : more than one node in queue
    string record = head->getRecord();
    Node *temp = head;
    head = head->getNext();
    delete temp;
    count -= 1; // update count
    return record;
  }
}

string Deque::removeLast() {
  if (isEmpty()) {
    // case 1 : empty queue
    return "Error: Attempt to removeFirst from empty queue";
  } else if (head == tail) {
    // case 2 : one node in queue
    string record = head->getRecord();
    delete head;
    head = tail = NULL;
    count -= 1; // update count
    return record;
  } else {
    // case 3 : more than one node in queue
    string record = tail->getRecord();
    Node *temp = tail;
    // set new tail
    Node *curr = head;
    for (int i = 0; i < count; i++) {
      if (curr->getNext() == tail) {
        tail = curr;
        break;
      }
    }
    delete temp;
    count -= 1; // update count
    return record;
  }
}
string Deque::toString() {
  if (isEmpty()) {
    return "Empty Deque";
  }
  Node *curr = head;
  string out = "";
  while (curr != NULL) {
    if (curr == head) {
      out.append(" [Head] -> ");
    }
    out.append(curr->getRecord());
    if (curr == tail) {
      out.append(" <- [Tail] ");
    } else {
      out.append(" -> ");
    }
    curr = curr->getNext();
  }
  return out;
}
#endif // !DEQUE_H
