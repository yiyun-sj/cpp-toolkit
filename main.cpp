#include <iostream>
#include <sstream>
#include "heap.h"
using namespace std;

int main() {
  Heap<int> heap = Heap<int>();

  int n, x;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x;
    heap.add(x);
  }

  heap.print();

  for (int i = 0; i < n; i++) {
    cout << heap.getMax();
    heap.deleteMax();
  }
  cout << endl;

  return 0;
}