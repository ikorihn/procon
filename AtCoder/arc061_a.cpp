#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int N = S.length();

  int64_t sum = 0;
  for (int bit = 0; bit < (1 << (N - 1)); bit++) {
    int64_t tmp = 0;

    for (int i = 0; i < N; i++) {
      tmp *= 10;
      tmp += S[i] - '0';
      if (bit & (1 << i)) {
        sum += tmp;
        tmp = 0;
      }
      if (i == N - 1) {
        sum += tmp;
      }
    }
  }

  cout << sum << endl;

  return 0;
}