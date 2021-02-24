#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> S, int mid, int key) { return S.at(mid) >= key; }

int binarySearch(vector<int> S, int key) {
  int ng = -1;
  int ok = S.size() - 1;

  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    // cout << key << "," << mid << endl;
    if (check(S, mid, key)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

int main() {
  int N;
  cin >> N;
  vector<int> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  int Q;
  cin >> Q;
  vector<int> T(Q);
  for (int i = 0; i < Q; i++) {
    cin >> T.at(i);
  }

  int cnt = 0;
  for (int i = 0; i < Q; i++) {
    int q = T.at(i);
    int idx = binarySearch(S, q);
    // cout << idx << endl;
    if (0 <= idx && idx < N && S.at(idx) == q) {
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}