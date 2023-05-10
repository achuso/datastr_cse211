#include "tree.h"
#include <iostream>
using namespace std;

int main(){

    Tree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(4);
    tree.insert(2);
    tree.insert(1); 
    tree.insert(7);
    tree.insert(6);
    tree.insert(8);
    tree.insert(9);
   
    tree.inOrder();
    cout << tree.count(3,7,3) <<endl ;
}