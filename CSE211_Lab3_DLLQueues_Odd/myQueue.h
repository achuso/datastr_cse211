#include "genDLList.h"


class MyQueue{

	public:
		MyQueue()
		{
			DoublyLinkedList<int> queue;
		}
		void enqueue(int data) // add to tail
		{
	        queue.addToDLLTail(data);
	        queueSize++;
		}
		
		int dequeue() //delete the element in the front
		{
		    if(queue.isEmpty())
				return -1;
				
	        int el = queue.firstEl();
	        queue.deleteFromDLLHead();
	        queueSize--;
	        return el;
		}
		
		int peek() //return the element in the front 
		{
			return queue.firstEl();
		}
		
		bool isEmpty()
		{
			return queue.isEmpty();
		}

		int getSize()
		{
			return queueSize;
		} 

	private:
		DoublyLinkedList<int> queue;
		int queueSize = 0;
};
