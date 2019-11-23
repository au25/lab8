//
// Created by Oscar Au on 2019-11-21.
//

#include <iostream>

#pragma once

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
};

template<typename T>
class MyLinkedList {
private:
    Node<T>* head;
public:
    MyLinkedList(){head->setNext(NULL);}
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
            head->setData(data);
        }

        while(last->getNext() != NULL){
            last = last->getNext();
        }
        last->setData(data);
        last->setNext(newNode);
        newNode->setData(NULL);
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
        if (node->getData() != NULL){
            std::cout << node->getData() << " " << std::endl;
            std::cout.flush();
            std::cout.clear();
        }
        node = node->getNext();
    }
}
