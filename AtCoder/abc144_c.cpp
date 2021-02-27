#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll N;
  cin >> N;

  vector<pair<ll, ll>> pairs;

  ll rt = sqrt(N);
  for (ll i = 1; i <= rt; i++) {
    if (N % i == 0) {
      pairs.push_back(make_pair(i, N / i));
    }
  }

  ll min_p = N + 2;
  pair<ll, ll> target_p;
  for (ll i = 0; i < pairs.size(); i++) {
    auto p = pairs[i];
    ll sum = p.first + p.second;
    if (sum < min_p) {
      target_p = p;
      min_p = sum;
    }
  }

  cout << target_p.first + target_p.second - 2LL << endl;

  return 0;
}