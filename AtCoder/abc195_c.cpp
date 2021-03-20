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
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
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

  string N;
  cin >> N;

  ll ans = 0;

  ll len = (N.length() - 1) / 3;
  debug(len);
  ll num = stoll(N);

  debug(num);

  if (num <= 999) {
    ans = 0;
  } else {
    FOR(i, 1, len) {
      ll p = pow(10, 3 * i);
      ll pp = pow(10, 3 * (i + 1));
      debug(i);
      debug(p);
      debug(pp);

      if (i == len) {
        debug(i * (num - p + 1));
        ans += i * (num - p + 1);
      } else {
        debug(i * (pp - p));
        ans += i * (pp - p);
      }
    }
  }

  cout << ans << endl;

  /**
   * len(str) / 3 が0 → 0
   * len(str) / 3 が1 → 1 * (N - 1000 + 1)
   * len(str) / 3 が2 → 1 * (1,000,000 - 1,000) + 2 * (N - 10 ^ 4 + 1)
   * len(str) / 3 が3 → 1 * (1,000,000 - 1,000) + 2 * (1,000,000,000 -
   * 1,000,000)  +  3 * ...
   *
   * 27,182,818,284,590
   * 1000000000000000
   * 999999999999999
   */

  return 0;
}