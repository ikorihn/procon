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
  vector<pair<int, int>> A(N), B(N);
  int min_sum = INF32;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    A[i] = make_pair(a, i);
    B[i] = make_pair(b, i);

    min_sum = min(min_sum, a + b);
  }

  // int min_a = INF32;
  // int min_ai = 0;
  // int min_b = INF32;
  // int min_bi = 0;
  // int min_sum = INF32;
  // REP(i, N) {
  //   if (min_a < A[i]) {
  //     min_ai = i;
  //   }
  //   if (min_b < B[i]) {
  //     min_bi = i;
  //   }
  //   min_a = min(min_a, A[i]);
  //   min_b = min(min_b, B[i]);

  //   min_sum = min(min_sum, INF32);
  // }

  sort(ALL(A));
  sort(ALL(B));

  int ans = 0;
  if (A[0].second == B[0].second) {
    int max_a = max(A[0].first, B[1].first);
    int max_b = max(A[1].first, B[0].first);
    ans = min(max_a, max_b);
  } else {
    ans = max(A[0].first, B[0].first);
  }

  if (ans < min_sum) {
    cout << ans << endl;
  } else {
    cout << min_sum << endl;
  }

  return 0;
}