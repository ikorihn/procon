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

  ll N;
  cin >> N;

  // N=3桁のとき 2桁のは全部 9こ
  // 11,22,33,..,99
  // 1010,1111,1212,...9999
  // N=5桁のとき 2桁4桁
  // N=6桁のとき 2桁4桁と6桁の途中まで
  // 100100,101101,...,555555,...9999999

  int ans = 0;

  string nst = to_string(N);
  int len = nst.length();
  for (int i = 1; i <= len / 2; i++) {
    ll keta = pow(10, i);
    // debug(i); debug(keta);
    for (int j = keta / 10; j < keta; j++) {
      ll num = j * keta + j;
      // debug(num);
      if (num <= N) {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}