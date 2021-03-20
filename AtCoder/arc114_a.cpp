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

vector<ll> prime_factorize(long long N) {
  vector<ll> res;
  for (long long a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    long long ex = 0;  // 指数

    // 割れる限り割り続ける
    while (N % a == 0) {
      ++ex;
      N /= a;
    }

    // その結果を push
    res.push_back(a);
  }

  // 最後に残った数について
  if (N != 1) res.push_back(N);
  sort(ALL(res));
  return res;
}

ll gcd(ll x, ll y) {
  if (x % y == 0) {
    return y;
  } else {
    return gcd(y, x % y);
  }
}

int main() {
  // 小数の桁数の出力指定
  // cout << fixed << setprecision(10);
  // 入力の高速化用のコード
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<int> X(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i];
  }

  set<int> primes;
  primes.insert(1);
  REP(i, N) {
    int n = X[i];
    debug(n);
    const auto& res = prime_factorize(n);
    bool already = false;
    for (auto r : res) {
      primes.insert(r);
      /*
      for (auto p : primes) {
        if (p == r) {
          already = true;
        }
      }
      */
    }
    /*
    if (!already) {
      bool br = false;
      for (auto r : res) {
        for (auto p : primes) {
          if (r != p) {
            primes.insert(r);
            br = true;
            break;
          }
        }
        if (br) {
          break;
        }
      }
      // primes.insert(res[0].first);
    }
    */
  }

  vector<int> primev(primes.begin(), primes.end());

  int sz = primev.size();
  ll m = INF64;
  for (int bit = 0; bit < (1 << sz); bit++) {
    ll tmp_num = 1;
    for (int i = 0; i < sz; i++) {
      if (bit & (1 << i)) {
        tmp_num *= primev[i];
      }
    }

    bool cannot = false;
    for (auto n : X) {
      if (gcd(tmp_num, n) == 1) {
        cannot = true;
      }
    }
    if (!cannot) {
      m = min(m, tmp_num);
    }
  }

  // ll ans = 1;
  // for (auto p : primes) {
  //   debug(p);
  //   ans *= p;
  // }

  cout << m << endl;

  return 0;
}
