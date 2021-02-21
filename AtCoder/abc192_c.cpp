#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> f(K + 1);

  f.at(0) = N;
  for (int i = 1; i <= K; i++) {
    string min = to_string(f.at(i - 1));
    sort(min.begin(), min.end());

    string max = to_string(f.at(i - 1));
    sort(max.begin(), max.end());
    reverse(max.begin(), max.end());
    f.at(i) = stoi(max) - stoi(min);
  }

  cout << f.at(K) << endl;

  return 0;
}