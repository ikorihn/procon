#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X;
  cin >> A >> B >> C >> X;

  int count = 0;
  for (int a = 0; a <= A; a++) {
    int x = X - 500 * a;
    if (x < 0) {
      continue;
    } else if (x == 0) {
      count++;
      continue;
    }
    for (int b = 0; b <= B; b++) {
      int y = x - 100 * b;
      if (y < 0) {
        continue;
      } else if (y == 0) {
        count++;
        continue;
      }
      for (int c = 0; c <= C; c++) {
        int z = y - 50 * c;
        if (z < 0) {
          continue;
        } else if (z == 0) {
          count++;
          continue;
        }
      }
    }
  }

  cout << count << endl;

  return 0;
}