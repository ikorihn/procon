#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Y;
  cin >> N >> Y;

  for (int x = 0; x <= N; x++) {
    for (int y = 0; y <= N - x; y++) {
      int z = (N - x - y);
      int sum = 10000 * x + 5000 * y + 1000 * z;
      if (sum == Y) {
        cout << x << " " << y << " " << z << endl;
        return 0;
      }
    }
  }

  cout << "-1 -1 -1" << endl;
  return 0;
}