#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin >> N;
  double rt = sqrt(N);

  int64_t min_f = INT_MAX;
  for (int64_t i = 1; i <= rt; i++) {
    if (N % i == 0) {
      int64_t j = N / i;
      int64_t f = max(to_string(i).length(), to_string(j).length());
      min_f = min(min_f, f);
    }
  }
  cout << min_f << endl;
  return 0;
}