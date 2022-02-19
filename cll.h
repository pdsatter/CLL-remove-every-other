#include <iostream>

struct Node{
  int data;
  Node* prev = nullptr;
  Node* next = nullptr;
  Node() = delete;
  Node(int d, Node*p, Node*n):data(d),prev(p), next(n){};
  Node(int d):data(d),prev(nullptr), next(nullptr){};
};

class CLL{
  private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int length = 0;

  public:
    Node* gethead(){return head;};
    Node* gettail(){return tail;};
    
    void addFront(int d);
    void addBack(int d);

    void deleteFront();
    void deleteBack();
    void deleteAt(int i);
    int deleteEveryOther(int cycles=0);

    void print();
    void printLength();
};