#include <iostream>

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
        Node<T>* newNode(data);
        newNode->setNext(head);
        head = newNode;
    }
    void pushBack(T data){
        auto *newNode = new Node<T>(data);

        Node<T>* last = head;
        if(head->getNext() == NULL){
            head->setData(data);
        }
        while(last->getNext() != NULL){
            last = last->getNext();
        }
        last->setNext(newNode);
    }
};

template<typename DLL, typename T>
void print(MyLinkedList<DLL> dll){
    Node<T> *node;
    node = dll.getHead();
    while (node->getNext() != NULL){
        cout << node->getData() << endl;
        node = node->getNext();
    }
}

int main() {
    Node<int> head(10);
    Node<int> middle(20);
    Node<int> tail(30);

    MyLinkedList<int> intList;
    intList.pushBack(3);
    intList.pushBack(4);
    print<int, int>(intList);
    return 0;
}


