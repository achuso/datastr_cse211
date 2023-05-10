// Name-Surname: Onat Ribar
// Student ID: 20210702099
// CSE211 Section: 1

#include "genDLList.h"
#include <string>

using namespace std;

/*
I am assuming the head as the top, and tail as the bottom of the stack,
and all operations are done accordingly.

To make it work the other way around:

 1) Replace all "addToDLLHead()" and "deleteFromDLLHead()" with
                "addToDLLTail()" and "deleteFromDLLTail()" respectively
 2) Adjust T& DLStack<T>::top() into:
    {
            T value = stack.deleteFromDLLTail();
            stack.addToDLLTail(value);
            return value;
    }
 */

template <class T>
class DLStack {
    public:
        void push(T el);
        void pop();
        T& top();
        bool IsEmpty();
    private:
        DoublyLinkedList<T> stack;
};

template<class T>
void DLStack<T>::push(T el) {
    stack.addToDLLHead(el);
    // method addToDLLHead covers the case for which the stack is empty (head == NULL)
}

template<class T>
void DLStack<T>::pop() {
    if (!IsEmpty())
        stack.deleteFromDLLHead();
}

template<class T>
T& DLStack<T>::top() {
    return stack.firstEl();
}

template<class T>
bool DLStack<T>::IsEmpty() {
    return stack.isEmpty();
}

bool goldenString(const string &str) {

    DLStack<char> stackInstance;

    // push first and last elements of the string to the stack
    stackInstance.push(str[0]);
    stackInstance.push(str[str.length() - 1]);

    while(!stackInstance.IsEmpty()) {
        switch(stackInstance.top()) {
            case 'a': case 'e': case 'i':
            case 'o': case 'u':
                return false;
            default:
                stackInstance.pop();
                break;
        }
    }
    return true;
}

bool checkParentheses(const string &str) {

    DLStack<char> stackInstance;

    for(int i = 0; str[i]; i++){

        // if a closing parentheses is to be added to an empty stack, it will never be closed anyway, return 0 right away.
        if(stackInstance.IsEmpty() && (str[i] == ')' || str[i] == ']' || str[i] == '}'))
            return false;

        // if the upcoming closing parentheses doesn't close the latest parentheses opener
        // e.g. str = "({", if the next closing parentheses isn't a '}', should return false
        if
                (
                ((str[i] == ')' || str[i] == ']') && stackInstance.top() == '{' )
                || ((str[i] == ')' || str[i] == '}') && stackInstance.top() == '[' )
                || ((str[i] == ']' || str[i] == '}') && stackInstance.top() == '(' )
                )
            return false;

        // regular push/pop operations
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
            stackInstance.push(str[i]);
        else if
        (
            (stackInstance.top() == '{' && str[i] == '}') ||
            (stackInstance.top() == '(' && str[i] == ')') ||
            (stackInstance.top() == '[' && str[i] == ']')
        )
            stackInstance.pop();
    }

    return stackInstance.IsEmpty();
}

