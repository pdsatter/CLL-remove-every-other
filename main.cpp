#include <iostream>
#include "cll.h"

int main() {
  CLL list;
  list.addFront(4);
  list.addFront(3);
  list.addFront(2);
  list.addFront(1);
  list.addBack(5);
  list.addBack(6);
  list.addBack(7);
  list.addBack(8);
  list.addBack(9);

  int cycles = 0;
  cycles = list.deleteEveryOther(cycles);

  std::cout << '\n' << "Cycles: " << cycles << '\n';

  return 0;
  
}
// 2 4 6 8 . 3 7 . 5 . 1           (1-8) 4 cycles
// 2 4 6 8 . 3 7 . 5 . 9 . 1       (1-9) 5 cycles