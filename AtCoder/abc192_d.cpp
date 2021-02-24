#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll base, string X, ll M) {
  ll basenTo10 = 0;
  int N = X.length();
  for (int i = 0; i < N; i++) {
    int x = X.at(i) - '0';
    if (basenTo10 > (M - x) / base) return false;

    basenTo10 = basenTo10 * base + x;

    if (basenTo10 > M) {
      return false;
    }
  }
  return true;
}

int main() {
  string X;
  ll M;
  cin >> X >> M;

  if (X.length() == 1) {
    int x = X.at(0) - '0';
    if (x > M) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
    return 0;
  }

  int ma = 0;
  for (auto x : X) {
    ma = max(x - '0', ma);
  }

  ll ok = ma;
  ll ng = M + 1;
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (check(mid, X, M)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << max(0LL, (ok - ma)) << endl;

  return 0;
}