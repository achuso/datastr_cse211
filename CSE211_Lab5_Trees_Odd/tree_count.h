// CSE211.1 Lab 5 - Trees
// Name: Onat Ribar
// Student nr: 20210702099

#include <queue>

using std::queue;

template<class T>
int Tree<T>::count(const T & small, const T & big, int level) {

    // Queue to store the addresses of the nodes
	queue<TreeNode<T>*> breadthNodes;

	int itemsInLevel = 0; // Return value

	TreeNode<T>* temp = root;

	breadthNodes.push(temp);

    // Iteratively traverse (BFS) through each node between levels 0 and parameter level via TreeNode<T>* temp initialized to root
	for(int curLevel = 0, curSize = 0; curLevel <= level; curLevel++) {

		curSize = breadthNodes.size();
        // For N curSize there are N parent nodes in level curLevel
        // (starting from curLevel = 0, since only root node exists, curSize will become 1)

        // Iteration through each node in curLevel
		for(int i = 0; i < curSize; i++) {
			temp = breadthNodes.front();
			if(curLevel == level && (small>= temp->data <= big))
                // Every time a data is found with given criteria, increment itemsInLevel and return it at the end
				itemsInLevel++;

            // Add right and left children of the parent node(s) to the queue
            // (If any child is null, just don't push that child)
			if((temp->left != NULL))
				breadthNodes.push(temp->left);
            if((temp->right != NULL))
                breadthNodes.push(temp->right);

            // Pop the parent nodes (first curSize elements from the queue's front) so that only child nodes remain to become parent nodes for the next iteration.
			if(!breadthNodes.empty())
				breadthNodes.pop();
            // If no child nodes were pushed (all children of the parents are NULL), all leaves were visited. Break.
			else
                break;
		}
	}

	return itemsInLevel;
}
