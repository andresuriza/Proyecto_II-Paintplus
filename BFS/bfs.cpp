#include <iostream>
#include <queue>
using namespace std;

class BFS{
    private:
    int matrix[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
                          {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},};
    queue<int> bfsQueue1;
    queue<int> reviewedList;

    public:
    void printMatrix() {
        int i = 0;
        int j = 0;
        
        while (i < 10) {
            while (j < 10) {
                cout << matrix[i][j];
                j++;
            }
            j = 0;
            i++;;
            cout << "\n";
        } 
    }

    void bfs(int start) {
        queue<int> bfsQueue;

        int mInitial = start / 10;
        int nInitial = start % 10;

        int data = matrix[mInitial][nInitial];

        bfsQueue.push(start);

        while (bfsQueue.size() > 0) {
            int num = bfsQueue.front();
            int newnum;

            int m = num / 10;
            int n = num % 10;

            if (matrix[m][n] == data) {
                matrix[m][n] = 5;

                if ((n - 1) >= 0) {
                    newnum = (m * 10) + (n - 1);
                    bfsQueue.push(newnum);
                }

                if ((m - 1) >= 0) {
                    newnum = ((m - 1) * 10) + n;
                    bfsQueue.push(newnum);
                }

                if ((n + 1) <= 9) {
                    newnum = (m * 10) + (n + 1);
                    bfsQueue.push(newnum);
                }

                if ((m + 1) <= 9) {
                    newnum = ((m + 1) * 10) + n;
                    bfsQueue.push(newnum);
                }
            }

            bfsQueue.pop();
        }

        printMatrix();
    }
};

int main() {
    BFS prueba;

    prueba.bfs(34);
}