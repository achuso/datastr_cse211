#include <iostream>
template <class T>
class Tree;

template <class T>
class TreeNode {
private:
	TreeNode<T> * left;
	TreeNode<T> * right;
	T data;

public:
	TreeNode(const T & el) {
		data = el;
		left = NULL;
		right = NULL;
	}

	friend class Tree<T>;
};


template<class T>
class Tree {
private:
	TreeNode<T> * root;

public:
	Tree() {
		root = NULL;
	}

	void insert(const T & el) {
		TreeNode<T> * newnode = new TreeNode<T>(el);

		if (!root) {
			root = newnode;
		}
		else {
			TreeNode<T> * current = root;
			while (true) {
				if (el < current->data) {
					if (current->left) {
						current = current->left;
					}
					else {
						current->left = newnode;
						break;
					}
				}
				else {
					if (current->right) {
						current = current->right;
					}
					else {
						current->right = newnode;
						break;
					}
				}
			}
		}
	}
	void inOrder(){
		inOrder(root);
		std::cout<<std::endl;
	}
	void inOrder(TreeNode<T>* treeNode){
		 if (!treeNode)
                return;
        inOrder(treeNode->left);
        std::cout << treeNode->data << " " ;
        inOrder(treeNode->right);
	}
	int count(const T & small, const T & big, int level);

};

#include "tree_count.h"