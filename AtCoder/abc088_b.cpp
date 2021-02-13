#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> cards(N);
  for (int i = 0; i < N; i++) {
    cin >> cards.at(i);
  }
  sort(cards.begin(), cards.end());
  reverse(cards.begin(), cards.end());

  int diff = 0;
  for (int i = 0; i < cards.size(); i++) {
    if (i % 2 == 0) {
      diff += cards.at(i);
    } else {
      diff -= cards.at(i);
    }
  }

  cout << diff << endl;
}