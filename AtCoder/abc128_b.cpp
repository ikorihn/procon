#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  string s;
  int a;
  int index;
  vector<tuple<string, int, int>> p(N);
  for (int i = 0; i < N; i++) {
    cin >> s >> a;
    p.at(i) = make_tuple(s, 100 - a, i + 1);
  }

  sort(p.begin(), p.end());

  int ans_o;
  for (int i = 0; i < N; i++) {
    ans_o = get<2>(p.at(i));
    cout << to_string(ans_o) << endl;
  }

  return 0;
}