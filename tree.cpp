#include <bits/stdc++.h>

using namespace std;

struct Node{
  int data;
  Node *parent;
  vector<Node*> children;
};

bool isRoot(Node *p){
  if(p -> parent == NULL)
    return true;
  else
    return false;
}

bool isLeaf(Node *p){
  if(p -> children.size() == 0)
    return true;
  else
    return false;
}

int depth(Node *p){
  if(isRoot(p) == true)
    return 0;
  else{
    int counter = 0;
    while(p -> parent != NULL){
      p = p -> parent;
      counter++;
    }
    return counter;
  }
}

int height(Node *p){

  int h = 0;
  for(int i = 0; i < p -> children.size(); i++){
    struct Node* child = p -> children[i];
    // since it has for loop size, minimum height becomes at least 1 now
    h = 1 + height(child);
  }

  return h;
}

int getElement(Node *p){
  return p -> data;
}

vector<Node*> children(Node *p){
  if(isLeaf(p) == true){
    cout << "given node is the leaf node!" << endl;
  }

  return p -> children;
}

Node* parent(Node *p){
  if(isRoot(p) == true){
    cout << "given node is the root node!" << endl;
    return p;
  }

  return p -> parent;
}

int main(){

  struct Node* root;
  root = new Node;
  root -> parent = NULL;
  root -> data = 0;
  
  struct Node* node1;
  node1 = new Node;
  node1 -> parent = root;
  node1 -> data = 1;

  struct Node* node2;
  node2 = new Node;
  node2 -> parent = root;
  node2 -> data = 2;

  struct Node* node3;
  node3 = new Node;
  node3 -> parent = node2;
  node3 -> data = 3;

  root -> children.push_back(node1);
  root -> children.push_back(node2);
  node2 -> children.push_back(node3);

  cout << height(root) << endl;
  cout << depth(node3) << endl;

  cout << getElement(node3) << endl;

  vector<Node*> my_children = children(root);
  for(int i = 0; i < my_children.size(); i++){
    cout << my_children[i] -> data << " ";
  }
  cout << endl;

  cout << parent(node3) -> data << endl;
}