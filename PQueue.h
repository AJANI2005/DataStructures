/* Author   :   Ajani Small
 * DATE     :   26 February, 2025
 *
 * Purpose:
 *
 * This class implements a priority queue structure.
 * In particular, it provides operations for enqueueing elements with
 * priority, dequeueing highest priority elements, and displaying all
 * elements in sorted priority order.
 *
 */

#ifndef PQUEUE_H
#define PQUEUE_H
#include "Node.h"
class PQueue {
private:
  Node *head;
  Node *tail;
  int count;

public:
  /**
   * @brief Constructs an empty priority queue
   * Initializes head and tail pointers to NULL and count to 0
   */
  PQueue();

  /**
   * @brief Adds a new node with given priority
   * @param node The node to be added
   * @param priority Priority value for ordering
   */
  void enqueue(Node node, int priority);

  /**
   * @brief Removes and returns highest priority node
   * @return String representation of removed node or error message if empty
   */
  string dequeue();

  /**
   * @brief Checks if priority queue is empty
   * @return true if queue is empty, false otherwise
   */
  bool isEmpty() { return count == 0; }

  /**
   * @brief Returns string representation of all nodes
   * @return String containing all nodes in priority order or "Empty Priority Queue" if empty
   */
  string displayAll();

  /**
   * @brief Returns current size of priority queue
   * @return Number of nodes in queue
   */
  int size() { return count; }

  /**
   * @brief Returns highest priority node without removing it
   * @return String representation of highest priority node or error message if empty
   */
  string front();

  /**
   * @brief Returns bottom node without removing it
   * @return String representation of bottom node or error message if empty
   */
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
  // Create and initialize new node
  Node *newNode = new Node(node);
  newNode->setPriority(priority);

  if (isEmpty()) {
    // First node - set both head and tail
    head = tail = newNode;
  } else if (priority > head->getPriority()) {
    // New highest priority - insert at front
    newNode->setNext(head);
    head = newNode;
  } else if (priority <= tail->getPriority()) {
    // New lowest priority - insert at end
    tail->setNext(newNode);
    tail = newNode;
  } else {
    // Insert in middle based on priority
    Node *current = head;
    while (current->getNext() != NULL &&
           current->getNext()->getPriority() >= priority) {
      current = current->getNext();
    }
    // Insert after current node
    newNode->setNext(current->getNext());
    current->setNext(newNode);
  }
  count += 1;
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
