#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a, b;
  cin >> N >> a >> b;

  int count = 0;
  for (int i = 1; i <= N; i++) {
    int p = i % 10;
    int q = (i / 10) % 10;
    int r = (i / 100) % 10;
    int s = (i / 1000) % 10;
    int t = (i / 10000) % 10;

    int sum = p + q + r + s + t;
    if (a <= sum && sum <= b) {
      count += i;
    }
  }

  cout << count << endl;

  return 0;
}
