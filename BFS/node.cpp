#include <iostream>
using namespace std;

class Node{
    private:
    int data = -1;
    int ID;
    bool state = false;
    Node* nextNode;

    public:
    int getData() {
        return data;
    }

    void setData(int newData) {
        data = newData;
    }

    int getID() {
        return ID;
    }

    void setID(int newID) {
        ID = newID;
    }

    bool getState() {
        return state;
    }

    void setState(bool newState) {
        state = newState;
    }

    Node* getNextNode() {
        return nextNode;
    }

    void setNextNode(Node* newNextNode) {
        nextNode = newNextNode;
    }
};