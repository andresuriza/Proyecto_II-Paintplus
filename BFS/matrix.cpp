#include <iostream>
using namespace std;

#include "list.cpp"

class Matrix {
    private:
    int sizex;
    int sizey;
    List* header;
    List* lastList;

    // int matrix[20][20];
    // int bfsQueue[];

    public:

    int getSizex() {
        return sizex;
    }

    int getSizey() {
        return sizey;
    }

    /*
    void createMatrix() {
        int i = 0;
        int j = 0;

        while (i < 100) {
            while (j < 100) {
                matrix[i][j] = 0;
                j++;
            }
            i++;
        }
        printMatrix();
    }

    void printMatrix() {
        int i = 0;
        int j = 0;
        
        while (i < 100) {
            while (j < 100) {
                cout << matrix[i][j] << endl;
                j++;
            }
            i++;
        } 
    }

    void bfs(int x, int y) {
        
    }
    */
};

/*
int main(int argc, char* argv[]) {
    Matrix prueba;

    prueba.createMatrix();
}
*/