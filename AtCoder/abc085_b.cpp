#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> flag(101, 0);

  vector<int> mochi(N);
  for (int i = 0; i < N; i++) {
    cin >> mochi.at(i);
  }

  sort(mochi.begin(), mochi.end());

  int count = 1;
  for (int i = 1; i < mochi.size(); i++) {
    if (mochi.at(i - 1) != mochi.at(i)) {
      count++;
    }
  }

  cout << count << endl;
}