// Name: Ajani Small
// ID: 400017967
// Date: 2/26/2025
// Description: Stack class for a node (Node.h)

#ifndef STACK_H
#define STACK_H
#include "Node.h"
class Stack {
private:
  Node *top;
  int count;

public:
  Stack();
  void push(Node node);
  string pop();
  bool isEmpty() { return count == 0; }
  string toString();
  int size() { return count; }
};

Stack::Stack() {
  top = NULL;
  count = 0;
}
void Stack::push(Node node) {
  // case 1 : empty stack
  Node *newNode = new Node(node);
  if (isEmpty()) {
    top = newNode;
  } else {
    // add to top
    newNode->setNext(top);
    top = newNode;
  }
  count += 1; // update count
}

string Stack::pop() {
  if (isEmpty()) {
    // case 1 : empty stack
    return "Error: Attempt to removeFirst from empty stack";
  } else if (size() == 1) {
    // case 2 : one node in stack
    string record = top->getRecord();
    delete top;
    top = NULL;
    count -= 1; // update count
    return record;
  } else {
    // case 3 : more than one node in stack
    string record = top->getRecord();
    Node *temp = top;
    top = top->getNext();
    delete temp;
    count -= 1; // update count
    return record;
  }
}

string Stack::toString() {
  if (isEmpty()) {
    return "Empty Stack";
  }
  Node *curr = top;
  string out = "";
  while (curr != NULL) {
    if (curr == top) {
      out.append(" [Top] -> ");
    }
    out.append(curr->getRecord());
    out.append(" -> ");
    curr = curr->getNext();
  }
  return out;
}
#endif // !STACK_H
