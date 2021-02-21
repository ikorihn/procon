#include <bits/stdc++.h>
using namespace std;

vector<int64_t> memo(100, 0);

int64_t luca(int n) {
  if (n == 0) {
    return 2;
  }
  if (n == 1) {
    return 1;
  }

  if (memo.at(n) > 0) {
    return memo.at(n);
  }

  int64_t ans = luca(n - 1) + luca(n - 2);
  memo.at(n) = ans;
  return ans;
}

int main() {
  int N;
  cin >> N;

  int64_t ans = luca(N);

  cout << ans << endl;

  return 0;
}
