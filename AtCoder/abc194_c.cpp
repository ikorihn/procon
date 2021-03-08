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

  ll sum = 0;
  ll sum2 = 0;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    int a = 0;
    cin >> a;
    A[i] = a;
    sum += a;
    sum2 += pow(a, 2);
  }

  // ai ^ 2 * (N - 1)
  sum2 = sum2 * (N - 1);

  // -2 * (2 * 8 + 4 * 2  + 8 * 4)
  // 8 + 4 + 2
  // 2 *(8 + 4)
  // 8 *(4)

  ll tmp_kake = 0;
  REP(i, N) {
    sum = (sum - A[i]);
    tmp_kake += A[i] * sum;
  }

  ll ans = sum2 - 2 * tmp_kake;

  cout << ans << endl;

  return 0;
}