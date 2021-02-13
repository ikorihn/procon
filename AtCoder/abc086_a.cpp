#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  string out = "Odd";
  if (a * b % 2 == 0) {
    out = "Even";
  }
  cout << out << endl;

  return 0;
}