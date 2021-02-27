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

pair<ll, ll> score(vector<ll> card_s, vector<ll> card_t, vector<ll> cardset,
                   ll s, ll t) {
  if (cardset[s] <= 0) {
    return make_pair(-1, -1);
  }
  card_s[s]++;
  cardset[s]--;
  if (cardset[t] <= 0) {
    return make_pair(-1, -1);
  }
  card_t[t]++;

  ll score_s = 0;
  FOR(i, 1, 9) { score_s += i * pow(10, card_s[i]); }
  ll score_t = 0;
  FOR(i, 1, 9) { score_t += i * pow(10, card_t[i]); }

  return make_pair(score_s, score_t);
}

ll denominator(ll K) {
  ll amari = (K * 9) - 8;
  return amari * (amari - 1);
}

int main() {
  // 小数の桁数の出力指定
  cout << fixed << setprecision(10);
  // 入力の高速化用のコード
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int K;
  cin >> K;

  string S, T;
  cin >> S >> T;

  // 1オリジンでカウント
  vector<ll> cardset(10);
  FOR(i, 1, 9) { cardset[i] = K; }

  vector<ll> cards_s(10, 0), cards_t(10, 0);
  REP(j, 4) {
    ll card_s = S[j] - '0';
    ll card_t = T[j] - '0';
    cards_s[card_s]++;
    cards_t[card_t]++;
    cardset[card_s]--;
    cardset[card_t]--;
  }

  ll pattern = 0;
  FOR(i, 1, 9) {
    FOR(j, 1, 9) {
      pair<ll, ll> scores = score(cards_s, cards_t, cardset, i, j);
      if (scores.first > scores.second) {
        // debug(i);
        // debug(j);
        // debug(scores.first);
        // debug(scores.second);
        debug(cardset[i]);
        debug(cardset[j]);
        ll b = cardset[j];
        if (i == j) {
          b = cardset[j] - 1;
        }
        pattern += cardset[i] * b;
      }
    }
  }

  ll den = denominator(K);
  debug(den);
  debug(pattern);

  double ans = (double)pattern / den;

  cout << ans << endl;

  return 0;
}