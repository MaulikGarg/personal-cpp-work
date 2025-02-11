#include <../libraries/mylib.h>  //for printing error
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Matrix {
  vector<vector<int>> matrix;

 public:
  Matrix(int r, int c) : matrix(r, vector<int>(c)) {}
  Matrix();

  Matrix operator*(const Matrix& m) {
    if (matrix.empty() || m.matrix.empty() || matrix[0].size() != m.matrix.size()) printError("Undefined multiplication.");
    Matrix result(matrix.size(), m.matrix[0].size());
    for (int i = 0; i < matrix.size(); ++i)
      for (int j = 0; j < m.matrix[0].size(); ++j)
        for (int k = 0; k < m.matrix.size(); ++k)
          result.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
    return result;
  }

void display() {
  for (auto& row : matrix) {
    for (auto& elem : row) cout << setw(10) << elem;
      cout << '\n';
    }
}};

Matrix::Matrix() {
  cout << "Enter rows and columns: ";
  int r, c; cin >> r >> c;
  if (r < 1 || c < 1) printError("Invalid matrix dimensions.");
  matrix.resize(r, vector<int>(c));
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) {
      cout << "Element " << i + 1 << "," << j + 1 << ": ";
      cin >> matrix[i][j];
    }
}

int main() {
  Matrix m1, m2;
  (m1 * m2).display();
}
