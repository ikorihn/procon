#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int arr[N];
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  bool loop = true;
  int count = 0;
  while (loop) {
    for (int i = 0; i < N; i++) {
      if (arr[i] % 2 == 0) {
        arr[i] = arr[i] / 2;
      } else {
        loop = false;
      }
    }
    if (loop) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}