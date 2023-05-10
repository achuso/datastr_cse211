
#include "ONAT_RIBAR.h"

int main() {
    PersonLinkedList list = PersonLinkedList();

    list.loadFile("input.txt");

    list.add("onat", 21);
    list.add("freud", 64);
    list.update("onat", 32);
    list.printByAge();
    list.printByName();

    list.remove("freud");
    list.saveToFileByAge("outputAge.txt");
    list.saveToFileByName("outputName.txt");

    return 0;
}
