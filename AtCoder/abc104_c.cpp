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

  ll D, G;
  cin >> D >> G;

  vector<ll> P(D), C(D);
  for (int i = 0; i < D; i++) {
    cin >> P[i] >> C[i];
  }

  ll ans = INF64;

  for (int bit = 0; bit < (1 << D); bit++) {
    ll score = 0;
    ll questions = 0;
    vector<bool> CMP(D, false);
    for (int i = 0; i < D; i++) {
      if (bit & (1 << i)) {
        ll p = P[i];
        ll c = C[i];
        score += p * 100 * (i + 1) + c;
        questions += p;
        CMP[i] = true;
      }
    }

    debug(bit);
    debug(score);
    debug(questions);

    if (score >= G) {
      ans = min(ans, questions);
      continue;
    }

    for (int i = D - 1; i >= 0; i--) {
      if (CMP[i]) {
        continue;
      }
      ll p = P[i];
      REP(j, p) {
        score += 100 * (i + 1);
        questions += 1;

        debug(score);
        debug(questions);
        if (score >= G) {
          break;
        }
      }
      if (score >= G) {
        break;
      }
    }
    ans = min(ans, questions);
  }

  cout << ans << endl;

  return 0;
}