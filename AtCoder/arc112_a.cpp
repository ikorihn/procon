#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  vector<pair<int, int>> LR(T);
  for (int i = 0; i < T; i++) {
    int a, b;
    cin >> a >> b;
    LR.at(i) = make_pair(a, b);
  }

  vector<int> ans(T, 0);

  for (int t = 0; t < T; t++) {
    int a, b;
    tie(a, b) = LR.at(t);
    cout << a << " " << b << endl;
    for (int i = a; i <= b; i++) {
      for (int j = a; j < i; j++) {
        if (j - i >= a) {
          ans.at(i)++;
        }
      }
    }
  }

  for (int i = 0; i < T; i++) {
    cout << ans.at(i) << endl;
  }

  return 0;
}