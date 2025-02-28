// Name: Ajani Small
// ID: 400017967
// Date: 2/26/2025
// Description: Deque class for a node (Node.h)

#ifndef DEQUE_H
#define DEQUE_H
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
  string displayAll();
  string front();
  string back();
};
Deque::Deque() {
  head = tail = NULL;
  count = 0;
}
string Deque::front() {
  if (head != NULL) {
    return head->getRecord();
  } else {
    return "Deque is empty";
  }
};
string Deque::back() {
  if (tail != NULL) {
    return tail->getRecord();
  } else {
    return "Deque is empty";
  }
};
void Deque::insertFirst(Node node) {
  Node *newNode = new Node(node);

  if (isEmpty()) {
    head = tail = newNode;
  } else {
    newNode->setNext(head);
    head = newNode;
  }
  count += 1;
}

void Deque::insertLast(Node node) {
  Node *newNode = new Node(node);

  if (isEmpty()) {
    head = tail = newNode;
  } else {
    tail->setNext(newNode);
    tail = newNode;
  }
  count += 1;
}

string Deque::removeFirst() {
  if (isEmpty()) {
    return "Error: Attempt to removeFirst from empty deque";
  } else if (head == tail) {
    string record = head->getRecord();
    delete head;
    head = tail = NULL;
    count -= 1;
    return record;
  } else {
    string record = head->getRecord();
    Node *temp = head;
    head = head->getNext();
    delete temp;
    count -= 1;
    return record;
  }
}

string Deque::removeLast() {
  if (isEmpty()) {
    return "Error: Attempt to removeLast from empty deque";
  } else if (head == tail) {
    string record = head->getRecord();
    delete head;
    head = tail = NULL;
    count -= 1;
    return record;
  } else {
    string record = tail->getRecord();
    Node *temp = tail;

    // Find new tail
    Node *curr = head;
    while (curr && curr->getNext() != tail) {
      curr = curr->getNext();
    }
    // Now curr is the previous node of tail
    tail = curr;
    tail->setNext(NULL);
    delete temp;
    count -= 1;
    return record;
  }
}

string Deque::displayAll() {
  if (isEmpty()) {
    return "Empty Deque";
  }
  Node *curr = head;
  string out = "";
  while (curr != NULL) {
    out.append(curr->getRecord());
    out.append("\n");
    curr = curr->getNext();
  }
  return out;
}
#endif // !DEQUE_H
