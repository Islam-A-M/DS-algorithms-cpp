#include <iostream>
using namespace std;
template<class T>
class linkedListNode {
public:
  T data;
  linkedListNode<T> *next;
  linkedListNode<T> *back;
  linkedListNode(T _data) {
    this->data = _data;
    this->next = nullptr;
    this->back = nullptr;
  }
};

template<class T>
class linkedListIterator {
private:
  linkedListNode<T> *currentNode;


public:
  linkedListIterator() 
  {
  currentNode = nullptr;
   }
  linkedListIterator(linkedListNode <T> *node) { 
    currentNode = node;
   }
  T data() { return this->currentNode->data; }
  linkedListIterator<T> next() {
    this->currentNode = this->currentNode->next;
    return *this;
  }
  linkedListNode <T> *current() { return this->currentNode; }
};

template<class T>
class linkedList {
public:
  linkedListNode<T> *head = nullptr;
  linkedListNode<T> *tail = nullptr;
  int llength=0;

  linkedListIterator<T> begin() {
    linkedListIterator<T> itr(this->head);
    return itr;
  }
  void printList() {
    for (linkedListIterator<T> itr = this->begin(); itr.current() != NULL;
         itr.next()) {
          
          cout << itr.data();

          if ( itr.current()->next!=nullptr)
          {
            cout << " -> ";
          }
          
          
    }
    cout << "\n";
  }
  linkedListNode<T>* find(T _data) {
    for (linkedListIterator<T> itr = this->begin(); itr.current() != NULL;
         itr.next()) {
      if (_data == itr.data()) {
        return itr.current();
      }
    }
    return nullptr;
  }

  void insertAfter(linkedListNode<T>* node, T _data) {
    linkedListNode<T> *newNode = new linkedListNode<T>(_data);
    newNode->next = node->next;
    newNode->back = node;
    node->next = newNode;
    if (newNode->next == nullptr) {
      this->tail = newNode;
    } else {
      newNode->next->back = newNode;
    }
    this->llength=this->llength+1;
  }

  void insertLast(T _data) {
    linkedListNode<T>* newNode = new linkedListNode<T>(_data);
    if (this->tail == NULL) {
      this->head = newNode;
      this->tail = newNode;
    } else {
      newNode->back = this->tail;
      this->tail->next = newNode;
      this->tail = newNode;
    }
    this->llength=this->llength+1;
    

  }

  void insertBefore(linkedListNode <T> *node, T _data) {
    if (node==nullptr)
    {
      return;
    }
    
    linkedListNode<T> *newNode = new linkedListNode<T>(_data);
    newNode->next = node;

    if (node == this->head) {
      this->head = newNode;
    } else {
      node->back->next = newNode;
    }
    node->back = newNode;
    this->llength=this->llength+1;

  }

  void deleteNode(linkedListNode <T> *node) {
    if (this->head == this->tail) {
      this->head = NULL;
      this->tail = NULL;
    } else if (node->back == NULL) {
      this->head = node->next;
      node->next->back = NULL;
    } else if (node->next == NULL) {
      this->tail = node->back;
      node->back->next = NULL;
    } else {
      node->back->next = node->next;
      node->next->back = node->back;
    }
    delete node;
    this->llength=this->llength-1;

  }
  void getLength(){
        cout << "\n";
        cout << this->llength;
        cout << "\n";


  }
  void copy_linked_list(linkedList <T> *target){

      for (linkedListIterator<T> itr = this->begin(); itr.current() != NULL;
         itr.next()) {
          target->insertLast(itr.current()->data);

    }
  }
};