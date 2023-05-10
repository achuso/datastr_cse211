// CSE211.1 TERM PROJECT
// Name: Onat Ribar
// Student nr.: 20210702099

#include <iostream>
#include <string>
#include <fstream>

using std::string, std::cout, std::endl, std::ifstream, std::ofstream;

struct PersonNode {
    string name;
    int age = 0;
    // Arrange two branches of a singly linked list sharing the same nodes
    PersonNode* nextAge = nullptr;
    PersonNode* nextName = nullptr;
};

class PersonLinkedList {
    public:
        PersonLinkedList() {
            headAge = headName = nullptr;
        }
        void add(string name, int age);
        bool remove(string name);
        void update(string name, int age);
        void printByAge();
        void printByName();
        void loadFile(string filename);
        void saveToFileByAge(string filename);
        void saveToFileByName(string filename);   
    private:
        PersonNode* headAge;
        PersonNode* headName;
};

void PersonLinkedList::add(string name, int age) {
	
	PersonNode* HeadOfAll = new PersonNode;
    HeadOfAll->nextName = headName;
    HeadOfAll->nextAge = headAge;

	PersonNode* toBeAdded = new PersonNode;
	toBeAdded->name = name;
	toBeAdded->age = age;

	PersonNode* tempName = HeadOfAll, *tempAge = HeadOfAll;
	
	for(; (tempName->nextName != nullptr) && (tempName->nextName->name.compare(toBeAdded->name)) <= 0; tempName = tempName->nextName);

    for(; (tempAge->nextAge != nullptr) && (tempAge->nextAge->age <= toBeAdded->age); tempAge = tempAge->nextAge);

    toBeAdded->nextName = tempName->nextName;
	tempName->nextName = toBeAdded;	
	
    toBeAdded->nextAge = tempAge->nextAge;
	tempAge->nextAge = toBeAdded;			

	headName = HeadOfAll->nextName;
	headAge = HeadOfAll->nextAge;

}

bool PersonLinkedList::remove(string name) {

    PersonNode* HeadOfAll = new PersonNode;
    HeadOfAll->nextName = headName;
    HeadOfAll->nextAge = headAge;

    PersonNode* tempName = HeadOfAll, *tempAge = HeadOfAll;

    for(; (tempName->nextName != nullptr) && (tempName->nextName->name != name); tempName = tempName->nextName);

    for (; (tempAge->nextAge != nullptr) && (tempAge->nextAge->age != tempName->nextName->age); tempAge = tempAge->nextAge);

    if (tempName->nextName == nullptr && tempAge->nextAge == nullptr)
        return false;

    PersonNode* del = tempName->nextName;

    tempName->nextName = del->nextName;
    tempAge->nextAge = del->nextAge;

    delete del;

    headName = HeadOfAll->nextName;
    headAge = HeadOfAll->nextAge;

    return true;

}

void PersonLinkedList::update(string name, int age) {
    if(PersonLinkedList::remove(name))
        PersonLinkedList::add(name, age);
    else cout << "ERROR: Update failed..." << '\n';
}

void PersonLinkedList::printByAge() {
    int flag = 0;
    cout << "Attempting printing list by age..." << endl;
    for(PersonNode* temp = headAge; temp != nullptr; temp = temp->nextAge) {
        cout << temp->name << '\t' << temp->age << '\n';
        flag++;
    }
    if(!flag)
        cout << "ERROR: List is empty. Could not print by age..." << endl;
    else
        cout << "Printing list by age successful." << '\n' << '\n';
}

void PersonLinkedList::printByName() {
    int flag = 0;
    cout << "Attempting printing list by name..." << endl;
    for(PersonNode* temp = headName; temp != nullptr; temp = temp->nextName) {
        cout << temp->name << '\t' << temp->age << endl;
        flag++;
    }
    if(!flag)
        cout << "ERROR: List is empty. Could not print by name..." << '\n' << '\n';
    else
        cout << "Printing list by name successful." << '\n' << '\n';
}

void PersonLinkedList::loadFile(string filename) {
    ifstream FILE;
    FILE.open(filename.c_str());
    if(!FILE.is_open()) {
        cout << "ERROR: File could not be opened..." << endl;
        return;
    }

    string name;
    int age;
    while(!FILE.eof()) {
        FILE >> name;
        FILE >> age;
        PersonLinkedList::add(name, age);
    }

    FILE.close();
}

void PersonLinkedList::saveToFileByAge(string filename) {
    ofstream FILE(filename);
    if(!FILE.is_open()) {
        cout << "ERROR: File could not be opened..." << endl;
        return;
    }

    for(PersonNode* temp = headAge; temp != nullptr; temp = temp->nextAge)
        FILE << temp->name << (temp->name.size() < 4 ? "\t\t" : "\t") << temp->age << endl;
    
    FILE.close();
}

void PersonLinkedList::saveToFileByName(string filename) {
    ofstream FILE(filename);
    if(!FILE.is_open()) {
        cout << "ERROR: File could not be opened..." << endl;
        return;
    }

    for(PersonNode* temp = headName; temp != nullptr; temp = temp->nextName) {
        FILE << temp->name << (temp->name.size() < 4 ? "\t\t" : "\t") << temp->age << endl;
    }

    FILE.close();
}