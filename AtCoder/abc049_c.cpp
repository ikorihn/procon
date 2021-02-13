#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  string DE[4] = {"dream", "dreamer", "erase", "eraser"};

  reverse(S.begin(), S.end());
  for (int i = 0; i < 4; i++) {
    reverse(DE[i].begin(), DE[i].end());
  }

  bool success = true;

  for (int i = 0; i < S.size();) {
    bool end = true;
    for (int j = 0; j < 4; j++) {
      string d = DE[j];
      if (S.substr(i, d.size()) == d) {
        end = false;
        i += d.size();
      }
    }
    if (end) {
      success = false;
      break;
    }
  }

  if (success) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
