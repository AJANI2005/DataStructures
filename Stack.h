/* Author   :   Ajani Small
 * ID       :   400017967
 * DATE     :   26 February, 2025
 *
 * Purpose:
 *
 * This class implements a LIFO (Last-In-First-Out) stack structure.
 * In particular, it provides operations for pushing and popping
 * elements, viewing top and bottom elements, and displaying all elements
 * in the stack.
 *
 */

#ifndef STACK_H
#define STACK_H
#include "Node.h"
class Stack {
private:
  Node *head;
  Node *tail;
  int count;

public:
  /**
   * @brief Constructs an empty stack
   * Initializes head and tail pointers to NULL and count to 0
   */
  Stack();

  /**
   * @brief Pushes a new node onto top of stack
   * @param node The node to be added
   */
  void push(Node node);

  /**
   * @brief Removes and returns the top node
   * @return String representation of removed node or error message if empty
   */
  string pop();

  /**
   * @brief Checks if stack is empty
   * @return true if stack is empty, false otherwise
   */
  bool isEmpty() { return count == 0; }

  /**
   * @brief Returns string representation of all nodes
   * @return String containing all nodes or "Empty Stack" if empty
   */
  string displayAll();

  /**
   * @brief Returns current size of stack
   * @return Number of nodes in stack
   */
  int size() { return count; }

  /**
   * @brief Returns top node without removing it
   * @return String representation of top node or error message if empty
   */
  string front();

  /**
   * @brief Returns bottom node without removing it
   * @return String representation of bottom node or error message if empty
   */
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
  count += 1; // Increment size
}

string Stack::pop() {
  if (isEmpty()) {
    // Handle empty stack case
    return "Error: Attempt to pop from empty stack";
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
