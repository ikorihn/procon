#include <bits/stdc++.h>
using namespace std;

bool stog(vector<string> &street, vector<vector<bool>> &checked, int H, int W,
          int h, int w) {
  if (h < 0 || w < 0 || h >= H || w >= W) {
    return false;
  }
  if (street.at(h).at(w) == '#') {
    return false;
  }
  if (checked.at(h).at(w) == true) {
    return false;
  }
  if (street.at(h).at(w) == 'g') {
    return true;
  }

  checked.at(h).at(w) = true;
  bool reachable = false;
  if (stog(street, checked, H, W, h - 1, w)) {
    reachable = true;
  }
  if (stog(street, checked, H, W, h + 1, w)) {
    reachable = true;
  }
  if (stog(street, checked, H, W, h, w - 1)) {
    reachable = true;
  }
  if (stog(street, checked, H, W, h, w + 1)) {
    reachable = true;
  }
  return reachable;
}

bool canArrive(vector<string> &street, int H, int W) {
  vector<vector<bool>> checked(H, vector<bool>(W, false));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (street.at(i).at(j) == 's') {
        if (stog(street, checked, H, W, i, j)) {
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> street(H);

  for (int i = 0; i < H; i++) {
    cin >> street.at(i);
  }

  if (canArrive(street, H, W)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
