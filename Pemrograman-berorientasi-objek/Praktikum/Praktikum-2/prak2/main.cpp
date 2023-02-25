// main.cpp
#include "A.hpp"
#include "B.hpp"

int main() {
  B b; /** ANDA HARUS MENGGUNAKAN DEFAULT CONSTRUCTOR */
  
  A& a = b;
  a.setValue(888);
  b.setValue(10888);
  
  b.print(); // OUTPUT: (888, 10888)
  return 0;
}