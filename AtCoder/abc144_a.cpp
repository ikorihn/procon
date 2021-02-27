#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  if (A < 1 || A > 9 || B < 1 || B > 9) {
    cout << -1 << endl;
    return 0;
  }

  cout << A * B << endl;

  return 0;
}