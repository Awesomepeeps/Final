//bst.h
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

struct node
{
    int data;   //some questions use char * data;
    node * left;
    node * right;
};

class bst
{
    public:
    	//These functions are supplied already
    	bst();			//supplied
        void build(); 		//supplied
        void display(); 	//supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
  void preroot(node* root, node* current);
  void smallesttwo(node* root, node* current);
  void deleteall(node* root, node* current, node* previous);
  
  node* getroot();
  
 	private:
 		node * root;
		void display_tree(node*, int);
};
  

