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

struct Count {
  bool normal;
  bool exclamation;
};

int main() {
  // 小数の桁数の出力指定
  // cout << fixed << setprecision(10);
  // 入力の高速化用のコード
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  map<string, Count> m;
  bool exists = false;
  REP(i, N) {
    string s = S[i];
    bool hasExc = s[0] == '!';
    if (hasExc) {
      s = s.substr(1);
    }

    if (m.count(s)) {
      auto p = m[s];
      if (p.normal && hasExc || p.exclamation && !hasExc) {
        cout << s << endl;
        exists = true;
        break;
      }
    } else {
      m[s] = { !hasExc, hasExc };
    }
  }

  if (!exists) {
    cout << "satisfiable" << endl;
  }

  return 0;
}