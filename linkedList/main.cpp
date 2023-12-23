#include "doubly_list.cpp"
#include <iostream>
using namespace std;

int main() {

//   linkedListNode *first, *second, *third;

//   first = new linkedListNode(1);
//   second = new linkedListNode(2);
//   third = new linkedListNode(3);

//   third->data = 3;
//   third->next = NULL;

//   second->data = 5;
//   second->next = third;

//   first->data = 1;
//   first->next = second;

  // cout << first->data << second->data << third->data << "\n";

//   list->addHead(first);
//   // list->getLength();
//   // cout << "list length: " << list->getLength() << "\n";
//   cout << "list length: " << list->getLengthItr() << "\n";
//   list->printList();
//   cout << "list sum: " << list->sum() << "\n";

//   linkedListNode *result = list->find(87);
//   result->data = 99;
//   list->printList();
//   list->insertBefore(first, 66);
//   list->printList();
//   list->insertBefore(result, 44);
//   list->printList();

//   list->deleteNode(result);
//   list->printList();
//   list->deleteNode(66);
  linkedList<string> *list = new linkedList<string>;
  linkedList<string> *new_list = new linkedList<string>;

list->insertLast("hi");
list->insertLast(" my name is");
list->insertLast("islam");

// list->printList();

  list->insertAfter( list->find("islam"), "Ahmed");
  // list->printList();
    list->insertBefore( list->find("hi"), "hello");
  list->copy_linked_list(new_list);
  new_list->deleteNode(new_list->find("hello"));
  new_list->printList();
  new_list->getLength();

}