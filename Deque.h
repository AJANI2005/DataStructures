/* Author   :   Ajani Small
 * ID       :   400017967
 * DATE     :   26 February, 2025
 *
 * Purpose:
 *
 * This class implements a double-ended queue structure.
 * In particular, it provides operations for inserting and removing
 * elements from both ends, viewing front and back elements, and
 * displaying all elements in the deque.
 *
 */

#ifndef DEQUE_H
#define DEQUE_H
#include "Node.h"
class Deque {
private:
  // member variables
  Node *head;
  Node *tail;
  int count;

public:
  /**
   * @brief Constructs an empty deque
   * Initializes head and tail pointers to NULL and count to 0
   */
  Deque();

  /**
   * @brief Adds a new node to the back
   * @param node The node to be added
   */
  void insertLast(Node node);

  /**
   * @brief Adds a new node to the front
   * @param node The node to be added
   */
  void insertFirst(Node node);

  /**
   * @brief Removes and returns the back node
   * @return String representation of removed node or error message if empty
   */
  string removeLast();

  /**
   * @brief Removes and returns the front node
   * @return String representation of removed node or error message if empty
   */
  string removeFirst();

  /**
   * @brief Checks if deque is empty
   * @return true if deque is empty, false otherwise
   */
  bool isEmpty() { return count == 0; }

  /**
   * @brief Returns current size of deque
   * @return Number of nodes in deque
   */
  int size() { return count; }

  /**
   * @brief Returns string representation of all nodes
   * @return String containing all nodes or "Empty Deque" if empty
   */
  string displayAll();

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

// Deque Constructor - constructs an object of the Deque class
Deque::Deque() {
  head = tail = NULL;
  count = 0;
}

// This function returns the string representation of the node at the front of
// the deque If the deque is empty, it returns an error message
string Deque::front() {
  if (head != NULL) {
    return head->getRecord();
  } else {
    return "Deque is empty";
  }
};

// This function returns the string representation of the node at the back of
// the deque If the deque is empty, it returns an error message
string Deque::back() {
  if (tail != NULL) {
    return tail->getRecord();
  } else {
    return "Deque is empty";
  }
};

// This function inserts a new node at the front of the deque
void Deque::insertFirst(Node node) {
  // Create new node from input
  Node *newNode = new Node(node);

  if (isEmpty()) {
    // First node - set both head and tail
    head = tail = newNode;
  } else {
    // Add to front and update head
    newNode->setNext(head);
    head = newNode;
  }
  count += 1;
}

void Deque::insertLast(Node node) {
  Node *newNode = new Node(node);

  if (isEmpty()) {
    // set head and tail to the new node
    head = tail = newNode;
  } else {
    // insert node after tail and make it the new tail
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
    // clear head data
    delete head;
    head = tail = NULL;
    count -= 1; // update count
    return record;
  } else {
    string record = head->getRecord();
    Node *temp = head;
    // set new head
    head = head->getNext();
    // clear old head data
    delete temp;
    count -= 1; // update count
    return record;
  }
}

string Deque::removeLast() {
  if (isEmpty()) {
    // Handle empty deque case
    return "Error: Attempt to removeLast from empty deque";
  } else if (head == tail) {
    // Handle single node case
    string record = head->getRecord();
    delete head;
    head = tail = NULL;
    count -= 1;
    return record;
  } else {
    // Handle multiple nodes case
    string record = tail->getRecord();
    Node *temp = tail;

    // Find node before tail
    Node *curr = head;
    while (curr && curr->getNext() != tail) {
      curr = curr->getNext();
    }
    // Update tail and clean up
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
