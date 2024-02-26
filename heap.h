#pragma once
#include <vector>
#include <iostream>

template <class T>
class Heap {

private:
  int size;  // size of heap
  std::vector<T> items;  // underlying array

  // accessor helpers
  int parentIndex(int i) {return ((i-1)/2);}
  int leftChildIndex(int i) {return (2*i+1);}
  int rightChildIndex(int i) {return (2*i+2);}
  int lastIndex() {return (size-1);}

public:
  // Heap mutators
  Heap() : size(0), items(std::vector<T>()) {}

  Heap(std::vector<T> items) : size(items.size()), items(items) {
    Heapify();
  }

  ~Heap() {
    size = 0;
  }

  // Getters
  int getSize() { return size; }
  int getMax() { return items.front(); }

  void add(T item) {
    items.push_back(item);
    size += 1;
    fixUp(size - 1);
  }

  void fixUp(int j) {
    while (j != 0) {
      int pi = parentIndex(j);
      if (items[pi] >= items[j]) {
        break;
      }
      std::swap(items[pi], items[j]);
      j = pi;
    }
  }

  void fixDown(int j) {
    int maxIndex = j;
    while (1) {
      int lc = leftChildIndex(j);
      if (lc < size && items[lc] > items[j]) {
        maxIndex = lc;
      }
      int rc = rightChildIndex(j);
      if (rc < size && items[rc] > items[maxIndex]) {
        maxIndex = rc;
      }
      if (maxIndex == j) {
        break;
      }
      std::swap(items[j], items[maxIndex]);
      j = maxIndex;
    }
  }

  void Heapify() {
    for (int i = parentIndex(lastIndex()); i >= 0; i--) {
      fixDown(i);
    }
  }

  void deleteMax() {
    if (size == 0) return;
    items[0] = items[lastIndex()];
    items.pop_back();
    size--;
    fixDown(0);
  }

  void print() {
    for (int i = 0; i < size; i++) {
      std::cout << items[i];
    };
    std::cout << std::endl;
  }
};
