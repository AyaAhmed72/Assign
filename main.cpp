#include"function1.h"
using namespace std;
int main() {
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }
    if (solveNQueens(0, N)) {
        cout << "Solution exists. Board configuration:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Solution does not exist.\n";
    }
    return 0;
}
