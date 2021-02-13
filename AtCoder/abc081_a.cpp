#include <bits/stdc++.h>
using namespace std;

int main() {
  string t;
  cin >> t;

  int out = 0;
  for (int i = 0; i < t.size(); i++) {
    if (t.at(i) == '1') {
      out++;
    }
  }

  cout << out << endl;

  return 0;
}