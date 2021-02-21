#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  bool isdifficult = true;
  for (int i = 0; i < S.length(); i++) {
    char c = S.at(i);
    if (i % 2 == 0 && isupper(c) || i % 2 == 1 && islower(c)) {
      isdifficult = false;
    }
  }

  if (isdifficult) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}