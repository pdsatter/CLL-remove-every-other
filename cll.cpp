#include "cll.h"

// ADD FUNCTIONS
void CLL::addFront(int d){
 Node* newNode = new Node(d,tail, head);
 if (head == nullptr)
 {
   head=newNode;
   tail=newNode;
   newNode->next = head;
   newNode->prev = tail;
 }
 else
 {
   head->prev = newNode;
   head = newNode;
   tail->next = head;
 }
 length++;
};

void CLL::addBack(int d){
  Node* newNode = new Node(d,tail,head);
  if (head == nullptr)
  {
    head=newNode;
    tail=newNode;
    newNode->prev = tail;
    newNode->next = head;
  }
  else
  {
    tail->next = newNode;
    tail = newNode;
    head->prev = tail;
  }
  length++;
};

// DELETE FUNCTIONS
void CLL::deleteFront(){
  if (head==nullptr) return;
  if (length == 1){ // only 1 item
    delete head;
    head=nullptr;
    tail=nullptr;
    length = 0;
    return;
  }

  Node* tmpptr = head->next;
  delete head;
  head = tmpptr;
  head->prev = tail;
  tail->next = head;
  length--;
};

void CLL::deleteBack(){
  if (head==nullptr)return;
  if (length == 1){ // only 1 item
    delete head;
    head = nullptr;
    tail = nullptr;
    length = 0;
    return;
  }

  Node* tmpptr = tail->prev;
  delete tail;
  tail = tmpptr;
  tail->next = head;
  head->prev = tail;
  length--;
};

// FOR SINGLY LINKED LIST NOT DOUBLY
int CLL::deleteEveryOther(int cycles){
  if (head == nullptr) return cycles;
  std::cout << "Start of cycle " << cycles << '\n';
  if (head->next == head || head->next == nullptr){
    std::cout << "Deleting: " << head->data << '\n';
    delete head;
    head = nullptr;
    tail = nullptr;
    std::cout << "End of cycle " << cycles << '\n' << '\n';
    return cycles+1;
  }
  Node* prev = head;
  Node* curr = head->next;
  Node* after = curr->next;

  int count = 0;
  while (curr!= head){

    if (count%2 == 0){
      std::cout << "Deleting: " << curr->data << '\n';
      delete curr;
      prev->next = after;
    } 
    else prev = curr;
    curr = after;
    after = after->next;
    count ++;
  }
  std::cout << "End of cycle " << cycles << '\n' << '\n';
  return deleteEveryOther(cycles+1);
}



void CLL::deleteAt(int i){
  if (head == nullptr) return;
  if (i >= length) return;
  if (i == 0) return deleteFront(); 
  if (i == length-1) return deleteBack();
  
  Node* curr = head;
  for (int j=0; j<i; j++){
    curr = curr->next;
  }

  Node* tmpprev = curr->prev;
  Node* tmpnext = curr->next;

  delete curr;
  tmpprev->next = tmpnext;
  tmpnext->prev = tmpprev;

  length --;
};

// PRINT FUNCTIONS
void CLL::print(){
  if (head == nullptr) return;
  
  std::cout <<'\n';
  std::cout << "Print from head: " << '\n';
  
  Node*curr = head;
  int count = 0;
  while (count < length){
    
    std::cout << curr->data << '\n';
    curr=curr->next;
    count++;
  }
  
  std::cout <<'\n';
  std::cout << "Print from tail: " << '\n';

  curr=tail;
  count = 0;
  while (count<length){
    std::cout << curr->data << '\n';
    curr=curr->prev;
    count++;
  }
  std::cout <<'\n';
};
