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

  vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }

  int ans = 0;
  REP(i, N) {
    FOR(j, i + 1, N - 1) {
      int x1 = X[i];
      int y1 = Y[i];
      int x2 = X[j];
      int y2 = Y[j];

      double tilt;
      if ((x1 - x2) == 0) {
        tilt = 0;
      } else {
        tilt = (double)(y1 - y2) / (x1 - x2);
      }
      debug(i);
      debug(j);
      debug(tilt);

      if (tilt >= -1 && tilt <= 1) {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}