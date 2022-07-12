#include <iostream>
#include "list.h"

int main (){
  list ns;
  ns.append (1);
  ns.insert (0, 0);
  ns.append (2);
  ns.append (4);
  ns.append (5);
  ns.insert (3, 3);

  ns.print();
  std::cout << "\n Complete list \n";

  ns.supr(0);
  ns.print();
  std::cout << "\n List after supr. \n";
}
