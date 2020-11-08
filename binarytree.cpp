#include <bits/stdc++.h>

using namespace std;

struct Node{
  char element;
  Node* leftchild;
  Node* rightchild;
  Node* parent;
};

bool isRoot(Node *p){
  if(p -> parent == NULL)
    return true;
  else
    return false;
}

bool isLeaf(Node *p){
  if(p -> leftchild == NULL && p -> rightchild == NULL)
    return true;
  else
    return false;
}

bool isEmpty(Node* p){
  if(p -> leftchild == NULL && p -> rightchild == NULL)
    return true;
  else
    return false;
}

Node* parent(Node* p){
  if(isRoot(p) == true){
    cout << "You are passing parent to the parent() function!" << endl;
  }
  return p -> parent;
}

Node* root(Node* p){
  if(isRoot(p) == true){
    cout << "You just passed root to the root() function! passing parameter will be returned back!" << endl;
    return p;
  }
  else{
    Node* iter = p;
    while(iter -> parent != NULL){
      iter = p -> parent;
    }
    return iter;
  }
}

vector<Node*> children(Node* p){
  if(isLeaf(p) == true){
    cout << "you passed leaf node to find children of it!" << endl;
  }

  vector<Node*> children;
  children.push_back(p -> leftchild);
  children.push_back(p -> rightchild);
  return children;
}

int depth(Node* p){
  if(isRoot(p) == true)
    return 0;

  Node* iter = p;
  int counter = 0;
  while(iter -> parent != NULL){
    iter = p -> parent;
    counter++;
  }
  return counter;
}

int height(Node* p){
  int h = 0;
  Node* iter = p;
  
  if(p -> leftchild != NULL){
    iter = p -> leftchild;
    h = 1 + height(iter);
  }
  if(p -> rightchild != NULL){
    iter = p -> rightchild;
    h = 1 + height(iter);
  }

  return h;
}

void postOrder(Node* p){
  if(p -> leftchild != NULL)
    postOrder(p -> leftchild);
  if(p -> rightchild != NULL)
    postOrder(p -> rightchild);

  cout << p -> element << endl;
}

void inOrder(Node* p){
  if(p -> leftchild != NULL)
    inOrder(p -> leftchild);
  cout << p -> element << endl;
  if(p -> rightchild != NULL)
    inOrder(p -> rightchild);
}

void preOrder(Node* p){
  cout << p -> element << endl;

  if(p -> leftchild != NULL)
    preOrder(p -> leftchild);
  if(p -> rightchild != NULL)
    preOrder(p -> rightchild);
}

void dfs(Node* p){

}

void bfs(Node* p){
  
}

int main(){

  Node* root = new Node;
  Node* node1 = new Node;
  Node* node2 = new Node;
  Node* node3 = new Node;
  Node* node4 = new Node;
  Node* node5 = new Node;
  Node* node6 = new Node;
  Node* node7 = new Node;
  Node* node8 = new Node;


  
  root -> element = 'F';
  root -> leftchild = node1;
  root -> rightchild = node6;
  root -> parent = NULL;

  node1 -> element = 'B';
  node1 -> leftchild = node2;
  node1 -> rightchild = node3;
  node1 -> parent = root;

  node2 -> element = 'A';
  node2 -> leftchild = NULL;
  node2 -> rightchild = NULL;
  node2 -> parent = node1;

  node3 -> element = 'D';
  node3 -> leftchild = node4;
  node3 -> rightchild = node5;
  node3 -> parent = node1;

  node4 -> element = 'C';
  node4 -> leftchild = NULL;
  node4 -> rightchild = NULL;
  node4 -> parent = node3;

  node5 -> element = 'E';
  node5 -> leftchild = NULL;
  node5 -> rightchild = NULL;
  node5 -> parent = node3;

  node6 -> element = 'G';
  node6 -> leftchild = NULL;
  node6 -> rightchild = node7;
  node6 -> parent = node1;

  node7 -> element = 'I';
  node7 -> leftchild = node8;
  node7 -> rightchild = NULL;
  node7 -> parent = node6;

  node8 -> element = 'H';
  node8 -> leftchild = NULL;
  node8 -> rightchild = NULL;
  node8 -> parent = node7;

  cout << height(root) << endl;
  //postOrder(root);
  //inOrder(root);
  preOrder(root);
}