#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >>  C;
  bool ans = false;
  if (A > B) {
    ans = true;
  } else if (A == B && C == 1) {
    ans = true;
  }

  if (ans) {
    cout << "Takahashi" << endl;
  } else {
    cout << "Aoki" << endl;
  }

  return 0;
}