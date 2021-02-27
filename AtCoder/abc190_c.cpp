#include <bits/stdc++.h>
using namespace std;

int check(vector<int> &A, vector<int> &B, vector<int> &use) {
  int N = use.size();
  int M = A.size();
  vector<bool> flagA(M, false);
  vector<bool> flagB(M, false);
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (A.at(i) == use[j]) {
        // cout << "A:" << A[i] << endl;
        flagA.at(i) = true;
      }
      if (B.at(i) == use[j]) {
        // cout << "B:" << B[i] << endl;
        flagB.at(i) = true;
      }
    }
  }

  int ret = 0;
  for (int i = 0; i < M; i++) {
    if (flagA.at(i) && flagB.at(i)) {
      ret++;
    }
  }

  // cout << "ret:" << ret << endl;
  return ret;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) {
    cin >> A.at(i) >> B.at(i);
  }
  int K;
  cin >> K;
  vector<int> C(K), D(K);
  for (int i = 0; i < K; i++) {
    cin >> C.at(i) >> D.at(i);
  }

  // cout << endl;

  int ma = 0;
  for (int bit = 0; bit < (1 << K); bit++) {
    vector<int> use;
    for (int i = 0; i < K; i++) {
      if (bit & (1 << i)) {
        // cout << "c," << C.at(i) << endl;
        use.push_back(C.at(i));
      } else {
        // cout << "d," << D.at(i) << endl;
        use.push_back(D.at(i));
      }
    }

    ma = max(ma, check(A, B, use));
  }

  cout << ma << endl;

  return 0;
}