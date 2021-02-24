#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int LEN_B = N - 1;
  vector<int> B(LEN_B, 0);

  for (int i = 0; i < LEN_B; i++) {
    cin >> B.at(i);
  }

  vector<int> A(N, 0);
  A.at(0) = B.at(0);
  A.at(N - 1) = B.at(LEN_B - 1);
  for (int i = 1; i < LEN_B; i++) {
    int prev_b = B.at(i - 1);
    int b = B.at(i);
    int a = min(prev_b, b);
    A.at(i) = a;
  }

  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += A.at(i);
  }
  cout << sum << endl;

  return 0;
}