#include "doubly_list.cpp"
#include <iostream>
using namespace std;

int main() {
  linkedList *list = new linkedList;
list->insertLast(1);
list->insertLast(2);
list->insertLast(3);

list->printList();
}
