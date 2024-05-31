#include "bst.h"

using namespace std;

void bst::preroot(node* root, node* current) {
  if (root->left == NULL) {
    cout << "N/A" << endl;
  }
  else if (current->right == NULL && current != root) {
    //cout << "End condition is met: " << current->data << endl;
    cout << current->data << endl;
  }
  else if (current == root) {
    //cout << "current == root: " << current->data << endl;
    bst::preroot(root, current->left);
  }
  else if (current == root->left) {
    //cout << "current == root->left: " << current->data << endl;
    bst::preroot(root, current->right);
  }
  else {
    //cout << "normal case: " << current->data << endl;
    bst::preroot(root, current->right);
  }
}

node* bst::getroot() {
  return root;
}

void bst::deleteall(node* root, node* current, node* previous) {
  if (root->right == NULL) {
    return;
  }  
  if (current->right != NULL) {
    bst::deleteall(root, current->right, current);
  }
  if (current->left != NULL) {
    bst::deleteall(root, current->left, current);
  }
  if (previous->left == current) {
    previous->left = NULL;
    delete current;
  }
  else if (previous->right == current) {
    previous->right = NULL;
    delete current;
  }
}
