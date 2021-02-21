#include <bits/stdc++.h>
using namespace std;

int ctoi(char c) {
  switch (c) {
    case '0':
      return 0;
    case '1':
      return 1;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 4;
    case '5':
      return 5;
    case '6':
      return 6;
    case '7':
      return 7;
    case '8':
      return 8;
    case '9':
      return 9;
    default:
      return -1;
  }
}

int main() {
  string X;
  int64_t M;
  cin >> X >> M;

  string x_str = X;
  sort(x_str.begin(), x_str.end());
  char max_str = x_str.at(x_str.length() - 1);
  int max = ctoi(max_str);

  long long i = 1;
  while (true) {
    long long base = max + i;
    long long ans = 0;
    for (long long idx = 0; idx < X.length(); idx++) {
      long long num = ctoi(X.at(idx));
      ans += num * (long long)pow(base, idx);
    }
    if (ans > M) {
      break;
    }
    i++;
  }

  cout << i - 1 << endl;

  return 0;
}