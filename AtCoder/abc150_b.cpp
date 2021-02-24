#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  int count = 0;

  for (int i = 0; i < N - 2; i++) {
    char c = S.at(i);
    if (c == 'A') {
      char c2 = S.at(i + 1);
      if (c2 == 'B') {
        char c3 = S.at(i + 2);
        if (c3 == 'C') {
          count++;
        }
      }
    }
  }

  cout << count << endl;

  return 0;
}