#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> V(N), P(N);
  for (int i = 0; i < N; i++) {
    cin >> V[i] >> P[i];
  }

  int ans = -1;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += V[i] * P[i];
    if (sum > X * 100) {
      ans = i + 1;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}