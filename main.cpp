#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Node {
private:
    T data;
    Node* nextNode;
    Node* prevNode;
public:
    Node(){
        data = NULL;
        nextNode = NULL;
        prevNode = NULL;
    }
    explicit Node(T data) : data{data}{
        nextNode = NULL;
        prevNode = NULL;
    };
    ~Node() = default;
    T getData(){return data;}
    void setData(T newValue){this->data = newValue;}
    Node* getNext(){return nextNode;};
    void setNext(Node* nextNode){this->nextNode = nextNode;}
    Node* getPrev(){ return prevNode;};
    T getValue(){return data;}
};

template<typename T>
class MyLinkedList {
private:
    Node<T>* head;
public:
    MyLinkedList(){head->setNext(NULL);}
    MyLinkedList(Node<T>* node) : head{node}{};
    ~MyLinkedList(){};

    Node<T>* getHead(){return head;}

    void pushFront(T data){
        auto *newNode = new Node<T>(data);
        newNode->setNext(head);
        head = newNode;
    }

    void pushBack(T data){
        auto *newNode = new Node<T>(data);

        //set pointer to head
        Node<T>* last;

        if(head->getNext() == NULL){
            last = head;
            head->setData(data);  // head data = 3
        }

        //get last to point to last node
        while(last->getNext() != NULL){
            last = last->getNext();  // last points to second empty node
        }
        last->setNext(newNode);
    }

    void insert(Node<T>* const& prevNode, T data){
        auto *newNode = new Node<T>(data);
        newNode->setNext(prevNode->getNext());
        prevNode->setNext(newNode);

    }

    Node<T>* getPrevNode(T data){
        Node<T>* prevNode = head;

        while(prevNode->getNext() != NULL){
            if (prevNode->getData() == data){
                return prevNode;
            }
            prevNode = prevNode->getNext();
        }
    }
};

template<typename DLL, typename T>
void print(MyLinkedList<DLL> dll){
    Node<T> *node;
    node = dll.getHead();
    while (node->getData() != NULL){
        cout << node->getData() << endl;
        node = node->getNext();
    }
}


int main() {
//    Node<int> head(10);
//    Node<int> middle(20);
//    Node<int> tail(30);

    MyLinkedList<int> intList;
    intList.pushBack(3);
    intList.pushFront(1);
    intList.insert(intList.getPrevNode(1), 2);
    print<int, int>(intList);

    MyLinkedList<string> stringList;
    stringList.pushBack(reinterpret_cast<const char *>('c'));
    print<string, string>(stringList);
    return 0;
}


