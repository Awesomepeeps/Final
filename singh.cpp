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

int bst::countleaf(node* current) {
  if (current == NULL) {
    return 0;
  }

  if (current->left == NULL && current->right == NULL) {
    return 1;
  }

  return countleaf(current->right) + countleaf(current->left);
}

void bst::removeleaf(node* current, node* previous) {
  if (current == NULL) {
    return;
  }

  if (current->left == NULL && current->left == NULL) {
    if (previous->left == current) {
      previous->left = NULL;
      delete current;
    }
    else if (previous->right == current) {
      previous->right = NULL;
      delete current;
    }
    return;
  }

  removeleaf(current->left);
  removeleaf(current->right);
}

int bst::height(node* current) {
    if (current == NULL) {
      return -1;
    }
    int left_height = bst::height(current->left);
    int right_height = bst::height(current->right);
    return 1 + max(left_height, right_height);
}

void bst::mirror(node* current) {
    if (current == NULL) {
      return;
    }
    bst::mirror(current->left);
    bst::mirror(current->right);
    swap(current->left, current->right);
}

int bst::sum(node* current) {
    if (current == NULL) {
      return 0;
    }
    return current->data + sum(current->left) + sum(current->right);
}

int countNodes(node* current) {
    if (current == NULL) {
      return 0;
    }
    return 1 + countNodes(current->left) + countNodes(current->right);
}



/*


bool isBalanced(TreeNode* root) {
    if (!root) {
        // If the root is null, it's considered balanced
        return true;
    }
    
    // Calculate the height of the left and right subtrees
    int left_height = height(root->left);
    int right_height = height(root->right);
    
    // Calculate the height difference between the left and right subtrees
    int height_diff = left_height - right_height;
    
    // If the height difference is greater than 1 or less than -1,
    // the tree is unbalanced
    if (height_diff < -1 || height_diff > 1) {
        return false;
    }
    
    // Recursively check if both the left and right subtrees are balanced
    return isBalanced(root->left) && isBalanced(root->right);
}



void removeSmallestTwo(TreeNode*& root) {
    if (!root) return;

    TreeNode* smallest = root;
    while (smallest->left) {
        smallest = smallest->left;
    }

    // Remove smallest node
    if (smallest->right) {
        smallest = smallest->right;
    } else {
        delete smallest;
        root = nullptr;
        return;
    }

    TreeNode* second_smallest = smallest;
    while (second_smallest->left) {
        second_smallest = second_smallest->left;
    }

    // Remove second smallest node
    if (second_smallest->right) {
        second_smallest = second_smallest->right;
    } else {
        delete second_smallest;
        root = nullptr;
        return;
    }
}


*/
