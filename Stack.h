// Name: Ajani Small
// ID: 400017967
// Date: 2/26/2025
// Description: Stack class for a node (Node.h)

#ifndef STACK_H
#define STACK_H
#include "Node.h"
class Stack {
private:
  Node *head;
  Node *tail;
  int count;

public:
  Stack();
  void push(Node node);
  string pop();
  bool isEmpty() { return count == 0; }
  string displayAll();
  int size() { return count; }
  string front();
  string back();
};

Stack::Stack() {
  head = tail = NULL;
  count = 0;
}
string Stack::front() {
  if (head != NULL) {
    return head->getRecord();
  } else {
    return "Stack is empty";
  }
};
string Stack::back() {
  if (tail != NULL) {
    return tail->getRecord();
  } else {
    return "Stack is empty";
  }
};
void Stack::push(Node node) {
  Node *newNode = new Node(node);
  if (isEmpty()) {
    head = tail = newNode;
  } else {
    newNode->setNext(head);
    head = newNode;
  }
  count += 1;
}

string Stack::pop() { // remove from head
  if (isEmpty()) {
    // case 1 : empty stack
    return "Error: Attempt to pop from empty stack";
  } else if (head == tail) {
    // case 2 : one node in stack
    string record = head->getRecord();
    delete head;
    head = tail = NULL;
    count -= 1; // update count
    return record;
  } else {
    // case 3 : more than one node in stack
    string record = head->getRecord();
    Node *temp = head;
    head = head->getNext();
    delete temp;
    count -= 1; // update count
    return record;
  }
}

string Stack::displayAll() {
  if (isEmpty()) {
    return "Empty Stack";
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
#endif // !STACK_H
