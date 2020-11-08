
#include <bits/stdc++.h>

using namespace std;

struct Node{
  int value;
  Node *next;
  Node *prev;
};

void insert(Node &head, int idx, int val){
  struct Node *iter = &head;
  
  if(idx == 0){
    
  }

  for(int i = 0; i < idx; i++){
    iter = iter -> next;
  }

  if(iter -> next == NULL){
    iter -> next = new Node;
    tail = *(tail.next);
  }
  else{
    struct Node *origin = iter -> next;
    iter -> next = new Node;
    iter = iter -> next;
    iter -> value = val;
    iter -> next = origin;
  }
}

void del(Node &head, int idx){
  struct Node *iter = &head;
  
  if(idx == 0){
    head = *(head.next);
    iter = iter -> next;
    iter -> next -> prev = NULL;
    delete iter;
  }


  for(int i = 0; i < (idx - 1); i++){
    iter = iter -> next;
  }

  if(iter -> next -> next == &head){
    delete iter -> next;
    iter -> next = &head;
  }
  else{
    delete iter -> next;
    iter -> next = iter -> next -> next;
  }
}

void print(Node &head){
  struct Node *iter = &head;
  while( iter -> next != NULL){
    cout << iter -> value << endl;
    iter = iter -> next;
  }
  cout << iter -> value << endl;
  cout << "End of linnked list!" << endl;
}

int main(){

  // Initialize doulby linked list
  struct Node head;
  struct Node node1;
  struct Node node2;
  struct Node node3;
  head.value = 1;
  head.next = &node1;
  node1.value = 3;
  node1.next = &node2;
  node2.value = 5;
  node2.next = &node3;
  node3.value = 7;
  node3.next = NULL;

  insert(head, tail, 3, 9);
  print(head);
  insert(head, tail, 1, 11);
  print(head);
  del(head, tail, 0);
  print(head);
  del(head, tail, 2);
  print(head);

}