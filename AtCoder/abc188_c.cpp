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

  ll PN = pow(2, N);
  vector<pair<ll, ll>> A(PN);
  for (int i = 0; i < PN; i++) {
    int a;
    cin >> a;
    A[i] = make_pair(i + 1, a);
  }

  vector<int> vics(PN);
  for (ll n = N; n >= 2; n--) {
    int pn = A.size();
    debug(n);
    for (ll i = 0; i < (pn / 2); i++) {
      debug(A[i].second);
      debug(A[i + 1].second);
      if (A[i].second > A[i + 1].second) {
        A.erase(A.begin() + i + 1);
      } else {
        A.erase(A.begin() + i);
      }
    }
  }

  REP(i, A.size()) {
    debug(i);
    debug(A[i].first);
    debug(A[i].second);
  }

  if (A[0].second > A[1].second) {
    cout << A[1].first << endl;
  } else {
    cout << A[0].first << endl;
  }

  return 0;
}