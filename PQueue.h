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
  string front();
  string back();
};

PQueue::PQueue() {
  head = tail = NULL;
  count = 0;
}
string PQueue::front() {
  if (head != NULL) {
    return head->getRecord();
  } else {
    return "Priority Queue is empty";
  }
}
string PQueue::back() {
  if (tail != NULL) {
    return tail->getRecord();
  } else {
    return "Priority Queue is empty";
  }
}
void PQueue::enqueue(Node node, int priority) {
  Node *newNode =
      new Node(node); // Create a new node with the provided node data
  newNode->setPriority(priority); // Set the priority of the new node

  if (isEmpty()) {
    // If the queue is empty, newNode is both the head and tail
    head = tail = newNode;
  } else if (priority > head->getPriority()) {
    // If the new node has higher priority than the head, insert at the front
    newNode->setNext(head);
    head = newNode;
  } else if (priority <= tail->getPriority()) {
    // If the new node has lower priority than the tail, insert at the end
    tail->setNext(newNode);
    tail = newNode;
  } else {
    // Insert the node in the middle (sorted insert)
    Node *current = head;
    while (current->getNext() != NULL &&
           current->getNext()->getPriority() >= priority) {
      current = current->getNext();
    }

    // Insert the new node after the current node
    newNode->setNext(current->getNext());
    current->setNext(newNode);
  }

  count += 1; // update count
}

string PQueue::dequeue() {
  if (isEmpty()) {
    // case 1 : empty queue
    return "Error: Attempt to dequeue from empty priority queue";
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
