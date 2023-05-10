#include <iostream>
#include "DLLStack.h"

using namespace std;

int main() {
	
	string str = "golden";

	string str2 = "{[]]]}}}}";

	if (goldenString(str))
	    cout << "golden string"<<endl;
	else 
	    cout << "not a golden string"<<endl;

	if(checkParentheses(str2))
		cout << "true" << endl; 
	else
		cout << "false" << endl; 

}