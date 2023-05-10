#include "intSLList.h"

int delete_min(IntSLList & list) {

    int* toBeDeleted = list.find_min();
    int value = *toBeDeleted;

    list.deleteNode(*toBeDeleted);

    return value;
}