#include "linkedList.hpp"

using namespace std;



int main() {

    MyLinkedList<int> intList;
    intList.pushBack(3);
    intList.pushFront(1);
    intList.insert(intList.getPrevNode(1), 2);
    print<int, int>(intList);

    MyLinkedList<char> charList;
    charList.pushBack('c');
    charList.pushFront('a');
    charList.insert(charList.getPrevNode('a'), 'b');
//    print<char, char>(charList);
    return 0;
}


