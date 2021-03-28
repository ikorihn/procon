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

  vector<vector<int>> C(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> C[i][j];
    }
  }

  bool exists = false;
  vector<int> A(N), B(N);

  REP(i, N) {
    bool can = true;
    REP(j, N) {
      if (i == j) {
        continue;
      }

      debug(i);
      debug(j);

      ll num = C[i][0] - C[j][0];
      debug(num);
      REP(k, N) {
        ll tmp = C[i][k] - C[j][k];
        debug(tmp);
        if (tmp != num) {
          can = false;
          break;
        }
      }
      if (!can) {
        break;
      }
    }

    debug(can);
    if (can) {
      B = C[i];
      bool allPlus = true;
      REP(a, N) {
        int tmp = C[a][0] - B[0];
        debug(C[a][0]);
        debug(tmp);
        if (tmp < 0) {
          allPlus = false;
          break;
        }
        A[a] = tmp;
      }

      if (allPlus) {
        exists = true;

        break;
      }
    }
  }

  if (exists) {
    cout << "Yes" << endl;
    REP(i, N) {
      cout << A[i];
      if (i < N - 1) {
        cout << " ";
      }
    }
    cout << endl;
    REP(i, N) {
      cout << B[i];
      if (i < N - 1) {
        cout << " ";
      }
    }
    cout << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}