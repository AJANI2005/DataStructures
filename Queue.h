// Name: Ajani Small
// ID: 400017967
// Date: 2/26/2025
// Description: Queue class for a node (Node.h)

#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
class Queue {
private:
  Node *head;
  Node *tail;
  int count;

public:
  Queue();
  void enqueue(Node node);
  string dequeue();
  bool isEmpty() { return count == 0; }
  string toString();
  int size() { return count; }
};

Queue::Queue() {
  head = tail = NULL;
  count = 0;
}
void Queue::enqueue(Node node) {
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

string Queue::dequeue() {
  if (isEmpty()) {
    // case 1 : empty queue
    return "Error: Attempt to dequeue from empty queue";
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

string Queue::toString() {
  if (isEmpty()) {
    return "Empty Queue";
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
#endif // !QUEUE_H
