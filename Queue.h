/* Author   :   Ajani Small
 * ID       :   400017967
 * DATE     :   26 February, 2025
 *
 * Purpose:
 *
 * This class implements a FIFO (First-In-First-Out) queue structure.
 * In particular, it provides operations for enqueueing and dequeueing
 * elements, viewing front and back elements, and displaying all elements
 * in the queue.
 *
 */

#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
class Queue {
private:
  // member variables
  Node *head;
  Node *tail;
  int count;

public:
  /**
   * @brief Constructs an empty queue
   * Initializes head and tail pointers to NULL and count to 0
   */
  Queue();

  /**
   * @brief Adds a new node to the end of the queue
   * @param node The node to be added
   */
  void enqueue(Node node);

  /**
   * @brief Removes and returns the front node
   * @return String representation of removed node or error message if empty
   */
  string dequeue();

  /**
   * @brief Checks if queue is empty
   * @return true if queue is empty, false otherwise
   */
  bool isEmpty() { return count == 0; }

  /**
   * @brief Returns string representation of all nodes
   * @return String containing all nodes or "Empty Queue" if empty
   */
  string displayAll();

  /**
   * @brief Returns current size of queue
   * @return Number of nodes in queue
   */
  int size() { return count; }

  /**
   * @brief Returns front node without removing it
   * @return String representation of front node or error message if empty
   */
  string front();

  /**
   * @brief Returns back node without removing it
   * @return String representation of back node or error message if empty
   */
  string back();
};

// Constructor initializes the queue to be empty
Queue::Queue() {
  // initialize member variables
  head = tail = NULL;
  count = 0;
}

// This function returns the string representation of the Node at the front of
// the queue If the queue is empty it returns an error message
string Queue::front() {
  if (head != NULL) {
    return head->getRecord();
  } else {
    return "Queue is empty";
  }
};

// This function returns the string representation of the Node at the back of
// the queue If the queue is empty it returns an error message
string Queue::back() {
  if (tail != NULL) {
    return tail->getRecord();
  } else {
    return "Queue is empty";
  }
};

// This function adds a new node to the end of the queue
void Queue::enqueue(Node node) {
  // Create new node from input
  Node *newNode = new Node(node);
  if (isEmpty()) {
    // First node - set both head and tail
    head = tail = newNode;
  } else {
    // Add to end and update tail
    tail->setNext(newNode);
    tail = newNode;
  }
  count += 1; // Increment size
}

// This function removes and returns the string representation of the Node at
// the front of the queue
string Queue::dequeue() {
  if (isEmpty()) {
    // Handle empty queue case
    return "Error: Attempt to dequeue from empty queue";
  } else if (head == tail) {
    // Handle single node case
    string record = head->getRecord();
    delete head;
    head = tail = NULL;
    count -= 1;
    return record;
  } else {
    // Handle multiple nodes case
    string record = head->getRecord();
    Node *temp = head;
    head = head->getNext(); // Move head to next node
    delete temp;           // Free old head
    count -= 1;
    return record;
  }
}

// This function returns a string representation of all the nodes in the queue
string Queue::displayAll() {
  if (isEmpty()) {
    return "Empty Queue";
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
#endif // !QUEUE_H
