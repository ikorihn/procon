#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  stack<int> st1;
  stack<pair<int, int>> st2;

  int sum = 0;
  for (int i = 0; i < S.length(); i++) {
    char ch = S.at(i);
    if (ch == '\\') {
      st1.push(i);
    } else if (ch == '/' && st1.size() > 0) {
      int j = st1.top();
      st1.pop();
      sum += i - j;
    }
  }

  return 0;
}