#include "bst.h"

int main()
{
    bst object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */
    //object.smallesttwo(object.getroot(), object.getroot());
    object.deleteall(object.getroot(), object.getroot(), object.getroot());

    object.display();	//displays again after!
   
    return 0;
}
