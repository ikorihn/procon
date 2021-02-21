#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> mat(H, vector<char>(W));

  for (int h = 0; h < H; h++) {
    for (int w = 0; w < W; w++) {
      cin >> mat.at(h).at(w);
    }
  }

  vector<int> flagH(H, 0), flagW(W, 0);

  for (int h = 0; h < H; h++) {
    for (int w = 0; w < W; w++) {
      if (mat.at(h).at(w) == '#') {
        flagH[h] = 1;
        flagW[w] = 1;
      }
    }
  }

  for (int h = 0; h < H; h++) {
    if (flagH[h] != 1) {
      continue;
    }
    for (int w = 0; w < W; w++) {
      if (flagW[w] != 1) {
        continue;
      }
      cout << mat.at(h).at(w);
    }
    cout << endl;
  }

  return 0;
}
