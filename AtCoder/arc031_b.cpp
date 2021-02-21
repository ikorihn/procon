#include <bits/stdc++.h>
using namespace std;

void fillIsland(vector<string> &board, vector<vector<bool>> &checked, int y,
                int x) {
  int N = board.size();

  // 範囲外
  if (x < 0 || y < 0 || x >= N || y >= N) {
    return;
  }

  // 海
  if (board.at(y).at(x) == 'x') {
    return;
  }

  // チェック済み
  if (checked.at(y).at(x) == true) {
    return;
  }

  checked.at(y).at(x) = true;
  fillIsland(board, checked, y - 1, x);
  fillIsland(board, checked, y + 1, x);
  fillIsland(board, checked, y, x - 1);
  fillIsland(board, checked, y, x + 1);
}

bool isOneIsland(vector<string> &board) {
  int N = board.size();
  vector<vector<bool>> checked(N, vector<bool>(N, false));

  int x, y;
  for (int i = 0; i < N; i++) {
    bool br = false;
    for (int j = 0; j < N; j++) {
      if (board.at(i).at(j) == 'o') {
        y = i;
        x = j;
        br = true;
        break;
      }
    }
    if (br) {
      break;
    }
  }

  fillIsland(board, checked, y, x);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board.at(i).at(j) == 'o') {
        if (checked.at(i).at(j) == false) {
          return false;
        }
      }
    }
  }

  return true;
}

bool checkIsland(vector<string> &board) {
  int N = board.size();

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // x->oにして走査
      if (board.at(i).at(j) == 'x') {
        board.at(i).at(j) = 'o';

        if (isOneIsland(board)) {
          return true;
        }

        // xに戻す
        board.at(i).at(j) = 'x';
      }
    }
  }
  return false;
}

int main() {
  int N = 10;
  vector<string> board(N);
  for (int i = 0; i < N; i++) {
    cin >> board.at(i);
  }

  if (checkIsland(board)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
