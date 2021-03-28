#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DEBUG
#ifdef _DEBUG
#define debug(x) cout << #x << ": " << x << endl
#else
#define debug(x)
#endif
// iter
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i <= (int)(b); i++)
#define FORD(i, a, b) for (int i = a; i >= (int)(b); i--)
#define FORA(i, I) for (const auto& i : I)
// vec
#define ALL(x) x.begin(), x.end()
#define SIZE(x) ((int)(x.size()))
// 定数
// 2.147483647×10^{9}:32bit整数のinf
#define INF32 2147483647
// 9.223372036854775807×10^{18}:64bit整数のinf
#define INF64 9223372036854775807
// 問題による
#define MOD 1000000007

int main() {
  // 小数の桁数の出力指定
  // cout << fixed << setprecision(10);
  // 入力の高速化用のコード
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  ll ans = INF64;

  for (int bit = 0; bit < (1 << N - 1); bit++) {
    vector<ll> SUB(0);
    debug(bit);
    int prev_idx = 0;
    for (int i = 0; i < N - 1; i++) {
      if (bit & (1 << i)) {
        // vector<ll> s(A.begin() + prev_idx, A.begin() + i);
        ll s = A[prev_idx];
        debug(prev_idx);
        debug(i);
        for (int j = prev_idx; j <= i; j++) {
          s = s | A[j];
        }
        debug(s);
        SUB.push_back(s);
        prev_idx = i + 1;
      }
    }

    debug(prev_idx);
    ll s = A[prev_idx];
    for (int j = prev_idx; j < N; j++) {
      s = s | A[j];
    }
    debug(s);
    SUB.push_back(s);

    ll tmpans = 0;
    REP(i, SUB.size()) {
      debug(SUB[i]);
      tmpans = tmpans ^ SUB[i];
    }

    debug(tmpans);
    ans = min(ans, tmpans);
  }

  cout << ans << endl;

  return 0;
}