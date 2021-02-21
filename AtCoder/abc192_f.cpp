#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> a) {
  int sum = 0;
  for (int n : a) {
    sum += n;
  }
  return sum;
}

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());

  bool can = false;
  (X - sum(a)) % a.size() == 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {

    }
  }

  return 0;
}