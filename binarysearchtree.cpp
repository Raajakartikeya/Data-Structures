#include <iostream>
using namespace std;
struct node {
  int key;
  node *left, *right;
};
node *newNode(int item) {
  node* temp = new node;
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}


void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    cout << root->key << " -> ";
    inorder(root->right);
  }
}
node *insert(node *node, int key) {
  if (node == NULL) 
  return newNode(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

node *minValueNode(node *nod) {
  node *current=nod;
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

node *deleteNode(node *root, int key) {

  if (root == NULL) 
  return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      node *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == NULL) {
      node *temp = root->left;
      delete root;
      return temp;
    }
    node *temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

int main() {
  int ch,x;
  struct node *root = NULL;
  cout<<"\nMain Menu\n1.Insert\n2.Display\n3.Delete\n4.Exit";
  while(1)
  {
      cout<<"\nEnter  u r choice:";
      cin>>ch;
      switch(ch)
      {
          case 1:
          cout<<"Enter the value:";
          cin>>x;
          root = insert(root, x);
          break;
          case 2:
          cout << "Inorder traversal: ";
          inorder(root);
          break;
          case 3:
          cout<<"Enter the value to be deleted";
          cin>>x;
          root = deleteNode(root, x);
          break;
          case 4:
          exit(0);
          default:
          cout<<"Wrong Choice";
      }
  }
 
  
}