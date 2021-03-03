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

ll plus_num(ll b, ll c) {
  if (c < 0) {
    return 0;
  }

  // b>0で、b, b-1, ..(b-c/2)., -b,...(b-c/2)
  // Bから-Bまでの数と、Bから-1ずつしていったときの小さい方

  ll plus_num = min(b, c / 2 + 1);
  debug(plus_num);

  // 1引くより(-1)かけるほうが安いので確実に存在する
  ll minus_num = plus_num;
  if (b >= c / 2 + 1 && c % 2 == 0) {
    minus_num = (plus_num - 1);
  }
  debug(minus_num);

  ll zero = 0;
  if (b < c / 2 + 1) {
    zero = 1;
  }

  return plus_num + minus_num + zero;
}

ll minus_num(ll b, ll c) {
  if (c < 0) {
    return 0;
  }

  // b<0で、b, b-1, ..., (b-c/2)
  ll minus_num = c / 2 + 1;
  debug(minus_num);
  // -1かけた数が同じ数存在する
  ll plus_num = minus_num;
  if (c % 2 == 0) {
    plus_num = (minus_num - 1);
  }
  debug(plus_num);

  return plus_num + minus_num;
}

int main() {
  // 小数の桁数の出力指定
  // cout << fixed << setprecision(10);
  // 入力の高速化用のコード
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll B, C;
  cin >> B >> C;

  ll ans = 0;
  if (B > 0) {
    ans += plus_num(B - 1, C - 2);
    debug(ans);
    // B>0から1ずつ引いていくのと、C-1して負にしてからずっと引いていく
    ans += minus_num(B * (-1) - 1, C - 3);
    debug(ans);
  } else if (B < 0) {
    ans += minus_num(B - 1, C - 2);
    debug(ans);
    ans += plus_num(B * (-1) - 1, C - 3);
    debug(ans);
  } else {
    ans += minus_num(B - 1, C - 2);
    debug(ans);
  }

  // 自身と、自身に(-1)をかけた数
  ans += (B != 0 && C >= 1) ? 2 : 1;

  cout << ans << endl;

  return 0;
}