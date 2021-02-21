#include <bits/stdc++.h>
using namespace std;

bool calc(vector<int> &nums, int &calcResult, vector<string> &oper, int i) {
  if (i == nums.size()) {
    if (calcResult == 7) {
      return true;
    }
    return false;
  }

  if (nums[i] + calc(nums, calcResult, oper, i + 1) == 7) {
    oper.at(i) = nums[i] + "+";
    cout << oper.at(i) << endl;
  }
  if (nums[i] - calc(nums, calcResult, oper, i + 1) == 7) {
    oper.at(i) = nums[i] + "-";
    cout << oper.at(i) << endl;
  }

  return nums[i];
}

int main() {
  int t;
  cin >> t;

  vector<int> nums(4);

  nums[0] = (t / 1000) % 10;
  nums[1] = (t / 100) % 10;
  nums[2] = (t / 10) % 10;
  nums[3] = t % 10;

  // nums[i] + nums[i+1以降] か nums[i] - nums[i+1以降] が7
  vector<string> oper(4);
  int calcResult = 0;
  calc(nums, calcResult, oper, 0);

  for (string o : oper) {
    cout << o << endl;
  }

  cout << "=7" << endl;

  return 0;
}
