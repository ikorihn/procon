#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int mod = N % 100;
  cout << (100 - mod) << endl;

  return 0;
}