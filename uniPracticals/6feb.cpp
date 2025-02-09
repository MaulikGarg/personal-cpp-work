#include <iomanip>  //for setting width
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printError(const string& msg) {
  cerr << "\n"
       << string(msg.length(), '-') + "\n" + msg + "\n" +
              string(msg.length(), '-') + "\n";
  exit(1);
}

class Matrix {
 private:
  int r, c;
  vector<vector<int>> matrix;

 public:
  Matrix(int ir, int ic) : r{ir}, c{ic}, matrix(r, vector<int>(c)) {}

  Matrix() {
    cout << "Enter the number of rows and columns: ";
    cin >> r >> c;
    if (r < 1 || c < 1) printError("Rows and Columns must be more than 1.");
    matrix.resize(r, vector<int>(c));
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++) {
        cout << "Enter element " << i + 1 << ", " << j + 1 << ": ";
        cin >> matrix[i][j];
      }
  }

  Matrix operator*(const Matrix& operand2) {
    if (c != operand2.r) printError("undefined multiplication of matrices.");
    Matrix result{r, operand2.c};
    for (int r1 = 0; r1 < r; r1++)
      for (int c2 = 0; c2 < operand2.c; c2++) {
        for (int r2 = 0; r2 < operand2.r; r2++)
          result.matrix[r1][c2] += matrix[r1][r2] * operand2.matrix[r2][c2];
      }
    return result;
  }

  void display() {
    for (auto& row : matrix) {
      for (auto& element : row) cout << setw(10) << element;
      cout << '\n';
    }
  };
};

int main() {
  Matrix m1, m2;
  (m1 * m2).display();
  return 0;
}
