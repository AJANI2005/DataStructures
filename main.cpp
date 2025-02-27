#include "Node.h"
#include "PQueue.h"
int main() {
  Node n1 = Node("Jan", 2005, "Jon Bellion", "All time low", "UMG", 5);
  Node n2 = Node("Jan", 2005, "Jon Bellion", "Woke the F up", "UMG", 5);
  Node n3 = Node("Jan", 2005, "Jon Bellion", "Jungle", "UMG", 5);

  PQueue pq;
  pq.enqueue(n1, 5);
  pq.enqueue(n2, 4);
  pq.enqueue(n3, 5);
  cout << pq.toString() << endl;
  return 0;
}
