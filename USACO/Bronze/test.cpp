#include <iostream>
#include <vector>

using namespace std;

int main() {
  int M = 4, N = 5;
  vector<vector<int>> arr = {{1, 2, 3, 4, 5},
                             {6, 7, 8, 9, 10},
                             {11, 12, 13, 14, 15},
                             {16, 17, 18, 19, 20}};

  int row = 0, col = 0, direction = 0;
  int elements_left = M * N;
  int last_element = arr[0][0];
  while (elements_left > 0) {
    if (direction == 0) {
      // move right
      for (int i = 0; i < N - 1; ++i) {
        last_element = arr[row][col];
        col += 2;
        elements_left--;
        if (elements_left == 0) break;
      }
      direction = 1;
    } else if (direction == 1) {
      // move down
      for (int i = 0; i < M - 1; ++i) {
        last_element = arr[row][col];
        row += 2;
        elements_left--;
        if (elements_left == 0) break;
      }
      direction = 2;
    } else if (direction == 2) {
      // move left
      for (int i = 0; i < N - 1; ++i) {
        last_element = arr[row][col];
        col -= 2;
        elements_left--;
        if (elements_left == 0) break;
      }
      direction = 3;
    } else if (direction == 3) {
      // move up
      for (int i = 0; i < M - 1; ++i) {
        last_element = arr[row][col];
        row -= 2;
        elements_left--;
        if (elements_left == 0) break;
      }
      direction = 0;
      row++;
      col++;
      N -= 2;
      M -= 2;
    }
  }
  cout << "The last element is: " << last_element << endl;
  return 0;
}