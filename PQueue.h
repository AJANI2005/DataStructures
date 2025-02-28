// Name: Ajani Small
// ID: 400017967
// Date: 2/26/2025
// Description: Priority PQueue class for a node (PPQueue.h)

#ifndef PQUEUE_H
#define PQUEUE_H
#include "Node.h"
class PQueue {
private:
  Node *head;
  Node *tail;
  int count;

public:
  PQueue();
  void enqueue(Node node, int priority);
  string dequeue();
  bool isEmpty() { return count == 0; }
  string displayAll();
  int size() { return count; }
  Node *front() { return head; }
  Node *back() { return tail; }
};

PQueue::PQueue() {
  head = tail = NULL;
  count = 0;
}
void PQueue::enqueue(Node node, int priority) {
  Node *newNode = new Node(node);
  newNode->setPriority(priority);

  if (isEmpty()) {
    head = tail = newNode;
  } else if (priority > head->getPriority()) {
    newNode->setNext(head);
    head = newNode;
  } else if (priority < tail->getPriority()) {
    // insert at tail
    tail->setNext(newNode);
    tail = newNode;
  } else {
    // insert in middle
    Node *node = head;
    Node *next = node->getNext();
    while (next != NULL && next->getPriority() >= priority) {
      node = next;
      next = node->getNext();
    }
    // insert
    newNode->setNext(next);
    node->setNext(newNode);
    // tail = next ie. rhs
    tail = next;
  }
  count += 1; // update count
}

string PQueue::dequeue() {
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

string PQueue::displayAll() {
  if (isEmpty()) {
    return "Empty Priority Queue";
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
#endif // !PQUEUE_H
