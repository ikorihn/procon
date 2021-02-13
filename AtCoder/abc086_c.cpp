#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int t[N + 1], x[N + 1], y[N + 1];
  t[0] = x[0] = y[0] = 0;
  for (int i = 1; i <= N; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }

  bool can = true;
  for (int i = 0; i < N; i++) {
    int dt = t[i + 1] - t[i];
    int dxy = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
    if (dt < dxy) {
      can = false;
      break;
    }
    if (dt % 2 != dxy % 2) {
      can = false;
      break;
    }
  }

  if (can) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}