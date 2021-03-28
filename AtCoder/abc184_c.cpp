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

bool one(int a, int b, int c, int d) {
  if (a + b == c + d || a - b == c - d || abs(a - c) + abs(b - d) <= 3) {
    return true;
  }
  return false;
}

int move(int a, int b, int c, int d) {
  if (a == c && b == d) {
    return 0;
  }

  if (one(a, b, c, d)) {
    return 1;
  }

  // 差が偶数だったら2回
  if (abs(a + b - c - d) % 2 == 0) {
    return 2;
  }
  // 5*5マスの中で動いてから偶数になるか
  FOR(i, -2, 2) {
    FOR(j, -2, 2) {
      int ai = a + i;
      int bj = b + j;
      if (one(ai, bj, c, d)) {
        return 2;
      }
    }
  }

  return 3;
}

int main() {
  // 小数の桁数の出力指定
  // cout << fixed << setprecision(10);
  // 入力の高速化用のコード
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int ans = move(a, b, c, d);

  cout << ans << endl;

  return 0;
}