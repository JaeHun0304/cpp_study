
#include <bits/stdc++.h>

using namespace std;

struct Node{
  int value;
  Node *next;
};


// Watch out! we have to pass reference to pointer (Node *&head) to the function!
void insert(Node *&head, int idx, int val){
  struct Node *iter = head;
  if(idx == 0){
    while(iter -> next != head){
      iter = iter -> next;
    }
    struct Node *new_node = new Node;
    new_node -> value = val;
    new_node -> next = head;
    head = new_node;
    iter -> next = new_node;
    return;
  }

  for(int i = 0; i < idx; i++){
    iter = iter -> next;
    if(iter == head){
      cout << "index out of range!" << endl;
      return;
    }
  }

  if(iter -> next == head){
    iter -> next = new Node;
    iter = iter -> next;
    iter -> value = val;
    iter -> next = head;
  }
  else{
    struct Node *origin = iter -> next;
    iter -> next = new Node;
    iter = iter -> next;
    iter -> value = val;
    iter -> next = origin;
  }
}

void del(Node *&head, int idx){
  struct Node *iter = head;
  if(idx == 0){
    while(iter -> next != head){
      iter = iter -> next;
    }
    head = head -> next;
    delete iter -> next;
    iter -> next = head;
    return;
  }

  for(int i = 0; i < (idx - 1); i++){
    iter = iter -> next;
    if(iter == head){
      cout << "index out of range!" << endl;
      return;
    }
  }

  struct Node *deleteNode = iter -> next;
  if(iter -> next -> next == head){
    iter -> next = head;
    delete deleteNode;
  }
  else{
    iter -> next = iter -> next -> next;
    delete deleteNode;
  }
}

void print(Node *&head){
  struct Node *iter = head;
  while( iter -> next != head){
    cout << iter -> value << endl;
    iter = iter -> next;
  }
  cout << iter -> value << endl;
  cout << "End of linnked list!" << endl;
}

int main(){

  struct Node *head = new Node;
  struct Node *node1 = new Node;
  struct Node *node2 = new Node;
  struct Node *node3 = new Node;
  head -> value = 1;
  head -> next = node1;
  node1 -> value = 3;
  node1 -> next = node2;
  node2 -> value = 5;
  node2 -> next = node3;
  node3 -> value = 7;
  node3 -> next = head;

  insert(head, 3, 9);
  print(head);
  insert(head, 0, 11);
  print(head);
  del(head, 0);
  print(head);
  del(head, 2);
  print(head);

}