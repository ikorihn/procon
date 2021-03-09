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
#define FORA(i, I) for (const auto &i : I)
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

bool is_tree(vector<bool> &visited, vector<vector<int>> &G, int i, int parent) {
  auto g = G[i];

  // 次の葉がなければ終点
  if (g.size() == 0) {
    return true;
  }

  // 通過済みだったら閉路
  if (g.size() > 0 && visited[i]) {
    return false;
  }

  // 通過済みにする
  visited[i] = true;

  bool ans = true;
  for (auto c : g) {
    // 親と同じはskip
    if (c == parent) {
      continue;
    }

    if (!is_tree(visited, G, c, i)) {
      ans = false;
    }
  }

  return ans;
}

int main() {
  // 小数の桁数の出力指定
  // cout << fixed << setprecision(10);
  // 入力の高速化用のコード
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  vector<bool> visited(110, false);

  int ans = 0;
  REP(i, N) {
    if (!visited[i]) {
      if (is_tree(visited, G, i, -1)) {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}