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

int H, W, A, B;
int ans = 0;

bool allVisited(vector<vector<bool>> visited) {
  REP(i, H) {
    REP(j, W) {
      if (visited[i][j] == false) {
        return false;
      }
    }
  }
  return true;
}

bool fill(vector<vector<bool>> visited, int x, int y, int a, int b) {
  debug(x);
  debug(y);
  debug(a);
  debug(b);

  if (x >= W) {
    return false;
  }
  if (y >= H) {
    return false;
  }
  if (a < 0 || b < 0) {
    return false;
  }

  if (visited[x][y] == true) {
    if (x < W) {
      x++;
    } else {
      y++;
    }
  }

  visited[x][y] = true;

  // 横においたばあい
  if (x + 1 < W) {
    x++;
    visited[x][y] = true;
    if (x < W - 1) {
      x++;
    } else {
      y++;
      x = 0;
    }
    bool result = fill(visited, x, y, a - 1, b);
    if (!result) {
      return false;
    }
    if (allVisited(visited)) {
      ans++;
    }
  }

  // 縦においたばあい
  if (y + 1 < H) {
    y++;
    visited[x][y] = true;
    if (x < W - 1) {
      x++;
    } else {
      y++;
      x = 0;
    }
    bool result = fill(visited, x, y, a - 1, b);
    if (!result) {
      return false;
    }
    if (allVisited(visited)) {
      ans++;
    }
  }

  // 正方形をおいたばあい
  if (x < W - 1) {
    x++;
  } else {
    y++;
    x = 0;
  }
  bool result = fill(visited, x, y, a, b - 1);
  if (!result) {
    return false;
  }
  if (allVisited(visited)) {
    ans++;
  }

  return true;
}

bool solve() {
  int ans = 0;

  int x = 0;
  int y = 0;
  vector<vector<bool>> visited(H, vector<bool>(W));
  REP(i, H) {
    REP(j, W) { visited[i][j] = false; }
  }

  fill(visited, x, y, A, B);

  return false;
}

int main() {
  // 小数の桁数の出力指定
  // cout << fixed << setprecision(10);
  // 入力の高速化用のコード
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> H >> W >> A >> B;

  solve();

  cout << ans << endl;

  return 0;
}