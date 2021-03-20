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

void search(vector<int>& ans, int A, int B, int w) {
  REP(mikans, 1000000) {
    bool brk = false;
    FOR(i, A, B) {
      FOR(j, i, B) {
        REP(x, mikans) {
          int y = mikans - x;
          if (x * i + y * j == w) {
            ans.push_back(x + y);
          }
          if (x * i > w) {
            brk = true;
          }
        }
        if (brk) {
          break;
        }
      }
      if (mikans * i > w) {
        break;
      }
    }
    if (mikans * A > w) {
      return;
    }
  }
}

int main() {
  // 小数の桁数の出力指定
  // cout << fixed << setprecision(10);
  // 入力の高速化用のコード
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int A, B, W;
  cin >> A >> B >> W;

  int w = W * 1000;

  int M = 0;
  int m = INF32;

  vector<int> ans(0);
  REP(i, 1000000) {
    if (A * i <= w && w <= B * i) {
      m = min(m, i);
      M = max(M, i);
    }
  }

  if (M == 0) {
    cout << "UNSATISFIABLE" << endl;
  } else {
    cout << m << " " << M << endl;
  }

  return 0;
}