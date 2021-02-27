#include <bits/stdc++.h>
using namespace std;

int main() {
  int v, t, s, d;
  cin >> v >> t >> s >> d;
  bool ans = true;
  if (v * t <= d && d <= v * s) {
    ans = false;
  }

  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}