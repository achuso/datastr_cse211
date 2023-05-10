#include <iostream>
using namespace std;

#include "intSLList.h"

int delete_min(IntSLList & list);


int main() {

	IntSLList list;

	for (int i = 1; i < 6; i++) {
		list.addToTail(i);
	}
	list.addToTail(3);
    list.printAll();

    int minimum = delete_min(list);
	list.printAll();
	list.add_duplicate(3);
	list.printAll();

	cout << "min is: " << minimum << endl;

}
