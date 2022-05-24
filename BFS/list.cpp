#include <iostream>
using namespace std;

#include "node.cpp"

class List{
    private:
    int listNum;
    int size;
    Node* header;
    Node* lastNode;

    public:
    int getListNum() {
        return listNum;
    }

    void setListNum(int newListNum) {
        listNum = newListNum; 
    }

    int getSize() {
        return size;
    }

    Node* getHeader() {
        return header;
    }

    void setHeader() {
        Node newNode;
        Node* newNodeptr = &newNode;

        header = newNodeptr;
        lastNode = newNodeptr;
    }

    void addNode() {
        Node* temp = lastNode;

        Node newNode;
        Node* newNodeptr = &newNode;

        lastNode = newNodeptr;
        temp->setNextNode(newNodeptr);
    }
};