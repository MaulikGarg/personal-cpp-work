#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printError(const std::string& msg) {
  std::cerr << "\n"
            << std::string(msg.length(), '-') + "\n" + msg + "\n" +
                   std::string(msg.length(), '-') + "\n";
  exit(1);
}

class Matrix {
  vector<vector<int>> matrix;
  Matrix(size_t r, size_t c) : matrix(r, vector<int>(c)) {}

 public:
  Matrix();

  Matrix operator*(const Matrix& m) {
    if (matrix.empty() || m.matrix.empty() ||
        matrix[0].size() != m.matrix.size())
      printError("Undefined multiplication.");
    Matrix result(matrix.size(), m.matrix[0].size());
    for (size_t i = 0; i < matrix.size(); ++i)
      for (size_t j = 0; j < m.matrix[0].size(); ++j)
        for (size_t k = 0; k < m.matrix.size(); ++k)
          result.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
    return result;
  }

  void display() {
    for (auto& row : matrix) {
      for (auto& elem : row) cout << setw(10) << elem;
      cout << '\n';
    }
  }
};

Matrix::Matrix() {
  cout << "Enter rows and columns: ";
  int r, c;
  cin >> r >> c;
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
